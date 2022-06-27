# ML-Select

This is an HTML widget like an HTML `<select>` *+* auto complete

The steps taken to develop this widget are below. This was done to try and
explain the thought process instead of just providing the code.

# ReasonML and ReScript

The purpose of making this widget is to explore the **OCaml** based **ReasonML**
and **ReScript** for frontend web development.

Hence this is not a production ready library.

We won't discuss OCaml and its advantages but focus on exploring the ecosystem
and building the widget.

We start out knowing nothing about ReasonML or ReScript.

## Choosing between ReScript & ReasonML

As ReScript seems to have its own syntax deviating from OCaml, it might be
better to use ReasonML which deviates less and stays closer to OCaml. However
ReScript has gained a lot of traction. Because of tooling support it might be
easier for a newbie to start with ReScript and later try ReasonML to remain
closer to OCaml.

ResonML seems to be loosing traction for frontend web development. I got this
impression after spending a while surveying the ecosystem and maybe its not
completely true.

ReScript seems to be the way forward.

### Further exploration

After a lot more exploring, I have choosen ReasonML. The aim of this project is
not only to build the widget but also to get a taste of using OCaml for frontend
development.

It took quite a while to figure out the ecosystem and understand the communities
behind OCaml, ReScript and ReasonML.

It is important to understanding this ecosystem to choose between ReasonML and
ReScript.

### Why ReasonML?

ReScript being young, might continue to veer further towards JavaScript and spin
off into something different from ReasonML or OCaml. No doubt, ReScript might
become a useful and popular language but the JavaScript ecosystem is enormous
with already many popular languages compiling to JavaScript such as
*ClojureScript*, *Elm*, *PureScript*, *Dart* and *TypeScript*.

ReasonML seems to remain close to OCaml. It has the necessary JavaScript
interoperability and has *Reason React*. Being adopted by companies for frontend
development, it appears that ReasonML developers have reaped its benefits. Maybe
due to the changing ecosystem ReasonML teams might have to migrate to ReScript.

Owing to the **seemingly** fading away of ReasonML, maybe its not the best
choice to start a big production level app but I don't know the ecosystem well
enough to make such a decision yet.

Our aim is to use OCaml or a dialect for frontend development.

At the end of the day we want to write correct and readable code in an
expressive language. We also need to churn out top-notch apps despite their
changing requirements.

To each their own.

For now, lets dive into ReasonML to get the feel of OCaml for frontend web dev
and build the widget.

# Getting started

Choosing ReasonML over ReScript itself took quite a while.

Lets get started! ([Awesome
ReasonML](https://github.com/vramana/awesome-reasonml) may be a good place to
start.)

## Learning ReasonML

The first step is to learn ReasonML which we do using `bsb -make-world -w`.

## BuckleScript compiler

After getting a taste of ReasonML using the bsb compiler, we use Webpack to
help integrate ReasonML with a HTML page and create a build.

Create a sample project to get started.

    bsb -init CountrySelect -theme basic-reason

## Webpack - Creating `webpack.config.js`

We use webpack to load the compiled ReasonML into HTML.

Note: Being a newbie, I had considered using [this starter
app](https://github.com/yawaramin/fullstack-reason) but things worked out fine
with `bsb -make-world -w` and Webpack and hence didn't need the starter kit.

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
bs-loader](https://www.npmjs.com/package/bs-loader) but its documentation
recommends using `bsb`.

## Webpack

Now that our webpack setup is complete (see
[webpack.config.js](./webpack.config.js)) we can run a development server or
create a build.

To run the dev server:

    npm start

To make a production build:

    npm run build

# Learning ReasonML

## bs-platform

For learning, we use an older BuckleScript version to match our learning material.

    npm i bs-platoform@7.3.2

## Revision - ReasonML language 

+ See Pervasives (sqrt, sin, cost) (In the browser we also have Js.Math)
+ Js.log, Js.Math.,Js.String
+ if/else is an expr (returns something) Hence it always needs an else.
+ the terenary operator also works.
+ `+` `+.` `++`
+ "ascii str", 'char', {js|unicode multi-line string|js}, {j|total $total|j}
+ [%%raw {||}]  [%raw {||}]
+ -> (pipe-first for data-first) (data-first: good for type inferencing langs)
+ |> (reverse pipe)
+ _ pipe placeholder (data-first is inconvenient for partial application)
+ Punning (for records, like in JS obj {a})
+ list [1,2,3]  array [|1,2,3|]
+ labeled args (~arg1, ~arg2) (~arg1 as a1, ~arg2) (~arg1, ~arg2=?, ())
+ destructuring tuples, records
+ Instead of default values for fn params, use currying with labeled params.
+ Invariants, option, Some, None
+ Belt is the BuckleScript standard library
+ (Belt.Option.flatMap())  and Belt.Option.map()

## Revision - commands

+ bsb -init prj -theme basic-reason
+ bsb -themes
+ npm run build
+ npm run start

# Random notes

+ js_of_ocaml (existing before BuckleScript) does OCaml bytecode to JavaScript,
  facilitating use of OCaml libraries.
+ ReScript does rawlambda to JavaScript generating readable JavaScript.
+ BuckleScript was initially used to compile either vanilla OCaml or
  ReasonML to JavaScript. At some point, BuckleScript which was rebranded as
  ReScript developed its own syntax.

# Links

## Links - language

+ [data-first-and-data-last-a-comparison/](https://www.javierchavarri.com/data-first-and-data-last-a-comparison/)

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

