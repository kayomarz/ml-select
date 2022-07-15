let foo = 0; // fix an editor quirk

[@bs.module "react-select"] [@react.component]
external make:
  (
    ~autoFocus: bool,
    ~blurInputOnSelect: bool,
    ~captureMenuScroll: bool,
    ~classNamePrefix: string,
    ~className: string,
    ~components: 'components,
    ~formatOptionLabel: TypeOption.t => React.element,
    ~isLoading: bool,
    ~menuIsOpen: bool,
    ~onChange: TypeOption.t => unit,
    ~options: array(TypeOption.t),
    ~pageSize: int,
    ~placeholder: string
  ) =>
  React.element =
  "default";
