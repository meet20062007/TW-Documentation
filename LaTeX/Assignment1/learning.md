# Assignment 1 – Introduction to LaTeX, Equations and Citations

## Objective

Learn the basic structure of a LaTeX document, create and compile a simple document, use sections and lists, generate a table of contents, typeset inline and displayed mathematics, and add citations and cross-references with BibTeX.

## What I Learned

### 1. Creating a Basic LaTeX Document

A minimal LaTeX document contains a document class declaration and a document environment.

```latex
\documentclass{article}

\begin{document}
Hello World
\end{document}
```

- `\documentclass{article}` selects the article document class.
- `\begin{document}` marks the beginning of the document content.
- `\end{document}` marks the end of the document.

After writing the source, save it with the `.tex` extension, compile it, and view the generated output.

### 2. Document Class Options

Options can be added to the document class to control the font size and paper size.

```latex
\documentclass[12pt,a4paper]{article}
```

- `12pt` selects a 12-point base font size.
- `a4paper` selects A4 paper.
- The assignment asks us to find the default paper size and learn how to change it to A4; this document explicitly selects A4.

### 3. Sections and Subsections

The `\section` and `\subsection` commands organize the content into headings.

```latex
\section{My First LaTeX Document}

\subsection{Numbered List}
```

LaTeX automatically numbers these headings.

### 4. Table of Contents

The `\tableofcontents` command creates a table of contents from the document's section headings.

```latex
\begin{document}

\tableofcontents

\section{Introduction}
Document content.

\end{document}
```

Compile the document again after adding or changing headings so that the table of contents is updated.

### 5. Numbered Lists

The `enumerate` environment creates an ordered list. Each list entry begins with `\item`.

```latex
\begin{enumerate}
    \item First item
    \item Second item
    \item Third item
\end{enumerate}
```

### 6. Inline Mathematics

Inline math is written between `\(` and `\)`. It keeps the expression within the surrounding paragraph.

```latex
Einstein's mass-energy equation is \(E = mc^2\).
```

The `^` symbol creates a superscript, so `c^2` displays the square of \(c\).

### 7. Displayed Equations

The `equation` environment places a mathematical expression on its own line and numbers it automatically.

```latex
\begin{equation}
E = mc^2
\end{equation}
```

The assignment asks for the time-dependent Schrödinger equation. The expression uses:

- `\hbar` for the reduced Planck constant.
- `\frac{...}{...}` for fractions.
- `\partial` for partial derivatives.
- `\nabla^2` for the Laplacian.
- `\Psi` for the Greek capital psi.
- `\mathbf{r}` for a bold position vector.

### 8. Equation Labels and Cross-References

The `\label{...}` command gives an equation a reference key. The `\ref{...}` command prints its equation number.

```latex
\begin{equation}
E = mc^2
\label{eq:mass-energy}
\end{equation}

Equation~\ref{eq:mass-energy} gives the mass-energy relation.
```

The label is placed inside the equation environment. LaTeX updates the number automatically if the order of equations changes.

### 9. Citations with natbib

The `natbib` package provides citation commands such as `\citep` and `\citet`.

```latex
\usepackage{natbib}

Einstein's paper introduced the mass-energy relation
\citep{einstein1905}.
```

- `\citep{key}` creates a parenthetical citation.
- `\citet{key}` uses the author name as part of the sentence.
- The citation key must match an entry in the `.bib` file.

The assignment specifically asks for the `natbib` package.

### 10. BibTeX Bibliography

Bibliographic entries are stored in a separate `.bib` file. The LaTeX document refers to that file without writing the `.bib` extension.

```latex
\bibliographystyle{agu}
\bibliography{physics}
```

The assignment specifies the `agu` bibliography style and the file name `physics.bib`. The supplied `physics.bib` contains entries for Einstein's 1905 paper and Schrödinger's 1926 paper, which are the two works cited in the document.

## Important Notes

- The source file must be saved with the `.tex` extension.
- LaTeX commands begin with a backslash.
- The document content belongs between `\begin{document}` and `\end{document}`.
- Use `\section` and `\subsection` to organize content.
- Use `\tableofcontents` to generate the table of contents.
- Use `enumerate` and `\item` for numbered lists.
- Use `\(...\)` for inline mathematics.
- Use the `equation` environment for numbered display equations.
- Use `\label` and `\ref` to create equation cross-references.
- Use `natbib` for citations.
- The bibliography style requested in the assignment is `agu`.
- The bibliography file name requested in the assignment is `physics.bib`.

## Compilation Workflow

The document uses BibTeX. A typical command-line build sequence is:

```text
pdflatex first_latex_example.tex
bibtex first_latex_example
pdflatex first_latex_example.tex
pdflatex first_latex_example.tex
```

Run LaTeX again after BibTeX so citations, references, and the table of contents can be updated. The exact BibTeX executable name may differ between TeX installations.

## Common Mistakes Avoided

- Forgetting `\begin{document}` or `\end{document}`.
- Saving the source with an extension other than `.tex`.
- Forgetting to compile after editing the document.
- Writing a numbered list without the `enumerate` environment.
- Placing inline mathematics outside math delimiters.
- Using an equation label that does not match the key in `\ref`.
- Forgetting to load `natbib` before using its citation commands.
- Using a citation key that is absent from `physics.bib`.
- Forgetting to run BibTeX and recompile to update the bibliography and citations.

## Summary of Topics Covered

- Basic LaTeX document structure and the `article` class.
- Font size and A4 paper options.
- Sections, subsections, and table of contents.
- Numbered lists with `enumerate`.
- Inline mathematics and Einstein's mass-energy equation.
- Numbered equations and the Schrödinger equation.
- Equation labels and cross-references.
- `natbib` citation commands.
- BibTeX entries and the `agu` bibliography style.
