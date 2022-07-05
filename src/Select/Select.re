module ChevronDown = {
  [@react.component]
  let make = () =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      focusable="false"
      role="presentation"
        >
      <path
        d="M8.292 10.293a1.009 1.009 0 0 0 0 1.419l2.939 2.965c.218.215.5.322.779.322s.556-.107.769-.322l2.93-2.955a1.01 1.01 0 0 0 0-1.419.987.987 0 0 0-1.406 0l-2.298 2.317-2.307-2.327a.99.99 0 0 0-1.406 0z"
        fill="currentColor"
        fillRule="evenodd"
      />
    </svg>;
};

module SButton = {
  [@react.component]
  let make = (~label) => {
    <> <button> {React.string(label)} <ChevronDown /> </button> </>;
  };
};

type opt = {
  value: string,
  label: string,
};

[@react.component]
let make =
    (~defaultValue: option(string), ~onChange, ~className="", ~options) => {
  let strDefaultValue =
    switch (defaultValue) {
    | Some(str) => str
    | None => "-"
    };
  <div className={j|ml-select-with-auto-complete $className|j}>
    <SButton label=strDefaultValue />
  </div>;
};
