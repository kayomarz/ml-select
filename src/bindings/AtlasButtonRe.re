[@bs.module "@atlaskit/button"] [@react.component]
  external make: (
  ~children: 'a,
  ~onClick: 'b => unit,
  ~isSelected: bool,
  ~iconAfter: React.element
) => React.element = "default";
