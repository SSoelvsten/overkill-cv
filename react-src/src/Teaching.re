open Contact;

type time_of_course = Spring(int) | Fall(int)

type course = {
    name: string,
    time: list(time_of_course),
    ects: int,
    url: option(string),
    teacher: contact,
};

let courses : list(course) = [
    {
        name: "Computability and Logic",
        time: [Spring(2020), Spring(2021)],
        ects: 10,
        url: Some("https://kursuskatalog.au.dk/en/course/97743/Computability-and-Logic"),
        teacher: Contacts.jaco_van_de_pol,
    },
    {
        name: "Foundations of Algorithms and Datastructures",
        time: [Fall(2017)],
        ects: 10,
        url: Some("https://kursuskatalog.au.dk/en/course/82730/Foundations-of-Algorithms-and-Data-Structures"),
        teacher: Contacts.kasper_green,
    },
    {
        name: "Regularity and Automata",
        time: [Spring(2017)],
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
                {" (" |> React.string}
                {(time |> List.mapi((tidx, t) => {
                    (switch t {
                    | Spring(year) => "spring " ++ string_of_int(year)
                    | Fall(year) => "fall " ++ string_of_int(year)})
                    ++
                    (if (tidx === List.length(time) - 2 && List.length(time) == 2) {" and "}
                      else if (tidx < List.length(time) - 2) {", "}
                      else if (tidx === List.length(time) - 2) {", and "}
                      else {""})
                })) |> List.map(React.string) |> Array.of_list |> React.array}
                {") under " |> React.string}
                {link_of_contact(teacher)}
                {(if (idx < List.length(courses) - 2) {", "}
                  else if (idx === List.length(courses) - 2) {", and "}
                  else {". "}) |> React.string}
            </span>
        }) |> Array.of_list
           |> React.array}

        <br /> <br />

        {"I have supervised 2 bachelor students in implementing a " |> React.string}
        <Link text={"Cache-oblivious Ordered Boolean Decision Diagram"} href={"https://github.com/SSoelvsten/cache-oblivious-obdd"} />
        {" for a summer project based on a paper by Lars Arge in 1996 and my heavy optimisations and extensions thereof." |> React.string}
    </>
}
