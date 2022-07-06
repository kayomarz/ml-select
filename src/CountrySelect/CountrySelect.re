[@react.component]
let make = (~country: option(string), ~onChange, ~className="") => {
  <>
    <Select
      defaultValue={Country.getValidCountryCode(country)}
      onChange
      className
      dataUrl=Config.urlCountryList
    />
  </>;
};
