# LaTeX Documentation

LaTeX is a document preparation system based on the TeX typesetting system. It is used to create structured documents, technical reports, presentations, mathematical expressions, tables, and figures. This README summarizes the concepts and commands covered in the provided classroom lectures.

## What is LaTeX?

LaTeX is a markup-based document preparation system. Instead of manually formatting every part of a page, the writer describes the structure of the document using commands and environments, and LaTeX handles typesetting and layout.

### Why use LaTeX?

- It is portable and free.
- It provides professionally designed document layouts.
- It is convenient for mathematical formulae.
- It supports multiple output formats.
- It makes it easier to organize large documents.
- It can generate complex structures such as footnotes, references, tables of contents, and bibliographies.

## Tools and Compilation

### Common LaTeX tools

**Offline tools:**
- Windows: MiKTeX, TeXnicCenter, TeXstudio
- Linux: TeX Live, Kile, TeXstudio

**Online tools:**
- Overleaf
- Papeeria
- CoCalc

### Input and output files

- A LaTeX source file is a plain-text file with the `.tex` extension.
- It contains the document text and LaTeX commands.
- Compilation can produce PDF (`.pdf`), DVI (`.dvi`), PostScript (`.ps`), and Rich Text Format (`.rtf`) output.

### Compiling a document

```bash
pdflatex filename.tex
```

A traditional LaTeX workflow can also produce a DVI file:

```bash
latex filename.tex
```

For documents that use BibTeX, the bibliography is processed separately and the document may need multiple compilation passes so that references and citations are resolved:

```bash
latex filename
bibtex filename
pdflatex filename
pdflatex filename
```

Editors such as Overleaf and TeXstudio can compile documents automatically.

## Basic Document Structure

Every LaTeX document has three main parts:

1. **Document class** – declares the type and general layout of the document.
2. **Preamble** – contains package imports and configuration commands.
3. **Document body** – contains the content between `\begin{document}` and `\end{document}`.

### Basic template

```latex
\documentclass[11pt,a4paper]{article}

% Packages and configuration go here

\begin{document}

Hello, LaTeX!

\end{document}
```

The first line specifies the document class and its options. The document body starts with `\begin{document}` and ends with `\end{document}`.

### Document classes

The document class determines the overall structure and behaviour of a document.

| Class | Typical use | Main features covered in the lectures |
|---|---|---|
| `article` | Papers and short documents | Sections and subsections; no chapters |
| `report` | Longer reports | Chapters and sections |
| `book` | Books and theses | Chapters, front matter, main matter, and back matter |
| `beamer` | Presentations | Frames, overlays, and slide layouts |
| `letter` | Formal correspondence | Addresses, opening, closing, and signature |
| `exam` | Tests and quizzes | Questions, choices, and solutions |

Examples:

```latex
\documentclass[12pt,a4paper]{article}
\documentclass[11pt,letterpaper]{report}
\documentclass{book}
\documentclass{beamer}
\documentclass{letter}
\documentclass{exam}
```

### Book class example

```latex
\documentclass{book}

\begin{document}
\frontmatter
\chapter{Preface}
\mainmatter
\chapter{Introduction}
\section{Background}
\backmatter
\chapter{References}
\end{document}
```

### Beamer class example

```latex
\documentclass{beamer}

\begin{document}
\begin{frame}{Title Slide}
Welcome to my presentation!
\end{frame}

\begin{frame}{Main Points}
\begin{itemize}
    \item First item
    \item Second item
\end{itemize}
\end{frame}
\end{document}
```

### Letter class example

```latex
\documentclass{letter}

\signature{Jane Doe}
\address{123 Main St.\\City, Country}

\begin{document}
\begin{letter}{Recipient Name \\ Company \\ Address}
\opening{Dear Recipient,}
This is an example of a letter created in LaTeX.
\closing{Sincerely,}
\end{letter}
\end{document}
```

## Title, Abstract, and Sections

### Title and author information

```latex
\title{Document Title}
\author{Author Name}
\date{\today}

\begin{document}
\maketitle
\end{document}
```

A title page can also be customized using the title-page facilities shown in the lecture material.

### Abstract

The abstract environment places a short summary near the beginning of a document.

```latex
\begin{abstract}
This document introduces the fundamentals of LaTeX.
\end{abstract}
```

The abstract is generally not numbered and is formatted differently from the main text. Its appearance can vary with the document class.

