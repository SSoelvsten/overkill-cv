open Contact;

type project = {
    name: string,
    url: string,
    description: string
};

let projects : list(project) = [
    {
        name: "Adiar",
        url: "https://www.github.com/ssoelvsten/adiar",
        description: "An I/O efficient implementation of Binary Decision Diagrams (BDDs)"
    }
];

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
            <Link text="Turing 218" href="https://international.au.dk/about/contact/?b=5341" />
            <br />

            <br />

            <Link text="Curriculum Vitae"
                    href="https://github.com/SSoelvsten/Curriculum_Vitae/raw/master/cv.pdf"
                />

        </div>
        <div className="text">
            {"PhD student advised by " |> React.string}
            {link_of_contact(Contacts.jaco_van_de_pol)}
            {" researching the theoretical and practical design of logics, algorithms, and data structures for model checking and synthesis of Multi-Agent Systems (MAS)." |> React.string}

            <br /> <br />

            {"Tools I have developed as part of my research:" |> React.string}
            <ul>
                {projects |> List.map(({name,url,description}) => {
                    <li>
                        <Link text={name} href={url} />
                        {": " ++ description ++ "." |> React.string}
                    </li>
                }) |> Array.of_list |> React.array}
            </ul>
        </div>
    </div>
}