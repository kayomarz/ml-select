# ML-Select

This is a *React.js* component which functions like an HTML `<select>` *+* auto
complete.

This is not a production ready library. It is an exercise in exploring **OCaml**
based **ReasonML** and **ReScript** for frontend web development.

# Usage

    <CountrySelect
        className="custom-class"
        country=Some("us")
        onChange=(country => Js.log(country))
    />

# Steps taken to build the compoent

The rest of this page is a log of the steps required and decisions made while
developing this component.

## Todos

1. ✓ Explore the ecosystem and language.
2. ✓ ReasonML in the browser - Use webpack to integrate `ReasonML` with `bsb`.
3. ✓ Explore writing bindings.
4. ✗ Test for bindings. [This
   article](https://itnext.io/reasonml-create-bindings-for-npm-package-b8a3c6d0703e#cb5f)
   describes tests for ReasonML bindings using
   [@glennsl/bs-jest](https://github.com/glennsl/rescript-jest/tree/v0.3.2)
   which is marked as experimental. It's not yet clear how to write tests.
5. Interact with React.js
   + ✓ Initially use existing bindings and get familiar with ReasonReact.
   + ✓ Write bindings for basic use of `React-Select` (via npm).
6. Interface:
   `<CountrySelect
      className="custom-class"
      country=Some("us")
      onChange=(country => Js.log(country))
    />`
7. Complete the functionality
   + Write bindings for `react-select` required for this component.
   + Fetch countries from the server.
   + Create a `MlSelect` general component as parent which has the required
     functionality.
   + `CountrySelect` will then use `MlSelect`.
   + Handle invalid user input. i.e. what if a user types an option which does
     not exist and hits enter.
   + Ensure all keyboard shortcuts work (open/close dropdown, navigate and
     select options, cancel choice with keyboard)
   + The search filter is internal. It filters countries by name without case
     sensitivity.
   + Renders only visible options; it is not slow on opening.
8. Styling
   + Explore `Sketch-file` and `flag-icon-css`
   + Decide if we can use `scss` or explore what `bs-css` is all about. Is it a
     de-factor to work with ReasonML?
   + Do the styling.
9. As an exercise on bindings, write our own bindings for the React.js features
   which we need. i.e. don't use ReasonReact.
10. Deploy a live demo of `<CountrySelect/>`

## Aspects to learn

1. Ecosystem including build and test tools.
2. Language features.
3. How to write bindings such that they take advantage of type safety which
   ReScript/ReasonML provide.
4. Coding conventions - See [reasonml-style.pdf (cs.brown.edu)](https://cs.brown.edu/courses/cs017/content/docs/reasonml-style.pdf)

## Choosing between ReScript & ReasonML

**ReScript** seems to have its own syntax deviating from OCaml while ReasonML
stays closer to OCaml. ReScript has gained a lot of traction and seems to have
great tooling support.

**ReasonML** seems to be loosing traction for frontend web development. I got
this impression after spending a short while surveying the ecosystem and maybe
thats not completely true.

Being new to the ecosystem, **ReScript** seems to be the apparent choice.

### Further exploration

On further exploration, **ReasonML** seems to be the better choice, at-least for
this task of exploring OCaml for web development.

It took quite a while to figure out the ecosystem but it is an important step to
choose between ReasonML and ReScript.

### Why ReasonML?

**ReScript** being young, might continue to veer further towards JavaScript and
spin off into something different from ReasonML or OCaml. ReScript might become
a great language but the JavaScript ecosystem is enormous with many languages
compiling to JavaScript such as ClojureScript, Elm, PureScript, Dart and
TypeScript.

**ReasonML** seems to remain close to OCaml and serve our purpose. It has the
necessary JavaScript interoperability and has **ReasonReact**. Being adopted by
companies for frontend development, ReasonML developers seem to have reaped its
benefits and had a pleasant development experience. Maybe due to the changing
ecosystem ReasonML teams might have to migrate to ReScript.

Owing to fading away of ReasonML or so it **seems**, maybe its not the best
choice to start a production level app using ReasonML but I don't yet know the
ecosystem well enough to make this decision.

Eventually we want to write correct and readable code in an expressive
language. We also need to churn out top-notch apps despite their changing
requirements.

To each their own.

For this task, lets use **ReasonML** and get a feel of OCaml for frontend dev.

# Getting started

Choosing ReasonML over ReScript itself took quite a while. Lets get started!
([Awesome ReasonML](https://github.com/vramana/awesome-reasonml) maybe a good
place to start.)

## Design

1. Rather than design the component from scratch we use
   [react-select](https://react-select.com/home) which seems to be a seasoned
   component and should have predictable behaviour across browsers.

2. Since our focus is exploring `ReasonML` and its bindings, we use [this
   JavaScript example (React-select popout
   example)](https://github.com/JedWatson/react-select/blob/v3.0.0/docs/examples/Popout.js)
   to configure the component in ReasonML.

## Exploring ReasonML

We need to install a compiler and explore the language.

### BuckleScript compiler

To experiment we use the BuckleScript command `bsb -make-world -w` to compile
ReasonML, run the code using node and observe the compiled JavaScript which is
readable and which was one of the goals of the BuckleScript author.

Note: `bsb` helps with creating a sample project.

    bsb -init . -theme basic-reason

### Webpack - Creating `webpack.config.js`

After getting a taste of ReasonML, we next create a Webpack configuration to
load the compiled output JavaScript into an HTML page.

Note: Being a newbie, I had considered using [this starter
app](https://github.com/yawaramin/fullstack-reason) but things worked out fine
using `bsb` and Webpack and hence didn't need the starter kit.

We follow the [Webpack 5 guide - Getting
Started](https://webpack.js.org/guides/getting-started/) to use the following
webpack features:

    + html-webpack-plugin
    + clean dist dir
    + css and style loaders
    + scss
    + inline-source-map
    + enviromnents (env.development / env.production)

npm stuff for webpack

    npm install --save-dev webpack webpack-cli
    npm install --save-dev style-loader css-loader
    npm install --save-dev sass-loader sass
    npm install --save-dev webpack-dev-server
    npm install --save-dev html-webpack-plugin

Note: We start out without **bs-css** which we don't know much about yet and try
to use just scss. Lets see how this works out.

This is a [useful
article](https://medium.com/@arecvlohe/getting-started-with-reasonreact-f47c9fc3d60a)
to integrate code compiled by `bsb` with Webpack.

In bsconfig.js we changed package-specs `module` to `es6-global` and set
`in-source` to `false`.

During dev, bsb and webpack will both be watching for changes and we need two
concurrent commands for which npm package `concurrently` is used.

    npm install --save-dev concurrently

Note: There seems to be a [Webpack
bs-loader](https://www.npmjs.com/package/bs-loader) but its in maintenance mode
and the documentation recommends using `bsb` with its `.bs.js` extension which
is what we are doing.

To avoid the browser console from constantly showing a `404` due to a missing
favicon, lets grab one from [favicon.io](https://favicon.io/) licensed under
[CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/), update webpack config
`HtmlWebpackPlugin` with its path.

## Webpack

With [webpack.config.js](./webpack.config.js) and `scripts` defined in
[package.json](./package.json) we now have the necessary scaffolding to start
building frontend web apps in ReasonML!

To run the dev server:

    npm start

To make a production build:

    npm run build

# Learning ReasonML

There seem to be good quality learning resources for ReasonML which are a year
or two old. Since everything is new to us, we also use an older BuckleScript
version referred to in these documents. This is why `bs-platform` in the
[package.json](./package.json) is an older version while the current version is
*9.0.2* (28th June 2022)

This way we focus purely on learning and avoid distractions due to changes in
versions. Once we learn the basics, we can easily ramp up to the latest.

## Revision - ReasonML language 

+ if/else is an expr (returns something) Hence it always needs an else.
+ the terenary operator also works.
+ `+` `+.` `++`
+ "ascii str", 'char', {js|unicode multi-line string|js}, {j|total $total|j}
+ [%%raw {||}]  [%raw {||}]
+ -> (pipe-first for data-first) (data-first: good for type inferencing langs)
+ |> (reverse pipe)
+ _ pipe placeholder (data-first is inconvenient for partial application)
+ Punning (dont repeat the value if a var with same name is in scope)
+ list [1,2,3]  array [|1,2,3|]
+ labeled args (~arg1, ~arg2) (~arg1 as a1, ~arg2) (~arg1, ~arg2=?, ())
+ destructuring tuples, records
+ Instead of default values for fn params, use currying with labeled params.
+ Invariants, option, Some, None

## Revision - ReasonML bindings

For ReasonML to interact with existing JavaScript libraries we need to write
bindings in ReasonML for that library.

Hence, writing bindings turns out to be an important skill to master in order to
use existing JavaScript libraries. Bindings should be written such that they
take advantage of the type safety which ReasonML provides.

For instance, lets say a function of some JavaScript library expects an
`encoding` argument which can either be `ascii` or `utf8`. Any other string will
cause the JavaScript function to throw an exception. To correctly write a
binding for such a function, we need to write a binding such that the Reason
compiler itself permits only the above two strings. If we allow ReasonML code to
accept any value, our ReasonML code will still work but then we need to write
code to check for valid values which results in writing more code and our
missing out on the feature provided by ReasonML. Writing un-necessary lines of
code results needs a greater maintenance effort.  Of course if there's user
input, we will need extra code to give user feedback.

+ [@bs.scope]
+ [@bs.val]
+ [@bs.new]
+ [@bs.send]
+ [@bs.module]

## Revision - modules/libraries

+ Belt is the BuckleScript standard library
+ (Belt.Option.flatMap()) and Belt.Option.map()
+ Pervasives (sqrt, sin, cost) (In the browser we also have Js.Math)
+ Js.log, Js.Math.,Js.String

## Revision - commands

+ bsb -init prj -theme basic-reason
+ bsb -themes
+ bsb -make-world -w
+ bsb -clean-world

# Random notes

+ js_of_ocaml (existing before BuckleScript) does OCaml bytecode to JavaScript,
  facilitating use of OCaml libraries.
+ ReScript does rawlambda to JavaScript generating readable JavaScript.
+ BuckleScript was initially used to compile either vanilla OCaml or
  ReasonML to JavaScript. At some point, BuckleScript which was rebranded as
  ReScript developed its own syntax.

# Editor - VS Code

The ReasonML site suggests the
[vscode-ocaml-platform](https://github.com/ocamllabs/vscode-ocaml-platform)
(**VSCode OCaml Platform**) extension for Visual Studio Code.

Prerequisites

Before installing the extension, install:

    opam install ocaml-lsp-server
    opam install ocamlformat # May not need this, but who knows.
    
Next, install the extension.


# Links

## Links - language

+ [data-first-and-data-last-a-comparison/](https://www.javierchavarri.com/data-first-and-data-last-a-comparison/)
+ [ReasonML bindings](https://itnext.io/reasonml-create-bindings-for-npm-package-b8a3c6d0703e)
+ [A first ReasonReact app](https://jamesfriend.com.au/a-first-reason-react-app-for-js-developers)

## Links - ecosystem

+ [Awesome ReasonML](https://github.com/vramana/awesome-reasonml)
+ [An Invitation to
  ReasonML](https://protoship.io/blog/an-invitation-to-reasonml/)
+ [Writing JS using
  OCaml](https://www.kuniga.me/blog/2018/06/24/writing-javascript-using-ocaml.html) 
+ [Rationale to create
  ReScript](https://github.com/ocsigen/js_of_ocaml/issues/338) (ReasonML author)
+ [A short history of rescript
  bucklescript](https://discuss.ocaml.org/t/a-short-history-of-rescript-bucklescript/7222)
  (ReasonML author) 
+ [About bucklescript](https://discuss.ocaml.org/t/about-bucklescript/178)
  (ReasonML author) 
