[@bs.val] external setTimeout: (unit => unit, int) => int = "setTimeout";

[@bs.scope "JSON"] [@bs.val]
external parse: string => array(ReactSelectRe.SelectOptions.t) = "parse";

let useFetchData = dataUrl => {
  let (data, setData) = React.useState(() => "[]"->parse);
  let (isLoadingData, setIsLoadingData) = React.useState(() => true);

  React.useEffect1(
    () => {
      /* During dev, emulate a delay to build UI loading messages. */
      setTimeout(
        () => {
          setData(_ => Country.fetchCountries(dataUrl)->parse);
          setIsLoadingData(_ => false);
        },
        2000,
      );

      Some(() => ());
    },
    [||],
  );
  (data, isLoadingData);
};

[@react.component]
let make = (~country: option(string), ~onChange, ~className="") => {
  let (data, isLoadingData) = useFetchData(Config.countryDataUrl);

  isLoadingData
    ? <p> {React.string("Loading...")} </p>
    : <>
        <Select
          defaultValue={Country.getValidCountryCode(country)}
          onChange
          className
          options=data
        />
      </>;
};
