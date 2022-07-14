/* Virtual Scroll library: https://tanstack.com/virtual/v3 */

let optionItemHeightPx = 27;

[@react.component]
let make = (~children) => {
  let count = My.Array.length(children);

  let parentRef = React.useRef(Js.Nullable.null);

  let vizParams =
    ReactVirtualRe.makeVizParams(
      ~count,
      ~getScrollElement=() => parentRef.current,
      ~estimateSize=() => optionItemHeightPx,
      ~overscan=0,
      (),
    );

  let rowVirtualizer = ReactVirtualRe.useVirtualizer(vizParams);

  let totalSize = rowVirtualizer##getTotalSize();

  <div
    className="virtual-scroll-scrollable"
    ref={ReactDOM.Ref.domRef(parentRef)}>
    <div
      className="virtual-scroll-big-container"
      style={ReactDOM.Style.make(~height={totalSize ++ "px"}, ())}>
      {rowVirtualizer##getVirtualItems()##map(virtualItem => {
         let key = virtualItem##key;

         <div
           className="virtual-scroll-option"
           key
           style={ReactDOM.Style.make(
             ~transform={"translateY(" ++ virtualItem##start ++ "px)"},
             (),
           )}>
           {children[virtualItem##index]}
         </div>;
       })}
    </div>
  </div>;
};
