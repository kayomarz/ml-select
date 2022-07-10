let findItemWithValue = (options, value) => {
  My.Array.filter(options, (a: ReactSelectRe.SelectOptions.t) =>
    a.value == value
  )
  |> (arr => My.Array.length(arr) === 1 ? Some(arr[0]) : None);
};

let getLabelForValue = (options, value) => {
  findItemWithValue(options, value)->Belt.Option.map(opt => opt.label);
};

let getOptionIndex =
    (options: array(ReactSelectRe.SelectOptions.t), value: string)
    : option(int) => {
  let index =
    My.Array.findIndex(options, (a: ReactSelectRe.SelectOptions.t) => {
      value == a.value
    });
  index >= 0 ? Some(index) : None;
};
