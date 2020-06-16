open Contact;

type publication = {
    title: string,
    year: int,
    urls: list((string, string)),
    authors: list(contact),
    notes: option(React.element),
};

let publications : list(publication) = [
    {
        title: {j|∃R-Completeness of Stationary Nash Equilibria in Perfect Information Stochastic Games|j},
        year: 2020,
        urls: [("arXiv", "https://arxiv.org/abs/2006.08314")],
        authors: [Contacts.kristoffer_arnsfelt_hansen, Contacts.steffan_soelvsten],
        notes: Some(React.string({j|Submitted to MFCS 2020|j})),
    }
];

[@react.component]
let make = () => {
    <>
        <h2>{React.string("Publications")}</h2>
        <ul>
            {publications |> List.map(({title, year, urls, authors, notes}) => {
                <li className="publication" key={title}>
                    <emph> {React.string(title)} </emph>
                    { if (List.length(urls) > 0) {
                        <>
                            {React.string(" (")}
                            { urls |> List.mapi((idx, (name,url)) =>
                                <>
                                    <Link text={name} href={url} />
                                    {if (idx < List.length(urls) - 1) {React.string(", ")} else {<> </>}}
                                </>)
                                   |> Array.of_list
                                   |> React.array}
                            {React.string(")")}
                        </>
                    } else { <> </> }}
                    <br />
                    {authors |> List.map(({name}) => name )
                             |> Array.of_list
                             |> Js.Array.joinWith(", ")
                             |> React.string}
                    {(", " ++ string_of_int(year)) |> React.string}
                    {switch notes {
                    | None => <> </>
                    | Some(n) => <> <br /> n </>
                    }}
                </li>
            }) |> Array.of_list
               |> React.array}
        </ul>
    </>
}
