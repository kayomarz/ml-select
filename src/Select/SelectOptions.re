/* On hind sight it would be better to use the term `select tems` instead of
 * `select options`. With ReasonML's `option` we can get lost in terminology. */
open ReactSelectRe.SelectOptions;

let findItemWithValue = (options, value) => {
  My.Array.filter(options, a => a.value == value)
  |> (arr => My.Array.length(arr) === 1 ? Some(arr[0]) : None);
};

let getLabelForValue = (options, value) => {
  findItemWithValue(options, value)->Belt.Option.map(opt => opt.label);
};

let getOptionIndex = (options, value) => {
  let index = My.Array.findIndex(options, a => value == a.value);
  index >= 0 ? Some(index) : None;
};

let getRelativeToCurrent = (options, currentOpt, relativeIndex) => {
  currentOpt
  ->Belt.Option.map(opt => opt.value)
  ->Belt.Option.flatMap(strValue => getOptionIndex(options, strValue))
  ->Belt.Option.flatMap(My.Array.addIndex(options, _, relativeIndex))
  ->Belt.Option.map(i => options[i]);
};

let getNextOption = (options, currentOpt) => {
  getRelativeToCurrent(options, currentOpt, 1);
};

let getPrevOption = (options, currentOpt) => {
  getRelativeToCurrent(options, currentOpt, -1);
};

let getFirstOption = options => {
  My.Array.length(options) == 0 ? None : Some(options[0]);
};

let getLastOption = options => {
  let len = My.Array.length(options);
  len == 0 ? None : Some(options[len - 1]);
};

let mkFunctions = options => {
  let getNext = getNextOption(options);
  let getPrev = getPrevOption(options);
  let getFirst = () => getFirstOption(options);
  let getLast = () => getLastOption(options);
  let getOptionWithValue = value =>
    value->Belt.Option.flatMap(findItemWithValue(options));

  (getNext, getPrev, getFirst, getLast, getOptionWithValue);
};
