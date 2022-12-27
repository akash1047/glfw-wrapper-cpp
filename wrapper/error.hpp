#pragma once

#include <GLFW/glfw3.h>
#include <functional>
#include <string>

namespace glfw {

enum class error_kind : int {
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

class Error {
    public:
    // clear's last Error
    Error() {
        const char *des{nullptr};
        kind = error_kind(glfwGetError(&des));
        msg = des;
    }

    Error(error_kind e_kind, const char *des) : kind(e_kind), msg(des) {}

    // will throw everytime Error occurs

    private:
    error_kind kind{error_kind::no_error};
    std::string msg{};
};

static GLFWerrorfun FAIL_ON_ERROR = [](int code, const char *des) {
    throw Error{error_kind(code), des};
};

} // namespace glfw