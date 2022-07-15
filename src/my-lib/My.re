module String = {
  // As practise, write our own bindings where possible.

  [@bs.send] external toUpperCase: string => string = "toUpperCase";

  [@bs.send] external toLowerCase: string => string = "toLowerCase";
};

module Array = {
  // As practise, write our own bindings where possible.

  [@bs.send]
  external filter: (array('a), [@bs.uncurry] ('a => bool)) => array('a) =
    "filter";

  [@bs.send]
  external map: (array('a), [@bs.uncurry] ('a => 'b)) => array('b) =
    "map";

  [@bs.send]
  external findIndex: (array('a), [@bs.uncurry] ('a => bool)) => int =
    "findIndex";

  [@bs.send] external slice: (array('a), int, int) => array('a) = "slice";

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
};

module Dom = {
  module Element = {
    // As practise, write our own bindings where possible.

    [@bs.send] external focus: 'a => unit = "focus";
  };
};

module Window = {
  // As practise, write our own bindings where possible.

  [@bs.val] external window: 'window = "window";

  [@bs.send]
  external addEventListener: ('window, string, 'event => unit) => unit =
    "addEventListener";

  [@bs.send]
  external removeEventListener: ('window, string, 'event => unit) => unit =
    "removeEventListener";

  let useEventKeyEscape = (onEvent: unit => unit) => {
    let listener = (e: 'event) => {
      switch (e##key) {
      | "Escape" => onEvent()
      | _ => ()
      };
    };
    React.useEffect1(
      () => {
        addEventListener(window, "keydown", listener);
        Some(() => removeEventListener(window, "keydown", listener));
      },
      [||],
    );
  };
};
