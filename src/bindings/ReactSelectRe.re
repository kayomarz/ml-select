module SelectOptions = {
  type t = {
    value: string,
    label: string,
  };
};

[@bs.module "react-select"] [@react.component]
external make:
  (
    ~autoFocus: bool,
    ~blurInputOnSelect: bool,
    ~className: string,
    ~classNamePrefix: string,
    ~components: 'components,
    ~menuIsOpen: bool,
    ~onChange: SelectOptions.t => unit,
    ~options: array(SelectOptions.t),
    ~placeholder: string
  ) =>
  React.element =
  "default";
