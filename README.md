# opengl-starting-point

Starting point for modern OpenGL projects in C++ (Visual Studio Code project).

Uses glew, glfw3, and glm.

## Instructions

Designed to be edited and run with Visual Studio Code.

Install [Visual Studio Code](https://code.visualstudio.com), then follow the per-platform instructions below.

Be sure to install these plugins for VS Code:

* C/C++ Intellisense/debugging by Microsoft
* Shader languages support by slevesque

Afterwards, open the root directory of this repo in Visual Studio Code and press Cmd+Shift+B to build.

### MacOS

Install XCode.

Brew has up-to-date versions of all three dependencies.

```
brew update
brew install glfw glew glm
```

### Ubuntu Linux 17.10

The Ubuntu software repos have up-to-date versions of all three dependencies

```
sudo apt-get update
sudo apt-get install build-essential libglfw3-dev libglew-dev libglm-dev
```

### Windows 10

(coming soon)
