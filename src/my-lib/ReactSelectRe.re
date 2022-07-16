let foo = 0; // fix an editor quirk

[@bs.module "react-select"] [@react.component]
external make:
  (
    ~ariaErrormessage: string,
    ~ariaLabel: string,
    ~ariaHaspopup: bool,
    ~autoFocus: bool,
    ~backspaceRemovesValue: bool,
    ~blurInputOnSelect: bool,
    ~captureMenuScroll: bool,
    ~classNamePrefix: string,
    ~className: string,
    ~closeMenuOnSelect: bool,
    ~components: 'components,
    ~controlShouldRenderValue: bool,
    ~defaultValue: Js.nullable(TypeOption.t),
    ~formatOptionLabel: TypeOption.t => React.element,
    ~isClearable: bool,
    ~isLoading: bool,
    ~menuIsOpen: bool,
    ~onChange: TypeOption.t => unit,
    ~openMenuOnFocus: bool,
    ~options: array(TypeOption.t),
    ~pageSize: int,
    ~placeholder: string
  ) =>
  React.element =
  "default";
