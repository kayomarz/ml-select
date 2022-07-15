open TypeOption;

let pageSize = 6;

module Dropdown = {
  [@react.component]
  let make = (~children, ~isOpen, ~target) =>
    <div> target {isOpen ? <div> children </div> : React.null} </div>;
};

let formatOptionLabel = opt => {
  let flagSuffix = opt.value;
  <>
    <span className={j|fi fi-$flagSuffix|j} />
    <span> {React.string(opt.label)} </span>
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
      onOptionChange((newOpt.value, newOpt.label));
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
    (~className="", ~defaultValue: option(string), ~onChange, ~options) => {
  let (isOpen, setIsOpen) = React.useState(_ => false);

  let (opt, setSomeOpt, setNext, setPrev, setFirst, setLast) =
    useCurrentOption(options, defaultValue, onChange);

  let onSelectChange = opt => {
    setIsOpen(_ => false);
    setSomeOpt(Some(opt));
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

  /* https://react-select.com/advanced#experimental
   * When controlShouldRenderValue is disabled, it's recommended to also
   * disable isClearable and backspaceRemovesValue.
   * We set `controlShouldRenderValue` to false so that the search box remains
   * empty, else the search box gets the same label and even icon as the
   * default value */

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
           | Some(o) => React.string(o.label)
           | None => React.string({js|---|js})
           }}
        </Button>
      }>
      <ReactSelectRe
        autoFocus=true
        backspaceRemovesValue=true
        blurInputOnSelect=true
        captureMenuScroll=false
        className="mls-react-select"
        classNamePrefix="mls-react-select-"
        closeMenuOnSelect=false
        components=[%raw
          {|{MenuList: customMenuList, DropdownIndicator: null, IndicatorSeparator: null}|}
        ]
        controlShouldRenderValue=false
        defaultValue={Js.Nullable.fromOption(opt)}
        formatOptionLabel
        isClearable=false
        isLoading=false
        menuIsOpen=isOpen
        onChange=onSelectChange
        openMenuOnFocus=true
        options
        pageSize
        placeholder=[%raw {|"Search"|}]
      />
    </Dropdown>
  </div>;
};
