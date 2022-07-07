[@react.component]
let make = (~style=ReactDOM.Style.make(), ~children) =>
  <svg
    width="24"
    height="24"
    viewBox="0 0 24 24"
    focusable="false"
    role="presentation"
    style>
    children
  </svg>;
