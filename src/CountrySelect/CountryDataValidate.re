let isValidCountryCode = (code: string): bool => {
  switch (CountryCode.codeOfString(code)) {
  | Some(_) => true
  | None => false
  };
};

let isInvalidCountryRecord = (record: TypeOption.t): bool => {
  !isValidCountryCode(record.value);
};

let detectInvalidCountryRecords =
    (records: array(TypeOption.t)): option(array(TypeOption.t)) => {
  let invalidCodes = My.Array.filter(records, isInvalidCountryRecord);
  My.Array.length(invalidCodes) == 0 ? None : Some(invalidCodes);
};

let warnPrefix = "Invalid ISO country code (www.iso.org/obp/ui/#search/code)";

let warnInvalidCountryRecords = (url: string, records) => {
  switch (detectInvalidCountryRecords(records)) {
  | Some(records) => Js.Console.warn2({j|$warnPrefix from ($url)|j}, records)
  | None => ()
  };
};

let warnInvalidCountryCode = (invalidCode: string) => {
  Js.Console.warn({j|$warnPrefix: $invalidCode|j});
};

let getValidCodeOrNone = inputCode => {
  /* Country codes seem be uppercase in many references but our library uses
   * lowercase internally because:
   *
   * + Our country list received from the server sends lowercase.
   * + Others seem to prefer it too:
   *   https://github.com/IATI/IATI-Codelists-NonEmbedded/issues/273.
   *
   * Let the component accept either lower or upper case but internally lets use
   * lower case everywhere.
   */
  inputCode
  ->Belt.Option.map(My.String.toLowerCase)
  ->Belt.Option.flatMap(CountryCode.codeOfString)
  ->Belt.Option.map(CountryCode.stringOfCode);
};

let identifyInvalidCode = (code: option(string)) => {
  let isInvalid =
    switch (code) {
    | Some(_) =>
      switch (getValidCodeOrNone(code)) {
      | Some(_) => false
      | None => true
      }
    | None => false
    };

  let invalidCodeString =
    isInvalid
      ? switch (code) {
        | Some(str) => str
        | None => ""
        }
      : "";

  (isInvalid, invalidCodeString);
};
