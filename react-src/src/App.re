[@react.component]
let make = () => {
  <>
    <div className="header">
      <Banner />
      <hr/>

      <Info />
      <hr/>
    </div>

    <Teaching />
    <hr />

    <Publications />


    // Footer with OCaml Disclaimer
    <hr />
    <div className="footer">
      {React.string("Page written in ReasonML (i.e. OCaml) React and precompiled into a static website by server side rendering. Latest render: ")}{React.string(Js.Date.make() |> Js.Date.toUTCString)}
    </div>
  </>
};
