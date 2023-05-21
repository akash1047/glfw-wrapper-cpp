#pragma once

#include <GLFW/glfw3.h>

namespace glfw {

// glfw monitor
class monitor {
public:
    // get primary monitor
    static monitor primary() {
        return monitor(glfwGetPrimaryMonitor());
    }

    GLFWmonitor *monitor_id() {
        return this->id;
    }

protected:
    monitor(GLFWmonitor *monitor_id) : id(monitor_id) {}

private:
    GLFWmonitor *id{0};
};

} // namespace glfw
