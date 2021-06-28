#include "pch.h"
#include <iostream>

int main() {
    auto gl = gfx::init(800, 600, "Title");

    gfx::end(gl);
    return 0;
}
