[@react.component]
let make = (~text, ~href) => {
    <a className="link" href={href} target="_blank">{React.string(text)}</a>
}