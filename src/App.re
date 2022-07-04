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
