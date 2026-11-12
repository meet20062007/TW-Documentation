# Assignment 2 – Mathematical Notations and Equations

## Objective

Practice mathematical typesetting in LaTeX using inline and display equations, fractions, roots, mathematical symbols, calculus expressions, multi-line equations, and matrices.

## What I Learned

### 1. Basics

#### Inline Math

Inline math places an expression within the normal flow of text.

```latex
\(E = m.c^2\)
```

#### Display Math

Display math places an expression on a separate, centered line.

```latex
\[
v = u + a.t
\]
```

### 2. Fractions and Roots

#### Fractions

The `\frac{...}{...}` command places its first argument above its second argument.

```latex
\[
\frac{a+b}{c}
\]
```

#### Square Roots

The `\sqrt{...}` command typesets a square root.

```latex
\[
\sqrt{a^2+b^2}
\]
```

#### Combining Fractions and Roots

This combines a fraction, a square root, superscripts, and subscripts in one expression.

```latex
\[
x_i = \frac{\sqrt{a^2+b^2}}{c_i}
\]
```

### 3. Symbols and Math Fonts

#### Greek Letters and Subscripts

Greek letters are written using commands beginning with a backslash. Subscripts are written using `_` and braces when the subscript contains more than one character.

```latex
\[
G_{\mu\nu} + \Lambda g_{\mu\nu} = \kappa T_{\mu\nu}
\]
```

#### Logic and Set Symbols

This expression uses symbols for universal quantification, set membership, existence, implication, and the real numbers.

```latex
\[
\forall x \in \mathbb{R}\ \exists \epsilon > 0
\Rightarrow |x| < \epsilon
\]
```

The commands used are:

- `\forall` – universal quantifier.
- `\in` – membership in a set.
- `\mathbb{R}` – set of real numbers.
- `\exists` – existence.
- `\Rightarrow` – implication.

#### Summation and Binomial Coefficients

The `\sum` command creates a summation, while `\binom{n}{k}` creates a binomial coefficient.

```latex
\[
F(\theta) = \sum_{k=0}^{n} \binom{n}{k}
\theta^k(1-\theta)^{n-k}
\]
```

### 4. Calculus

#### Ordinary and Partial Derivatives

The expression below combines an ordinary derivative, partial derivatives, and a second-order partial derivative.

```latex
\[
\frac{du}{dx} + \frac{\partial u}{\partial t}
= \alpha \frac{\partial^2 u}{\partial x^2}
\]
```

- `\frac{du}{dx}` – ordinary derivative.
- `\frac{\partial u}{\partial t}` – partial derivative.
- `\partial` – command for the partial derivative symbol.

#### Definite Integral

The `\int` command creates an integral. The lower and upper limits are written using `_` and `^`.

```latex
\[
\int_0^1 (3x^2+2x+1)\,dx
\]
```

### 5. Multi-line Equations

#### Centering and Alignment

The `gather` environment centers each equation on a separate line and numbers the equations.

```latex
\begin{gather}
x = 5 \\
x+y = 3
\end{gather}
```

The `align` environment aligns equations at the `&` marker.

```latex
\begin{align}
x &= 5 \\
x+y &= 3
\end{align}
```

#### Multiline Equation

The `multline*` environment is used to display a long equation across multiple lines without equation numbering.

```latex
\begin{multline*}
(x+y+z)^3 = (x+y+z).(x+y+z).(x+y+z) \\
= x^3+y^3+z^3+3x^2y+3xy^2+3y^2z+3yz^2 \\
+3x^2z+3xz^2+6xyz
\end{multline*}
```

### 6. Matrices

The `matrix` environment creates a matrix without delimiters. Other matrix environments add different delimiters.

#### Matrix without delimiters

```latex
\[
\begin{matrix}
1 & 2 \\
3 & 4
\end{matrix}
\]
```

#### Matrix with square brackets

The `bmatrix` environment adds square brackets.

```latex
\[
\begin{bmatrix}
1 & 2 \\
3 & 4
\end{bmatrix}
\]
```

#### Matrix with vertical bars

The `vmatrix` environment adds vertical bars.

```latex
\[
\begin{vmatrix}
1 & 2 \\
3 & 4
\end{vmatrix}
\]
```

#### Matrix with parentheses

The `pmatrix` environment adds parentheses.

```latex
\[
\begin{pmatrix}
1 & 2 \\
3 & 4
\end{pmatrix}
\]
```

## Important Notes

- Inline equations are written using `\(...\)`.
- Display equations can be written using `\[...\]`.
- Use braces to group the contents of commands such as `\frac` and `\sqrt`.
- Use `^` for superscripts and `_` for subscripts.
- Use `\\` to start a new line inside multi-line equation and matrix environments.
- Use `&` to mark alignment points in the `align` environment.
- The `amsmath` package provides environments such as `gather`, `align`, and `multline`.

## Common Mistakes Avoided

- Leaving out braces around multi-character subscripts.
- Forgetting to provide both arguments to `\frac`.
- Forgetting the `&` alignment marker in an `align` environment.
- Using `\\` incorrectly when separating equation lines or matrix rows.
- Forgetting to include the required mathematical packages.

## Summary of Topics Covered

- Inline and display mathematical expressions.
- Fractions, square roots, superscripts, and subscripts.
- Greek letters, logic symbols, and set notation.
- Summations and binomial coefficients.
- Ordinary derivatives, partial derivatives, and definite integrals.
- Centered, aligned, and multiline equations.
- Matrices with different delimiters.

## Required Packages

The following packages are used in the assignment:

```latex
\usepackage{amsmath}
\usepackage{amssymb}
```
