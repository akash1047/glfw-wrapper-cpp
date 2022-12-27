#pragma once

#include "error.hpp"
#include "hint.hpp"
#include "window.hpp"
#include <GLFW/glfw3.h>

namespace glfw {

class Glfw {
    public:
    Glfw() {
        init();
    }

    Glfw(GLFWerrorfun error_callback) {
        glfwSetErrorCallback(error_callback);
        init();
    }

    ~Glfw() {
        glfwTerminate();
    }

    void default_window_hints() {
        glfwDefaultWindowHints();
    }

    void window_hint(WindowHint hint) {
        hint.apply();
    }

    Window create_window(std::uint32_t width, std::uint32_t height,
                         const char *title) {
        GLFWwindow *glfw_window =
            glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (glfw_window == nullptr) {
            throw Error{};
        }

        return Window{glfw_window};
    }

    private:
    static void init() {
        if (!glfwInit()) {
            throw Error{};
        }
    }
};

} // namespace glfw