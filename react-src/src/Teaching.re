open Contact;

type time_of_course = Spring(int) | Fall(int)

type course = {
    name: string,
    time: time_of_course,
    ects: int,
    url: option(string),
    teacher: contact,
};

let courses : list(course) = [
    {
        name: "Computability and Logic",
        time: Spring(2020),
        ects: 10,
        url: Some("https://kursuskatalog.au.dk/en/course/97743/Computability-and-Logic"),
        teacher: Contacts.jaco_van_de_pol,
    },
    {
        name: "Foundations of Algorithms and Datastructures",
        time: Fall(2017),
        ects: 10,
        url: Some("https://kursuskatalog.au.dk/en/course/82730/Foundations-of-Algorithms-and-Data-Structures"),
        teacher: Contacts.kasper_green,
    },
    {
        name: "Regularity and Automata",
        time: Spring(2017),
        ects: 5,
        url: Some("https://kursuskatalog.au.dk/en/course/64231/Regularity-and-Automata"),
        teacher: Contacts.anders_moller,
    }
];

[@react.component]
let make = () => {
    <>
        <h2>{React.string("Teaching")}</h2>
        {React.string("I have been a Teaching Assistant ")}
        {courses |> List.mapi((idx, {name, time, url, teacher}) => {
            <span key={name}>
                {React.string("in ")}
                {switch url {
                    | None => React.string(name)
                    | Some(url) => <Link text={name} href={url} />
                }}
                {" " ++ (switch time {
                    | Spring(year) => "(Spring of " ++ string_of_int(year) ++ ")"
                    | Fall(year) => "(Fall of " ++ string_of_int(year) ++ ")"
                } ++ " under ") |> React.string}
                {link_of_contact(teacher)}
                {(if (idx !== List.length(courses) - 1) {", "} else {". "}) |> React.string}
            </span>
        }) |> Array.of_list
           |> React.array}
    </>
}
