module Menu = {
  [@react.component]
  let make = (~children) => {
    let shadow = "red" /* 'hsla(218, 50%, 10%, 0.1)' */;
    <div
      style={ReactDOM.Style.make(
        ~backgroundColor="white",
        ~borderRadius="4",
        ~boxShadow="0 0 0 1px $shadow, 0 4px 11px $shadow",
        ~marginTop="8",
        ~position="absolute",
        ~zIndex="2",
        (),
      )}>
      children
    </div>;
  };
};

module Blanket = {
  [@react.component]
  let make = (~onClick) =>
    <div
      style={ReactDOM.Style.make(
        ~bottom="0",
        ~left="0",
        ~top="1",
        ~right="0",
        ~position="fixed",
        ~zIndex="1",
        (),
      )}
      onClick
    />;
};

module Dropdown = {
  [@react.component]
  let make = (~children, ~isOpen, ~target) =>
    <div style={ReactDOM.Style.make(~position="relative", ())}>
      target
      {isOpen ? <Menu> children </Menu> : React.null}
      {isOpen ? <Blanket onClick={_ => ()} /> : React.null}
    </div>;
};

module Svg = {
  [@react.component]
  let make = (~style=ReactDOM.Style.make(), ~children) =>
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      focusable="false"
      role="presentation"
      style>
      children
    </svg>;
};

module DropdownIndicator = {
  [@react.component]
  let make = () =>
    <div
      style={ReactDOM.Style.make(
        ~color="red" /* colors.neutral20 */,
        ~height="24",
        ~width="32",
        (),
      )}>
      <Svg>
        <path
          d="M16.436 15.085l3.94 4.01a1 1 0 0 1-1.425 1.402l-3.938-4.006a7.5 7.5 0 1 1 1.423-1.406zM10.5 16a5.5 5.5 0 1 0 0-11 5.5 5.5 0 0 0 0 11z"
          fill="currentColor"
          fillRule="evenodd"
        />
      </Svg>
    </div>;
};

module ChevronDown = {
  [@react.component]
  let make = () =>
    <Svg style={ReactDOM.Style.make(~marginRight="-6", ())}>
      <path
        d="M8.292 10.293a1.009 1.009 0 0 0 0 1.419l2.939 2.965c.218.215.5.322.779.322s.556-.107.769-.322l2.93-2.955a1.01 1.01 0 0 0 0-1.419.987.987 0 0 0-1.406 0l-2.298 2.317-2.307-2.327a.99.99 0 0 0-1.406 0z"
        fill="currentColor"
        fillRule="evenodd"
      />
    </Svg>;
};

[@react.component]
let make = (~options) => {
  let (open_, setOpen) = React.useState(_ => false);
  let toggleOpen = _ => setOpen(a => !a);
  Js.log2("open", open_);
  /* let onClose = () => (); */
  <div>
    <Dropdown
      isOpen=open_
      target={
        <ButtonRe
          onClick=toggleOpen isSelected=open_ iconAfter={<ChevronDown />}>
          {React.string("Select a country")}
        </ButtonRe>
      }>
      /* onClose */
  <ReactSelectRe
      options
    placeholder=[%raw {|"Search"|}]
    components=[%raw {|{DropdownIndicator: MlSelect$DropdownIndicator, IndicatorSeparator: null}|}]
    menuIsOpen=true
    autoFocus=true
    /> </Dropdown>
  </div>;
};
