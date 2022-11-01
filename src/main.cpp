#include "Libraries.h"
#include "Core.h"

int main() {
    Core core;
    assert(core.init());
    core.loop();
    return EXIT_SUCCESS;
}
