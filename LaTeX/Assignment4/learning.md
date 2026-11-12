# Assignment 4 – Lists, Colors, Figures etc.

## Objective

Practice creating different types of lists, positioning tables, defining and using colors, inserting images, rotating and cropping pictures, and placing multiple images side by side in LaTeX.

## What I Learned

### 1. Lists

LaTeX provides different environments to organize information.

#### Unordered List

The `itemize` environment creates a bulleted list. Each item begins with `\item`.

```latex
\begin{itemize}
    \item \LaTeX
    \item HTML (+CSS)
    \item Markdown
\end{itemize}
```

#### Ordered List

The `enumerate` environment creates a numbered list.

```latex
\begin{enumerate}
    \item To write research papers
    \item To embed math equations within other software
    \item To create CVs, project reports and presentations
\end{enumerate}
```

#### Description List

The `description` environment displays a term followed by its explanation.

```latex
\begin{description}
    \item[Presentational] Used by traditional word-processing systems.
    \item[Procedural] Markup gives instructions to programs.
    \item[Descriptive] Labels parts of a document by their meaning.
\end{description}
```

The assignment describes three categories of electronic markup:

- **Presentational:** Used by traditional word-processing systems and associated with WYSIWYG output.
- **Procedural:** Markup embedded in text that gives instructions to programs, such as TEX.
- **Descriptive:** Labels parts of a document according to what they are, such as LaTeX and HTML5.

### 2. Tables

The `tabular` environment is used to create tables. Column alignment and widths are specified in its argument.

```latex
\begin{tabular}{|p{2.5cm}|p{2cm}|p{2cm}|p{3.5cm}|}
\hline
Language & Requires compilation & Output & Use \\
\hline
C/C++ & Yes & Executable & To make apps \\
\hline
\LaTeX & Yes & PDF & To make documents \\
\hline
HTML/CSS/JS & No & Webpage & To make websites \\
\hline
2.5 cm & 2 cm & 2 cm & 3.5 cm \\
\hline
\end{tabular}
```

- `|` adds vertical borders.
- `&` separates columns.
- `\\` ends a row.
- `\hline` adds a horizontal line.
- `p{...}` sets a fixed column width and allows text to wrap.

#### Table Placement

The `table` environment makes a table a floating object. Its optional argument controls the preferred placement.

```latex
\begin{table}[t]
    \centering
    ...
    \caption{Table caption}
\end{table}
```

Common placement options include:

- `h` – here, if possible.
- `t` – top of a page.
- `b` – bottom of a page.
- `p` – a separate page for floats.

The assignment asks for the table to be rendered on a special page, so the solution uses `[p]`.

### 3. Colors

The `xcolor` package provides color support in LaTeX.

```latex
\usepackage{xcolor}
```

#### RGB Color

RGB represents a color using red, green, and blue components. The assignment asks for a color with 200 red, 20 green, and 200 blue.

```latex
\definecolor{custompurple}{RGB}{200,20,200}
```

#### HTML Hexadecimal Color

In HTML hexadecimal notation, the same RGB color is written as `#C814C8`. The two-digit pairs represent red (`C8`), green (`14`), and blue (`C8`).

The equivalent CSS numeric notation is `rgb(200,20,200)`.

For the `HTML` model in `\definecolor`, the six hexadecimal digits are supplied without the `#` symbol.

```latex
\definecolor{custompurple}{HTML}{C814C8}
```

#### Mixing Colors with `colorlet`

The `\colorlet` command can define a color by mixing existing colors.

```latex
\colorlet{custommix}{red!60!yellow}
```

This creates a mixture containing 60% red and 40% yellow.

#### Applying Colors to Mathematics

The `\textcolor` command applies a color to text or a mathematical expression.

```latex
\[
\textcolor{custompurple}{T(n)}
=
\textcolor{custommix}{aT(n/b)+f(n)}
\]
```

### 4. Figures

The `graphicx` package is used to insert and manipulate images.

```latex
\usepackage{graphicx}
```

