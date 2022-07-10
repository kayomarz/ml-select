external toOpt: 'a => ReactSelectRe.SelectOptions.t = "%identity";

module Dropdown = {
  [@react.component]
  let make = (~children, ~isOpen, ~target) =>
    <div> target {isOpen ? <div> children </div> : React.null} </div>;
};

let formatOptionLabel = (r: ReactSelectRe.SelectOptions.t) => {
  let flagSuffix = r.value;
  <>
    <span className={j|fi fi-$flagSuffix|j} />
    <span> {React.string(r.label)} </span>
  </>;
};

[@react.component]
let make =
    (
      ~className="",
      ~defaultValue: option(string),
      ~onChange,
      ~options: array(ReactSelectRe.SelectOptions.t),
    ) => {
  let (isOpen, setIsOpen) = React.useState(_ => false);

  let (opt, setOpt) =
    React.useState(_ => {
      defaultValue->Belt.Option.flatMap(
        SelectOptions.findItemWithValue(options),
      )
    });

  let closeOnEscape = e =>
    if (e##key == "Escape") {
      setIsOpen(_ => false);
    } else {
      ();
    };

  let onSelectChange: ReactSelectRe.SelectOptions.t => unit =
    e => {
      setIsOpen(_ => false);
      setOpt(_ => Some(e));
      onChange((e.value, e.label));
    };

  let setNextOrPrev = (opt, fn) => {
    opt
    ->Belt.Option.flatMap(fn(options))
    ->(
        newOpt => {
          setOpt(_ => newOpt);

          /* TODO: Used an escape hatch (toOpt) to forcibly co-erce a type
           * although it shouldn't be needed. Its difficult to figure this out.
           * Without explicitly stating the record type (SelectOptions.t) we get
           * see error:
           *   The record field value can't be found
           * On the other hand type inferencing should work out.
           * Need to look into this.
            */
          let o = toOpt(newOpt);
          onChange((o.value, o.label));
        }
      );
    ();
  };

  let setNext = setNextOrPrev(_, SelectOptions.getNextOption);
  let setPrev = setNextOrPrev(_, SelectOptions.getPrevOption);

  let onKeyDown = evt => {
    let key = ReactEvent.Keyboard.key(evt);
    switch (key) {
    | "ArrowUp" => setPrev(opt)
    | "ArrowLeft" => setPrev(opt)
    | "ArrowDown" => setNext(opt)
    | "ArrowRight" => setNext(opt)
    | _ => ()
    };
  };

  <div className={j|$className mls-select-with-auto-complete|j}>
    <Dropdown
      isOpen
      target={
        <Button
          grabFocus=true isOpen onClick={_ => setIsOpen(a => !a)} onKeyDown>
          {switch (opt) {
           | Some((c: ReactSelectRe.SelectOptions.t)) =>
             React.string(c.label)
           | None => React.string("Error: No data") /* Shouldnt occur */
           }}
        </Button>
      }>
      <ReactSelectRe
        autoFocus=true
        blurInputOnSelect=false
        className="mls-react-select"
        classNamePrefix="mls-react-select-"
        components=[%raw
          {|{DropdownIndicator: null, IndicatorSeparator: null}|}
        ]
        formatOptionLabel
        isLoading=false
        menuIsOpen=isOpen
        onChange=onSelectChange
        onKeyDown=closeOnEscape
        options
        placeholder=[%raw {|"Search"|}]
      />
    </Dropdown>
  </div>;
};
