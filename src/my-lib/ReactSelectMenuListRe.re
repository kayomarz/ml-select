let foobar = ();

[@react.component] [@bs.module "react-select"] [@bs.scope "components"]
external make:
  /* Most of the props are not used in this ReasonML app. Hence we have not
   * defined types for them all. The props will be passed on as it is via
   * `components` prop. */
  (
    ~children: React.element,
    ~className: string,
    ~clearValue: {..},
    ~cx: {..},
    ~focusedOption: Js.nullable(TypeOption.t),
    ~getStyles: {..},
    ~getValue: unit => array(TypeOption.t),
    ~hasValue: {..},
    ~innerProps: {..},
    ~innerRef: {..},
    ~isMulti: {..},
    ~isRtl: {..},
    ~maxHeight: {..},
    ~options: array(TypeOption.t),
    ~selectOption: {..},
    ~selectProps: {..},
    ~setValue: {..},
    ~theme: {..}
  ) =>
  React.element =
  "MenuList";
