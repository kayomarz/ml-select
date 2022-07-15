/* Bindings for `@tanstack/react-virtual` virtual scroll library
 * https://tanstack.com/virtual/v3
 */

let foo = 0; // fix an editor quirk

[@bs.module "@tanstack/react-virtual"]
external useVirtualizer: 'a => 'b = "useVirtualizer";

[@bs.obj]
external makeVizParams:
  (
    ~count: int,
    ~estimateSize: unit => int,
    ~getScrollElement: unit => 'a,
    ~overscan: int,
    ~paddingStart: int,
    ~paddingEnd: int,
    ~enableSmoothScroll: bool,
    unit
  ) =>
  {..};
