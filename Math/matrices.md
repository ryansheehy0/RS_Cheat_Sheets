[Home](../README.md)

# Matrices

$$
\quad C \\
$$

$$
R
\begin{bmatrix}
	1 & 2 & 3 \\
	4 & 5 & 6 \\
	7 & 8 & 9 \\
\end{bmatrix}
$$

Rows($R$) and columns($C$) all start at 1 and when specifying the size of a matrix it takes the form of $R$ x $C$.

- Matrices are often used to represent vectors. A vector has a starting point, ending point, and a direction. They can represent many types of data.

<!-- TOC -->

- [Adding/Subtracting:](#addingsubtracting)
	- [Example:](#example)
- [Multiplying:](#multiplying)
	- [Example of multiplying by a constant:](#example-of-multiplying-by-a-constant)
	- [Example of multiplying 2 matrices:](#example-of-multiplying-2-matrices)
	- [Examples of scaling and rotating:](#examples-of-scaling-and-rotating)
- [Inverse:](#inverse)
	- [Steps:](#steps)
	- [Example:](#example)
- [Row Echelon Form:](#row-echelon-form)
	- [Example:](#example)
- [Eigenvectors and Eigenvalues:](#eigenvectors-and-eigenvalues)
	- [Calculating the Eigenvectors and Eigenvalues:](#calculating-the-eigenvectors-and-eigenvalues)
	- [Example:](#example)
- [Dividing:](#dividing)
- [Dot product:](#dot-product)
- [Cross product:](#cross-product)
- [Kernels/Image Filters:](#kernelsimage-filters)

<!-- /TOC -->

## [Adding/Subtracting:](#matrices)
- Only matrices of the same size can be added/subtracted

### [Example:](#matrices)

$$
\begin{array}{}
	\begin{bmatrix}
		1 & 2 \\
		3 & 4 \\
	\end{bmatrix}\quad +
	&
	\begin{bmatrix}
		5 & 6 \\
		7 & 8 \\
	\end{bmatrix}\quad =
	&
	\begin{bmatrix}
		1+5 & 2+6 \\
		3+7 & 4+8 \\
	\end{bmatrix}\quad =
	&
	\begin{bmatrix}
		6 & 8 \\
		10 & 12 \\
	\end{bmatrix}
\end{array}
$$

$$
\begin{array}{}
	\begin{bmatrix}
		1 & 2 \\
		3 & 4 \\
	\end{bmatrix}\quad -
	&
	\begin{bmatrix}
		5 & 6 \\
		7 & 8 \\
	\end{bmatrix}\quad =
	&
	\begin{bmatrix}
		1-5 & 2-6 \\
		3-7 & 4-8 \\
	\end{bmatrix}\quad =
	&
	\begin{bmatrix}
		-4 & -4 \\
		-4 & -4 \\
	\end{bmatrix}
\end{array}
$$

## [Multiplying:](#matrices)

- The number of columns in the 1st matrix must be equal to the number of rows in the 2nd matrix
- The result of the multiplication is the rows of the 1st matrix and the column of the 2nd matrix.
- When multiplying matrices together the order of the multiplication matters
- When multiplying vectors represented by a matrix it scales and rotates the vector.

$$\text{1st matrix} * \text{2nd matrix}$$

$$
\begin{array}{}
	\text{Rows from 1st matrix}
	\left[
	\begin{array}{c}
		\left.
			\begin{array}{c}
				\text{ \ row } 1 (\text{col } 1 ) \\
				\text{ \ row } 1 (\text{col } 2 ) \\
				\text{ \ row } 1 (\text{col } 3 ) \\
			\end{array}
		\right] \\
	\text{row } 2 (\text{col } 1) \\
	\text{row } 2 (\text{col } 2) \\
	\text{row } 2 (\text{col } 3) \\
	\text{row } 3 (\text{col } 1) \\
	\text{row } 3 (\text{col } 2) \\
	\text{row } 3 (\text{col } 3) \\
	\vdots
	\end{array}
	\right.
	\text{Columns from 2nd matrix}
\end{array}
$$

### [Example of multiplying by a constant:](#matrices)

$$
	4 *
	\begin{bmatrix}
		1 & 2 \\
		3 & 4 \\
	\end{bmatrix}\quad = \quad
	\begin{bmatrix}
		1 & 2 \\
		3 & 4 \\
	\end{bmatrix} * 4\quad = \quad
	\begin{bmatrix}
		4(1) & 4(2) \\
		4(3) & 4(4) \\
	\end{bmatrix}\quad = \quad
	\begin{bmatrix}
		4 & 8 \\
		12 & 16 \\
	\end{bmatrix}
$$

### [Example of multiplying 2 matrices:](#matrices)

$$
2\text{x}3\quad A =
\begin{bmatrix}
	1 & 2 & 3\\
	4 & 5 & 6\\
\end{bmatrix}\qquad\quad
3\text{x}4\quad B =
\begin{bmatrix}
	7  & 8  & 9  & 10\\
	11 & 12 & 13 & 14\\
	15 & 16 & 17 & 18\\
\end{bmatrix}
$$

$$A * B \ne B * A$$

$$
A * B =
\begin{bmatrix}
	1(7)+2(11)+3(15) & 1(8)+2(12)+3(16) & 1(9)+2(13)+3(17) & 1(10)+2(14)+3(18)\\
	4(7)+5(11)+6(15) & 4(8)+5(12)+6(16) & 4(9)+5(13)+6(17) & 4(10)+5(14)+6(18)\\
\end{bmatrix}
$$

$$
\qquad\text{ \ }
=\begin{bmatrix}
	74  & 80  & 86 & 92\\
	173 & 188 & 203 & 218\\
\end{bmatrix}
$$

- $B * A$ cannot be calculated because the number of columns in $B$ doesn't equal the number of rows in $A$.

### [Examples of scaling and rotating:](#matrices)
- This matrix rotates a vector by 90 degrees counter-clockwise:

$$
\qquad\text{ \ }
=\begin{bmatrix}
	0 & -1 \\
	1 & 0 \\
\end{bmatrix}
$$

- This matrix scales a vector by 2

$$
\qquad\text{ \ }
=\begin{bmatrix}
	2 & 0 \\
	0 & 2 \\
\end{bmatrix}
$$

## [Inverse:](#matrices)
$A^{-1} = \frac{1}{\text{determinant}(A)} * \text{adjugate}(A)$

With $A$ being the matrix and $A^{-1}$ being the inverse.

- Only square matrices ($2x2, 3x3, 4x4, \dots$) can be inverted.
- If the determinant is 0 then the matrix cannot be inverted.
- If Matrix $A$ is multiplied by $A^{-1}$ the result is the identity matrix($I$) of the same size which has $1\text{s}$ on its left diagonal and $0\text{s}$ everywhere else.

### [Steps:](#matrices)

1. Get the **adjugate**:
	1. Get the **matrix of minors**
		1. Cross out each position's row and column and create a matrix of matrices.
			- Ex:

$$
			\begin{bmatrix}
				\underline{1} & 0 & 1 \\
				0 & 2 & 1 \\
				1 & 1 & 1 \\
			\end{bmatrix} \rightarrow
			\begin{bmatrix}
				\cancel{1} & \cancel{0} & \cancel{1} \\
				\cancel{0} & 2 & 1 \\
				\cancel{1} & 1 & 1 \\
			\end{bmatrix} \rightarrow
			\begin{bmatrix}
				2 & 1 \\
				1 & 1 \\
			\end{bmatrix}
$$

$$
			\begin{bmatrix}
				1 & \underline{0} & 1 \\
				0 & 2 & 1 \\
				1 & 1 & 1 \\
			\end{bmatrix} \rightarrow
			\begin{bmatrix}
				\cancel{1} & \cancel{0} & \cancel{1} \\
				0 & \cancel{2} & 1 \\
				1 & \cancel{1} & 1 \\
			\end{bmatrix} \rightarrow
			\begin{bmatrix}
				0 & 1 \\
				1 & 1 \\
			\end{bmatrix}
$$

$$
			\downarrow
$$

$$
			\begin{bmatrix}
				\begin{bmatrix}
					2 & 1 \\
					1 & 1 \\
				\end{bmatrix} &
				\begin{bmatrix}
					0 & 1 \\
					1 & 1 \\
				\end{bmatrix} &
				\dots \\
				\dots & \dots & \dots \\
				\dots & \dots & \dots \\
			\end{bmatrix}
$$

<ol>
	<ol>
		<ol start="2">
			<li>Repeat recursively until you are left with only a 2&#215;2 matrices.</li>
			<li>Take the determinant of the 2&#215;2 matrices.</li>
			<ul>
				<li>The left diagonal multiplied together minus the right diagonal multiplied together.</li>
			</ul>
		</ol>
	</ol>
</ol>

$$
\text{Left diagonal} =
\begin{bmatrix}
	\underline{\space\space} & \space\space \\
	\space\space & \underline{\space\space} \\
\end{bmatrix} \qquad
\text{Right diagonal} =
\begin{bmatrix}
	\space\space & \underline{\space\space} \\
	\underline{\space\space} & \space\space \\
\end{bmatrix}
$$

<ul>
	<ul>
		<ul>
			<ul>
				<li>Ex:</li>
			</ul>
		</ul>
    </ul>
</ul>

$$
\begin{bmatrix}
	3 & 5 \\
	-7 & 2 \\
\end{bmatrix}
$$

$$(3 * 2) - (5 * -7) = 41$$

<ol>
	<ol start=2>
		<li>Get the <b>matrix of cofactors</b></li>
		<ul>
			<li>Multiply alternating rows of +1 and -1 to the matrix of minors.</li>
		</ul>
	</ol>
</ol>

$$
\begin{bmatrix}
	+ & - \\
	- & + \\
\end{bmatrix}
\begin{bmatrix}
	+ & - & + \\
	- & + & - \\
	+ & - & + \\
\end{bmatrix}
\begin{bmatrix}
	+ & - & + & - \\
	- & + & - & + \\
	+ & - & + & - \\
	- & + & - & + \\
\end{bmatrix}
\dots
$$

<ul>
	<ul>
		<ul>
		<li>Ex:</li>
		</ul>
	</ul>
</ul>

$$
\begin{bmatrix}
	2 & 1 \\
	1 & 1 \\
\end{bmatrix} *
\begin{bmatrix}
	+ & - \\
	- & + \\
\end{bmatrix} =
\begin{bmatrix}
	2 & -1 \\
	-1 & 1 \\
\end{bmatrix}
$$

<ol>
	<ol start=3>
		<li>Get the <b>adjugate</b></li>
		<ul>
			<li>Flip the <b>matrix of cofactors</b> along the left diagonal.</li>
			<li>Ex:</li>
		</ul>
	</ol>
</ol>

$$
\begin{bmatrix}
	\underline{3} & 5 & -7 \\
	2 & \underline{1} & 2 \\
	3 & 4 & \underline{5} \\
\end{bmatrix} \rightarrow
\begin{bmatrix}
	3 & 2 & 3 \\
	5 & 1 & 4 \\
	-7 & 2 & 5 \\
\end{bmatrix}
$$

2. Get the **determinant**:
<ul>
	<ul>
		<li>Multiply the elements in the first row of the matrix(A) with its corresponding elements in its adjugate and add them up together.</li>
		<li>Ex: </li>
	</ul>
</ul>

$$
A =
\begin{bmatrix}
	1 & 1 & 3 \\
	2 & 3 & 4 \\
	7 & 4 & 5 \\
\end{bmatrix} \qquad
\text{adj} =
\begin{bmatrix}
	-1 & 7 & -5 \\
	18 & -16 & 2 \\
	-13 & 3 & 1 \\
\end{bmatrix}
$$

$$(1 * -1) + (1 * 7) + (3 * -5) = -9$$

3. Plug **determinant** and **adjugate** into the equation.

### [Example:](#matrices)

$$
A =
\begin{bmatrix}
	1 & 0 & 1 \\
	0 & 2 & 1 \\
	1 & 1 & 1 \\
\end{bmatrix}
$$

$$
\begin{bmatrix}
	\begin{bmatrix}
		2 & 1 \\
		1 & 1 \\
	\end{bmatrix} &
	\begin{bmatrix}
		0 & 1 \\
		1 & 1 \\
	\end{bmatrix} &
	\begin{bmatrix}
		0 & 2 \\
		1 & 1 \\
	\end{bmatrix} \\
	\begin{bmatrix}
		0 & 1 \\
		1 & 1 \\
	\end{bmatrix} &
	\begin{bmatrix}
		1 & 1 \\
		1 & 1 \\
	\end{bmatrix} &
	\begin{bmatrix}
		1 & 0 \\
		1 & 1 \\
	\end{bmatrix} \\
	\begin{bmatrix}
		0 & 1 \\
		2 & 1 \\
	\end{bmatrix} &
	\begin{bmatrix}
		1 & 1 \\
		0 & 1 \\
	\end{bmatrix} &
	\begin{bmatrix}
		1 & 0 \\
		0 & 2 \\
	\end{bmatrix}
\end{bmatrix}
$$

$$
\text{Matrix of minors} =
\begin{bmatrix}
	1 & -1 & -2 \\
	-1 & 0 & 1  \\
	-2 & 1 & 2  \\
\end{bmatrix}
$$

$$
\text{Matrix of cofactors} =
\begin{bmatrix}
	1 & -1 & -2 \\
	-1 & 0 & 1  \\
	-2 & 1 & 2  \\
\end{bmatrix} *
\begin{bmatrix}
	+ & - & + \\
	- & + & -  \\
	+ & - & +  \\
\end{bmatrix} =
\begin{bmatrix}
	1 & 1 & -2 \\
	1 & 0 & -1  \\
	-2 & -1 & 2  \\
\end{bmatrix}
$$

$$
\text{adjugate} =
\begin{bmatrix}
	1 & 1 & -2 \\
	1 & 0 & -1  \\
	-2 & -1 & 2  \\
\end{bmatrix}
$$

$$\text{determinant} = (1 * 1) + (0 * 1) + (1 * -2) = -1$$

$$
A^{-1} = \frac{1}{-1} *
\begin{bmatrix}
	1 & 1 & -2 \\
	1 & 0 & -1  \\
	-2 & -1 & 2  \\
\end{bmatrix} =
\begin{bmatrix}
	-1 & -1 & 2 \\
	-1 & 0 & 1  \\
	2 & 1 & -2  \\
\end{bmatrix}
$$

- Example of a system of equations:
	- Inverse matrices can also be used to solve system of equations which are a set of one or more equations that must be solved together.

$$
3x-2y=1
$$

$$
-x+4y=3
$$

$$
\begin{bmatrix}
	3 & -2 \\
	-1 & 4 \\
\end{bmatrix}
\begin{bmatrix}
	x \\
	y \\
\end{bmatrix}=
\begin{bmatrix}
	1 \\
	3 \\
\end{bmatrix}
$$

<ul>
	<ul>
		<li>Which input vector [x,y] maps to [1,3] when it is scales and rotated by the matrix?</li>
	</ul>
</ul>

$$
A =
\begin{bmatrix}
	3 & -2 \\
	-1 & 4 \\
\end{bmatrix} \rightarrow
\begin{bmatrix}
	4 & -1 \\
	-2 & 3 \\
\end{bmatrix} *
\begin{bmatrix}
	+ & - \\
	- & + \\
\end{bmatrix} =
\begin{bmatrix}
	4 & 1 \\
	2 & 3 \\
\end{bmatrix} \rightarrow
\begin{bmatrix}
	4 & 2 \\
	1 & 3 \\
\end{bmatrix}
$$

$$
(3*4) - (-1 * -2) = 10
$$

$$
A^{-1} =
\frac{1}{10} *
\begin{bmatrix}
	4 & 2 \\
	1 & 3 \\
\end{bmatrix} =
\begin{bmatrix}
	2/5 & 1/5 \\
	1/10 & 3/10 \\
\end{bmatrix}
$$

$$
\begin{bmatrix}
	2/5 & 1/5 \\
	1/10 & 3/10 \\
\end{bmatrix} *
\begin{bmatrix}
	1 \\
	3 \\
\end{bmatrix} =
\begin{bmatrix}
	1 \\
	1 \\
\end{bmatrix}
$$

$$
x = 1 \qquad y = 1
$$

## [Row Echelon Form:](#matrices)
- Row echelon form is used to solve system of equations easier.
- Row echelon form consists of modifying rows with equations consisting of other rows.

### [Example:](#matrices)

$$x + y - z = -2$$

$$2x - y + z = 5$$

$$-x +2y +2z = 1$$

$$
\left[
\begin{array}{c|c}
  \begin{matrix}
    1 & 1 & -1 \\
    2 & -1 & 1 \\
    -1 & 2 & 2
  \end{matrix}
  &
  \begin{matrix}
    -2 \\
    5 \\
	1
  \end{matrix}
\end{array}
\right]
\begin{matrix}
 \\
  \\
\xrightarrow{R_1 + R_3}{}
\end{matrix}
\left[
\begin{array}{c|c}
  \begin{matrix}
    1 & 1 & -1 \\
    2 & -1 & 1 \\
    0 & 3 & 1
  \end{matrix}
  &
  \begin{matrix}
    -2 \\
    5 \\
	-1
  \end{matrix}
\end{array}
\right]
\begin{matrix}
 \\
\xrightarrow{-2 R_1 + R_2}{}\\
 \\
\end{matrix}
\left[
\begin{array}{c|c}
  \begin{matrix}
    1 & 1 & -1 \\
    0 & -3 & 3 \\
    0 & 3 & 1
  \end{matrix}
  &
  \begin{matrix}
    -2 \\
    9 \\
	-1
  \end{matrix}
\end{array}
\right]
\begin{matrix}
 \\
  \\
\xrightarrow{R_2 + R_3}{}
\end{matrix}
$$

$$
\left[
\begin{array}{c|c}
  \begin{matrix}
    1 & 1 & -1 \\
    0 & -3 & 3 \\
    0 & 0 & 4
  \end{matrix}
  &
  \begin{matrix}
    -2 \\
    9 \\
	8
  \end{matrix}
\end{array}
\right]
\begin{matrix}
 \\
\xrightarrow{-1/3 * R_2}{}  \\
\xrightarrow{1/4 * R_3}{}
\end{matrix}
\left[
\begin{array}{c|c}
  \begin{matrix}
    1 & 1 & -1 \\
    0 & 1 & -1 \\
    0 & 0 & 1
  \end{matrix}
  &
  \begin{matrix}
    -2 \\
    -3 \\
	2
  \end{matrix}
\end{array}
\right]
$$

- Matrices in row echelon form can be converted back into equations to make the math easier.

$$x + y - z = -2$$

$$y-z=-3$$

$$z=2$$

$$y=-1 \text{ and } x=1$$

## [Eigenvectors and Eigenvalues:](#matrices)
- Any vector that is only scaled by a matrix and not rotated is called an Eigenvector of that matrix. How much that vector is scaled by is called the Eigenvalue.
- Only square matrices have eigenvectors and eigenvalues.
- Each Eigenvector has one Eigenvalue associated with it.
- Eigenvectors cannot be $\vec{0}$ because that would just result in $\vec{0}$ and give no valuable information.
- Eigenvectors and Eigenvalues are so useful because they can give insight into the long term behavior of a system.
- A matrix can have multiple Eigenvalues, but no more than its number of rows/columns.

$$A \vec{v} = \lambda \vec{v}$$

- Where $A$ is the matrix, $\vec{v}$ is the Eigenvector, and $\lambda$ is the Eigenvalue.

### [Calculating the Eigenvectors and Eigenvalues:](#matrices)

$$A \vec{v} - \lambda \vec{v} = \vec{0} $$

- Insert the Identify matrix($I$) which is equivalent ot multiplying by 1 for matrices.

$$A \vec{v} - \lambda I \vec{v} = \vec{0}$$

$$(A - \lambda I) \vec{v} = \vec{0}$$

- $\vec{v}$ cannot be $\vec{0}$ so $(A - \lambda I)$ cannot have an inverse which means the determinant of $(A - \lambda I)$ must be equal to 0.

$$(A - \lambda I)^{-1} (A - \lambda I) \vec{v} = (A - \lambda I)^{-1} \vec{0}$$

$$(A - \lambda I)^{-1} (A - \lambda I) = I \text{\quad and \quad} (A - \lambda I)^{-1} \vec{0} = \vec{0}$$

$$I \vec{v} \ne \vec{0}$$

$$\text{determinant}(A - \lambda I) = 0$$

- $\text{determinant}(A - \lambda I)$ is used to find the Eigenvalues($\lambda$) which can be used to calculate the Eigenvectors($\vec{v}$).
	- Each Eigenvalue($\lambda$) is used to calculate its Eigenvector($\vec{v}$) using $(A - \lambda I) \vec{v} = 0$ and translated into its row echelon form and then translated into an equation. Assuming one of the variables is 1 the other can be calculated and the Eigenvector($\vec{v}$) can be calculated.
	- This has to be done for each Eigenvalue($\lambda$) separately

### [Example:](#matrices)

$$.8(h_1) + .1(z_1) = h_2$$

$$.2(h_1) + .9(z_1) = z_2$$

- What will $h$ and $z$ converge to as the cycles go to $\infty$?
- In other words, what is the eigenvector for the matrix

$$
\begin{bmatrix}
.8 & .1 \\
.2 & .9 \\
\end{bmatrix}
$$

$$
\text{determinant}
\left(
\begin{bmatrix}
.8 & .1 \\
.2 & .9 \\
\end{bmatrix} -
\lambda
\begin{bmatrix}
1 & 0 \\
0 & 1 \\
\end{bmatrix}
\right) = 0
$$

- What are the eigenvalues($\lambda$)?

$$
\text{determinant}
\left(
\begin{bmatrix}
.8 & .1 \\
.2 & .9 \\
\end{bmatrix} -
\begin{bmatrix}
\lambda & 0 \\
0 & \lambda \\
\end{bmatrix}
\right) =
\text{determinant}
\left(
\begin{bmatrix}
.8-\lambda & .1 \\
.2 & .9-\lambda \\
\end{bmatrix}
\right) =
$$

$$((.8-\lambda)(.9-\lambda)) - (.2 * .1) = \lambda^2 - 1.7\lambda + 0.7 = 0$$

$$ \lambda_1 = 1 \text{\quad and \quad} \lambda_2 = .7 $$

- $\lambda_1 = 1$

$$
\begin{bmatrix}
.8-1 & .1 \\
.2 & .9-1 \\
\end{bmatrix} =
\begin{bmatrix}
-.2 & .1 \\
.2 & -.1 \\
\end{bmatrix}
\begin{matrix}
 \\
\xrightarrow{R_1 + R_2}{} \\
\end{matrix}
\begin{bmatrix}
-.2 & .1 \\
0 & 0 \\
\end{bmatrix}
$$

$$
\begin{bmatrix}
-.2 & .1 \\
0 & 0 \\
\end{bmatrix}
\begin{bmatrix}
h \\
z \\
\end{bmatrix} =
\begin{bmatrix}
0 \\
0 \\
\end{bmatrix}
$$

$$-0.2h + .1z = 0$$

$$h = 1 \text{\quad and \quad} z = 2$$

$$
\vec{v_1} =
\begin{bmatrix}
1 \\
2 \\
\end{bmatrix}
$$

- $\lambda_2 = .7$

$$
\begin{bmatrix}
.8-.7 & .1 \\
.2 & .9-.7 \\
\end{bmatrix} =
\begin{bmatrix}
.1 & .1 \\
.2 & .2 \\
\end{bmatrix}
\begin{matrix}
 \\
\xrightarrow{-2R_1 + R_2}{} \\
\end{matrix}
\begin{bmatrix}
.1 & .1 \\
0 & 0 \\
\end{bmatrix}
$$

$$
\begin{bmatrix}
.1 & .1 \\
0 & 0 \\
\end{bmatrix}
\begin{bmatrix}
h \\
z \\
\end{bmatrix} =
\begin{bmatrix}
0 \\
0 \\
\end{bmatrix}
$$

$$.1h + .1z = 0$$

$$h = 1 \text{\quad and \quad} z = -1$$

$$
\vec{v_2} =
\begin{bmatrix}
1 \\
-1 \\
\end{bmatrix}
$$

## [Dividing:](#matrices)
## [Dot product:](#matrices)
## [Cross product:](#matrices)
## [Kernels/Image Filters:](#matrices)
