CS372 Documents
==================================
This folder is for any documents you need to produce for the class.
For example, some assignments will ask your either theory or
interpretation questions.   You will put documents containing your
answer in this folder.

# Folder Structure

The folders in this repository are organized so that you can use CMake
to build for your favorite platform and IDE. 

The three top-level folders:
- `apps`: Applications go here.  A sample application named `listtest`
  is located in this folder and can be used as a template for
  assignments.
- `include`:  Header files will go here.  The `CMake` sample
  applications in the `apps` folder are setup to get the header files
  from this folder.
- `docs`: Here's where documentation such as this file will live.
  Certain assignments will ask you to collect and report data on the
  programs you've written.  Document that information in this folder.
  
# Working with `CMake`

`CMake` is a command-line utility.  However, it is aware of the common
IDEs such as Visual Studio, Code::Blocks, Xcode, and others.  CMake is
included as part of the extensions for Visual Studio and Visual Studio
Code.  If you're working with the full version of Visual Studio,  use
the links to the PowerShell CLI installed by Visual Studio.  MacOS users
will need to use the HomeBrew package manager to install `CMake`.

## Building with `CMake`

From the command-line, you first need to execute `CMake` to build the
"build system" for your application:

```sh
cmake -S . -B build.windows
```

This command looks for the CMake data files and your source code in the
current folder (the `-S` option on the "dot" folder) and creates the
build files in a folder named "build.windows".   Nothing specific about
this name, just a convention Your Glorious Instructor uses to keep
things organized.

Then you can build your application with the command:

```sh
cmake --build build.windows
```

If you're running on Windows, `Cmake` understands the Microsoft Build
format and will create Visual Studio project files for you.  Just point
Visual Studio at that folder.    

