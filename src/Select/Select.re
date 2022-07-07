[@bs.scope "JSON"] [@bs.val]
external stringify: string => array(ReactSelectRe.SelectOptions.t) = "parse";
/* external stringify: string => array(opt) = "parse"; */

module Dropdown = {
  [@react.component]
  let make = (~children, ~isOpen, ~target) =>
    <div style={ReactDOM.Style.make(~position="relative", ())}>
      target
      {isOpen ? <div className="mls-menu"> children </div> : React.null}
    </div>;
  /* {isOpen ? <div className="mls-blanket" onClick={_ => close()} /> : React.null} */
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
      ~defaultValue: option(string),
      ~onChange,
      ~className="",
      ~dataUrl: string,
    ) => {
  let (isOpen, setIsOpen) = React.useState(_ => true);
  let options = useSelectOptions(dataUrl);
  
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
          options
          placeholder=[%raw {|"Search"|}]
          components=[%raw
            {|{DropdownIndicator: Select$DropdownIndicator, IndicatorSeparator: null}|}
          ]
          menuIsOpen=true
          autoFocus=true
        />
      </Dropdown>
  </div>;
};
