#include <iostream>
#include "../include/zEngine/application.h"

int main() {
    auto app = zEngine::Application::GetSingleton();
    return app->Run();
}