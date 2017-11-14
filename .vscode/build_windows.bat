@echo off

if not exist "build" mkdir "build"
xcopy /s /Y lib build

call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
set compilerflags=/Od /Zi /EHsc /Fo.\build\
set sourcefiles=src/cpp/*.cpp
set linkerflags=opengl32.lib glew32.lib glfw3dll.lib /OUT:build/opengl-app.exe

cl.exe %compilerflags% %sourcefiles% /I include /link %linkerflags% /LIBPATH:lib
