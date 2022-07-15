let foo = 0; // fix an editor quirk

[@react.component]
let make =
    (
      ~children,
      ~className: string,
      ~clearValue,
      ~cx,
      ~focusedOption,
      ~getStyles,
      ~getValue,
      ~hasValue,
      ~innerProps,
      ~innerRef,
      ~isMulti,
      ~isRtl,
      ~maxHeight,
      ~options: array(TypeOption.t),
      ~selectOption,
      ~selectProps,
      ~setValue,
      ~theme,
    )
    : React.element => {
  <ReactSelectMenuListRe
    className
    clearValue
    cx
    focusedOption
    getStyles
    getValue
    hasValue
    innerProps
    innerRef
    isMulti
    isRtl
    maxHeight
    options
    selectOption
    selectProps
    setValue
    theme>
    <VirtualScroller focusedOption> children </VirtualScroller>
  </ReactSelectMenuListRe>;
};
