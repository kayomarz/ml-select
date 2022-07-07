module Dropdown = {
  [@react.component]
  let make = (~children, ~isOpen, ~target) =>
    <div> target {isOpen ? <div> children </div> : React.null} </div>;
};

module DropdownIndicator = {
  [@react.component]
  let make = () => <SubComponent.DropdownIndicator />;
};

[@react.component]
let make =
    (
      ~className="",
      ~options: array(ReactSelectRe.SelectOptions.t),
      ~defaultValue: option(string),
      ~onChange,
    ) => {
  let (isOpen, setIsOpen) = React.useState(_ => true);

  let (opt, setOpt) =
    React.useState(_ => {
      defaultValue->Belt.Option.flatMap(
        SelectOptions.findItemWithValue(options),
      )
    });

  let onSelectChange: ReactSelectRe.SelectOptions.t => unit =
    e => {
      Js.log3("onMenuChange", e.value, e.label);
      setIsOpen(_ => false);
      setOpt(_ => Some(e));
    };

  <div className={j|$className mls-select-with-auto-complete|j}>
    <Dropdown
      isOpen
      target={
        <Button onClick={_ => setIsOpen(a => !a)} isSelected=isOpen>
          {switch (opt) {
           | Some((c: ReactSelectRe.SelectOptions.t)) =>
             React.string(c.label)
           | None => React.string("Error: No data") /* Shouldnt occur */
           }}
        </Button>
      }>
      <ReactSelectRe
        autoFocus=true
        blurInputOnSelect=false
        className="mls-react-select"
        classNamePrefix="mls-react-select-"
        components=[%raw
          {|{DropdownIndicator: Select$DropdownIndicator, IndicatorSeparator: null}|}
        ]
        isLoading=false
        menuIsOpen=true
        onChange=onSelectChange
        options
        placeholder=[%raw {|"Search"|}]
      />
    </Dropdown>
  </div>;
};
