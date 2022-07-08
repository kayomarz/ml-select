[@react.component]
let make = (~onClick, ~isSelected, ~children) =>
  <AtlasButtonRe onClick isSelected iconAfter={<SubComponent.ChevronDown />}>
    children
  </AtlasButtonRe>;
