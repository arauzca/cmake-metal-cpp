# [<img src="/assets/cmake.svg" style="height:45px; float:left; margin-right:2px" />](https://cmake.org "CMake") cmake metal-cpp

## About

---

**metal-cpp** is a low overhead and header only C++ interface for Metal that helps developers add Metal functionality to graphics applications that are written in C++ (such as game engines). **metal-cpp** removes the need to create a shim and allows developers to call Metal functions directly from anywhere in their existing C++ code.

**cmake-metal-cpp** provides a way to integrate **metal-cpp** to projects using CMake. The project can be configured to provide the headers of Metal-cpp or to automatically create a single header file using the script provided by Apple.

## How to build

---

- Clone this project to the source of your project or add it as [submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules).
- In your `CMakeLists.txt` file add:

```cmake
add_subdirectory(cmake-metal-cpp)
```

- Add the  compile definitions and link the library provided by **cmake-metal-cpp**. For instahce if you have an executable `my-target`:

```cmake
target_compile_definitions(my-target PUBLIC ${METAL_CPP_COMPILE_DEFS})
target_link_libraries(my-target metal-cpp)
```

## Options

---

This project provides two different options for the creation of the headers, individual headers or a single header file. The extensions AppKit and MetalKit, which are enabled by default can be excluded.

- `MAKE_METAL_SINGLE_HEADER`: Use metal-cpp as a single-header include in your project. Default value: `OFF`.
- `INCLUDE_APPKIT_EXTENSION`: Include the AppKit extension from metal-cpp-extensions. Default value: `ON`.
- `INCLUDE_METALKIT_EXTENSION`: Include the MetalKit extension from metal-cpp-extensions. Default value: `ON`.
- `ENABLE_BETA`: For beta developers targeting macOS13. Defatul value: `OFF`.

## How to use the headers

---

In your source code you only need to add the headers (or header if the single header option is on) and start coding.

- Individual headers:

```c++
#include <Metal/Metal.hpp>
#include <AppKit/AppKit.hpp>
#include <MetalKit/MetalKit.hpp>
```

- Single header file:

```c++
#include <Metal.hpp>
```

## Credits

---

**CMake Logo**: Cmake team. The original uploader was [Francesco Betti Sorbelli](https://it.wikipedia.org/wiki/Utente:Francesco_Betti_Sorbelli) at [Italian Wikipedia](https://it.wikipedia.org/wiki/Pagina_principale). Vectorized by Magasjukur2 [CC BY 2.0](https://creativecommons.org/licenses/by/2.0/).

**metal-cpp**: Copyright © 2021 Apple Inc.

**metal-cpp-beta**: Copyright © 2022 Apple Inc.

**metal-cpp-extensions**: Copyright © 2021 Apple Inc.

## Disclaimer

---

I do not own any of the **metal-cpp** works, however I have modified some of the header files with preprocessing directives in favor of automating the creation of the metal single header.
