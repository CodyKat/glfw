//========================================================================
// GLFW - An OpenGL framework
// Platform:    X11 (Unix)
// API version: 3.0
// WWW:         http://www.glfw.org/
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Marcus Geelnard
// Copyright (c) 2006-2010 Camilla Berglund <elmindreda@elmindreda.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include "internal.h"


//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
// Enable system keys
//========================================================================

void _glfwPlatformEnableSystemKeys(_GLFWwindow* window)
{
    if (window->X11.keyboardGrabbed)
    {
        XUngrabKeyboard(_glfwLibrary.X11.display, CurrentTime);
        window->X11.keyboardGrabbed = GL_FALSE;
    }
}

//========================================================================
// Disable system keys
//========================================================================

void _glfwPlatformDisableSystemKeys(_GLFWwindow* window)
{
    if (XGrabKeyboard(_glfwLibrary.X11.display, window->X11.window,
                      True, GrabModeAsync, GrabModeAsync, CurrentTime)
        == GrabSuccess)
    {
        window->X11.keyboardGrabbed = GL_TRUE;
    }
}

