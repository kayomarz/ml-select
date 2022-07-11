let useGrabFocus = (grabFocus, isOpen) => {
  let refEl = React.useRef(Js.Nullable.null);

  React.useEffect1(
    () => {
      if (grabFocus && !Js.Nullable.isNullable(refEl.current) && !isOpen) {
        /* TODO: This creates a race to grab `focus` because other components
         * too may contend to get focus. Instead use a top-level application
         * construct to handle granting of focus.
         */
        My.Dom.Element.focus(refEl.current);
        ();
      } else {
        ();
      };
      Some(() => ());
    },
    [|isOpen, grabFocus|],
  );
  refEl;
};

[@react.component]
let make =
    (~ariaKeyshortcuts, ~children, ~grabFocus, ~isOpen, ~onClick, ~onKeyDown) => {
  let btnRef = useGrabFocus(grabFocus, isOpen);

  <button
    className="mls-select-button"
    onClick
    onKeyDown
    ariaKeyshortcuts
    ref={ReactDOM.Ref.domRef(btnRef)}>
    <span className="btn-label"> children </span>
    <svg
      className="btn-icon"
      viewBox="0 0 30 18"
      xmlns="http://www.w3.org/2000/svg">
      <polygon points="0 0 30 0 15 18 0 0" />
    </svg>
  </button>;
};