### Section commands

LaTeX provides commands to organize content hierarchically:

```latex
\section{Main Section}
\subsection{Subsection}
\subsubsection{Sub-subsection}
```

Section numbering can be controlled, and an unnumbered heading can be created with the starred form:

```latex
\section*{Acknowledgements}
```

The lecture also covers controlling section and subsection numbering.

## Text Formatting and Page Layout

### Font sizes

Font-size commands change the size of the text within their scope. The lecture demonstrates the standard size commands, including:

```latex
{\small Small text}
{\large Large text}
{\Large Larger text}
{\huge Huge text}
```

### Text alignment

```latex
\begin{flushleft}
Left-aligned text
\end{flushleft}

\begin{center}
Centered text
\end{center}

\begin{flushright}
Right-aligned text
\end{flushright}
```

### Spaces and paragraphs

- Entering several spaces has the same effect as entering one space in normal text.
- Multiple blank lines do not create multiple extra spaces; a blank line starts a new paragraph.
- Extra spaces and blank lines do not directly control the final page layout.
- Use `\\` for a manual line break where appropriate.
- Use vertical-space commands when a deliberate amount of space is required.

### Line and page breaks

The lectures cover manual line breaks, paragraph spacing, page breaks, preventing page breaks between lines, and line-breaking controls.

```latex
First line\\
Second line

\newpage
```

LaTeX also provides hyphenation controls. It automatically hyphenates words when needed, and permissible break points can be specified within a word.

### Comments

A percent sign starts a comment. Text after `%` on that line is ignored by LaTeX.

```latex
% This is a comment
Some document text.
```

### Special characters

The following characters have special meanings in LaTeX:

```text
$ & % # _ { } ~ ^ \
```

Commonly escaped forms include:

```latex
\$ \& \% \# \_ \{ \}
```

Some characters, such as `~`, `^`, and the backslash, require special commands when they must be printed as ordinary text.

## Page Styles and Document Appearance

### Page styles

The `\pagestyle` command controls headers and footers.

```latex
\pagestyle{plain}
\pagestyle{headings}
\pagestyle{empty}
```

- `plain` – prints the page number at the bottom; this is the default style in the lecture example.
- `headings` – displays the current chapter or section heading and page number in the header.
- `empty` – suppresses both header and footer.

### Page size and margins

Paper size can be selected as a document-class option:

```latex
\documentclass[a4paper]{article}
% or
\documentclass[letterpaper]{article}
```

The `geometry` package customizes page margins:

```latex
\usepackage{geometry}
\geometry{
    left=2.5cm,
    right=2.5cm,
    top=2.5cm,
    bottom=2.5cm
}
```

### Custom headers and footers

The `fancyhdr` package provides control over header and footer content.

```latex
\usepackage{fancyhdr}
\pagestyle{fancy}
\fancyhf{}
\fancyhead[L]{Left Header}
\fancyhead[C]{Center Header}
\fancyhead[R]{Right Header}
\fancyfoot[C]{\thepage}
```

### Page background colour

The lecture demonstrates changing the page background colour using colour support from the relevant package.

## Mathematical Notations

Mathematical content can be written inline or as a separate displayed expression.

### Inline and display mathematics

Inline mathematics appears within a line of text:

```latex
The relation is \(x+y=10\).
```

Display mathematics is centred on a separate line:

```latex
\[
x+y=10
\]
```

The lecture material also demonstrates the `displaymath` environment for displayed equations.

### Superscripts and subscripts

- Superscript: `^`
- Subscript: `_`

```latex
$a_i^2 + b_j^3$
```

### Greek letters and special symbols

Greek letters are written using a backslash followed by the letter name.

```latex
$\alpha, \beta, \gamma, \delta, \lambda, \pi, \theta$
```

Examples of relation and logic symbols:

```latex
$a \leq b$    % less than or equal to
$x \neq y$    % not equal to
$A \cap B$    % intersection
$A \cup B$    % union
$A \subseteq B$
```

Other symbols shown in the lectures include `\times`, `\otimes`, `\oplus`, `\subset`, `\supset`, `\int`, `\oint`, `\sum`, and `\prod`.

### Fractions, roots, sums, products, and integrals

```latex
\[
\frac{a+b}{c}, \qquad \sqrt{x}, \qquad \sqrt[3]{y}
\]

\[
\sum_{i=1}^{n} i, \qquad
\prod_{k=1}^{m} k, \qquad
\int_{0}^{\infty} e^{-x}\,dx
\]
```

