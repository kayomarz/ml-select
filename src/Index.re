module App = {
  [@react.component]
  let make = () =>
    <CountrySelect
      className="custom-class"
      country={Some("us")}
      onChange={country => Js.log(country)}
    />;
};

let reactRender = () => {
  switch (ReactDOM.querySelector("#root")) {
  | Some(root) => ReactDOM.render(<App />, root)
  | None => ()
  };
};
