#pragma once

#include "error.hpp"
#include "window.hpp"
#include <GLFW/glfw3.h>
#include <exception>

namespace glfw {

class glfw {
public:
    glfw() = default;

    glfw(glfw &&rhs) {
        rhs.destroy = false;
    }

    glfw &operator=(glfw &&rhs) {
        rhs.destroy = false;
        return *this;
    }

    glfw(const glfw &) = delete;
    glfw &operator=(const glfw &rhs) = delete;

    ~glfw() {
        if (this->destroy) glfwTerminate();
    }

    inline window::builder window_builder() {
        return window::builder{};
    }

    inline void poll_events() {
        glfwPollEvents();
    }

    inline void terminate() {
        glfwTerminate();
    }

private:
    bool destroy{true};
};

inline glfw init() {
    if (!glfwInit()) throw get_error();

    return glfw{};
}

} // namespace glfw
