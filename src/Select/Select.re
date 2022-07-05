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

[@react.component]
let make =
    (~defaultValue: option(string), ~onChange, ~className="", ~options) => {
  let strDefaultValue =
    switch (defaultValue) {
    | Some(str) => str
    | None => "-"
    };
  <div className> <SButton label=strDefaultValue /> </div>;
};
