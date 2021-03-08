type status = PhDStudent | PostDoc | AssocProf | Prof | None;

type contact = {
    name: string,
    status: status,
    url: option(string),
    contact: option(string),
    association: option(string),
};

let name_of_contact = (contact : contact) => {
    let status_string = switch contact.status {
        | AssocProf => "Assoc. Prof."
        | Prof => "Prof."
        | _ => ""
    }

    status_string ++ " " ++ contact.name
}

let link_of_contact = (contact : contact) => {
    let name = name_of_contact(contact)

    switch contact.url {
        | Some(u) => <Link text={name} href={u} />
        | None => name |> React.string
    }
}

module Contacts = {
    let steffan_soelvsten : contact = {
        name: {j|Steffan Sølvsten|j},
        status: PhDStudent,
        url: Some("https://ssoelvsten.github.io/"),
        contact: Some("soelvsten@cs.au.dk"),
        association: None,
    }

    let jaco_van_de_pol : contact = {
        name: "Jaco van de Pol",
        status: Prof,
        url: Some("https://www.cs.au.dk/~jaco/"),
        contact: Some("jaco@cs.au.dk"),
        association: Some("PhD. supervisor"),
    };

    let anders_moller : contact = {
        name: {j|Anders Møller|j},
        status: Prof,
        url: Some("https://cs.au.dk/~amoeller/"),
        contact: Some("amoeller@cs.au.dk"),
        association: None,
    }

    let kasper_green : contact = {
        name: "Kasper Green Larsen",
        status: AssocProf,
        url: Some("https://cs.au.dk/~larsen/"),
        contact: Some("larsen@cs.au.dk"),
        association: None,
    };

    let kristoffer_arnsfelt_hansen : contact = {
        name: "Kristoffer Arnsfelt Hansen",
        status: AssocProf,
        url: Some("https://www.cs.au.dk/~arnsfelt/"),
        contact: Some("arnsfelt@cs.au.dk"),
        association: Some("Advisor for research project in Algorithmic Game Theory")
    };

    let anna_blume_jakobsen : contact = {
        name: "Anna Blume Jakobsen",
        status: None,
        url: None,
        contact: None,
        association: Some("Bachelor student, who initially implemented my algorithms for Adiar")
    }

    let mathias_weller_berg_thomasen : contact = {
        name: "Mathias Weller Berg Thomasen",
        status: None,
        url: None,
        contact: None,
        association: Some("Bachelor student, who initially implemented my algorithms for Adiar")
    }
};