### Mathematical fonts

The slides demonstrate different mathematical typefaces, including calligraphic, fraktur, normal, roman, bold, and sans-serif forms.

```latex
\[
\mathcal{RQSZ} \qquad
\mathfrak{RQSZ} \qquad
\mathrm{RQSZ}
\]

\[
\mathnormal{3x^2} \qquad
\mathbf{3x^2} \qquad
\mathsf{3x^2}
\]
```

### Overbrace and underbrace

These commands place annotations above or below an expression.

```latex
\[
\overbrace{a+b+c}^{d}
\qquad
\underbrace{a+b+c}_{d}
\]
```

### Binomial coefficients

```latex
\[
\binom{n}{k} = \frac{n!}{k!(n-k)!}
\]
```

## Equations and Alignment

### Numbered equations

The `equation` environment automatically numbers an equation.

```latex
\begin{equation}
\int_0^1 x^2\,dx = \frac{1}{3}
\end{equation}
```

### Long and split equations

The lecture material covers multiline equations and splitting long expressions across lines. The `amsmath` package provides environments such as `multline` and `split` for this purpose.

```latex
\usepackage{amsmath}

\begin{multline}
a+b+c+d+e+f \\
= g+h+i+j
\end{multline}
```

### Grouping equations

The `gather` environment groups and centres multiple equations.

```latex
\begin{gather}
a+b=c \\
x+y=z
\end{gather}
```

### Array environment

The `array` environment creates aligned columns inside mathematical mode. Column alignment can be specified with `l`, `c`, and `r`.

```latex
\[
\begin{array}{lcr}
\text{Left} & \text{Center} & \text{Right} \\
a & b & c \\
1 & 2 & 3
\end{array}
\]
```

Arrays can also represent piecewise functions:

```latex
\[
f(x)=\left\{
\begin{array}{ll}
-x, & x<0 \\
0,  & x=0 \\
x^2, & x>0
\end{array}
\right.
\]
```

### Matrices

The `amsmath` package provides matrix environments with different delimiters.

```latex
\usepackage{amsmath}

\[
\begin{matrix}
a & b \\
c & d
\end{matrix}
\]
```

Common matrix environments shown in the slides:

- `matrix` – no surrounding delimiters.
- `pmatrix` – parentheses.
- `bmatrix` – square brackets.
- `Bmatrix` – curly braces.
- `vmatrix` – single vertical bars.
- `Vmatrix` – double vertical bars.

The lectures also demonstrate larger matrices, extra vertical spacing between rows, and small matrices for inline use.

## Lists

LaTeX provides three commonly used list environments.

### Unordered list

```latex
\begin{itemize}
    \item Apples
    \item Oranges
    \item Bananas
\end{itemize}
```

### Ordered list

```latex
\begin{enumerate}
    \item First item
    \item Second item
\end{enumerate}
```

### Description list

```latex
\begin{description}
    \item[HTML] HyperText Markup Language
    \item[PDF] Portable Document Format
\end{description}
```

The lecture material also covers customizing lists with the `enumitem` package and creating custom list-like layouts with `trivlist`.

## Tables

Tables are created using the `tabular` environment. Column alignment is specified as:

- `l` – left aligned.
- `c` – centred.
- `r` – right aligned.

The `&` character separates columns, `\\` ends a row, and `\hline` draws a horizontal line.

### Simple table

```latex
\begin{center}
\begin{tabular}{|c|c|c|}
\hline
 a & b & c \\
 a & b & c \\
 a & b & c \\
\hline
\end{tabular}
\end{center}
```

### Combining columns

The `\multicolumn` command combines cells across columns.

```latex
\begin{tabular}{|p{1.5cm}|p{1.5cm}|p{1.5cm}|}
\hline
\multicolumn{3}{|c|}{Books} \\
\hline
Food name & Author & Publication \\
\hline
Book1 & Author1 & P1 \\
Book1 & Author2 & P2 \\
Book1 & Author3 & P3 \\
\hline
\end{tabular}
```

### Combining rows

The `\multirow` command can make a cell span multiple rows. The `multirow` package is required.

```latex
\usepackage{multirow}

\begin{tabular}{|c|c|c|}
\hline
col1 & col2 & col3 \\
\hline
\multirow{3}{4em}{Multiple row} & cell2 & cell3 \\
                               & cell5 & cell6 \\
                               & cell8 & cell9 \\
\hline
\end{tabular}
```

