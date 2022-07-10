open Jest;

let _ =
  describe("my-lib/My", () => {
    Expect.(
      test("addIndex", () => {
        expect(My.Array.addIndex([|1, 2, 3|], 1, 1)) |> toBe(Some(2))
      })
    );

    Expect.(
      test("addIndex", () => {
        expect(My.Array.addIndex([|1, 2, 3|], 99, 1)) |> toBe(None)
      })
    );

    Expect.(
      test("addIndex", () => {
        expect(My.Array.addIndex([|1, 2, 3|], 1, 99))
        |> toBe(Some(2))
      })
    );

    Expect.(
      test("addIndex", () => {
        expect(My.Array.addIndex([|1, 2, 3|], 1, -99))
        |> toBe(Some(0))
      })
    );
  });
