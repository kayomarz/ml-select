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

  let onSelectChange: ReactSelectRe.SelectOptions.t => unit =
    e => {
      setIsOpen(_ => false);
      setOpt(_ => Some(e));
      onChange((e.value, e.label));
    };

  let closeOnEscape = e =>
    if (e##key == "Escape") {
      setIsOpen(_ => false);
    } else {
      ();
    };

  <div className={j|$className mls-select-with-auto-complete|j}>
    <Dropdown
      isOpen
      target={
        <Button grabFocus=true isOpen onClick={_ => setIsOpen(a => !a)}>
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
          {|{DropdownIndicator: null, IndicatorSeparator: null}|}
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