### Table positioning

The `table` environment allows LaTeX to position a table as a floating object.

```latex
\begin{table}[h!]
\centering
\begin{tabular}{|c|c|}
\hline
Name & Marks \\
\hline
Alice & 90 \\
Bob & 85 \\
\hline
\end{tabular}
\caption{Student marks}
\label{tab:marks}
\end{table}
```

Positioning options shown in the lecture include:

- `h` – here.
- `t` – top of the page.
- `b` – bottom of the page.
- `p` – a page reserved for floats.
- `!` – relaxes some internal placement restrictions.
- `H` – place at this exact location (provided by the relevant float package).

### Referencing tables

Use `\label{}` to assign a label and `\ref{}` to refer to the table number.

```latex
Table~\ref{tab:marks} shows the student marks.
```

### Table size, row/column spacing, and colour

The table lecture also demonstrates changing row and column sizing and applying colour to rows and columns. These techniques are part of the table-formatting material.

## Figures and Images

To include an image, load the `graphicx` package and use `\includegraphics`.

```latex
\usepackage{graphicx}

\includegraphics[scale=0.5]{example-image.jpg}
```

The image file should be available in the project. Its size can be adjusted with `width`, `height`, or `scale` options.

### Figure environment, captions, and labels

The `figure` environment supports centring, captions, and cross-referencing.

```latex
\begin{figure}
    \centering
    \includegraphics[width=0.5\textwidth]{example-image}
    \caption{A centered sample figure}
    \label{fig:sample}
\end{figure}
```

Reference the figure later with:

```latex
Figure~\ref{fig:sample} shows the sample image.
```

### Rotating and cropping images

The slides demonstrate the `angle`, `trim`, and `clip` options.

```latex
\includegraphics[angle=30]{example-image}
\includegraphics[trim=20 30 40 50,clip,width=3cm]{example-image}
```

### Multiple images side by side

The `minipage` environment can be used to arrange images next to one another.

```latex
\begin{minipage}{0.45\textwidth}
    \includegraphics[width=\linewidth]{exampleA}
    \captionof{figure}{Image A}
\end{minipage}
\quad
\begin{minipage}{0.45\textwidth}
    \includegraphics[width=\linewidth]{exampleB}
    \captionof{figure}{Image B}
\end{minipage}
```

## Colours in LaTeX

LaTeX colour support is added by loading the `xcolor` package.

```latex
\usepackage{xcolor}
```

### Text colour

Use `\textcolor{colour}{text}` to colour a word or phrase.

```latex
\textcolor{blue}{Blue text} and \textcolor{green}{green text}.
```

### Colouring mathematical expressions

```latex
\[
\textcolor{magenta}{E=mc^2}
\]
```

### Predefined and custom colours

The slides show predefined colours such as `red`, `violet`, `teal`, `brown`, `cyan`, and `lime`.

Custom colours can be defined using RGB, HTML, or named-colour mixing models:

```latex
\definecolor{myblue}{RGB}{10,60,200}
\definecolor{softpink}{HTML}{FFB6C1}
\definecolor{alert}{named}{red!80!black}

\textcolor{myblue}{Custom Blue}
```

### Background highlights and colour scope

```latex
\colorbox{yellow}{Important highlight!}
\fcolorbox{red}{white}{Critical label}
```

A local colour change can be limited with braces:

```latex
{\color{blue}BlueWord} is blue, while the rest is not.
```

The lecture also demonstrates setting a colour that applies to subsequent text.

## Picture Environment and Drawings

The picture environment is used in the lecture to draw simple objects using coordinates and drawing commands. Topics demonstrated include drawing lines and arrows, circles and ovals, frames, positioned text, dashed boxes, stacks, curves, and repeated patterns.

A basic picture environment has the following structure:

```latex
\setlength{\unitlength}{1mm}
\begin{picture}(100,60)
    \put(10,10){\line(1,0){40}}
    \put(10,10){\circle{10}}
    \put(60,20){\makebox(20,10){Text}}
\end{picture}
```

Coordinates are measured relative to the picture's coordinate system. The `\put` command places an object at a specified coordinate.

## Boxes and Positioning

The environment lectures cover several commands for arranging content in boxes and controlling horizontal or vertical placement.

