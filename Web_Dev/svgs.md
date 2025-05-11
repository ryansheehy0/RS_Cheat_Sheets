[Home](../README.md#web-dev)

# SVGs

Scalable Vector Graphics is a XML namespace markup language used to describe 2d vector graphics. They are infinity scalable without loosing image quality.

In order to make a svg you need to wrap your element in

```HTML
<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
  <!-- SVG content goes here -->
</svg>
```

XML allows you to define your own custom elements and attributes, but in order to apply rules to these elements and attributes you need a XML namespace. The **xmlns** attribute is used to define this XML namespace and if left off there may be unexpected behaviors.

The `xmlns:xlink="http://www.w3.org/1999/xlink"` attribute allow you to use links and use in your svg.

<!-- TOC -->

- [Width, Height, and viewBox attributes](#width-height-and-viewbox-attributes)
- [Attributes for all SVG elements](#attributes-for-all-svg-elements)
	- [stroke-dasharray and stroke-dashoffset](#stroke-dasharray-and-stroke-dashoffset)
	- [transform](#transform)
- [Line](#line)
- [Rectangle](#rectangle)
- [Polygon](#polygon)
- [Polyline](#polyline)
- [Circle](#circle)
- [Ellipse](#ellipse)
- [Path](#path)
- [Text](#text)
- [Text path](#text-path)
- [Group](#group)
- [Link](#link)
- [Use](#use)
- [defs](#defs)
- [Image](#image)
- [ClipPath](#clippath)
- [Mask](#mask)
- [Linear Gradient](#linear-gradient)
- [Radial Gradient](#radial-gradient)
- [Pattern](#pattern)
- [Filter](#filter)
- [Information Elements](#information-elements)
	- [Metadata](#metadata)
	- [Description](#description)
	- [Title](#title)

<!-- /TOC -->

## [Width, Height, and viewBox attributes](#svgs)

The width and height properties define the width and height of the viewPort. The viewPort allows you to see a portion of an svg. Like looking through a window.
- The default units for width and height are pixels.

The viewBox is like the viewPort, but it allows for panning and zooming. Like looking through binoculars.

When defining the viewBox attribute it uses this format: `viewBox="min-x min-y width height"`
- min-x and min-y define the top left corner of viewBox and these are used for panning
- width and height are used for zooming.
	- width/height > width/height attributes then zoom out
	- with/height < width/height attributes then zoom int
- You should only use the viewBox attribute when the width and height attributes are defined.

## [Attributes for all SVG elements](#svgs)
- fill: Defines the fill color
- stroke: Defines the stroke color
- stroke-width
- opacity
- stroke-opacity
- fill-opacity
- id and class
- Different event attributes
	- onclick, onmouseover, onmouseout, onload, etc
- accessible rich internet applications(aria-)

### [stroke-dasharray and stroke-dashoffset](#svgs)
**stroke-dasharray** is an array of values which defines the lengths of alternating dashes and gaps. It follows the pattern of line length then gap length.

- Ex 1: `stroke-dasharray="10 5"` line length of 10 followed by gap length of 5. This repeats for the whole SVG element.
- Ex 2: `stroke-dasharray="2 6 8"` line 2 -> gap 6 -> line 8 -> gap 2 -> line 6 -> gap 8 -> repeat.

**stroke-dashoffset** rotates the lines and gaps. If it's positive it rotates it clockwise, if negative counter clockwise.

### [transform](#svgs)

- translate(x, y)
	- Moves the svg according to the top left
- rotate(degrees)
	- Rotates from the top left
- scale(ratio)
	- Scales by the ration from the top left
- skewX(angle) and skewY(angle)
	- Skews an element along the X or Y axis
- matrix(a, b, c, d, e, f)

The order of transforms matters
- `transform="translate(10, 10) rotate(45)`
	- Moves then rotates from the new origin set by translate
- `transform="rotate(45) translate(10, 10)`
	- Rotates from the original origin and then translates. The translation is also rotated.

## [Line](#svgs)
`<line x1="" y1="" x2="" y2=""/>`

## [Rectangle](#svgs)
`<rect x="" y="" width="" height="" />`

## [Polygon](#svgs)
Used to create a closed shape by connecting the first and last points.

- Polygon automatically connects the first and last points.

`<polygon points="x1,y1 x2,y2 x3,y3" />`

- Lines are drawn at each of the points.
- Ex: `<polygon points="10,10 10,50 50,50"/>` draws a triangle

## [Polyline](#svgs)
Used to create an open shape. There is no connecting between the last and first points.

`<polyline points="x1,y1 x2,y2 x3,y3 />`

## [Circle](#svgs)
`<circle cx="" cy="" r="" />`

## [Ellipse](#svgs)
`<ellipse cx="" cy="" rx="" ry="" />`

## [Path](#svgs)
Used to draw lines, arcs, quadratics, and cubic bezier curves.

- The path element used a virtual pen. Move the pen then draw with the pen. When a drawing element is used, it moves the virtual pen.
	- `Mx,y` moves the pen
	- `Lx,y` draws a line to x and y
		- `Hdistance` draws a line on the x axis that distance
		- `Vdistance` draws a line on the y axis that distance
	- `Arx,ry xRotation largeArcFlag,sweepFlag x,y` draws an elliptical arc
		- rx and ry are the radius in the x or y axis.
		- xRotation rotates the elliptical arc across the x axis
			- An xRotation of 45 rotates the elliptical arc from _ to \
		- largeArcFlag of 1 pics the arc that is that large of the 2
		- sweepFlag of 1 put the arc in the clockwise and 0 in the counterclockwise directions.
		- x and y are the ending points
	- `Qcx,cy x,y` draws the quadratic equations
		- cx and cy define the control point
		- x and y defines the end point
	- `Ccx1,cy1 cx2,cy2 x,y` draws the cubic bezier curve which has 2 more control points than the quadratic equation.
		- cx1,cy1 and cx2,cy2 defines the 2 other control points
		- x and y defines the end point
	- `Z` draws a line from the starting point to the end point of the path. If the start and end point are the same it closes the path.

- Any commands which are uppercase letters are absolutely positioned while any commands which are lowercase letters are relatively positioned.
	- Relatively positioned means positioned from the last command/virtual pen position.
	- Ex: `M100,100 L150,150` draws line from 100,100 to 150,150
	- Ex: `M100,100 l150,150` draws line from 100,100 to 250,250

```HTML
<path d="M100,100 L150,150 L150,200
	A50,50 0 1,0 100,150
	Q20,250 200,300
	C200,400 375,350 400,300
	Z
"/>
```

## [Text](#svgs)

```HTML
<text x="" y="">
	Text
	<tspan fill="red">red</tspan>
</text>
```

The origin on the text is the bottom left.

You can have other attributes:
- `font-size=""`
- `font-family=""`
- etc

Tspan is used to style text independently from the other text.

## [Text path](#svgs)
Sets a path where text can be rendered. This allows text to be curved.

```HTML
<text>
  <textPath href="#path">Curved Text</textPath>
</text>
```

## [Group](#svgs)
The group elements allows you to group different svg elements together in order to style them together.

```HTML
<g>
	<!-- Grouped SVG elements -->
</g>
```

## [Link](#svgs)
Allows you to have a hyperlink inside your svg. You need the xmlns:xlink attribute set in your svg in order for this to work.

```HTML
<a xlink:href="https://example.com">
	<text x="50" y="50" fill="white" text-anchor="middle" alignment-baseline="middle">Click me</text>
</a>
```

## [Use](#svgs)
References another SVG element defined with the id attribute. You need the xmlns:xlink attribute set in your svg in order for this to work.

`<use xlink:href="#existingElement" />`

## [defs](#svgs)
Defines reusable SVG elements. In order to give the definition a nation you have to use the id attribute.

```HTML
<defs>
	<linearGradient id="grad1" x1="0%" y1="0%" x2="100%" y2="0%">
		<stop offset="0%" style="stop-color:rgb(255,255,0);stop-opacity:1" />
		<stop offset="100%" style="stop-color:rgb(255,0,0);stop-opacity:1" />
	</linearGradient>
</defs>
<ellipse cx="100" cy="70" rx="85" ry="55" fill="url(#grad1)" />
```

## [Image](#svgs)
Displays raster images

`<image x="" y="" width="" height="" href="" />`

## [ClipPath](#svgs)
Creates a path which can hide or show portions of other elements.

```HTML
<clipPath id="clip">
  <rect width="50" height="50" />
</clipPath>
```

## [Mask](#svgs)
Defines an image mask which can hide or show portions of other elements.

```HTML
<mask id="mask">
  <!-- Define mask elements here -->
</mask>
```

What is the difference between clipPath and mask?

## [Linear Gradient](#svgs)

```HTML
<linearGradient x1="0%" y1="0%" x2="100%" y2="0%">
	<stop offset="0%" style="stop-color:rgb(255,255,0);stop-opacity:1" />
	<stop offset="100%" style="stop-color:rgb(255,0,0);stop-opacity:1" />
</linearGradient>
```

- x1 and y1 define the first point
- x2 and y2 define the end point
- The linear gradient flows from the first point to the end point

## [Radial Gradient](#svgs)

```HTML
<radialGradient cx="50%" cy="50%" r="50%" fx="50%" fy="50%">
	<stop offset="0%" style="stop-color:rgb(255,255,255);stop-opacity:0" />
	<stop offset="100%" style="stop-color:rgb(0,0,255);stop-opacity:1" />
</radialGradient>
```

What is fx and fy?

## [Pattern](#svgs)
A pattern element which can be redrawn at repeated x and y coordinates intervals(tiled).

```HTML
<defs>
	<pattern id="star" viewBox="0,0,10,10" width="10%" height="10%">
		<polygon points="0,0 2,5 0,10 5,8 10,10 8,5 10,0 5,2" />
	</pattern>
</defs>

<circle cx="50" cy="50" r="50" fill="url(#star)" />
```

## [Filter](#svgs)
Apply a filter, defined by grouping filter primitives, to svg elements.

```HTML
<filter id="blurMe">
	<feGaussianBlur stdDeviation="5" />
</filter>

<circle cx="170" cy="60" r="50" fill="green" filter="url(#blurMe)" />
```

| Filter primitive    | Description |
|---------------------|-------------|
| feBlend             |             |
| feColorMatrix       |             |
| feComponentTransfer |             |
| feComposite         |             |
| feConvolveMatrix    |             |
| feDiffuseLighting   |             |
| feDisplacementMap   |             |
| feDropShadow        |             |
| feFlood             |             |
| feGaussianBlur      |             |
| feImage             |             |
| feMerge             |             |
| feMorphology        |             |
| feOffset            |             |
| feSpecularLighting  |             |
| feTile              |             |
| feTurbulence        |             |

## [Information Elements](#svgs)

### [Metadata](#svgs)

```HTML
<metadata>
  <!-- Include metadata information here -->
</metadata>
```

### [Description](#svgs)

`<desc>This is an example SVG document.</desc>`

### [Title](#svgs)

`<title>SVG Document Title</title>`


Questions
- clipPath
- mask
- radial gradient fx and fy
- filters