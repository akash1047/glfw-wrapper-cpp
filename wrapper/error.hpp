#pragma once

#include <GLFW/glfw3.h>
#include <functional>
#include <string>
#include <tuple>

namespace wrap {

enum class error_kind {
    no_error = GLFW_NO_ERROR,
    not_initialized = GLFW_NOT_INITIALIZED,
    no_current_context = GLFW_NO_CURRENT_CONTEXT,
    invalid_enum = GLFW_INVALID_ENUM,
    invalid_value = GLFW_INVALID_VALUE,
    out_of_memory = GLFW_OUT_OF_MEMORY,
    api_unavailable = GLFW_API_UNAVAILABLE,
    version_unavailable = GLFW_VERSION_UNAVAILABLE,
    platform_error = GLFW_PLATFORM_ERROR,
    format_unavailable = GLFW_FORMAT_UNAVAILABLE,
    no_window_context = GLFW_NO_WINDOW_CONTEXT,
};

class Error : public std::exception {
    public:
    // Get recent error from glfw error stack.
    //
    // Clear's last error from the error stack in the process.
    Error() {
        const char *desc{nullptr};
        kind = error_kind(glfwGetError(&desc));
        msg = desc;
    }

    // construct Error from error_kind and c_str
    Error(error_kind e_kind, const char *desc) : kind(e_kind), msg(desc) {}

    const char *what() const noexcept override {
        return msg.c_str();
    }

    // get inner error_kind and msg
    std::tuple<error_kind, std::string> get() {
        return {kind, msg};
    }

    bool operator==(error_kind e) {
        return kind == e;
    }

    bool operator!=(error_kind e) {
        return kind != e;
    }

    error_kind get_error_kind() {
        return kind;
    }

    std::string get_msg() {
        return msg;
    }

    private:
    error_kind kind{error_kind::no_error};
    std::string msg{};
};

static GLFWerrorfun FAIL_ON_ERROR = [](int code, const char *desc) {
    throw Error{error_kind(code), desc};
};

} // namespace wrap