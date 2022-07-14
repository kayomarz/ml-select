/* We don't put this type definition in Select.re because Select.re has React
 * stuff and we want to also keep some separation between React and plain
 * ReasonML */

type t = {
  value: string,
  label: string,
};
