module String = {
  [@bs.send] external toUpperCase: string => string = "toUpperCase";
  [@bs.send] external toLowerCase: string => string = "toLowerCase";
};

module Array = {
  [@bs.send]
  external filter: (array('a), [@bs.uncurry] ('a => bool)) => array('a) =
    "filter";

  [@bs.get] external length: array('a) => int = "length";
};
