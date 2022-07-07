[@react.component]
let make = (~options) => {
  Js.log2("<List/>", options);
  <div>
    {React.string("List")}
    {options->Belt.Array.map(r => <p> {React.string(r.label)} </p>)->React.array}
  </div>;
};
