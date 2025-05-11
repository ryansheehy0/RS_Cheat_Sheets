[Home](../README.md#web-dev)

# HTML
- The purpose of this cheat sheet is to provide an overview of the most useful HTML elements.

<!-- TOC -->

- [Start of HTML](#start-of-html)
- [Text Formatting](#text-formatting)
- [Linking and Embedding](#linking-and-embedding)
	- [Map](#map)
- [Lists](#lists)
- [Tables](#tables)
- [Forms](#forms)
- [Grouping](#grouping)
- [Self Closing Tags](#self-closing-tags)
- [Comments](#comments)
- [Details](#details)
- [Dialog](#dialog)
- [HTML entities](#html-entities)
- [Attributes](#attributes)
- [Inline elements vs block elements](#inline-elements-vs-block-elements)
- [CSS in HTML](#css-in-html)
- [JavaScript in HTML](#javascript-in-html)

<!-- /TOC -->

## [Start of HTML](#html)

```HTML
<!DOCTYPE html>
<html>
    <head> <!-- Contains metadata -->
        <title>Title</title>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    </head>
    <body> <!-- Contains the visible content -->
    </body>
</html>
```

You can add an favicon in the top of the tab by adding this to the head:

```HTML
<link rel="icon" href="/favicon.svg" >
```

## [Text Formatting](#html)

```HTML
<h1>Heading</h1>        <!-- Headings from 1 to 6 -->
<p>Paragraph</p>
<strong>Bold</strong>
<em>Italic</em>
<sup>Superscript</sup>
<sub>Subscript</sub>
<del>Crossed out</del>
<ins>Underline</ins>
<code>Code block</code>
<mark>Highlighting</mark>
```

## [Linking and Embedding](#html)

```HTML
<a href="URL/filepath">Link</a>
<a href="URL/filepath" target="_blank">Link in new tab</a>
<img src="URL/filepath" alt="Description">
    <!-- "Image of" is said before alt texts. -->
<audio controls> <!-- Little play bar for playing audio -->
  <source src="file.mp3" type="audio/mpeg">
</audio>
<video controls>
  <source src="file.mp4" type="video/mp4">
</video>
<iframe src="url" title="description"></iframe> <!-- Embed other html in your page -->
<!-- Used for embedding other files like PDFs -->
<embed src="/pdfFile.pdf" type="application/pdf"/>
```

### [Map](#html)

Map allows you to click in specific spots inside of an image and go to a specific link.

```HTML
<img src="workplace.jpg" alt="Workplace" usemap="#workmap" width="400" height="379">

<map name="workmap">
  <area shape="rect" coords="34,44,270,350" alt="Computer" href="computer.htm">
  <area shape="rect" coords="290,172,333,250" alt="Phone" href="phone.htm">
  <area shape="circle" coords="337,300,44" alt="Cup of coffee" href="coffee.htm">
</map>
```

## [Lists](#html)

```HTML
<ul>                 <!-- Unordered list -->
  <li>Item 1</li>    <!-- List item -->
  <li>Item 2</li>
</ul>
<ol>                 <!-- Ordered list -->
  <li>Item 1</li>
  <li>Item 2</li>
</ol>

<!-- Nested lists -->

<ul>
  <li>Item 1</li>
  <li>Item 2
    <ul>
      <li>Sub-item 1</li>
      <li>Sub-item 2</li>
    </ul>
  </li>
</ul>
```

## [Tables](#html)

```HTML
<table>              <!-- Defines a table -->
  <tr>               <!-- Table row -->
    <th>Header 1</th> <!-- Table header cell -->
    <th>Header 2</th>
  </tr>
  <tr>
    <td>Data 1</td>   <!-- Table data cell -->
    <td>Data 2</td>
  </tr>
</table>
```

## [Forms](#html)

```HTML
<form action="/submit" method="post">  <!-- Defines a form. Method can only be get and post. -->
  <input type="text" name="username" placeholder="Username">  <!-- Text input -->
  <input type="password" name="password" placeholder="Password">  <!-- Password input -->
  <input type="submit" value="Submit">  <!-- Submit button -->
  <input type="checkbox" name="agree" id="agree">  <!-- Checkbox -->
  <label for="agree">I agree to the terms</label>

  <input type="hidden" name="hiddenValue" value="hidden value sent"> <!-- Sends a hidden value when sending the form -->

  <input type="radio" name="gender" value="male">  <!-- radio button where you can only click the circle -->
  <label for="male">male</label>
  <input type="radio" name="gender" value="female">
  <label for="female">female</label>

  <input type="radio" name="gender" id="male">  <!-- radio button where you can click the label and the circle-->
  <label for="male">male</label>
  <input type="radio" name="gender" id="female">
  <label for="female">female</label>

  <textarea name="message" placeholder="Message"></textarea>  <!-- Textarea used for multi-line text input. -->

  <datalist> <!-- Like a dropdown menu, but you can also type -->
    <option value="Edge">
    <option value="Firefox">
    <option value="Chrome">
    <option value="Opera">
    <option value="Safari">
  </datalist>

  <select name="country">  <!-- Select dropdown -->
    <optgroup label="North America"> <!-- Sub title in the options dropdown-->
      <option value="us">United States</option>
      <option value="ca">Canada</option>
    </optgroup>
  </select>
</form>
```

Forms by default send a http POST request with the endpoint in action. The server responds with a html page to be loaded after the submission of the post.

## [Grouping](#html)

```HTML
<div>Container</div>
<span>Inline</span>
<header>Header</header>
<main>Main content</main>
<footer>Footer</footer>
<nav>Navigation menu</nav>
<section>Section of a document</section>
<article>Self contained article</article>
<aside>Side Content</aside>
<button>Click Me!!!</button>
```

## [Self Closing Tags](#html)

```HTML
<br>    <!-- Line break -->
<hr>    <!-- Horizontal rule/line -->
<wbr>   <!-- Word break. The browser can line wrap at that point if necessary. -->
```

## [Comments](#html)

```HTML
<!-- Comments -->
```

## [Details](#html)
Small dropdown that can be opened and closed.

```HTML
<details>
  <summary>Epcot Center</summary>
  <p>Epcot is a theme park at Walt Disney World Resort featuring exciting attractions, international pavilions, award-winning fireworks and seasonal special events.</p>
</details>
```

## [Dialog](#html)
Dialogs are used for modals

```HTML
<dialog>
  <button autofocus>Close</button>
  <p>This modal dialog has a groovy backdrop!</p>
</dialog>
<button>Show the dialog</button>
```

```CSS
::backdrop { /* Styles the background of the dialog when it's popped up */
  opacity: 0.75;
}
```

```javascript
const dialog = document.querySelector("dialog")
const showButton = document.querySelector("dialog + button")
const closeButton = document.querySelector("dialog button")

showButton.addEventListener("click", () => {
  dialog.showModal()
})

closeButton.addEventListener("click", () => {
  dialog.close()
})
```

## [HTML entities](#html)
- Used to represent reserved characters within HTML.

| Text    | Symbol                 |
|---------|------------------------|
| &lt\;   | <                      |
| &gt\;   | >                      |
| &amp\;  | &                      |
| &quot\; | "                      |
| &apos\; | '                      |
| &copy\; | &copy;                 |
| &reg\;  | &reg;                  |
| &deg\;  | &deg;                  |
| &emsp\; | tab that doesn't break |

## [Attributes](#html)

|          |                                                                          |
|----------|--------------------------------------------------------------------------|
| class    | Elements can have multiple classes and multiple elements can have the same class. |
| id       | A unique identifier. 2 or more elements cannot have the same id.         |
| style    | Inline CSS.                                                              |
| title    | Additional info that is often displayed as a tooltip.                    |
| disabled | Disables user interaction.                                               |

## [Inline elements vs block elements](#html)
- Block elements take up the whole line
- Inline elements just are inline
- You can force inline or block with CSS

## [CSS in HTML](#html)
- Put into the `<head>` of the HTML so the browser can style before it paints the page.

```HTML
<link rel="stylesheet" type="text/css" href="style.css" />
```

## [JavaScript in HTML](#html)
- Put at the very end of the HTML `<body>` so the JavaScript can interact with the HTML elements.

```HTML
<script src="script.js"></script>
```

- You can also use the `defer` keyword and put in in the header where it will only be loaded after the dom is created.

```HTML
<script src="script.js" defer></script>
```

- `noscript` is ran when the user doesn't have javascript enabled.

```HTML
<noscript>Your browser does not support JavaScript!</noscript>
```
