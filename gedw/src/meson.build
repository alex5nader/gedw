gedw_sources = [
    'main.cpp',
    'gfx/core.cpp',
    'math/core.cpp',
]

gedw = executable(
    'gedw', gedw_sources,
    include_directories: gedw_include,
    dependencies: [ glfw_dep, glew_dep ],
    install: true,
)