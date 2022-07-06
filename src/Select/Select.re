module ChevronDown = {
  [@react.component]
  let make = () =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      focusable="false"
      role="presentation">
      <path
        d="M8.292 10.293a1.009 1.009 0 0 0 0 1.419l2.939 2.965c.218.215.5.322.779.322s.556-.107.769-.322l2.93-2.955a1.01 1.01 0 0 0 0-1.419.987.987 0 0 0-1.406 0l-2.298 2.317-2.307-2.327a.99.99 0 0 0-1.406 0z"
        fill="currentColor"
        fillRule="evenodd"
      />
    </svg>;
};

module SButton = {
  [@react.component]
  let make = (~label, ~onClick=_ => ()) => {
    <> <button onClick> {React.string(label)} <ChevronDown /> </button> </>;
  };
};

type opt = {
  value: string,
  label: string,
};

module SList = {
  [@react.component]
  let make = (~options) => {
    Js.log2("options", options);
    <>
      /* Evaluate possibilities to display list of items
       * We can try using <input type=text> and use its list attribute
       * to point to a datalist
       *
       * Or
       *
       * We can use a <select size=6> to display 6 rows
       *
       * Or
       *
       * We can implement the list ourselves.
       *
       * The first two options are difficult to style in a cross browser
       * compatible way.
       *
       */
      <form>
        <p>{React.string("List using <input> and list=datalist:")}</p>
        <input list="days" type_="text" />
        <datalist id="days">
          {React.array(
             Belt.Array.map(options, countryRecord => {
               <option label={countryRecord.label}>
                 {React.string(countryRecord.value)}
               </option>
             }),
           )}
        </datalist>
      </form>
      <form>
        <p>{React.string("List using <select> and size=6:")}</p>
        <select className="mls-select" size=6>
          {React.array(
             Belt.Array.map(options, countryRecord => {
               <option label={countryRecord.label}>
                 {React.string(countryRecord.value)}
               </option>
             }),
           )}
        </select>
      </form>
    </>;
  };
};

[@bs.scope "JSON"] [@bs.val]
external stringify: string => array(opt) = "parse";

/* let useData = url => { */
/*   let (options, _) = */
/*     React.useState(() => Country.fetchCountries(url)->stringify); */
/*   options; */
/* }; */

[@react.component]
let make =
    (
      ~labelDefault: option(string),
      ~onChange,
      ~className="",
      ~dataUrl: string,
    ) => {
  let (label, _) =
    React.useState(() =>
      switch (labelDefault) {
      | Some(str) => str
      | None => "-"
      }
    );

  let (isOpen, setIsOpen) = React.useState(() => true);
  Js.log(onChange);
  /* let options = useData(urlData); */
  let (options, _) =
    React.useState(() => Country.fetchCountries(dataUrl)->stringify);

  <div className={j|mls-select-with-auto-complete $className|j}>
    <SButton onClick={_ => setIsOpen(b => !b)} label />
    {isOpen ? <SList options /> : React.null}
  </div>;
};
