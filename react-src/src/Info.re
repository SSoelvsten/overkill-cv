open Contact;

[@react.component]
let make = () => {
    <div className="info">
        <img className="portrait" src="img/portrait2_bw.jpg"/>
        <div className="contact">
            {React.string("Email: ")}
            <Link text="soelvsten@cs.au.dk" href="mailto:soelvsten@cs.au.dk" />  <br />

            <br />

            <Link text="Logic and Semantics Group"
                href="https://cs.au.dk/research/logic-and-semantics/" /> <br />
            <Link text="Department of Computer Science" href="https://cs.au.dk/en/"/> <br />
            <Link text="Aarhus University" href="https://au.dk/en/"/> <br />
            {"Office: " |> React.string}
            <Link text="Turing" href="https://international.au.dk/about/contact/?b=5341" />
            {" 218," |> React.string} <br />

            <br />

            <Link text="Curriculum Vitae"
                    href="https://github.com/SSoelvsten/Curriculum_Vitae/raw/master/cv.pdf"
                />

        </div>
        <div className="text">
            {"PhD student advised by " |> React.string}
            {link_of_contact(Contacts.jaco_van_de_pol)}
            {" researching optimisation of algorithms and datastructures for model verification and synthesis of Multi-agent Games." |> React.string}

            <br /> <br />

            {"My research focuses on both theoretical insights on the underlying theory of model verification and algorithmic game theory, but also the development of new techniques and optimisations for model checking and synthesis of Multi-agent systems." |> React.string}
        </div>
    </div>
}