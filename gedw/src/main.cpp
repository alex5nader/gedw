#include <iostream>

#include "gfx/core.h"

int main() {
    auto gl = gedw::gfx::init(800, 600, "Title");

    gl.end();
    return 0;
}
