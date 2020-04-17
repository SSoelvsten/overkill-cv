type status = PhDStudent | PostDoc | AssocProf | Prof;

type contact = {
    name: string,
    status: status,
    url: string,
    contact: string,
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
    <Link text={name_of_contact(contact)} href={contact.url} />
}

module Contacts = {
    let steffan_soelvsten : contact = {
        name: {j|Steffan Sølvsten|j},
        status: PhDStudent,
        url: "https://ssoelvsten.github.io/",
        contact: "soelvsten@cs.au.dk",
        association: None,
    }

    let jaco_van_de_pol : contact = {
        name: "Jaco van de Pol",
        status: Prof,
        url: "https://www.cs.au.dk/~jaco/",
        contact: "jaco@cs.au.dk",
        association: Some("PhD. supervisor"),
    };

    let anders_moller : contact = {
        name: {j|Anders Møller|j},
        status: Prof,
        url: "https://cs.au.dk/~amoeller/",
        contact: "amoeller@cs.au.dk",
        association: None,
    }

    let kasper_green : contact = {
        name: "Kasper Green Larsen",
        status: AssocProf,
        url: "https://cs.au.dk/~larsen/",
        contact: "larsen@cs.au.dk",
        association: None,
    };

    let kristoffer_arnsfelt_hansen : contact = {
        name: "Kristoffer Arnsfelt Hansen",
        status: AssocProf,
        url: "https://www.cs.au.dk/~arnsfelt/",
        contact: "arnsfelt@cs.au.dk",
        association: Some("Advisor for research project in Algorithmic Game Theory")
    };
};