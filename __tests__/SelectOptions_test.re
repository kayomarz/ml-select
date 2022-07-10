open Jest;

let _ =
  describe("getLabelForValue", () => {
    let options: array(ReactSelectRe.SelectOptions.t) = [|
      {value: "foo", label: "Foo foo"},
      {value: "bar", label: "Bar bar"},
      {value: "foo-bar", label: "Foo-Bar foo-bar"},
    |];

    Expect.(
      test("get existing 0", () => {
        expect(SelectOptions.getLabelForValue(options, "foo"))
        |> toBe(Some("Foo foo"))
      })
    );

    Expect.(
      test("get existing 1", () => {
        expect(SelectOptions.getLabelForValue(options, "bar"))
        |> toBe(Some("Bar bar"))
      })
    );

    Expect.(
      test("non existing", () => {
        expect(SelectOptions.getLabelForValue(options, "baz")) |> toBe(None)
      })
    );

    Expect.(
      test("getOptionIndex", () => {
        expect(SelectOptions.getOptionIndex(options, "bar"))
        |> toBe(Some(1))
      })
    );

    Expect.(
      test("getOptionIndex", () => {
        expect(SelectOptions.getOptionIndex(options, "foo"))
        |> toBe(Some(0))
      })
    );

    Expect.(
      test("getOptionIndex", () => {
        expect(SelectOptions.getOptionIndex(options, "baz")) |> toBe(None)
      })
    );

    Expect.(
      test("getRelativeToCurrent", () => {
        expect(
          SelectOptions.getRelativeToCurrent(
            options,
            {value: "bar", label: "Bar bar"},
            1,
          ),
        )
        |> toEqual(
             Some(
               {value: "foo-bar", label: "Foo-Bar foo-bar"}: ReactSelectRe.SelectOptions.t,
             ),
           )
      })
    );

    Expect.(
      test("getRelativeToCurrent", () => {
        expect(
          SelectOptions.getRelativeToCurrent(
            options,
            {value: "bar", label: "Bar bar"},
            99,
          ),
        )
        |> toEqual(
             Some(
               {value: "foo-bar", label: "Foo-Bar foo-bar"}: ReactSelectRe.SelectOptions.t,
             ),
           )
      })
    );

    Expect.(
      test("getRelativeToCurrent", () => {
        expect(
          SelectOptions.getRelativeToCurrent(
            options,
            {value: "bar", label: "Bar bar"},
            -1,
          ),
        )
        |> toEqual(
             Some(
               {value: "foo", label: "Foo foo"}: ReactSelectRe.SelectOptions.t,
             ),
           )
      })
    );

    Expect.(
      test("getRelativeToCurrent", () => {
        expect(
          SelectOptions.getRelativeToCurrent(
            options,
            {value: "bar", label: "Bar bar"},
            -99,
          ),
        )
        |> toEqual(
             Some(
               {value: "foo", label: "Foo foo"}: ReactSelectRe.SelectOptions.t,
             ),
           )
      })
    );
  });
