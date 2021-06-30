#include <GL/glew.h>

#include "gfx/program.h"
#include "gfx/renderobject.h"
#include "gfx/renderer.h"
#include "math/core.h"

using namespace gedw;
using namespace gedw::gfx;
using namespace gedw::math;

int main() {
    auto gl = GlInstance::init(800, 600, "Title", {
        .clear = { .r = 0.4f, .g = 0.3f, .b = 0.5f },
    });
    
    Slice<float> vertices({
        -.5f, -.5f,  1.0f, 0.0f, 0.0f,
         .5f, -.5f,  0.0f, 1.0f, 0.0f,
         .5f,  .5f,  0.0f, 0.0f, 1.0f,
        -.5f,  .5f,  1.0f, 1.0f, 1.0f,
    });
    RenderObject ro(vertices, { 2, 3 });

    Renderer renderer("res/shader.glsl");

    float offset = 0.0f, increment = 0.05f;

    while (gl.isRunning()) {
        renderer.clear();

        if (abs(offset) >= 1.0f) {
            increment *= -1;
        }
        offset += increment;
        renderer.getProgram().setUniform2f("u_Camera", offset, offset);

        renderer.draw(ro);

        renderer.render(gl);
    }

    return 0;
}
