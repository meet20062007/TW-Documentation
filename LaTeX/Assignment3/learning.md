# Assignment 3 – Arrays, Mathematical Expressions and Tables

## Objective

Practice advanced LaTeX structures using overbraces and underbraces, the `array` and `cases` environments, matrices, and different table layouts. The assignment also covers multi-column and multi-row cells, colored tables, paragraph text inside cells, professional tables using `booktabs`, nested tables, and mathematical expressions inside tables.

## What I Learned

### 1. Overbraces and Underbraces

The `\overbrace` command places a brace above an expression, while `\underbrace` places a brace below it. Both commands can include a label.

```latex
\[
\overbrace{a+b+c}^{\text{First Group}}
+
\underbrace{x+y+z}_{\text{Second Group}}
\]
```

These commands are useful for identifying parts of a long mathematical expression, such as the groups and total shown in Question 1.

### 2. Array Environment

The `array` environment creates a mathematical array. Its column specification controls alignment, and `&` separates columns.

```latex
\[
A=
\left[
\begin{array}{c|ccc}
 & x_1 & x_2 & x_3\\
\hline
y_1 & a_{11} & a_{12} & a_{13}\\
y_2 & a_{21} & a_{22} & a_{23}\\
y_3 & a_{31} & a_{32} & a_{33}
\end{array}
\right]
\]
```

- `c` centers a column.
- `|` inserts a vertical line.
- `\hline` inserts a horizontal line.
- `&` separates columns.
- `\\` ends a row.

### 3. Piecewise Functions with `cases`

The `cases` environment displays a piecewise-defined function with a large left brace. Each row contains an expression and its condition.

```latex
\[
f(x)=
\begin{cases}
x^2+2x+1, & x<0,\\
\sqrt{x}+1, & 0\leq x<4,\\
\dfrac{x^2-1}{x-1}, & x\geq 4.
\end{cases}
\]
```

The `&` symbol separates the function expression from its condition.

### 4. Matrices with Group Labels

The `\overbrace` command can also label groups of matrix columns. The `\multicolumn` command allows a brace and its label to span multiple columns in an array.

```latex
\[
\left[
\begin{array}{ccc|cc}
\multicolumn{3}{c|}{\overbrace{\phantom{a_{11}\quad a_{12}\quad a_{13}}}^{\text{Column Group 1}}}
&
\multicolumn{2}{c}{\overbrace{\phantom{a_{14}\quad a_{15}}}^{\text{Column Group 2}}}
\\
a_{11} & a_{12} & a_{13} & a_{14} & a_{15}\\
a_{21} & a_{22} & a_{23} & a_{24} & a_{25}\\
a_{31} & a_{32} & a_{33} & a_{34} & a_{35}
\end{array}
\right]
\]
```

### 5. Annotating a Mathematical Expression

The expression in Question 5 combines a summation and a matrix contribution. The `\underbrace` command labels each part and the complete expression.

```latex
\[
F(x)=
\underbrace{\sum_{i=1}^{n}
(a_i x_i^2+b_i x_i+c_i)}_{\text{Quadratic Contribution}}
+
\underbrace{
\begin{bmatrix}x_1&x_2&\cdots&x_n\end{bmatrix}
A
\begin{bmatrix}x_1\\x_2\\\vdots\\x_n\end{bmatrix}
}_{\text{Matrix Contribution}}
\]
```

The matrix \(A\) is an \(n\times n\) matrix whose entries are represented by \(a_{ij}\).

### 6. Tables with Borders and Alignment

The `tabular` environment creates tables. The column specification determines alignment and borders.

```latex
\begin{tabular}{|c|l|c|}
\hline
\textbf{Roll No.} & \textbf{Name} & \textbf{CGPA}\\
\hline
101 & Amit & 8.45\\
102 & Neha & 9.12\\
\hline
\end{tabular}
```

- `c` centers cell content.
- `l` left-aligns cell content.
- `r` right-aligns cell content.
- `|` creates vertical borders.
- `\hline` creates horizontal borders.
- `\textbf{...}` makes headings bold.

### 7. Merging Columns with `\multicolumn`

The `\multicolumn` command merges adjacent columns into one cell. In Question 7, the heading spans all three columns.

```latex
\begin{tabular}{|c|c|c|}
\hline
\multicolumn{3}{|c|}{\textbf{Academic Performance}}\\
\hline
Student & Midterm & Final\\
\hline
A & 78 & 89\\
B & 85 & 92\\
C & 91 & 94\\
\hline
\end{tabular}
```

Its arguments specify the number of columns to span, alignment and border formatting, and cell content.

### 8. Merging Rows with `\multirow`

The `multirow` package provides the `\multirow` command, which allows one cell to span multiple rows.

```latex
\usepackage{multirow}

\begin{tabular}{|c|l|c|c|}
\hline
Department & Course & Credits & Grade\\
\hline
\multirow{3}{*}{CSE}
& Data Structures & 4 & A\\
& Machine Learning & 4 & A+\\
& Operating Systems & 3 & B+\\
\hline
\multirow{2}{*}{ECE}
& Digital Electronics & 4 & A\\
& Signals & 3 & B+\\
\hline
\end{tabular}
```

The first argument is the number of rows to span, and `*` lets LaTeX calculate the natural width.

### 9. Colored Tables with `xcolor` and `colortbl`

The `xcolor` package with the `table` option and the `colortbl` package allow table rows and cells to be colored.

