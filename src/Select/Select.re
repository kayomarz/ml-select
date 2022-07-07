module SButton = {
  [@react.component]
  let make = (~label) => {
    <button> {React.string(label)} </button>;
  };
};

type opt = {
  value: string,
  label: string,
};

[@bs.scope "JSON"] [@bs.val]
external stringify: string => array(opt) = "parse";

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
  let strDefaultValue =
    switch (defaultValue) {
    | Some(str) => str
    | None => "-"
    };
  <div className> <SButton label=strDefaultValue /> <List options /> </div>;
};
