module String = {
  [@bs.send] external toUpperCase: string => string = "toUpperCase";
  [@bs.send] external toLowerCase: string => string = "toLowerCase";
};

module Array = {
  [@bs.send]
  external filter: (array('a), [@bs.uncurry] ('a => bool)) => array('a) =
    "filter";

  [@bs.send]
  external findIndex: (array('a), [@bs.uncurry] ('a => bool)) => int =
    "findIndex";

  [@bs.get] external length: array('a) => int = "length";

  /* Add a value to the current index without crossing array limits */
  let addIndex = (arr: array('b), currentIndex: int, relativeIndex: int) => {
    let len = length(arr);
    if (currentIndex < 0 || currentIndex >= len) {
      None;
    } else {
      let newIndex = currentIndex + relativeIndex;
      if (newIndex < 0) {
        Some(0);
      } else if (newIndex >= len) {
        Some(len - 1);
      } else {
        Some(newIndex);
      };
    };
  };
  /* let getRelativeToCurrent = */
  /*   (options, currentOpt: ReactSelectRe.SelectOptions.t, relativeIndex: int) => { */
  /*   adMy.Array.findIndex(options, opt.value) */
  /* }; */
};

module Dom = {
  module Element = {
    [@bs.send] external focus: 'a => unit = "focus";
  };
};
