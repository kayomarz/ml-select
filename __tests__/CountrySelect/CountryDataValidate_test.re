open Jest;
open CountryDataValidate;

let _ =
  describe("validity of country records (iso country code)", () => {
    let allValid: array(ReactSelectRe.SelectOptions.t) = [|
      {value: "au", label: "Australia"},
      {value: "in", label: "India"},
      {value: "jp", label: "Japan"},
      {value: "mc", label: "Monaco"},
      {value: "us", label: "United States"},
    |];

    let fewInvalid: array(ReactSelectRe.SelectOptions.t) = [|
      {value: "au", label: "Australia"},
      {value: "in", label: "India"},
      {value: "jp", label: "Japan"},
      {value: "aa", label: "Bar"},
      {value: "mc", label: "Monaco"},
      {value: "zz", label: "Baz"},
      {value: "us", label: "United States"},
    |];

    Expect.(
      test("isValidCountryCode - valid", () => {
        expect(isValidCountryCode("au")) |> toBe(true)
      })
    );

    Expect.(
      test("isValidCountryCode - invalid 0", () => {
        expect(isValidCountryCode("aa")) |> toBe(false)
      })
    );

    Expect.(
      test("isValidCountryCode - valid 1", () => {
        expect(isValidCountryCode("zz")) |> toBe(false)
      })
    );

    Expect.(
      test("detectInvalidCountryRecords - all-valid", () => {
        expect(detectInvalidCountryRecords(allValid)) |> toBe(None)
      })
    );

    Expect.(
      test("detectInvalidCountryRecords - some-invalid", () => {
        let invalids: array(ReactSelectRe.SelectOptions.t) = [|
          {value: "aa", label: "Bar"},
          {value: "zz", label: "Baz"},
        |];
        expect(detectInvalidCountryRecords(fewInvalid))
        |> toEqual(Some(invalids));
      })
    );

    Expect.(
      test("detectInvalidCountryRecords - some-invalid", () => {
        expect(detectInvalidCountryRecords([||]))
        |> toEqual(None);
      })
    );
  });