### LR boxes

LR boxes store content in a horizontal box.

```latex
\makebox[4cm][c]{Centered content}
```

### Paragraph boxes

A `\parbox` creates a box containing a paragraph of text.

```latex
\parbox{5cm}{This is text inside a paragraph box.}
```

### Rule boxes

The `\rule` command draws a horizontal or vertical rule.

```latex
\rule{4cm}{0.4pt}
```

### Raising and lowering boxes

The lecture also covers raising and lowering boxed content to adjust its vertical position.

## Cross-References and Bibliography

### Cross-references

Labels and references allow sections, figures, tables, and equations to be referenced by their generated numbers.

```latex
\section{Introduction}
\label{sec:intro}

See Section~\ref{sec:intro} for the introduction.
```

Use labels close to the object being referenced. LaTeX may need to be compiled more than once before all references are updated.

### Bibliography with thebibliography

A bibliography can be written directly using the `thebibliography` environment.

```latex
\begin{thebibliography}{9}
\bibitem{lamport}
Leslie Lamport,
\textit{LaTeX: A Document Preparation System}.
\end{thebibliography}
```

### BibTeX

BibTeX manages bibliographic entries in a separate `.bib` file. The `.tex` document cites entries using citation keys, and BibTeX processes the bibliography data.

A typical entry has a type and fields such as author, title, year, publisher, journal, or book title, depending on the entry type.

Example `.bib` entry:

```bibtex
@book{lamport,
    author    = {Leslie Lamport},
    title     = {LaTeX: A Document Preparation System},
    publisher = {Addison-Wesley},
    year      = {1994}
}
```

The lectures also cover BibTeX entry types, required fields, name and title details, abbreviations, and the `crossref` field for proceedings or book collections.

## Indexing with MakeIndex

The environment lecture introduces creating an index with MakeIndex, including index entries and special characters used in index entries.

A typical workflow uses an index command in the document and then runs MakeIndex as part of compilation. The slides focus on the process and entry types rather than a complete index template.

## Troubleshooting and Common Errors

The lectures recommend checking the compiler output and using the reported line number and error message to locate problems.

Common issues covered include:

- Missing or mismatched braces.
- Missing `\end{...}` for an environment.
- Incorrect commands or package setup.
- A mismatch between the number of `&` separators and the declared number of table columns.
- Overfull and underfull box warnings caused by line or page layout.
- TeX capacity or resource-limit errors.

### Debugging strategy

1. Read the first error message and inspect its line number.
2. Check the command immediately before the reported location; the actual mistake may occur earlier.
3. Match every `\begin{...}` with the correct `\end{...}`.
4. Check braces and special characters.
5. For tables and arrays, verify that every row has the expected number of columns.
6. Compile again after correcting the issue.

## Important Notes and Best Practices

1. Keep the preamble organized and place package imports before `\begin{document}`.
2. Close every environment with its matching `\end{...}` command.
3. Use braces to group commands and limit formatting scope.
4. Escape reserved characters when they must appear as ordinary text.
5. Use meaningful labels for sections, figures, tables, and equations.
6. Compile multiple times when references or bibliographies need to be resolved.
7. Check table column counts and alignment when using `&` and `\\`.
8. Use packages when the required feature needs them, such as `graphicx`, `xcolor`, `geometry`, `fancyhdr`, `amsmath`, and `multirow`.

## Summary of Topics Covered

- Introduction to LaTeX, tools, source files, and compilation.
- Document structure, classes, title pages, abstracts, and sections.
- Text formatting, alignment, spacing, comments, special characters, and hyphenation.
- Page styles, margins, paper sizes, headers, footers, and page backgrounds.
- Mathematical notation, symbols, fonts, equations, arrays, and matrices.
- Itemized, enumerated, and description lists.
- Tables, merged rows and columns, positioning, labels, references, sizing, and colours.
- Figures, image sizing, captions, cropping, rotation, and multiple images.
- Text and math colours, custom colours, and highlights.
- Picture environment drawings and coordinate-based placement.
- Boxes, cross-references, bibliographies, BibTeX, and MakeIndex.
- Finding and fixing common LaTeX errors and warnings.

## Resources

- [LaTeX Project](https://www.latex-project.org/)
- [Overleaf Documentation](https://www.overleaf.com/learn)
- [CTAN – Comprehensive TeX Archive Network](https://www.ctan.org/)
