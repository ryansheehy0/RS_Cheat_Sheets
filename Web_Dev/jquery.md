[Home](../README.md#web-dev)

# jQuery

[jQuery](https://jquery.com/)

A JavaScript library to make HTML document traversal and manipulation, event handling, animation, and Ajax(Asynchronous JavaScript and XML) easier to use.

```
// JS which tends to be put at the very end of the body tag before any custom JS
    <script src="https://code.jquery.com/jquery-3.7.0.js"></script>
```

See [here](https://releases.jquery.com/) for any up to date links.

<!-- TOC -->

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
- [jQuery UI](#jquery-ui)
	- [Interactions](#interactions)
		- [Droppable](#droppable)
	- [Widgets](#widgets)
		- [Autocomplete](#autocomplete)
	- [Effects](#effects)

<!-- /TOC -->

## [Selecting Elements](#jquery)

|             |                                                                        |
|-------------|------------------------------------------------------------------------|
| $(selector) | Gets an element from a CSS selector wrapped in "s, or a jQuery object. |

It is recommended to wrap any jQuery in `$(document).ready(` or `$(function () {` so that the code only executes once the DOM has fully loaded.

## [Changing HTML](#jquery)

|                   |                                                                           |
|-------------------|---------------------------------------------------------------------------|
| $("HTML")         | Creates an element from an HTML string. Automatically adds a closing tag. |
| .append(element)  | Inserts the element arg as the last child of the selected element.        |
| .prepend(element) | Inserts the element arg as the first child of the selected element.       |
| .remove()         | Removes the element.                                                      |
| .empty()          | Removes all the children of the element.                                  |

## [Modifying/Getting Contents](#jquery)

|                |                                              |
|----------------|----------------------------------------------|
| .text(content) | Sets or gets the text content of an element. |
| .html(content) | Sets or gets the HTML content of an element. |
| .val(value)    | Sets or gets the value of form elements.     |

## [Changing CSS](#jquery)

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

## [Manipulating Attributes](#jquery)

|                                 |                                              |
|---------------------------------|----------------------------------------------|
| .attr("attributeName", "value") | Sets or gets the value of an attribute.      |
| .removeAttr(attributeName)      | Removes an attribute from selected elements. |

## [Handling Events](#jquery)

|                          |                                                      |
|--------------------------|------------------------------------------------------|
| .click(handler)          | Attaches a click event handler to selected elements. |
| .on("eventType", handlerFunction)  | Attaches an event handler function to selected elements.      |
| .off("eventType", handlerFunction) | Removes an event handler function from selected elements.     |

```
// To dynamically add listeners to dynamically added elements.
    // You cannot get the element when the element isn't created in the DOM
$(Selector that is already created).on("event name", ".class", function(event){
    // Handle event
    // $(event.target) gets the element that gave the event in jquery.
})
```

## [Traversing the DOM](#jquery)

|                              |                                                     |
|------------------------------|-----------------------------------------------------|
| .find(selector)              | Finds descendants that match the provided selector. |
| .parent()                    | Gets the direct parent of selected elements.        |
| .siblings(optional selector) | Gets the siblings of selected element.              |
| .children(optional selector) | Gets the children of selected element.              |

You can use `.eq(index)` to get the element with the index. Ex: `$("#id").children().eq(0).text("test")`

.eq returns a jQuery instance and not a normal DOM element like with []

## [Animations](#jquery)

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

### [Optional Animation Arguments](#jquery)

```
$(selector).animation(duration, "easing", callback)
```

|          |                                                             |
|----------|-------------------------------------------------------------|
| duration | Duration of the animation in milliseconds.                  |
| easing   | Acceleration/deceleration effect of the animation.          |
| callback | A callback function is run when the animation is completed. |

## [AJAX Requests](#jquery)

|                            |                                        |
|----------------------------|----------------------------------------|
| $.ajax(options)            | Performs an asynchronous HTTP request. |
| $.get(url, data, success)  | Performs a GET request.                |
| $.post(url, data, success) | Performs a POST request.               |

```
$.ajax({url: "URL"})
.then(function (response){
    console.log(response)
    // Automatically converts the jsons to an object
})
```

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

## [Useful Functions](#jquery)

|                                              |                                                   |
|----------------------------------------------|---------------------------------------------------|
| $.each(element, function(index, element) {}) | Does something for each of the selected elements. |
| location.reload()                            | Reloads the page.                                 |

## [jQuery UI](#jquery)

[jQuery UI](https://jqueryui.com/)

```
// CSS which goes in the head before any custom CSS links
    <link rel="stylesheet" href="//code.jquery.com/ui/1.13.2/themes/base/jquery-ui.css">
// JS which tends to be put at the very end of the body tag before any custom JS and after the regular jQuery
    <script src="https://code.jquery.com/ui/1.13.2/jquery-ui.js"></script>
```

### [Interactions](#jquery)

| Interactions  | Description                                                                         |
|---------------|-------------------------------------------------------------------------------------|
| .draggable()  | Can drag an element around.                                                         |
| .droppable()  | Tends to be used with draggable. Can detect when one element is dropped on another. |
| .resizable()  | Can resize element.                                                                 |
| .selectable() | Can select elements individually or grouped by clicking and dragging.               |
| .sortable()   | Can drag and drop a items in a list.                                                |

#### [Droppable](#jquery)

```
$( "#draggable" ).draggable()
$( "#droppable" ).droppable({
  drop: function( event, ui ) {
    $( this ).addClass( "ui-state-highlight" )
    // Code when dropped
  }
});
```

### [Widgets](#jquery)

| Widget                    | Description                                                                     |
|---------------------------|---------------------------------------------------------------------------------|
| .accordion()              | Makes a div a collapsible panel with header and div children being the panels.  |
| .autocomplete()           | When typing into input it gives a dropdown menu with suggested autocompletions. |
| .button()                 |                                                                                 |
| .checkboxradio()          | A checkbox                                                                      |
| .controlgroup()           | Visually group related controls.                                                |
| .datepicker()             | Calendar to pick a date                                                         |
| .dialog()                 | A dialog window popup.                                                          |
| .menu()                   | Creates a menu that can be clicked through.                                     |
| .progressbar({value: 50}) | A progress bar with some percentage completed.                                  |
| .selectmenu()             | A menu that can be selected through                                             |
| .slider()                 | A slide able box along a bar.                                                   |
| .spinner()                | Can increment or decrement numerical values using up and down arrows.           |
| .tabs()                   | Sets of tabs.                                                                   |
| .tooltip()                | A small tooltip                                                                 |

#### [Autocomplete](#jquery)

```
var availableTags = [
  "C",
  "C++",
  "Java",
  "JavaScript",
  "Python",
];
$("#tags").autocomplete({
  source: availableTags
});
```

### [Effects](#jquery)

A list of effects can be found [here](https://jqueryui.com/effect/).
