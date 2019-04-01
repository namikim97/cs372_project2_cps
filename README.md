# C++ to PostScript Library
Nami Kim, Alex Lewandowski, Simeon Ng  
For UAF CS372 Software Construction Spring 2019.

### Description:
* This is a C++ to PostScript library that allows users to define shapes from our shape language in C++, and output drawings of the shapes in PostScript.  
* Compiling the listed files will output sample PostScript code to 'testShapes.ps' which can be interpreted by a PostScript viewer.

### Shape Language + Examples:
##### Basic Shapes:
* **Circle**(double **radius**) - Creates a circle with a given radius.
* **Polygon**(int **numSides**, double **sideLength**) - Creates a polygon with given number of sides and side length.
* **Rectangle**(double **width**, double **height**) - Creates a rectangle with given width and height.
* **Spacer**(double **width**, double **height**) - Creates a spacer(rectangle) with given width and height that is not drawn to the page.
* **Square**(double **sideLength**) - Creates a square with given side length.
* **Triangle**(double **sideLength**) - Creates a triangle with given side length.
##### Compound Shapes:
Compound shapes can be built from basic shapes or compound shapes themselves.
* **Rotated**(Shape **shape**, double **RotationAngle**) - Creates a given shape rotated counterclockwise by the given angle.
* **Scaled**(Shape **shape**, double **horScale**, double **vertScale**) - Creates a given shape scaled horizontally and vertically by the given factors.  
* **Layered**(std::initializer_list<std::shared_ptr<Shape>>**shape**) - Creates a shape consisting of the given shapes around the current point.  
* **Vertical**(std::initializer_list<std::shared_ptr<Shape>>**shape**) - Creates a shape consisting of the given shapes grouped vertically.
* **Horizontal**(std::initializer_list<std::shared_ptr<Shape>>**shape**) - Creates a shape consisting of the given shapes grouped horizontally.

### Files:
* cps.cpp - Main File. Includes a shapes-to-PostScript testing/drawing strategy with page.cpp/h.
* cpsTests.cpp - Catch2 tests for Shape classes.
* shapes.cpp/h - Source/Header file for Shape classes. Contains derived basic shapes and rainbow snowmen.
* compound.cpp/h - Source/Header file for Shape classes. Contains derived compound shapes.
* page.cpp/h - Source/Header file for Page class. Contains framework for drawing shapes to a page in PostScript.
* human.cpp/h - Source/Header file for Human class. Class for drawing randomized figures.
