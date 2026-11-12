# Learning Notes — Assignment 7: Doxygen

## Objective

The assignment focuses on documenting a small, multi-file C++ project with **Doxygen**. The goal is to add structured comments to the source code and generate HTML and PDF documentation from those comments.

> **File note:** The uploaded file is named `Assignment 7.pdf`, but its first page is titled **“Assignment 9 - Doxygen”**. These notes follow the instructions in the uploaded PDF.

## What I learned

### 1. Why code documentation matters

- Documentation explains the purpose and expected behavior of code.
- It makes a project easier to understand, maintain, and extend.
- Doxygen can turn documentation comments in source files into a reference manual.

### 2. Doxygen documentation comments

Doxygen recognizes specially formatted comments and commands. The assignment asks for commands using either `@` or `\\` prefixes.

| Command | Purpose |
|---|---|
| `\\mainpage` | Defines the project's main documentation page. |
| `@file` | Documents a source or header file. |
| `@class` | Identifies and documents a class. |
| `@brief` | Gives a short description. |
| `@detail` | Adds a more detailed explanation. |
| `@enum` | Documents an enumeration. |
| `@param` | Explains a function parameter. |
| `@return` | Explains the returned value. |
| `\\todo` | Marks work or documentation that remains to be done. |

### 3. Documenting the project elements

The assignment identifies these documentation tasks:

- **Main page:** Add a project overview using `\\mainpage` or `@file`.
- **Logger class:** Document the file and class with `@file`, `@class`, and `@brief`.
- **Log Level enum:** Use `@enum` and describe every enumerator value.
- **Logger constructor:** Document the constructor and its parameters.
- **CalculationEngine class:** Document the file and class using `@file`, `@class`, `@brief`, and `@detail`.
- **Power calculation:** Describe the `base` and `exponent` parameters with `@param`, document the result with `@return`, and review the existing `\\todo` tag.

### 4. The role of the Doxyfile

The `Doxyfile` is Doxygen's configuration file. It controls which source files are processed and which documentation formats are generated. For this assignment, it must be configured to generate:

- **HTML** documentation for browsing in a web browser.
- **LaTeX** output, which is used to build the PDF reference manual.

### 5. Generating the documentation

Generate the documentation with:

```bash
doxygen Doxyfile
```

Open the generated HTML documentation with:

```bash
xdg-open docs/html/index.html
```

The assignment asks us to enter the generated LaTeX directory and run `make` to build the PDF. The workflow supplied for this project is:

```bash
cd docs
cd latex
make pdf
```

Open the resulting reference manual with:

```bash
xdg-open refman.pdf
```

### 6. Understanding the generated formats

- **HTML:** Useful for navigating documentation, classes, functions, and cross-references.
- **LaTeX/PDF:** Useful as a printable, shareable reference manual.

## Key takeaways

- Doxygen generates documentation from specially formatted source-code comments.
- Good documentation describes the purpose and contract of classes and functions, not merely their names.
- Parameters, return values, enum values, and constructors should be documented clearly.
- The `Doxyfile` determines the generated output and formats.
- The same source documentation can be published as HTML and converted into a PDF manual.

## Assignment checklist

- [ ] Install Doxygen.
- [ ] Find TODO comments and undocumented elements in the supplied source files.
- [ ] Document the main page, `Logger`, log-level enum, constructor, and `CalculationEngine`.
- [ ] Document the power-calculation parameters and return value; review the existing TODO.
- [ ] Configure HTML and LaTeX output in `Doxyfile`.
- [ ] Run `doxygen Doxyfile`.
- [ ] Open and inspect the generated HTML documentation.
- [ ] Build and inspect the generated PDF reference manual.

## Reference

These notes are based on the uploaded assignment PDF (internally titled **“Assignment 9 - Doxygen”**) and the accompanying Doxygen lecture PDF.
