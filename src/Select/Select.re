external toOpt: 'a => ReactSelectRe.SelectOptions.t = "%identity";

module Dropdown = {
  [@react.component]
  let make = (~children, ~isOpen, ~target) =>
    <div> target {isOpen ? <div> children </div> : React.null} </div>;
};

let formatOptionLabel = (r: ReactSelectRe.SelectOptions.t) => {
  let flagSuffix = r.value;
  <>
    <span className={j|fi fi-$flagSuffix|j} />
    <span> {React.string(r.label)} </span>
  </>;
};

let customMenuList = MenuList.make;

/* This hook handles state of the currently selection option and provides some 
 * helper functions */
let useCurrentOption = (options, defaultValue, onOptionChange) => {
  let (getNext, getPrev, getFirst, getLast, getOptionWithValue) =
    SelectOptions.mkFunctions(options);

  let (opt, setOpt) = React.useState(_ => getOptionWithValue(defaultValue));

  let setSomeOpt = opt => {
    switch (opt) {
    | Some(newOpt) =>
      setOpt(_ => opt);
      /* TODO: Use escape hatch `toOpt` to force type coercion. It shouldn't be
       * needed bu as a newbie, can't figure it out. Without explicit record
       * type (SelectOptions.t) we get: `record field value can't be found`. On
       * the other hand type inferencing should work. Need to look into this. */
      let o = toOpt(newOpt);
      onOptionChange((o.value, o.label));
      ();
    | None => ()
    };
  };

  let setNext = () => setSomeOpt(getNext(opt));
  let setPrev = () => setSomeOpt(getPrev(opt));
  let setFirst = () => setSomeOpt(getFirst());
  let setLast = () => setSomeOpt(getLast());

  (opt, setSomeOpt, setNext, setPrev, setFirst, setLast);
};

[@react.component]
let make =
    (
      ~className="",
      ~defaultValue: option(string),
      ~onChange,
      ~options: array(ReactSelectRe.SelectOptions.t),
    ) => {
  let (isOpen, setIsOpen) = React.useState(_ => false);

  let (opt, setSomeOpt, setNext, setPrev, setFirst, setLast) =
    useCurrentOption(options, defaultValue, onChange);

  let onSelectChange: ReactSelectRe.SelectOptions.t => unit =
    o => {
      setIsOpen(_ => false);
      setSomeOpt(Some(o));
    };

  let onKeyDown = evt => {
    let key = ReactEvent.Keyboard.key(evt);
    switch (key) {
    | "ArrowUp" => setPrev()
    | "ArrowLeft" => setPrev()
    | "ArrowDown" => setNext()
    | "ArrowRight" => setNext()
    | "Home" => setFirst()
    | "End" => setLast()
    | _ => ()
    };
  };

  My.Window.useEventKeyEscape(() => setIsOpen(_ => false));

  <div className={j|$className mls-select-with-auto-complete|j}>
    <Dropdown
      isOpen
      target={
        <Button
          ariaKeyshortcuts="ArrowUp ArrowDown ArrowLeft ArrowRight Home End"
          isClosed={!isOpen}
          onClick={_ => setIsOpen(a => !a)}
          onKeyDown>
          {switch (opt) {
           | Some((c: ReactSelectRe.SelectOptions.t)) =>
             React.string(c.label)
           | None => React.string({js|---|js})
           }}
        </Button>
      }>
      <ReactSelectRe
        autoFocus=true
        blurInputOnSelect=true
        className="mls-react-select"
        classNamePrefix="mls-react-select-"
        components=[%raw
          {|{MenuList: customMenuList, DropdownIndicator: null, IndicatorSeparator: null}|}
        ]
        formatOptionLabel
        isLoading=false
        menuIsOpen=isOpen
        onChange=onSelectChange
        options
        placeholder=[%raw {|"Search"|}]
      />
    </Dropdown>
  </div>;
};
