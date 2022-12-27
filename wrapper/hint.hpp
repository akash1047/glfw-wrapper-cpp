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

class init_hint : public hint {
#define OPT_HINT(FUNC, HINT)                                                   \
    static init_hint FUNC(bool opt) {                                          \
        return {HINT, (opt) ? GLFW_TRUE : GLFW_FALSE};                         \
    }

    public:
    OPT_HINT(joystick_hat_buttons, GLFW_JOYSTICK_HAT_BUTTONS)
    OPT_HINT(cocoa_chdir_resources, GLFW_COCOA_CHDIR_RESOURCES)
    OPT_HINT(cocoa_menubar, GLFW_COCOA_MENUBAR)

    private:
    init_hint(int t_hint, int value) : hint(t_hint, value) {}
};

#undef OPT_HINT

class window_hint : public hint {
#define OPT_HINT(FUNC, HINT)                                                   \
    static window_hint FUNC(bool opt) {                                        \
        return {HINT, (opt) ? GLFW_TRUE : GLFW_FALSE};                         \
    }

    public:
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

    private:
    window_hint(int t_hint, int value) : hint(t_hint, value) {}
};

} // namespace glfw