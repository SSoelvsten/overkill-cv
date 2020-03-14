open Contact;

type publication_status = InReview | Accepted(string) | Published(string)

type publication = {
    title: string,
    status: publication_status,
    year: int,
    url: option(string),
    authors: list(contact),
    notes: option(React.element),
};

let publications : list(publication) = [
    {
        title: {j|∃R-Completeness of Stationary Nash Equilibria in Perfect Information Stochastic Games|j},
        status: InReview,
        year: 2020,
        url: None,
        authors: [Contacts.kristoffer_arnsfelt_hansen, Contacts.steffan_soelvsten],
        notes: None,
    }
];

[@react.component]
let make = () => {
    <>
        <h2>{React.string("Publications")}</h2>
        <ul>
            {publications |> List.map(({title, status, year, url, authors, notes}) => {
                <li className="publication" key={title}>
                    <emph>
                        {switch url {
                        | None => React.string(title)
                        | Some(url) => <Link text={title} href={url} />
                        }}
                    </emph> <br />
                    {authors |> List.map(({name}) => name )
                             |> Array.of_list
                             |> Js.Array.joinWith(", ")
                             |> React.string}
                    <br />
                    {switch status {
                    | InReview => "In Review"
                    | Accepted(publication) => "To be published in " ++ publication
                    | Published(publication) => publication
                    } |> React.string}
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
