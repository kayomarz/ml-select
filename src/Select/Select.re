module SButton = {
  [@react.component]
  let make = (~label, ~onClick) => {
    <button onClick=onClick> {React.string(label)} </button>;
  };
};

[@bs.scope "JSON"] [@bs.val]
external stringify: string => array(List.opt) = "parse";

[@react.component]
let make =
    (
      ~className="",
      ~dataUrl: string,
      ~defaultValue: option(string),
      ~onChange,
    ) => {
  let (options, _) =
    React.useState(() => Country.fetchCountries(dataUrl)->stringify);
  let (isOpen, setIsOpen) = React.useState(_ => true);
  let strDefaultValue =
    switch (defaultValue) {
    | Some(str) => str
    | None => "-"
    };
  <div className={j|$className mls-select-with-auto-complete|j}>
    <SButton label=strDefaultValue onClick={_ => setIsOpen(b => !b)} />
    {isOpen ? <List options /> : React.null}
  </div>;
};
