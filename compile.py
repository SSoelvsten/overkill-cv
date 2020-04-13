import subprocess
import os


def compile_static_html():
    # Compile ReasonML Source
    os.system("cd react-src/ && npm run build")

    # Extract Static HTML from React app
    cmd = ["node react-src/src/Compile.bs.js"]
    process = subprocess.run(cmd,
                             stdin=subprocess.PIPE,
                             stdout=subprocess.PIPE,
                             universal_newlines=True,
                             shell=True)

    static_html = process.stdout

    with open("react-src/src/index.html") as file:
        index_html = file.read()

        # Replace root node in index.html with static HTML
        index_html = index_html.replace("<div id=\"root\"></div>\n", static_html)
        index_html = index_html.replace("    <script src=\"/Index.js\"></script>\n", "")

        # Add style sheet
        style = "    <link rel=\"stylesheet\" href=\"styles.css\">"
        index_html = index_html.replace("  </head>\n", style + "\n  </head>\n")

        return index_html

if __name__ == "__main__":
    # Copy over style sheet
    os.system("cp react-src/src/styles.css build/styles.css")
    os.system("cp -R img build/img")

    # Combine into static website
    static_html = compile_static_html()

    with open("build/index.html", 'w') as index_file:
        index_file.write(static_html)

