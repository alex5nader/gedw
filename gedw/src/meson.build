gedw_sources = [
    'main.cpp',
    'gfx/buffer/index.cpp',
    'gfx/buffer/vertex.cpp',
    'gfx/array.cpp',
    'gfx/core.cpp',
    'gfx/object.cpp',
    'math/core.cpp',
]

gedw = executable(
    'gedw', gedw_sources,
    include_directories: gedw_include,
    dependencies: [ glfw_dep, glew_dep ],
    install: true,
)