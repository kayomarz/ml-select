[@react.component]
let make = (~country: option(string), ~onChange, ~className="") => {
  <>
    <Select
      labelDefault={Country.getValidCountryCode(country)}
      onChange
      className
      dataUrl=Config.urlCountryList
    />
  </>;
};
