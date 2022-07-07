module SelectOptions {
  type t = {
    value: string,
    label: string
  };
};

type componentsT = {
  .
    "DropdownIndicator": React.element,
  "IndicatorSeparator": React.element
};

[@bs.module "react-select"] [@react.component]
  external make: (
  ~options: array(SelectOptions.t),
  ~components: 'components,
  ~placeholder: string,
  ~menuIsOpen: bool,
  ~autoFocus: bool,
) => React.element = "default";
