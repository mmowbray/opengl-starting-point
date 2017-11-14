# opengl-starting-point

Starting point for modern OpenGL (v3.0+) projects in C++ (Visual Studio Code project).

Uses glew, glfw3, and glm.

## Instructions

Designed to be edited and run with Visual Studio Code.

Install [Visual Studio Code](https://code.visualstudio.com), then follow the per-platform instructions below.

Be sure to install these plugins for VS Code:

* C/C++ Intellisense/debugging by Microsoft
* Shader languages support by slevesque

Afterwards, clone the repo and follow per-platform instructions below.

Then, open the root directory of this repo in Visual Studio Code and press Cmd+Shift+B to build.
To run (any platform):

```
./build/opengl-app
```
### MacOS

Install XCode from the App Store.
Install [brew](https://brew.sh).

Brew has up-to-date versions of all three dependencies.

```
brew update
brew install glfw glew glm
```

### Ubuntu Linux 17.10 x64

The Ubuntu software repos have up-to-date versions of all three dependencies.

```
sudo apt-get update
sudo apt-get install build-essential libglfw3-dev libglew-dev libglm-dev
```

### Windows 10 x64

Unfortunately, no handy software repository exist in the Window world like they do in the *\*nix* world.
Fortunately, it's [not too painful](https://blogs.msdn.microsoft.com/vcblog/2016/10/24/building-your-c-application-with-visual-studio-code) to set up.

First, either install Visual Studio 2015 or just the [Visual C++ 2015 Tools](http://landinghub.visualstudio.com/visual-cpp-build-tools).

If you used just the tools, change .vscode/build_windows line 6 from:

```
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
```
to
```
call “C:\Program Files (x86)\Microsoft Visual C++ Build Tools\vcbuildtools.bat” x64
```

Create a *lib* folder in the root of the repo.

#### Add glfw3

Download glfw3 pre-compiled binaries (64-bit) from [here](http://www.glfw.org/download.html).

* From within the .zip, extract the contents of the lib-vc2015 folder to your newly-created *lib* folder.
* From within the .zip, Copy the include/GLFW folder to your include folder.

#### Add glew

Download glew binaries (Windows 32 and 64) from [here](http://glew.sourceforge.net/).
* From within the .zip, extract the contents of the /lib/Release/x64 folder to your newly-created *lib* folder.
* From within the .zip, extract glew32.dll from the /bin/Release/x64 folder to the same *lib* folder.
* Copy the include/GL folder to your include folder.

#### Add glm

Download the latest release from [here](https://github.com/g-truc/glm/tags).
* From within the .zip, extract the glm folder to your include folder.

Building should now work 😄
