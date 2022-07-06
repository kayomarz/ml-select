module App = {
  [@react.component]
  let make = () =>
    <>
      <p> {React.string("Country Select Demo")} </p>
      <CountrySelect
        className="custom-class"
        country={Some("US")}
        onChange={country => Js.log(country)}
      />
    </>;
};

let reactRender = () => {
  switch (ReactDOM.querySelector("#root")) {
  | Some(root) => ReactDOM.render(<App />, root)
  | None => ()
  };
};
