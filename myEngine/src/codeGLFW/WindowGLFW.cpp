#include "pch.h"
#include  "WindowGLFW.h"

Engine::WindowGLFW::WindowGLFW()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Engine::WindowGLFW::Create(int width, int height)
{
    mWindow = glfwCreateWindow(width, height, "MyGame", NULL, NULL);
    assert(mWindow != NULL);
    glfwMakeContextCurrent(mWindow);
}

void Engine::WindowGLFW::SwapBuffers()
{
    glfwSwapBuffers(mWindow);
}

void Engine::WindowGLFW::PollEvents()
{
    glfwPollEvents();
}

int Engine::WindowGLFW::GetWidth() const
{
    int width, height;
    glfwGetWindowSize(mWindow, &width, &height);
    return width;
}

int Engine::WindowGLFW::GetHeight() const
{
    int width, height;
    glfwGetWindowSize(mWindow, &width, &height);
    return height;
}

Engine::WindowGLFW::~WindowGLFW()
{
    glfwTerminate();
}
