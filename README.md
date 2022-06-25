# ML-Select

This is a HTML widget like...

HTML `<select>` *+* auto complete

Not meant to be a libary, this is an exercise in exploring the *OCaml* based
*ReasonML* and *ReScript* for frontend web development.

We won't discuss OCaml and its advantages but focus on exploring the ecosystem
and building the widget.

## ReasonML and ReScript

We start out knowing nothing about ReasonML or ReScript.

### Choosing between ReScript & ReasonML

ReScript promotes its own Syntax, veering towards JavaScript. I would prefer to
stay closer to OCaml but ReScript has gained a lot of traction. Because of
tooling support it might be easier for a newbie to start with ReScript and later
try ReasonML to remain closer to OCaml.

ResonML seems to be loosing traction for frontend web development. I got this
impression after spending a while surveying the ecosystem and maybe its not
completely true.

ReScript seems to be the way forward.

### Further exploration

After a lot more exploring, I finally chosen ReasonML. The aim of this project
is not only to build the widget but also to get a taste of using OCaml for
frontend development.

It took quite a while to figure out the ecosystem and understand the communities
behind OCaml, ReScript and ReasonML communities.

It is important to understanding this ecosystem to choose between ReasonML and
ReScript.

### Why ReasonML?

ReScript being young, might continue to veer further towards JavaScript as it
has already sought out to do and spin off into something very different from
ReasonML or OCaml. No doubt, ReScript might become a useful and popular language
but the JavaScript ecosystem is enormous with many languages compiling to
JavaScript such as *ClojureScript*, *Elm*, *PureScript*, *Dart* and
*TypeScript*.

Our aim is to use OCaml or a dialect for frontend development.

ReasonML seems to remain closer OCaml. It has the necessary JavaScript
interoperability and also has *Reason React*. It has been adopted by companies
for frontend development where ReasonML developers have reaped its benefits but
due to the changing ecosystem some ReasonML teams have had to migrate to
ReScript.

Owing to the **seemingly** fading away of ReasonML, maybe its not the best
choice to start a big production level app but I don't know the ecosystem well
enough to make such a decision yet.

At the end of the day we want to write correct and readable code in an
expressive language. We also need to churn out top-notch apps despite their
changing requirements.

To each their own.

For now, lets dive into ReasonML to get a feel of the OCaml dialect for frontend
web dev.

# Getting started

Choosing ReasonML over ReScript itself took quite a while.

Lets get started! ([Awesome
ReasonML](https://github.com/vramana/awesome-reasonml) may be a good place to
start.)

## Starter kit

Being newbies, lets use a starter kit.

### Notable links

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

### Notes

Some random notes for my reference.

+ js_of_ocaml (existing before BuckleScript) does OCaml bytecode to JavaScript,
  facilitating use of OCaml libraries.
+ ReScript does rawlambda to JavaScript generating readable JavaScript.
+ BuckleScript was initially used to compile either vanilla OCaml or
  ReasonML to JavaScript. At some point, BuckleScript which was rebranded as
  ReScript developed its own syntax.