```latex
\usepackage[table]{xcolor}
\usepackage{colortbl}

\definecolor{headerblue}{HTML}{28558A}
\definecolor{rowblue}{HTML}{DCEAF7}

\begin{tabular}{|l|c|c|}
\hline
\rowcolor{headerblue}
\color{white}\textbf{Model} &
\color{white}\textbf{Parameters} &
\color{white}\textbf{FLOPs}\\
\hline
ResNet18 & 11.7M & 1.8G\\
MobileNetV2 & 3.5M & 0.3G\\
\hline
\end{tabular}
```

- `\definecolor` defines a custom color.
- `\rowcolor` applies a background color to a complete row.
- `\cellcolor` applies a background color to an individual cell.
- `\color{white}` changes the text color.

Question 10 applies individual cell colors based on marks:

- Marks greater than or equal to 90: green.
- Marks from 75 to 89: yellow.
- Marks below 75: red.

### 10. Paragraphs Inside Table Cells

Fixed-width paragraph columns allow long text to wrap automatically inside a cell. The `p{width}` column type sets a fixed width.

```latex
\begin{tabular}{|p{2.5cm}|p{3cm}|p{3cm}|}
\hline
\textbf{Technique} & \textbf{Description} & \textbf{Advantages}\\
\hline
Pruning &
Removes unnecessary parameters from a neural network. &
Reduces model size and computation.\\
\hline
\end{tabular}
```

The `tabularx` package also provides the `X` column type, which expands to use the available table width. This is useful when a table must fit within the page.

### 11. Professional Tables with `booktabs`

The `booktabs` package provides commands for clean, professional tables without vertical lines.

```latex
\usepackage{booktabs}

\begin{tabular}{lrrrr}
\toprule
\textbf{Model} & \textbf{Parameters} & \textbf{FLOPs} & \textbf{Accuracy} & \textbf{Energy}\\
\midrule
ResNet18 & 11.7M & 1.82G & 94.21 & 0.00093\\
MobileNetV2 & 3.5M & 0.30G & 92.84 & 0.00061\\
EfficientNet-B0 & 5.3M & 0.39G & 93.52 & 0.00072\\
\bottomrule
\end{tabular}
```

- `\toprule` creates the top rule.
- `\midrule` separates the heading from the data.
- `\bottomrule` creates the bottom rule.

A table can be placed inside the `table` environment to add a caption and label.

### 12. Nested Tables

A table can be placed inside a cell of another table by using a `tabular` environment inside that cell. Question 13 uses this technique to show the performance metrics for each model.

```latex
\begin{tabular}{|c|c|c|}
\hline
Model & Architecture &
\begin{tabular}{|c|c|}
\hline
Metric & Value\\
\hline
Accuracy & 94\%\\
F1 Score & 93\%\\
\hline
\end{tabular}\\
\hline
\end{tabular}
```

The inner table is independent and has its own rows, columns, and borders.

### 13. Mathematical Expressions Inside Tables

Mathematical expressions can be placed inside table cells using inline math delimiters such as `$...$` or `\(...\)`.

```latex
\begin{tabular}{|c|c|c|c|}
\hline
Model & Loss Function & Parameters & Complexity\\
\hline
Linear &
$\displaystyle L=\frac{1}{n}\sum_{i=1}^{n}(y_i-\hat{y}_i)^2$ &
10K & $O(n)$\\
\hline
CNN &
$\displaystyle L=-\sum y\log(\hat{y})$ &
1.2M & $O(n^2)$\\
\hline
Transformer &
$\displaystyle L=-\sum_i y_i\log p_i$ &
110M & $O(n^2d)$\\
\hline
\end{tabular}
```

The `\displaystyle` command makes mathematical expressions larger and easier to read inside table cells.

## Important Notes

- Use `\overbrace` for labels above expressions and `\underbrace` for labels below them.
- The `array` environment is used for mathematical arrays; `tabular` is used for ordinary tables.
- In arrays and tables, `&` separates columns and `\\` ends rows.
- Use `cases` for piecewise functions.
- Use `\multicolumn` to merge columns and `\multirow` to merge rows.
- Load `multirow` to use `\multirow`.
- Load `xcolor` with the `table` option and `colortbl` for colored tables.
- Use `\cellcolor` for individual cell backgrounds.
- Fixed-width `p{...}` columns allow paragraphs to wrap.
- `tabularx` helps tables fit a specified width.
- `booktabs` provides `\toprule`, `\midrule`, and `\bottomrule`; avoid vertical lines in booktabs tables.
- A nested `tabular` can be placed inside a cell of an outer table.
- Use math mode inside table cells for mathematical expressions.

## Common Mistakes Avoided

- Forgetting to close `\overbrace`, `\underbrace`, or `cases` expressions.
- Using the wrong number of column specifications in an array or table.
- Forgetting `&` between columns or `\\` between rows.
- Forgetting to load the `multirow` package before using `\multirow`.
- Using `\multicolumn` with an incorrect span count.
- Forgetting to load the table support for `xcolor` when using `\rowcolor` or `\cellcolor`.
- Allowing long text to overflow instead of using fixed-width columns.
- Adding vertical lines to a table that is required to use `booktabs` styling.
- Forgetting math delimiters around formulas in table cells.

## Summary of Topics Covered

- Overbraces and underbraces with labels.
- Mathematical arrays and piecewise functions.
- Matrices with grouped columns.
- Annotated mathematical expressions and quadratic/matrix contributions.
- Table borders, headings, and alignment.
- Merged cells using `\multicolumn` and `\multirow`.
- Colored rows and cells using `xcolor` and `colortbl`.
- Paragraph wrapping inside fixed-width table cells.
- Professional tables using `booktabs`.
- Nested tables.
- Mathematical expressions inside table cells.
