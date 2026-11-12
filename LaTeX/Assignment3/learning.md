Assignment 3 – Mathematical Notations and Equations
Objective
Practice mathematical typesetting in LaTeX using inline and display equations, fractions, roots, mathematical symbols, calculus expressions, multi-line equations, and matrices.
What I Learned
1. Basics
Inline Math:
\(E = m.c^2\)
Inline math places an expression within the normal flow of text.

Display Math:
\[
v = u + a.t
\]
Display math places an expression on a separate, centered line.
2. Fractions and Roots
Fractions:
\frac{a+b}{c}
The \frac{} command places its first argument above its second argument.

Square Roots:
\sqrt{a^2+b^2}
The \sqrt{} command typesets a square root.

Combining Fractions and Roots:
x_i = \frac{\sqrt{a^2+b^2}}{c_i}
This combines a fraction, a square root, superscripts, and subscripts in one expression.
3. Symbols and Math Fonts
Greek Letters and Subscripts:
G_{\mu\nu} + \Lambda g_{\mu\nu} = \kappa T_{\mu\nu}
Greek letters are written using commands beginning with a backslash. Subscripts are written using _ and braces when the subscript contains more than one character.

Logic and Set Symbols:
\forall x \in \mathbb{R}\ \exists \epsilon > 0
\Rightarrow |x| < \epsilon
This uses:
- \forall for the universal quantifier.
- \in for membership.
- \mathbb{R} for the real numbers.
- \exists for the existential quantifier.
- \Rightarrow for implication.
Summation and Binomial Coefficients:
F(\theta) = \sum_{k=0}^{n} \binom{n}{k}
\theta^k(1-\theta)^{n-k}
- \sum creates a summation symbol with limits.
- \binom{n}{k} creates a binomial coefficient.
- ^ creates superscripts.
4. Calculus
Ordinary and Partial Derivatives:
\frac{du}{dx} + \frac{\partial u}{\partial t}
= \alpha \frac{\partial^2 u}{\partial x^2}
- \frac{du}{dx} represents an ordinary derivative.
- \partial is used for partial derivatives.
- \partial^2 represents a second-order partial derivative.
Definite Integral:
\int_0^1 (3x^2+2x+1)\,dx
- \int creates an integral symbol.
- _0 and ^1 specify the lower and upper limits.
- \, adds a small space before the differential.
5. Multi-line Equations
Centering and Alignment
Gather Environment:
\begin{gather}
x = 5 \\
x+y = 3
\end{gather}
The gather environment places multiple equations on separate centered lines and numbers them individually.

Align Environment:
\begin{align}
x &= 5 \\
x+y &= 3
\end{align}
The align environment aligns equations at the & symbol. Each line receives an equation number.
Multiline Equation
\begin{multline*}
(x+y+z)^3 = (x+y+z).(x+y+z).(x+y+z) \\
= x^3+y^3+z^3+3x^2y+3xy^2+3y^2z+3yz^2 \\
+3x^2z+3xz^2+6xyz
\end{multline*}
The multline* environment is used to break a long equation across multiple lines without equation numbering.
6. Matrices
Matrix without Brackets:
\[
\begin{matrix}
1 & 2 \\
3 & 4
\end{matrix}
\]
Matrix with Square Brackets:
\[
\begin{bmatrix}
1 & 2 \\
3 & 4
\end{bmatrix}
\]
Determinant-style Vertical Bars:
\[
\begin{vmatrix}
1 & 2 \\
3 & 4
\end{vmatrix}
\]
Matrix with Parentheses:
\[
\begin{pmatrix}
1 & 2 \\
3 & 4
\end{pmatrix}
\]
- & separates columns.
- \\ separates rows.
- The matrix environment determines the surrounding brackets.
Important Notes
1. Use \( ... \) for inline mathematical expressions.
2. Use \[ ... \] for centered display equations.
3. Use braces {} when a superscript or subscript contains multiple characters.
4. Use & to define alignment points in the align environment.
5. Use \\ to separate rows in matrices and lines in multi-line equations.
6. The amsmath package provides environments such as gather, align, and multline.
7. The amssymb package provides additional mathematical symbols.
Common Mistakes Avoided
- Forgetting to close math mode.
- Missing braces in fractions, roots, superscripts, or subscripts.
- Forgetting & in aligned equations and matrices.
- Using an incorrect row separator.
- Forgetting to load the required mathematical packages.
Key Takeaways
- Inline and display math are used for different equation layouts.
- Fractions and roots can be combined in mathematical expressions.
- Greek letters, logic symbols, and set symbols are available through LaTeX commands.
- Derivatives, partial derivatives, and integrals can be typeset using mathematical commands.
- gather, align, and multline help format multi-line equations.
- Matrix environments provide different bracket styles.
Required Packages
\usepackage{amsmath}
\usepackage{amssymb}
Files
This assignment covers mathematical basics, fractions and roots, symbols and math fonts, calculus, multi-line equations, and matrices.
Compilation
pdflatex assignment3.tex
pdflatex assignment3.tex