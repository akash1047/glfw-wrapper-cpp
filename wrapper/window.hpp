#pragma once

#include <GLFW/glfw3.h>

namespace glfw {

class window {
    public:
    window(GLFWwindow *safe_handle) : handle(safe_handle) {}
    ~window() {
        glfwDestroyWindow(handle);
    }

    private:
    GLFWwindow *handle{nullptr};
};

} // namespace glfw