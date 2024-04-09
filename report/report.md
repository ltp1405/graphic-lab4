---
title: "Report for lab 03"
---

# Lab Result
- Implement Transform class, which is a class representing a 2D transformation that 
can be combined.
- Implement a simple 2D polygon drawing application using the implemented Transform class.

# Implementation
## Transform class
- The Transform class is implemented using the underlying matrix representation.
- Operations such as translation, rotation, and scaling are implemented.
- The class also supports the combination of transformations through `*` operator.

## Poygon transformation
- Transform is actually not applied directly to the polygon. Instead, the transformation
is stored and accumulated in the `transform` variable. By the time the polygon is drawn,
point-containing checked, the transformation is applied to the polygon. This is done
to reduce accumulated error when applying multiple transformations.

## 2D Polygon Drawing Application
- The application is implemented using OpenGL and Glut.
- The application allows the user to draw a polygon by enable drawing Polygon mode.
- The user can also apply transformations to the polygon by left-clicking the shapes
and using hotkeys to apply transformations as required by the lab description.
