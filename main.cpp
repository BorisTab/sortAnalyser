#include <thread>
#include "Analyser/stats.h"
#include "UserInterface/gui.h"

int main() {
    UserInterface gui;
    std::thread guiThread(&UserInterface::windowIsOpen, &gui);

    size_t pointNum = 30;
    size_t graphicStep = 10;
    auto graphic = new Stats*[pointNum];

    for (int i = 1; i <= pointNum; ++i) {
        graphic[i] = new Stats(0, i * graphicStep);
        graphic[i]->printInfo();
        delete graphic[i];
    }

    delete[] graphic;
    guiThread.join();

    return 0;
}
