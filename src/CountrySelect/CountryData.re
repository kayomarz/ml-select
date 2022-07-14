// As practise, write our own bindings where possible.

[@bs.val] external fetch: string => Js.Promise.t('response) = "fetch";

[@bs.send]
external fetchResponseJson:
  'response => Js.Promise.t(array(ReactSelectRe.SelectOptions.t)) =
  "json";

let fetchCountries =
    (url: string): Js.Promise.t(array(ReactSelectRe.SelectOptions.t)) => {
  fetch(url)
  |> Js.Promise.then_(response => fetchResponseJson(response))
  |> Js.Promise.then_(records => {
       CountryDataValidate.warnInvalidCountryRecords(url, records);
       Js.Promise.resolve(records);
     });
};
