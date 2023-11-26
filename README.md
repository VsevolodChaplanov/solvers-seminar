# SLAE solvers project

To prepare a library of matrix solvers for systems of linear algebraic equations for further use in solving homogeneous partial differential equations.

## Main problems to be solved:

* Prepare a project for inclusion in the project of a general solver of Navier Stokes equations
* To formalize the dependencies of the project
* Realize basic algorithms for solving SLAEs
* Realize basic utility functions for working with matrices 

# Tasks

Tasks within the code will be labeled __# TASK__, tasks of higher complexity will be labeled # HARDMODE. 

Tasks can be either writing C++ code, cmake, devops, etc.

## Help and notes

In some places when there are notes to help at first guide the project

Best practices and parsing of mistakes will be dealt with in the seminar sessions


# Best practices and parsing of mistakes will be dealt with in the seminar sessions

The library consists of:

* library code that you will need to complete, directory slae/

    * the include directory contains user interfaces for the library

        * the utility/ directory contains general functions for working with matrices and vectors, you can extend these functions as needed.

        * solvers/ directory contains the solver interface as well as the solver implementations themselves, here you add the solver implementation tasks that are separated from each other.

    * the src/ directory contains resource files

* examples of how to use the functions and classes you have written, examples/ directory.

# Grading system

* Implementing the solver - 15 points
* Writing tests and passing them - 5 points
* Passing code review - 10 points
* Implementing utilitarian functions when using them in other modules - 5 points
* Writing an example of using your solver/function - 5 points.

Additional points

* Add cmake file for connecting sanitizers to the project - 3 points for each (threads, address, memory, ub).

* Add cmake file for IWYU - 2 points.

* Add cmake file for cross-compiler and cross-platform development - 20 points (additionally fix other cmake files)

* Add precompiled headers support to the project - 5 points

* Add cross-platform and cross-compiler export file generation to the project - 3 points.

* Add to the project the ability to build the project as a dynamic library - 10 points.

Additional points for fixing errors

* Find an error and open an issue - 2 points.
* Fix an error in an issue - 3 points.

## How to turn in your work

* Before making changes to the project, make a separate branch in git (branch_name - carries information about your task)

```bash
git checkout -b <branch_name>
```

* Make changes

* Push to the project's github repository
```bash
git push -u
```

* Open Merge request, put teacher as reviewer.