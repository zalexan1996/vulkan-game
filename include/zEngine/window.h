#pragma once
#include <string>

class GLFWwindow;

namespace zEngine
{
    class Window
    {
        public:
            Window(int width, int height, const std::string& windowName);
            Window(const Window&) = delete;
            ~Window();

            bool shouldClose();

            void Poll();
        private:
            GLFWwindow *window;
    };
} // namespace zEngine