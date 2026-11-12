# Assignment 5 – Report & Presentation

## Objective

Create a LaTeX report using the `report` document class and prepare a short Beamer presentation supporting the report. The assignment covers title pages, abstracts, chapters, heading styles, page headers and footers, and presentation slides.

## What I Learned

### 1. Report Document Class

The `report` class is used to create documents that are organized into chapters and sections.

```latex
\documentclass[12pt,a4paper]{report}
```

- `12pt` sets the base font size.
- `a4paper` selects A4 paper.
- The `report` class supports chapter-level organization.

### 2. Page Margins

The `geometry` package controls page margins.

```latex
\usepackage[margin=1in]{geometry}
```

This sets all four margins to approximately one inch, as required by the assignment.

### 3. Title Page

A title page can be created with the `titlepage` environment. The assignment requires the title, author's name, ID, date, course name, and instructor's name.

```latex
\begin{titlepage}
\thispagestyle{empty}
\centering
{\Huge\bfseries Introduction to LaTeX\par}
\vspace{2cm}
{\Large Your Name\par}
Your ID\par
Course: Technical Writing Lab\par
Course Instructor: Instructor Name\par
\today
\end{titlepage}
```

- `\Huge` makes the title very large.
- `\bfseries` makes the title bold.
- `\Large` formats the author's name.
- `\today` inserts the current date.
- `\thispagestyle{empty}` removes the header and footer from the title page.

### 4. Abstract and Introduction

The `abstract` environment adds a short summary of the report. The main content can then begin with an Introduction chapter.

```latex
\begin{abstract}
This report introduces LaTeX and its document formatting features.
\end{abstract}

\chapter{Introduction}
```

### 5. Chapters and Heading Styles

The `report` class supports chapters, sections, and subsections.

The `sectsty` package changes the appearance of these headings.

```latex
\usepackage{xcolor}
\usepackage{sectsty}

\chapterfont{\color{red}\bfseries\Huge}
\sectionfont{\color{magenta}\itshape\Large}
\subsectionfont{\color{orange}}
```

The assignment requires:

- Chapter titles: red, bold, and Huge.
- Section titles: magenta, italic, and Large.
- Subsection titles: orange.

### 6. Headers and Footers

The `fancyhdr` package is used to customize page headers and footers.

```latex
\usepackage{fancyhdr}

\pagestyle{fancy}
\fancyhf{}
\fancyhead[L]{Your Name}
\fancyhead[C]{Course Title}
\fancyhead[R]{\today}
```

- `\fancyhf{}` clears the default header and footer fields.
- `\fancyhead[L]` places content on the left.
- `\fancyhead[C]` places content in the center.
- `\fancyhead[R]` places content on the right.

The title page uses the empty page style. The custom header is applied from the following page onward. The `plain` page style can also be redefined so chapter-opening pages use the same header.

### 7. Beamer Presentation

The `beamer` document class is used to create slide presentations.

```latex
\documentclass{beamer}
\usetheme{Madrid}

\title{Introduction to LaTeX}
\author{Your Name}
\date{\today}

\begin{document}

\begin{frame}
    \titlepage
\end{frame}

\begin{frame}{Introduction}
    \begin{itemize}
        \item LaTeX is a document preparation system.
        \item It is useful for technical documents.
    \end{itemize}
\end{frame}

\end{document}
```

- `\usetheme{Madrid}` selects a presentation theme.
- Each `frame` environment creates a slide.
- `\titlepage` creates the title slide.
- The `itemize` environment creates bullet points.

The assignment asks for a short presentation of 3–4 slides: a title slide, 1–2 content slides, and a concluding slide.

## Important Notes

- Use the `report` class for chapter-based reports.
- Load packages in the preamble, before `\begin{document}`.
- The `geometry` package controls page margins.
- The `sectsty` package changes heading styles.
- The `fancyhdr` package controls headers and footers.
- Use `\thispagestyle{empty}` to remove headers and footers from a particular page.
- Redefine the `plain` page style if chapter-opening pages must also show the custom header.
- Use the `beamer` class to create presentations.
- A Beamer slide is created using the `frame` environment.

## Common Mistakes Avoided

- Using the `article` class when chapters are required.
- Forgetting to set the font size and paper size in the document class.
- Forgetting to configure all page margins.
- Leaving the title page with a header or footer.
- Forgetting to load `sectsty`, `xcolor`, or `fancyhdr`.
- Applying heading formatting to the wrong heading level.
- Forgetting that chapter-opening pages may use the `plain` page style.
- Creating a presentation without the required title, content, and conclusion slides.

## Summary of Topics Covered

- `report` document class with 12pt font and A4 paper.
- Page margins using `geometry`.
- Title page and title formatting.
- Abstract and Introduction.
- Chapters, sections, and subsections.
- Heading colors and styles using `sectsty`.
- Headers and footers using `fancyhdr`.
- Removing the title page header and footer.
- Creating a 3–4 slide presentation using Beamer.

## Required Packages

```latex
\usepackage[margin=1in]{geometry}
\usepackage{xcolor}
\usepackage{sectsty}
\usepackage{fancyhdr}
```

The presentation uses:

```latex
\documentclass{beamer}
\usetheme{Madrid}
```

## Personal Details to Replace

Before submitting, replace the placeholders in the report and presentation with your actual name, ID, course instructor, and institution details.
