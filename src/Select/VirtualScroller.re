/* Virtual Scroll library: https://tanstack.com/virtual/v3 */

open TypeOption;

/* To make the arrow buttons work correctly with this virtual scroll compoent we
 * need to identify the index of the element (which is a react element) within the
 * children. To use our existing `SelectOptions.getOptionIndex` we need to
 * extract the `value` from this react element. Not sure how to do this using
 * React.element type, so we resort to this escape hatch and forcibly coerce */
external coerce: 'a => 'b = "%identity";
let reactElToOpt = (reactEl: React.element): TypeOption.t => {
  let d = coerce(reactEl)##props##data;
  {value: d##value, label: d##label};
};

let optionItemHeightPx = 27;
let paddingTopBottomPx = 4;

external coerce2: 'a => Js.Nullable.t('b) = "%identity";

let toSomeOptions = children => {
  Belt.Array.keepMap(children, c => {
    Belt.Option.map(Js.Nullable.toOption(coerce2(c)), el =>
      {value: el##props##value, label: el##props##label}
    )
  });
};

let useScrollToItem =
    (rowVirtualizer, children, focusedOption, getValue) => {
  let childrenAsOptions =
    React.useMemo1(() => toSomeOptions(children), [|children|]);

  let someOpt =
    switch (Js.Nullable.toOption(focusedOption)) {
    | Some(o) => Some(o)
    | None =>
      let focusedOpts = getValue();
      My.Array.length(focusedOpts) > 0 ? Some(focusedOpts[0]) : None;
    };

  React.useEffect1(
    () => {
      switch (someOpt) {
      | Some(opt) =>
        let i = SelectOptions.getOptionIndex(childrenAsOptions, opt.value);
        rowVirtualizer##scrollToIndex(i);
      | None => ()
      };
      Some(() => ());
    },
    [|someOpt|],
  );
};

[@react.component]
let make = (~children, ~focusedOption, ~getValue) => {
  let count = My.Array.length(children);
  let parentRef = React.useRef(Js.Nullable.null);

  let vizParams =
    ReactVirtualRe.makeVizParams(
      ~count,
      ~estimateSize=() => optionItemHeightPx,
      ~getScrollElement=() => parentRef.current,
      ~overscan=0,
      ~paddingEnd=paddingTopBottomPx,
      ~paddingStart=paddingTopBottomPx,
      ~enableSmoothScroll=false,
      (),
    );

  let rowVirtualizer = ReactVirtualRe.useVirtualizer(vizParams);
  let totalSize = rowVirtualizer##getTotalSize();

  useScrollToItem(rowVirtualizer, children, focusedOption, getValue);

  <div
    className="virtual-scroll-scrollable"
    ref={ReactDOM.Ref.domRef(parentRef)}>
    <div
      className="virtual-scroll-big-container"
      style={ReactDOM.Style.make(~height={totalSize ++ "px"}, ())}>
      {rowVirtualizer##getVirtualItems()##map(virtualItem => {
         <div
           className="virtual-scroll-option"
           key={virtualItem##key}
           style={ReactDOM.Style.make(
             ~transform={"translateY(" ++ virtualItem##start ++ "px)"},
             (),
           )}>
           {children[virtualItem##index]}
         </div>
       })}
    </div>
  </div>;
};
