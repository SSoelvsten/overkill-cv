# SSoelvsten.github.io
As a researcher you will inevitably have to create a CV website. It seems like a
universal law for all these websites, that they also have to be completely
static and have no styling to speak off. Following up on this tradition, this
website will be no different.

On the other hand, I definitely do not want to get close to the sheer horror of
having to write _HTML_ by hand. Being a former full-stack developer and a PhD
student in the Logic and Semantics and Programming Languages group, the only
honorable paths are even fewer. Hence this website is made the following way

- The website is a React application purely written in the OCaml variant
  [ReasonML](https://reasonml.github.io/).
  - Yes, the source code has pattern-matching, algebraic types, structs and
    absolutely no bugs in it anywhere!
- A server-side rendering of the application is then replacing the `root` node
  for React in the HTML template.
  
## Dependencies
To install all dependencies do the following
```bash
cd react-src/
npm install
```

## Compile
To compile a new static version of the website just run `make`.

