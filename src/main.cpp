#include <iostream>
#include "../include/zEngine/application.h"

using namespace zEngine;

int main() {
    int code = 0;
    Application* app;
    try
    {
        app = Application::GetSingleton();
        code = app->Run();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Application terminated with error: " << std::endl
            << e.what() << std::endl;
    }

    if (app != nullptr)
    {
        delete app;
    }

    return code;
}