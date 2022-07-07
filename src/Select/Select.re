[@bs.scope "JSON"] [@bs.val]
external stringify: string => array(ReactSelectRe.SelectOptions.t) = "parse";

module Dropdown = {
  [@react.component]
  let make = (~children, ~isOpen, ~target) =>
    <div> target {isOpen ? <div> children </div> : React.null} </div>;
};

module DropdownIndicator = {
  [@react.component]
  let make = () => <SubComponent.DropdownIndicator />;
};

let useSelectOptions = dataUrl => {
  let (options, _) =
    React.useState(() => Country.fetchCountries(dataUrl)->stringify);
  options;
};

let getDefaultValueAsString = defaultValue => {
  switch (defaultValue) {
  | Some(str) => str
  | None => "-"
  };
};

[@react.component]
let make =
    (
      ~className="",
      ~dataUrl: string,
      ~defaultValue: option(string),
      ~onChange,
    ) => {
  let (isOpen, setIsOpen) = React.useState(_ => true);
  let options = useSelectOptions(dataUrl);

  let onMenuChange: ReactSelectRe.SelectOptions.t => unit =
    e => {
      Js.log3("onMenuChange", e.value, e.label);
      setIsOpen(_ => false);
    };

  /* let onClose = () => (); */
  <div className={j|$className mls-select-with-auto-complete|j}>
    <Dropdown
      isOpen
      target={
        <Button onClick={_ => setIsOpen(a => !a)} isSelected=isOpen>
          {React.string("Select a country")}
        </Button>
      }>
      /* onClose */

        <ReactSelectRe
          autoFocus=true
          blurInputOnSelect=false
          className="mls-react-select"
          classNamePrefix="mls-react-select-"
          components=[%raw
            {|{DropdownIndicator: Select$DropdownIndicator, IndicatorSeparator: null}|}
          ]
          menuIsOpen=true
          onChange=onMenuChange
          options
          placeholder=[%raw {|"Search"|}]
        />
      </Dropdown>
  </div>;
};
