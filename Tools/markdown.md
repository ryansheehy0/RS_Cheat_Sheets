[Home](../README.md)

# Markdown
- Markdown is a lightweight markup language that can be converted to HTML
    - Valid HTML can be used within markdown

<!-- TOC -->

- [Links and Etc](#links-and-etc)
- [Emphasis](#emphasis)
- [Lists](#lists)
	- [Unordered Lists](#unordered-lists)
	- [Ordered Lists](#ordered-lists)
	- [More Complex Lists](#more-complex-lists)
- [Tables](#tables)
- [Math](#math)
	- [Special characters](#special-characters)
	- [Exponents and subscripts](#exponents-and-subscripts)
	- [Comparisons](#comparisons)
	- [Special operations](#special-operations)
	- [Trig](#trig)
	- [Other](#other)

<!-- /TOC -->

## [Links and Etc](#markdown)

|                          |                        |
|--------------------------|------------------------|
| \#, ##, ###, ..., ###### | Headings               |
| \[Link Text](URL)        | Link                   |
| \[Text](#header-name)    | Link to \# Header Name |
| \!\[Alt Text](URL)       | Video/Image            |
| `---`                    | Horizontal Line        |
| \\                       | Escape character       |
| `<!-- Text -->`           | Comments               |
| \` Text `                | Inline Code            |
| \`\`\` Text ```          | Code Block             |
| > Text                   | Blockquote             |
| >> Text                  | Nested Blockquote      |

## [Emphasis](#markdown)

|               |                |
|---------------|----------------|
| \*\*Text\*\*  | Bold           |
| \_Text\_      | Italics        |
| \~\~Text\~\~  | Strike through |
| \<u>Text\</u> | Underline      |

## [Lists](#markdown)
### [Unordered Lists](#markdown)

```
- Start
    - Indented
```

### [Ordered Lists](#markdown)

```
1. First
2. Second
    1. First
    2. Second
```

- You can have all your ordered lists be set to 1. to automatically number them

```
1. First
1. Second
1. Third
1. etc
```

### [More Complex Lists](#markdown)
- If you are doing anything that involves complex lists it is recommended to use HTML

```
<ol>
    <li>First</li>
    <li>Second</li>
    <ol start="2">
        <li>Second</li>
    </ol>
</ol>
```

- If you want to start an unordered list indented you use html

```
<ul>
    <ul>
        <li>Indented Unordered List</li>
    </ul>
</ul>
```

## [Tables](#markdown)
- You need a new line on top and below any tables

```
Text

| Title 1  | Title 2  | Title 3 | etc |
| -------- | -------- | ------  | --- |
| Cell 1   | Cell 2   | Cell 3  | etc |

Text
```

|       |              |
|-------|--------------|
| `---` | Left align   |
| `--:` | Right align  |
| `:-:` | Center align |

## [Math](#markdown)
- Use `$ LaTeX $` for inline math expressions.
- Use `$$ LaTeX $$` for block math expressions.
    - You can also use ` ```math ` as well.

### [Special characters](#markdown)

| LaTeX   | Symbol    |
|---------|-----------|
| \pi     | $\pi$     |
| \infty  | $\infty$  |
| \Delta  | $\Delta$  |
| \alpha  | $\alpha$  |
| \theta  | $\theta$  |
| \lambda | $\lambda$ |
| \sigma  | $\sigma$  |
| \mu     | $\mu$     |
| \bigcap | $\bigcap$ |
| \bigcup | $\bigcup$ |

### [Exponents and subscripts](#markdown)

| LaTeX           | Symbol            |
|-----------------|-------------------|
| a_b             | $a_b$             |
| a^b             | $a^b$             |
| a_b^c           | $a_b^c$           |
| a \atop b       | $a \atop b$       |
| \underset{a}{b} | $\underset{a}{b}$ |
| \overset{a}{b}  | $\overset{a}{b}$  |

### [Comparisons](#markdown)

| LaTeX   | Symbol    |
|---------|-----------|
| >       | $>$       |
| <       | $<$       |
| \le     | $\le$     |
| \ge     | $\ge$     |
| =       | $=$       |
| \ne     | $\ne$     |
| \approx | $\approx$ |

### [Special operations](#markdown)

| LaTeX                         | Symbol                          |
|-------------------------------|---------------------------------|
| \frac{a}{b}                   | $\frac{a}{b}$                   |
| f'                            | $f'$                            |
| \sqrt[a]{b}                   | $\sqrt[a]{b}$                   |
| \sum_{k=1}^n a_k b_k          | $\sum_{k=1}^n a_k b_k$          |
| \int_0^{10} a b               | $\int_0^{10} a b$               |
| \underset{x \to \infty}{\lim} | $\underset{x \to \infty}{\lim}$ |

### [Trig](#markdown)

| LaTeX   | Symbol    |
|---------|-----------|
| \sin    | $\sin$    |
| \cos    | $\cos$    |
| \tan    | $\tan$    |
| \arcsin | $\arcsin$ |
| \arccos | $\arccos$ |
| \arctan | $\arctan$ |

### [Other](#markdown)

| LaTeX                    | Symbol                     |
|--------------------------|----------------------------|
| \textcolor{#22BB22}{abc} | $\textcolor{#22BB22}{abc}$ |
| \sout{abc}               | $\cancel{abc}$             |
| \leftarrow               | $\leftarrow$               |
| \rightarrow              | $\rightarrow$              |
| \leftrightarrow          | $\leftrightarrow$          |
| \dots                    | $\dots$                    |
| \vdots                   | $\vdots$                   |