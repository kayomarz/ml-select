type opt = {
  value: string,
  label: string,
};

[@react.component]
let make = (~options: array(opt)) => {
  <form className="mls-list">
    {options
     ->Belt.Array.map(r =>
         <input type_="text" readOnly=true value={r.label} />
       )
     ->React.array}
  </form>;
};
