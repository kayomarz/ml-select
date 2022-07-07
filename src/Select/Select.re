module Menu = {
  [@react.component]
  let make = (~children) => {
    let shadow = "red" /* 'hsla(218, 50%, 10%, 0.1)' */;
    <div
      style={ReactDOM.Style.make(
        ~backgroundColor="white",
        ~borderRadius="4",
        ~boxShadow="0 0 0 1px $shadow, 0 4px 11px $shadow",
        ~marginTop="8",
        ~position="absolute",
        ~zIndex="2",
        (),
      )}>
      children
    </div>;
  };
};

module Dropdown = {
  [@react.component]
  let make = (~children, ~isOpen, ~target) =>
    <div style={ReactDOM.Style.make(~position="relative", ())}>
      target
      {isOpen ? <Menu> children </Menu> : React.null}
    </div>;
  /* {isOpen ? <Blanket onClick={_ => ()} /> : React.null} */
};

module DropdownIndicator = {
  [@react.component]
  let make = () => <SubComponent.DropdownIndicator />;
};

[@bs.scope "JSON"] [@bs.val]
external stringify: string => array(ReactSelectRe.SelectOptions.t) = "parse";
/* external stringify: string => array(opt) = "parse"; */

[@react.component]
let make =
    (
      ~defaultValue: option(string),
      ~onChange,
      ~className="",
      ~dataUrl: string,
    ) => {
  let (isOpen, setIsOpen) = React.useState(_ => false);
  /* let onClose = () => (); */
  let strDefaultValue =
    switch (defaultValue) {
    | Some(str) => str
    | None => "-"
    };
  let (options, _) =
    React.useState(() => Country.fetchCountries(dataUrl)->stringify);
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
