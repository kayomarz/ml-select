[@react.component]
let make = (~country: option(string), ~onChange, ~className="") => {
  <>
    <Select
      className
      dataUrl=Config.urlCountryList
      defaultValue={Country.getValidCountryCode(country)}
      onChange
    />
  </>;
};
