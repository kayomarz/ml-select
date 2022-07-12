let getValidCountryCode = inputCode => {
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
