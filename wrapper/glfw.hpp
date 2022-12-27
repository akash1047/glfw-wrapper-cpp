#pragma once

#include "error.hpp"
#include "window.hpp"
#include <GLFW/glfw3.h>

namespace glfw {

class glfw {
    public:
    glfw() {
        init();
    }

    glfw(GLFWerrorfun error_callback) {
        glfwSetErrorCallback(error_callback);
        init();
    }

    ~glfw() {
        glfwTerminate();
    }

    window create_window(std::uint32_t width, std::uint32_t height,
                         const char *title) {
        GLFWwindow *glfw_window =
            glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (glfw_window == nullptr) {
            throw error{};
        }

        return window{glfw_window};
    }

    private:
    static void init() {
        if (!glfwInit()) {
            throw error{};
        }
    }
};

} // namespace glfw