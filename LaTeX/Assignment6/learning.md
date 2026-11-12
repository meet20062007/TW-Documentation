# Assignment 6 – Document Structure

## Objective

Practice document formatting and structure in LaTeX. This assignment covers font configuration, page background color, paragraph spacing and hyphenation, alphabetic section numbering, equations, saveboxes, paragraph boxes, index creation, and bibliography management.

## What I Learned

### A. Fonts and Background

#### Changing the Page Background

The `xcolor` package can define a custom color, and `\pagecolor` applies it to the page background.

```latex
\usepackage{xcolor}

\definecolor{pagebackground}{HTML}{FFF2E5}
\pagecolor{pagebackground}
```

The assignment page uses a light peach background. The hexadecimal color above is used to approximate the displayed background.

#### Using Different Font Families

The `fontspec` package allows fonts to be selected by their installed names. The assignment uses DejaVu Serif as the main font, DejaVu Sans as the sans-serif font, and Courier as the monospace font.

```latex
\usepackage{fontspec}

\setmainfont{DejaVu Serif}
\setsansfont{DejaVu Sans}
\setmonofont{Courier}
```

The font family can be switched for individual text:

```latex
This text uses the main font.

{\sffamily This text uses the sans-serif font.}

{\ttfamily This text uses the monospace font.}
```

The `fontspec` package requires XeLaTeX or LuaLaTeX. The assignment specifically asks to configure TeXstudio to use XeLaTeX as the default compiler.

#### Trivlist

The `trivlist` environment can be used to arrange the three font examples as separate list items.

```latex
\begin{trivlist}
    \item First font example.
    \item Second font example.
    \item Third font example.
\end{trivlist}
```

### B. Spacing

#### New Line Without a New Paragraph

The `\\` command starts a new line while keeping the text in the same paragraph.

```latex
This is the first line of a paragraph.\\
This is another line, but not another paragraph.
```

#### Vertical Space

The `\vspace{...}` command inserts vertical space. The assignment uses a 1 cm gap before the next paragraph.

```latex
\vspace{1cm}
```

#### Hyphenation

LaTeX can break long words at suitable points. The `\-` command specifies a possible hyphenation point manually.

```latex
antidis\-establishmentarianisms
```

The `\mbox{...}` command keeps its contents together and prevents a line break inside the enclosed text.

```latex
\mbox{antidisestablishmentarianisms}
```

These commands demonstrate the difference between allowing a long word to break and keeping the whole word on one line.

#### Page Break and Reserved Space

The `\newpage` command starts the next page. Vertical space can be left at the beginning of that page to reserve room for the section C content, which is not specified in the assignment.

```latex
\newpage
\vspace*{3cm}
```

### D. Numbering

#### Alphabetic Section Numbering

The `\Alph` counter representation changes section numbers to uppercase letters.

```latex
\renewcommand{\thesection}{\Alph{section}}
```

This produces section labels such as A, B, C, D, and E.

#### Equations

The `equation` environment automatically numbers displayed equations.

```latex
\begin{equation}
\frac{x^2}{a^2}+\frac{y^2}{b^2}=1
\end{equation}

\begin{equation}
x^2+y^2=1
\end{equation}
```

The ellipse equation is placed before the circle equation, as required. Therefore, the ellipse receives equation number 1 and the circle receives equation number 2.

### E. Boxes and Lines

#### Saveboxes

A savebox stores content so it can be reused. First declare a box, then store content in it with `\sbox`, and display it with `\usebox`.

```latex
\newsavebox{\messagebox}
\sbox{\messagebox}{This message is written in a savebox.}

\usebox{\messagebox}
\usebox{\messagebox}
\usebox{\messagebox}
```

This allows the same stored message to be printed multiple times.

#### Paragraph Box

The `\parbox` command creates a box with a specified width and allows text to wrap within it.

```latex
\parbox{5cm}{This message is wrapped in a 5cm paragraph box.}
```

The `\fbox` command draws a border around its contents.

```latex
\fbox{\parbox{5cm}{This message is wrapped in a 5cm paragraph box.}}
```

#### Horizontal Line

The `\rule` command creates a line or filled rectangular rule.

```latex
\rule{\textwidth}{0.4pt}
```

The first argument sets the width and the second argument sets the thickness.

### Index

The `imakeidx` package and `\makeindex` enable index generation. The `\index{...}` command adds terms to the index, and `\printindex` prints the collected index.

```latex
\usepackage{imakeidx}
\makeindex

Text about fonts.\index{fonts}

\clearpage
\printindex
```

Relevant terms from the document can be indexed, such as background, numbering, and savebox.

### Bibliography and BibTeX

A `.bib` file stores bibliographic entries. Each entry has a citation key that is used in the LaTeX document.

Example citation:

```latex
We cite the LaTeX reference \cite{oetiker2021notso}.
```

Example BibTeX entry:

```bibtex
@manual{oetiker2021notso,
  author       = {Tobias Oetiker},
  title        = {The Not So Short Introduction to {LaTeX2e}},
  year         = {2021},
  organization = {CTAN}
}
```

The bibliography is printed using a bibliography style and the name of the `.bib` file, without its extension.

```latex
\bibliographystyle{plain}
\bibliography{references}
```

The assignment's reference list includes the Oetiker LaTeX introduction and Overleaf's guide to bibliography management with BibTeX. The supplied PDF refers to an attached `.bib` file, but no separate `.bib` file was included with the uploaded assignment PDF; the accompanying `references.bib` is therefore created from the two references printed on page 4.

## Important Notes

- `fontspec` requires XeLaTeX or LuaLaTeX; this assignment specifically requests XeLaTeX.
- Font names must match fonts installed on the computer compiling the document.
- `\pagecolor` changes the page background.
- `\\` starts a new line; `\vspace{1cm}` adds vertical space.
- `\-` introduces a possible hyphenation point.
- `\mbox{...}` prevents line breaks inside its contents.
- `\newpage` starts a new page.
- `\renewcommand{\thesection}{\Alph{section}}` changes section numbering to uppercase letters.
- `\newsavebox`, `\sbox`, and `\usebox` create, store, and reuse boxed content.
- `\parbox` creates a fixed-width paragraph box, while `\fbox` adds a border.
- `\index` adds an index entry; `\printindex` prints the index.
- BibTeX uses citation keys to connect `\cite{...}` commands to entries in the `.bib` file.

## Compilation Workflow

Compile the document with XeLaTeX and run the index and bibliography processors.

```text
xelatex assignment6.tex
makeindex assignment6.idx
bibtexu assignment6
xelatex assignment6.tex
xelatex assignment6.tex
```

The final two XeLaTeX runs update references, index, and bibliography information in the document.

## Common Mistakes Avoided

- Compiling a `fontspec` document with pdfLaTeX instead of XeLaTeX.
- Using font names that are not installed on the system.
- Confusing a line break with a new paragraph.
- Forgetting the leading `*` in `\vspace*` when reserving space at the top of a page.
- Forgetting to create the savebox before storing or displaying its content.
- Forgetting to run the index processor after adding index entries.
- Forgetting to run BibTeX and then recompile the LaTeX document.
- Using a citation key in `\cite` that does not exist in the `.bib` file.

## Summary of Topics Covered

- Page background color and font configuration with `fontspec`.
- DejaVu Serif, DejaVu Sans, and Courier font families.
- `trivlist` for arranging font examples.
- Line breaks, vertical spacing, and hyphenation.
- Alphabetic section numbering.
- Numbered ellipse and circle equations.
- Saveboxes, paragraph boxes, and horizontal rules.
- Index creation and compilation.
- Bibliography entries, citations, and BibTeX compilation.
