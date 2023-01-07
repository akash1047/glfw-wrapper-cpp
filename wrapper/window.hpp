#pragma once

#include <GLFW/glfw3.h>

namespace wrap {

class Window {
    public:
    Window(GLFWwindow *safe_handle) : handle(safe_handle) {}
    ~Window() {
        glfwDestroyWindow(handle);
    }

    private:
    GLFWwindow *handle{nullptr};
};

} // namespace wrap