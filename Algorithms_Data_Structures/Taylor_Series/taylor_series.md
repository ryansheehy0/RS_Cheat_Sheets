[Home](../../README.md)

# Taylor Series

Taking non polynomial functions and finding polynomials which approximate the function near some value of $x$.

## Equation:
Polynomials: $ax^0 + bx^1 + cx^2 + ...$

$f(x)$ $=$ function wanting to approximate

$p(x)$ $=$ polynomial that approximates $f(x)$

$p(x) = f(a) + \frac{df(a)}{dx} \frac{(x-a)}{1!} + \frac{d^2f(a)}{dx^2} \frac{(x-a)^2}{2!} + ... = \frac{d^nf(a)}{dx^n} \frac{(x-a)^n}{n!} + ...$

- If $x$ lies within the radius of convergence for $f(x)$ and $a$, then the more terms added to $p(x)$ the more accurate the approximation.

## Example:

$\qquad f(x)=cos(x)$ approximate at $a = 0$

$\qquad \frac{df}{dx} = -sin(x) \qquad \frac{d^2f}{dx^2} = -cos(x) \qquad \frac{d^3f}{dx^3} = sin(x)$

$\qquad f(0) = 1 \qquad \frac{df(0)}{dx} = 0 \qquad \frac{d^2f(0)}{dx^2} = -1 \qquad \frac{d^3f(0)}{dx^3} = 0$

$\qquad p(x) = 1 + 0 \frac{x}{1} + -1 \frac{x^2}{2} + 0 \frac{x^3}{6}$

$\qquad p(x) = 1 - \frac{x^2}{2} \approx cos(x)$

![](./taylor_series_diagram.png)
