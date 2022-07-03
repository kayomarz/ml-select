let desserts:array(MlSelect.SelectOptions.t) =
[|
 { "value": "one", "label": "One" },
 { "value": "two", "label": "Two" },
 { "value": "three", "label": "Three" },
 |];

[@react.component]
  let make = () => <MlSelect options=desserts/>;
