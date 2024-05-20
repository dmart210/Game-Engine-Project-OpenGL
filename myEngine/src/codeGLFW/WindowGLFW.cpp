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

    glfwSetWindowUserPointer(mWindow, &mCallbacks);

    glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keycode, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
            KeyPressed e{ keycode };
            callbacks->keyPressedFunc(e);
        }
        else if (action == GLFW_RELEASE) {
            Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
            KeyReleased e{ keycode };
            callbacks->keyReleasedFunc(e);
        }
        });

    glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
        Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
        callbacks->windowCloseFunc;
        });


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

void Engine::WindowGLFW::SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc)
{
    mCallbacks.keyPressedFunc = callbackFunc;
}

void Engine::WindowGLFW::SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc)
{
    mCallbacks.keyReleasedFunc = callbackFunc;
}

void Engine::WindowGLFW::SetWindowCloseCallback(std::function<void()>& callbackFunc)
{
    mCallbacks.windowCloseFunc = callbackFunc;
}

Engine::WindowGLFW::~WindowGLFW()
{
    glfwTerminate();
}

