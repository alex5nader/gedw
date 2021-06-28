gedw_sources = [
    'main.cpp',
    'gfx/core.cpp',
]

gedw = executable(
    'gedw', gedw_sources,
    include_directories: gedw_include,
    dependencies: [ glfw_dep, glew_dep ],
    # cpp_pch: 'pch/gedw.h',
    install: true,
)