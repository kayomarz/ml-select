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

[@react.component]
let make =
    (
      ~className="",
      ~defaultValue: option(string),
      ~onChange,
      ~options: array(ReactSelectRe.SelectOptions.t),
    ) => {
  let (isOpen, setIsOpen) = React.useState(_ => false);

  let (opt, setOpt) =
    React.useState(_ => {
      defaultValue->Belt.Option.flatMap(
        SelectOptions.findItemWithValue(options),
      )
    });

  let closeOnEscape = e =>
    if (e##key == "Escape") {
      setIsOpen(_ => false);
    } else {
      ();
    };

  let onSelectChange: ReactSelectRe.SelectOptions.t => unit =
    e => {
      setIsOpen(_ => false);
      setOpt(_ => Some(e));
      onChange((e.value, e.label));
    };

  let setSomeOpt = opt => {
    switch (opt) {
    | Some(newOpt) =>
      setOpt(_ => opt);
      /* TODO: Used an escape hatch (toOpt) to forcibly co-erce a type although
       * it shouldn't be needed. Its difficult to figure this out. Without
       * explicitly stating the record type (SelectOptions.t) we see error:
       *    The record field value can't be found
       * On the other hand type inferencing should work. Need to look into this.
       */
      let o = toOpt(newOpt);
      onChange((o.value, o.label));
      ();
    | None => ()
    };
  };

  let setNextOrPrev = (opt, fn) => {
    let partial = fn(options);
    opt->Belt.Option.flatMap(partial)->setSomeOpt;
  };

  let setNext = setNextOrPrev(_, SelectOptions.getNextOption);
  let setPrev = setNextOrPrev(_, SelectOptions.getPrevOption);
  let setFirst = () => setSomeOpt(SelectOptions.getFirstOption(options));
  let setLast = () => setSomeOpt(SelectOptions.getLastOption(options));

  let onKeyDown = evt => {
    let key = ReactEvent.Keyboard.key(evt);
    switch (key) {
    | "ArrowUp" => setPrev(opt)
    | "ArrowLeft" => setPrev(opt)
    | "ArrowDown" => setNext(opt)
    | "ArrowRight" => setNext(opt)
    | "Home" => setFirst()
    | "End" => setLast()
    | _ => ()
    };
  };

  <div className={j|$className mls-select-with-auto-complete|j}>
    <Dropdown
      isOpen
      target={
        <Button
          ariaKeyshortcuts="ArrowUp ArrowDown ArrowLeft ArrowRight Home End"
          grabFocus=true
          isOpen
          onClick={_ => setIsOpen(a => !a)}
          onKeyDown>
          {switch (opt) {
           | Some((c: ReactSelectRe.SelectOptions.t)) =>
             React.string(c.label)
           | None => {React.string({js|---|js})}
           }}
        </Button>
      }>
      <ReactSelectRe
        autoFocus=true
        blurInputOnSelect=false
        className="mls-react-select"
        classNamePrefix="mls-react-select-"
        components=[%raw
          {|{MenuList: customMenuList, DropdownIndicator: null, IndicatorSeparator: null}|}
        ]
        formatOptionLabel
        isLoading=false
        menuIsOpen=isOpen
        onChange=onSelectChange
        onKeyDown=closeOnEscape
        options
        placeholder=[%raw {|"Search"|}]
      />
    </Dropdown>
  </div>;
};
