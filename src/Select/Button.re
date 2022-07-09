[@react.component]
let make = (~onClick, ~isSelected, ~children) => {
  let btn = React.useRef(Js.Nullable.null);
  React.useEffect1(
    () => {
      My.Dom.Element.focus(btn.current);
      Some(() => ());
    },
    [||],
  );
  <button
    ref={ReactDOM.Ref.domRef(btn)} className="mls-select-button" onClick>
    <span className="btn-label"> children </span>
    <svg
      xmlns="http://www.w3.org/2000/svg"
      className="btn-icon"
      viewBox="0 0 30 15">
      <polygon points="0 0 30 0 15 15 0 0" />
    </svg>
  </button>;
};
