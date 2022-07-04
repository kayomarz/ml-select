type opt = {
  value: string,
  label: string,
};

[@react.component]
let make = (~defaultValue: option(string), ~onChange, ~className, ~options) => {
  let strDefaultValue =
    switch (defaultValue) {
    | Some(str) => str
    | None => "-"
    };
  <div> <button> {React.string(strDefaultValue)} </button> </div>;
};
