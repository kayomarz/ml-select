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
    ~classNamePrefix: string,
    ~className: string,
    ~components: 'components,
    ~formatOptionLabel: SelectOptions.t => React.element,
    ~isLoading: bool,
    ~menuIsOpen: bool,
    ~onChange: SelectOptions.t => unit,
    ~onKeyDown: 'ev => unit,
    ~options: array(SelectOptions.t),
    ~placeholder: string
  ) =>
  React.element =
  "default";
