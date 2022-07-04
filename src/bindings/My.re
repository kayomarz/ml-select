module String = {
  [@bs.send] external toUpperCase: string => string = "toUpperCase";
  [@bs.send] external toLowerCase: string => string = "toLowerCase";
};
