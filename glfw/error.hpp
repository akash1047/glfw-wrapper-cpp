#pragma once

#include <GLFW/glfw3.h>
#include <exception>
#include <string>

namespace glfw {

class error: public std::exception {
public:
    error(int err_code, const char *desc) : code(err_code), msg(desc) {}

    const char *what() const noexcept override {
        return this->msg.c_str();
    }

    bool operator==(int kind) {
        return this->code == kind;
    }

private:
    int code{GLFW_NO_ERROR};
    std::string msg;
};

inline error get_error() {
    int code;
    const char *description;

    code = glfwGetError(&description);

    return error{code, description};
}

} // namespace glfw
