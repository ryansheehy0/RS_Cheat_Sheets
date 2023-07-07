[Home](./README.md)

# jQuery
A JavaScript library to make HTML document traversal and manipulation, event handling, animation, and Ajax(Asynchronous JavaScript and XML) easier to use.

The JS should be <style> before your custom JS file.

## Table of Contents

- [Table of Contents](#table-of-contents)
- [Selecting Elements](#selecting-elements)
- [Changing HTML](#changing-html)
- [Modifying/Getting Contents](#modifyinggetting-contents)
- [Changing CSS](#changing-css)
- [Manipulating Attributes](#manipulating-attributes)
- [Handling Events](#handling-events)
- [Traversing the DOM](#traversing-the-dom)
- [Animations](#animations)
    - [Optional Animation Arguments](#optional-animation-arguments)
- [AJAX Requests](#ajax-requests)
- [Useful Functions](#useful-functions)

## Selecting Elements

|             |                                                                        |
|-------------|------------------------------------------------------------------------|
| $(selector) | Gets an element from a CSS selector wrapped in "s, or a jQuery object. |


It is recommended to wrap any jQuery in `$(document).ready(` or `$(function () {` so that the code only executes once the DOM has fully loaded.

## Changing HTML

|                   |                                                                           |
|-------------------|---------------------------------------------------------------------------|
| $("HTML")         | Creates an element from an HTML string. Automatically adds a closing tag. |
| .append(element)  | Inserts the element arg as the last child of the selected element.        |
| .prepend(element) | Inserts the element arg as the first child of the selected element.       |
| .remove()         | Removes the element.                                                      |
| .empty()          | Removes all the children of the element.                                  |

## Modifying/Getting Contents

|                |                                              |
|----------------|----------------------------------------------|
| .text(content) | Sets or gets the text content of an element. |
| .html(content) | Sets or gets the HTML content of an element. |
| .val(value)    | Sets or gets the value of form elements.     |

## Changing CSS

|                                    |                                               |
|------------------------------------|-----------------------------------------------|
| .addClass(className)               | Adds a CSS class to selected elements.        |
| .removeClass(className)            | Removes a CSS class from selected elements.   |
| .toggleClass(className)            | Toggles a CSS class on selected elements.     |
| .css("property", "property value") | Sets the css property from selected elements. |

```
Set multiple CSS properties
$(selector).css({
    "property1": "value1",
    "property2": "value2",
    "property3": "value3"
})
```

Often times a jass.css file is used which has a lot of CSS utility classes which can be added and removed with jQuery to apply custom CSS easily.

## Manipulating Attributes

|                                 |                                              |
|---------------------------------|----------------------------------------------|
| .attr("attributeName", "value") | Sets or gets the value of an attribute.      |
| .removeAttr(attributeName)      | Removes an attribute from selected elements. |

## Handling Events

|                          |                                                      |
|--------------------------|------------------------------------------------------|
| .click(handler)          | Attaches a click event handler to selected elements. |
| .on("eventType", handlerFunction)  | Attaches an event handler function to selected elements.      |
| .off("eventType", handlerFunction) | Removes an event handler function from selected elements.     |

## Traversing the DOM

|                              |                                                     |
|------------------------------|-----------------------------------------------------|
| .find(selector)              | Finds descendants that match the provided selector. |
| .parent()                    | Gets the direct parent of selected elements.        |
| .siblings(optional selector) | Gets the siblings of selected element.              |
| .children(optional selector) | Gets the children of selected element.              |

You can use `.eq(index)` to get the element with the index. Ex: `$("#id").children().eq(0).text("test")`

.eq returns a jQuery instance and not a normal DOM element like with []

## Animations

|               |                                                 |
|---------------|-------------------------------------------------|
| .show()       | Sets CSS property display to its default value. |
| .hide()       | Sets CSS property display to none.              |
| .toggle()     | Toggles .show() and .hide()                     |
| .fadeIn()     | Animates the opacity from 0 to 1.               |
| .fadeOut()    | Animates the opacity from 1 to 0.               |
| .fadeToggle() | Toggles between .fadeIn and .fadeOut            |
| .slideDown()  | Animates the height from 0 to default.          |
| .slideUp()    | Animates the height from default to 0.          |
| .slideToggle()    | Toggles .slideDown and .slideUp          |

### Optional Animation Arguments

```
$(selector).animation(duration, "easing", callback)
```

|          |                                                             |
|----------|-------------------------------------------------------------|
| duration | Duration of the animation in milliseconds.                  |
| easing   | Acceleration/deceleration effect of the animation.          |
| callback | A callback function is run when the animation is completed. |

## AJAX Requests

|                            |                                        |
|----------------------------|----------------------------------------|
| $.ajax(options)            | Performs an asynchronous HTTP request. |
| $.get(url, data, success)  | Performs a GET request.                |
| $.post(url, data, success) | Performs a POST request.               |

```
$.ajax({
  url: "https://api.example.com/data",
  method: "GET",
  data: { id: 123 },
  success: function(response) {},
  error: function(xhr, status, error) {
        // The xhr is the XMLHttpRequest
        // xhr.status is the HTTP status code
        // xhr.statusText is the status message
    }
});
```

```
$.get("https://api.example.com/data", { id: 123 }, function(response) {});
```

```
$.post("https://api.example.com/data", { name: "John", age: 25 }, function(response) {});
```

## Useful Functions

|                                              |                                                   |
|----------------------------------------------|---------------------------------------------------|
| $.each(element, function(index, element) {}) | Does something for each of the selected elements. |
| location.reload()                            | Reloads the page.                                 |