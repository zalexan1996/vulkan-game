#include <iostream>
#include "../include/zEngine/application.h"

using namespace zEngine;

int main() {
    Application *app = Application::GetSingleton();
    return app->Run();
}