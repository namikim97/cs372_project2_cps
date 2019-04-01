# C++ to Post Script Program
Nami Kim, Alex Lewandowski, Simeon Ng  
For UAF CS372 Software Construction Spring 2019.

### Description:
Compiling all files will output sample PostScript code to 'testShapes.ps' which can be interpreted by a PostScript viewer. 

### Files:
* cps.cpp - Main File. Includes a shapes-to-PostScript testing/drawing strategy with page.cpp/h.
* cpsTests.cpp - Catch2 tests for Shape classes.
* shapes.cpp/h - Source/Header file for Shape classes. Contains derived basic shapes and rainbow snowmen.
* compound.cpp/h - Source/Header file for Shape classes. Contains derived compound shapes.
* page.cpp/h - Source/Header file for Page class. Contains framework for drawing shapes to a page in PostScript.
* human.cpp/h - Source/Header file for Human class. Class for drawing randomized figures.
