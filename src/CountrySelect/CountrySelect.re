[@bs.val] external setTimeout: (unit => unit, int) => int = "setTimeout";

[@bs.scope "JSON"] [@bs.val]
external parse: string => array(TypeOption.t) = "parse";

let useFetchData = dataUrl => {
  let (data, setData) = React.useState(() => "[]"->parse);
  let (isLoadingData, setIsLoadingData) = React.useState(() => true);

  React.useEffect1(
    () => {
      CountryData.fetchCountries(dataUrl)
      |> Js.Promise.then_(response => {
           setData(_ => response);
           setIsLoadingData(_ => false);
           Js.Promise.resolve(response);
         })
      |> ignore;

      Some(() => ());
    },
    [||],
  );
  (data, isLoadingData);
};

module MsgInvalidCountryCode = {
  [@react.component]
  let make = (~currentCountry: option(string)) => {
    let (isInvalid, invalidCodeString) =
      CountryDataValidate.identifyInvalidCode(currentCountry);

    if (isInvalid) {
      CountryDataValidate.warnInvalidCountryCode(invalidCodeString);
    } else {
      ();
    };
    isInvalid
      ? <dl className="invalid-iso-country">
          <dt> {React.string("Invalid ISO country code")} </dt>
          <dd> {React.string(invalidCodeString)} </dd>
        </dl>
      : React.null;
  };
};

[@react.component]
let make = (~country: option(string), ~onChange, ~className="") => {
  let (data, isLoadingData) = useFetchData(Config.countryDataUrl);
  let (currentCountry, setCurrentCountry) = React.useState(_ => country);
  let validCountryCode: option(string) =
    CountryDataValidate.getValidCodeOrNone(country);

  isLoadingData
    ? <div className="loading" ariaBusy=true>
        <p> {React.string("Welcome")} </p>
        <small ariaHidden=true> {React.string({js|☾˙❀‿❀˙☽|js})} </small>
        <p> {React.string("Loading...")} </p>
      </div>
    : <>
        <div className="lbl-country"> {React.string("Select a country")} </div>
        <Select
          ariaLabel="Select country"
          ariaErrormessage="invalidCountry"
          defaultValue=validCountryCode
          onChange={((value, _)) => {
            setCurrentCountry(_ => Some(value));
            let (isInvalid, _) =
              CountryDataValidate.identifyInvalidCode(Some(value));
            if (!isInvalid) {
              onChange(value);
            };
          }}
          className
          options=data
        />
        <div id="invalidCountry" className="invalid-iso-country">
          <MsgInvalidCountryCode currentCountry />
        </div>
      </>;
};
