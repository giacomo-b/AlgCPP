# AlgCPP

AlgCPP, pronounced algs-CPP, is a collection of common (and not-so-common) algorithms written in C++.

Most algorithms are based on Wayne and Sedgewick's [Algorithms](https://www.coursera.org/learn/algorithms-part1) course implementations, albeit with several modification:

-   The most obvious difference is that this library uses C++, while the original course uses Java.
-   The focus of this library is on flexibility and generality. You should be able to use these algorithms as they are for most applications. Should you need to make changes, abstract classes are provided to make sure the interface is consistent. This also makes it easy to experiment with several variations.
-   Since the development of all algorithms and classes is test-driven, this library makes it trivial to experiment with your own implementations. In fact, it is sufficient to make the code modifications and launch the unit tests to verify that the code still works as expected.

Furthermore, this repo:

-   Makes use of modern [CMake](https://cmake.org/) to simplify the build process and compilation across multiple platforms
-   Makes use of [doctest](https://github.com/onqtam/doctest) for unit testing
-   Implements code coverage reports
-   Is documented using [Doxygen](http://www.stack.nl/~dimitri/doxygen/), to make it as accessible as possible

## Code structure

``` text
.
├── CMakeLists.txt
├── apps
│   └── example_app.cpp
├── external
│   └── doctest (submodule)
├── include/algs
│   ├── algs.h
│   ├── example_algorithm.h
│   └── exampleConfig.h.in
│   └── utils
├── src
│   └── example_algorithm.cpp
└── tests
    ├── example_algorithm_tests.cpp
    ├── example_algorithm_integration_tests.cpp
    └── main.cpp
```

### Add your algorithms (and tests!)

If you add your own algorithm, you should put the headers inside [include/algs/](include/algs/) and the source files (if any) inside [src/](src/).

To add tests for your algorithms, just create additional source files inside [tests/](tests/) and they will be compiled to the target `unit_tests` by default. All you need to do is `#include "doctest.h"` to your tests.

### Create your applications

The `apps` folder is meant for example applications. For example, one of the [Algorithms](https://www.coursera.org/learn/algorithms-part1) course assignment is a solution to the percolation problem. Therefore, you will find `percolation.cpp` inside `apps`. Feel free to add any example you find interesting.

If you add a new executable, say `app/example.cpp`, you need to add the following two lines to [CMakeLists.txt](CMakeLists.txt): 

``` cmake
add_executable(example app/example.cpp)
target_link_libraries(example PRIVATE ${LIBRARY_NAME})
```

This will create a new target `example`.

## Running the code

### Building

To build the project, create a new `build` directory and run `cmake` inside it (choosing whether you want a Debug, Release, or Coverage configuration):

```bash
> mkdir build && cd build
> cmake .. -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release]
```

### Compiling applications

On Linux systems, use `make` to build the desired target:

```bash
> make
> ./percolation
```

### Running tests, generating coverage reports

To run the code tests just do:

```bash
> make test
```

If you prefer, you can also make a specific test target and run it, e.g.:

```bash
> make unit_tests
> ./unit_tests
```

### Generating coverage reports

```bash
> make coverage
```

### Generating Doxygen documentation

```bash
> make doc
```