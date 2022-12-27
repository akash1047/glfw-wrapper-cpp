#pragma once

#include <GLFW/glfw3.h>
#include <functional>

namespace glfw {

class hint {
    public:
    virtual ~hint() {}

    // applies hint
    void apply() const {
        fn();
    }

    protected:
    hint(int glfw_hint, int value)
        : fn([=] { glfwWindowHint(glfw_hint, value); }) {}

    private:
    std::function<void()> fn;
};

class InitHint : public hint {
    public:
    InitHint(int t_hint, int value) : hint(t_hint, value) {}
};

#define OPT_HINT(FUNC, HINT)                                                   \
    static InitHint FUNC(bool opt) {                                           \
        return {HINT, (opt) ? GLFW_TRUE : GLFW_FALSE};                         \
    }

namespace init_hint {

OPT_HINT(joystick_hat_buttons, GLFW_JOYSTICK_HAT_BUTTONS)
OPT_HINT(cocoa_chdir_resources, GLFW_COCOA_CHDIR_RESOURCES)
OPT_HINT(cocoa_menubar, GLFW_COCOA_MENUBAR)

} // namespace init_hint

#undef OPT_HINT

#define OPT_HINT(FUNC, HINT)                                                   \
    static WindowHint FUNC(bool opt) {                                         \
        return {HINT, (opt) ? GLFW_TRUE : GLFW_FALSE};                         \
    }

class WindowHint : public hint {

    public:
    WindowHint(int t_hint, int value) : hint(t_hint, value) {}
};

namespace window_hint {

OPT_HINT(resizable, GLFW_RESIZABLE)
OPT_HINT(visible, GLFW_VISIBLE)
OPT_HINT(decorated, GLFW_DECORATED)
OPT_HINT(focused, GLFW_FOCUSED)
OPT_HINT(auto_iconify, GLFW_AUTO_ICONIFY)
OPT_HINT(floating, GLFW_FLOATING)
OPT_HINT(maximized, GLFW_MAXIMIZED)
OPT_HINT(center_cursor, GLFW_CENTER_CURSOR)
OPT_HINT(transparent_framebuffer, GLFW_TRANSPARENT_FRAMEBUFFER)
OPT_HINT(focus_on_show, GLFW_FOCUS_ON_SHOW)
OPT_HINT(scale_to_monitor, GLFW_SCALE_TO_MONITOR)

} // namespace window_hint

#undef OPT_HINT

} // namespace glfw