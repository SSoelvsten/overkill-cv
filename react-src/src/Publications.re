open Contact;

type publication = {
    title: string,
    year: int,
    url: option((string, string)),
    authors: list(contact),
    note: option(React.element),
    note_urls: list((string, string))
};

let publications : list(publication) = [
    {
        title: {j|∃R-Completeness of Stationary Nash Equilibria in Perfect Information Stochastic Games|j},
        year: 2020,
        url: Some(("MFCS 2020", "https://doi.org/10.4230/LIPIcs.MFCS.2020.45")),
        authors: [Contacts.kristoffer_arnsfelt_hansen, Contacts.steffan_soelvsten],
        note: None,
        note_urls: [("arXiv", "https://arxiv.org/abs/2006.08314"),
                    ("Pre-recorded presentation", "https://www.youtube.com/watch?v=QoQaaPSoQdQ")],
    }
];

[@react.component]
let make = () => {
    <>
        <h2>{React.string("Publications")}</h2>
        <ul>
            {publications |> List.map(({title, year, url, authors, note, note_urls}) => {
                <li className="publication" key={title}>
                    {authors |> List.map(({name}) => name )
                             |> Array.of_list
                             |> Js.Array.joinWith(", ")
                             |> React.string}
                    <br />

                    <emph> {React.string(title)} </emph>
                    { switch (url) {
                        | None => <> </>
                        | Some((publication, href)) => <>
                            {React.string(", ")}
                            <Link text={publication} href={href} />
                        </>
                    }}
                    {(" (" ++ string_of_int(year) ++ ")") |> React.string}

                    { switch (note, note_urls) {
                    | (None, []) => <> </>
                    | (Some(note), _) => <> <br /> note </>
                    | _ => <br />
                    }}
                    { note_urls |> List.mapi((idx, (name,url)) => <>
                            <Link text={name} href={url} />
                            {if (idx < List.length(note_urls) - 1) {React.string(", ")} else {<> </>}}
                        </>) |> Array.of_list |> React.array}
                </li>
            }) |> Array.of_list
               |> React.array}
        </ul>
    </>
}
