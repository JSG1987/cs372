Build Instructions for Windows, macOS, and Linux
==================================
The convention with CMake is that you are do out-of-source builds.  That
means that you never build within the source directory.  You put build
products in a separate area not stored in the version control
system. Why not in version control?  As those are all generated products
which you can recreate.


You need to do two things to get started building an application using
`cmake`.  You first use `cmake` to build the project files appropriate
for your platform.   Then you can either use the cmake to build the
project in batch mode or use your favorite IDE.

Here's instructions on how to build for each platform:

## Linux::
- Make certain you are in the project's top level folder.  You should
  have a `source` at this level for the project.
- Run `cmake -S . -B build.linux` to rebuild the build system in the
  folder `build.linux`.
- Then run `cmake --build build.linux` to build the application

## macOS::
- Make certain you are in the project's top level folder.  You should
  have a `source` at this level for the project.
- Here you have an option
  - Run `cmake -S . -B build.macos` to rebuild the build system in the
  folder `build.macos` using UNIX-style makefiles.
  - Run `cmake -S . -B build.macos -G Xcode` to rebuild the build system
    in the folder `build.macos` using Xcode project files.
- Then run `cmake --build build.macos` to build the application in batch
  mode or load the Xcode project in the `build.macos` folder if you
  generated the build system for Xcode.

## Windows
- Make certain you are in the project's top level folder.  You should
  have a `source` at this level for the project.
- Run `cmake -S . -B build.windows` to rebuild the build system in the
  folder `build.windows`. The `cmake` utility understands Visual Studio
  project files and will automagically create them for you.
- Then run `cmake --build build.windows` to build the application in batch
  mode or load the Visual Studio solution in the `build.windows` folder 

# Pre-requisites
`cmake` is not installed by default in many Linux distributions.   Use your
distribution's package manager to install it onto your system.

For example, for Ubuntu and other Debian-based distributions:

```bash
sudo apt install cmake
```

For macOS, you will need the Homebrew package manager. This can be
  installed from [https://brew.sh](https://brew.sh) using the command:
  
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

- Once you Homebrew installed, use it to install `cmake` 

```bash
brew install cmake
```

`cmake` is included in Visual Studio.  You just need to run the command
in a terminal session (cmd.exe or Powershell) with the correct
environment variables in place.   Visual Studio includes links to this
in the Visual Studio folder in the start menu.
