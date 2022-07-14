[@bs.module "react-select"] [@react.component]
external make:
  (
    ~autoFocus: bool,
    ~blurInputOnSelect: bool,
    ~classNamePrefix: string,
    ~className: string,
    ~components: 'components,
    ~formatOptionLabel: TypeOption.t => React.element,
    ~isLoading: bool,
    ~menuIsOpen: bool,
    ~onChange: TypeOption.t => unit,
    ~options: array(TypeOption.t),
    ~placeholder: string
  ) =>
  React.element =
  "default";
