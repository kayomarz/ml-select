module SelectOptions {
  type t = {
    .
      "value": string,
    "label": string
  };
};

[@bs.module "react-select"] [@react.component]
  external make: (~options: array(SelectOptions.t)) => React.element = "default";
