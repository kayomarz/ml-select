# ML-Select

This is a *React.js* component which functions like an HTML `<select>` *+* auto
complete.

Rather than just presenting the code, the steps taken to develop this component,
and learn the language are described below .

# ReasonML and ReScript

The purpose of making this component is to explore the **OCaml** based
**ReasonML** and **ReScript** for frontend web development.

Hence this is not a production ready library.

## Choosing between ReScript & ReasonML

As **ReScript** seems to have its own syntax deviating from OCaml, it might be
better to use ReasonML which stays closer to OCaml. However ReScript has gained
a lot of traction and seems to have great tooling support.

Being new to the ecosystem, ReScript seems to be the way forward.

**ReasonML** seems to be loosing traction for frontend web development. I got
this impression after spending a while surveying the ecosystem and maybe thats
not completely true.

ReScript seems like the apparent choice forward.

### Further exploration

After a lot more exploring, I realized that **ReasonML** might be a better
choice at-least for this task.

The aim of this project is not only to build the component but also to get a
taste of using OCaml for frontend development.

It took quite a while to figure out the ecosystem and understand the communities
behind OCaml, ReScript and ReasonML but understanding this ecosystem is an
important step to choose between ReasonML and ReScript.

### Why ReasonML?

**ReScript** being young, might continue to veer further towards JavaScript and
spin off into something different from ReasonML or OCaml. No doubt, ReScript
might become a great language but the JavaScript ecosystem is enormous with
popular languages compiling to JavaScript such as *ClojureScript*, *Elm*,
*PureScript*, *Dart* and *TypeScript*.

One of our aim is to use **OCaml** or a dialect for frontend development.

Although the above is just speculation but we also have **ReasonML** which seems to
remain close to OCaml, has the necessary JavaScript interoperability and has
*Reason React*. Being adopted by companies for frontend development, ReasonML
developers seem have reaped its benefits and had a pleasant development
experience. Maybe due to the changing ecosystem ReasonML teams might have to
migrate to ReScript.

Owing to the **seemingly** fading away of ReasonML, maybe its not the best
choice to start a big production level app using ReasonML but I don't yet know
the ecosystem well enough to make this decision.

Eventually we want to write correct and readable code in an expressive
language. We also need to churn out top-notch apps despite their changing
requirements.

To each their own.

For this task, lets use **ReasonML** and get a feel of OCaml for frontend dev.

# Getting started

Choosing ReasonML over ReScript itself took quite a while.

Lets get started! ([Awesome
ReasonML](https://github.com/vramana/awesome-reasonml) maybe a good place to
start.)

## Learning ReasonML

The first step is to learn ReasonML.

### BuckleScript compiler

To experiment we used the BuckleScript
command `bsb -make-world -w` to compile ReasonML, ran the code using node and
observed the compiled JavaScript which is indeed readable, being also one of the
goals of the BuckleScript author.

`bsb` helps with creating a sample project.

    bsb -init CountrySelect -theme basic-reason


### Webpack - Creating `webpack.config.js`

After getting a taste of ReasonML, we create a Webpack configuration to load the
compiled JavaScript it an HTML page.

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

To avoid the browser console from constantly showing a `404` error due to a
missing favicon, lets grab one from [favicon.io](https://favicon.io/) licensed
under [CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/), update webpack
config `HtmlWebpackPlugin` with its path.

## Webpack

With [webpack.config.js](./webpack.config.js) and `scripts` defined in
[package.json](./package.json) we now have the necessary scaffolding to start
building frontend web apps in ReasonML!

To run the dev server:

    npm start

To make a production build:

    npm run build

# Learning ReasonML

There seem to be very good quality learning resources for ReasonML which are a
couple of years old. Since everything is new to us, we will these older learning
materials along with the older BuckleScript versions which they refer to. This
is why `bs-platform` in the [package.json](./package.json) is an older version
while the current version is *9.0.2* (28th June 2022)

This way we focus purely on learning and avoid distractions due to changes in
versions. Besides, the ReasonML language wouldn't have changed much and once we
learn the basics, we can easily ramp up to the latest tools.

## Revision - ReasonML language 

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

## Revision - modules/libraries

+ Belt is the BuckleScript standard library
+ (Belt.Option.flatMap())  and Belt.Option.map()
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