#### Inserting an Image

The `\includegraphics` command inserts an image. The image file must be available in the LaTeX project.

```latex
\begin{figure}[htbp]
    \centering
    \includegraphics[width=0.32\textwidth]{mnit_logo.png}
    \caption{MNIT logo}
\end{figure}
```

- `width` controls the image width.
- `\textwidth` represents the width of the text area.
- `\centering` centers the image.
- `\caption` adds a figure caption.

#### Rotating an Image

The `angle` option rotates an image by the specified number of degrees.

```latex
\includegraphics[angle=90,width=0.32\textwidth]{mnit_logo.png}
```

#### Cropping an Image

The `trim` option removes parts of an image. Its values represent the amount removed from the left, bottom, right, and top, respectively. The `clip` option makes the crop take effect.

```latex
\includegraphics[width=\textwidth,trim=0 0 0 55,clip]{mnit_building.jpg}
```

This is used to crop the sky from the top of the MNIT building picture and make the image as wide as the text.

#### Floating Figures

The `figure` environment allows LaTeX to position an image as a floating object.

```latex
\begin{figure}[htbp]
    \centering
    \includegraphics[width=\textwidth]{mnit_building.jpg}
    \caption{This is a floating image and can appear anywhere.}
\end{figure}
```

### 5. Multiple Images Using Minipages

The `minipage` environment creates separate content areas that can be placed next to each other. The assignment uses two minipages with equal widths.

```latex
\begin{figure}[htbp]
\centering
\begin{minipage}[c]{0.45\textwidth}
    \centering
    \includegraphics[width=\linewidth]{mnit_logo.png}
    \caption{This is the first minipage}
\end{minipage}
\hfill
\begin{minipage}[c]{0.45\textwidth}
    \centering
    \includegraphics[width=\linewidth]{mnit_building.jpg}
    \caption{This is the second minipage}
\end{minipage}
\end{figure}
```

- Both minipages use `0.45\textwidth`, so they have equal widths.
- `\linewidth` makes each image fit the width of its own minipage.
- `\hfill` adds flexible horizontal space between them.
- `[c]` vertically centers the minipage contents relative to each other.

## Important Notes

- Load `graphicx` to insert, rotate, and crop images.
- Load `xcolor` to define and apply colors.
- The RGB model uses three numeric components: red, green, and blue.
- HTML hexadecimal colors use six hexadecimal digits, two for each RGB component.
- In `\colorlet`, `red!60!yellow` means 60% red and 40% yellow.
- Use `\textcolor` to apply a color to text or mathematical expressions.
- The order of values in `trim` is left, bottom, right, and top.
- Use `clip` along with `trim` to crop an image.
- The image files must be present in the same project folder or at the specified paths.
- Table and figure placement options are preferences; LaTeX may move floats to a suitable location.

## Common Mistakes Avoided

- Forgetting `\item` inside list environments.
- Forgetting `&` between table columns or `\\` at the end of a row.
- Using the wrong number of column specifications in a table.
- Forgetting to load `xcolor` or `graphicx`.
- Supplying the HTML hexadecimal color with an incorrect number of digits.
- Forgetting that `trim` values are ordered left, bottom, right, top.
- Omitting `clip` when cropping an image.
- Using image filenames that do not match the actual files in the project.
- Giving the two minipages different widths when equal widths are required.

## Summary of Topics Covered

- Unordered, ordered, and description lists.
- Presentational, procedural, and descriptive markup.
- Tables, column widths, borders, and float placement.
- RGB and HTML hexadecimal color representations.
- Defining custom colors and mixing colors with `colorlet`.
- Applying colors to mathematical expressions.
- Inserting, rotating, and cropping figures.
- Floating images and captions.
- Arranging two equal-width images using minipages.

## Required Packages

```latex
\usepackage{graphicx}
\usepackage{xcolor}
\usepackage{array}
```

## Files Required

Keep the following image files in the same folder as `assignment4.tex`:

- `mnit_logo.png`
- `mnit_building.jpg`
