[@react.component]
let make =
    (
      ~children,
      ~className,
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
      ~options,
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
     children </ReactSelectMenuListRe>;
    /* TODO: render only visible items */
    /* {My.Array.slice(children, 0, 6)->React.array} */
};
