#pragma once

//Linking OS specific libraries  
#ifdef __linux__
#pragma comment(lib, "libGL")
#endif

#ifdef __WIN32
//#define WIN32_LEAN_AND_MEAN
//#include <Windows.h>
#pragma comment(lib, "opengl32.lib") 
//#pragma comment(lib, "glew32.lib")   
#endif

#ifdef __APPLE__
#pragma comment(lib, "OpenGL.framework")
#endif

#include<iostream>

using std::cout;
using std::endl;

// Including SFML for cross platform window, timer and input handling
#pragma comment(lib, "sfml-system.lib") 
#pragma comment(lib, "sfml-window.lib") 
#pragma comment(lib, "sfml-graphics.lib")

#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
