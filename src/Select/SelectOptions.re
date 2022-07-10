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

let getRelativeToCurrent =
    (options, currentOpt: ReactSelectRe.SelectOptions.t, relativeIndex: int)
    : option(ReactSelectRe.SelectOptions.t) => {
  getOptionIndex(options, currentOpt.value)
  ->Belt.Option.flatMap(My.Array.addIndex(options, _, relativeIndex))
  ->Belt.Option.map(i => options[i]);
};

let getNextOption = (options, currentOpt) => {
  getRelativeToCurrent(options, currentOpt, 1);
};

let getPrevOption = (options, currentOpt) => {
  getRelativeToCurrent(options, currentOpt, -1);
};
