/* This hook makes the button grab focus whenever `isClosed` becomes true.
 * It also makes the button grab focus on page load. */
let useGrabFocus = isClosed => {
  let (element, setElement) = React.useState(_ => None);

  let callbackRef =
    React.useCallback(node => setElement(_ => Js.Nullable.toOption(node)));

  React.useEffect2(
    () => {
      switch (isClosed) {
      | false => ()
      | true =>
        element->Belt.Option.map(_ => My.Dom.Element.focus(element)) |> ignore
      };
      Some(() => ());
    },
    (isClosed, element),
  );

  callbackRef;
};

[@react.component]
let make =
    (
      ~ariaKeyshortcuts,
      ~ariaLabel,
      ~children,
      ~isClosed,
      ~onClick,
      ~onKeyDown,
    ) => {
  let callbackRef = useGrabFocus(isClosed);

  /* aria-haspopup seems to be commented out due to technical reasons
     https://github.com/reasonml/reason-react/issues/309
   */
  <button
    ariaKeyshortcuts
    ariaLabel
    className="mls-select-button"
    onClick
    onKeyDown
    ref={ReactDOM.Ref.callbackDomRef(callbackRef)}>
    <span className="btn-label"> children </span>
    <svg
      className="btn-icon"
      viewBox="0 0 30 18"
      xmlns="http://www.w3.org/2000/svg">
      <polygon points="0 0 30 0 15 18 0 0" />
    </svg>
  </button>;
};
