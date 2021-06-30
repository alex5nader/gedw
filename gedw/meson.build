project(
    'gedw', 'cpp',
    default_options: ['cpp_std=c++17'],
)

glfw_dep = dependency('glfw3')
glew_dep = dependency('glew')

gedw_include = include_directories('include')

find = find_program('fd')

gedw_headers = run_command(find, '.', '--extension', 'h', './include').stdout().strip().split('\n')
gedw_sources = run_command(find, '.', '--extension', 'cpp', './src').stdout().strip().split('\n')

install_headers(gedw_headers, subdir: 'gedw')
install_subdir('res', install_dir: '.')
gedw = executable(
    'gedw', gedw_sources,
    include_directories: gedw_include,
    dependencies: [ glfw_dep, glew_dep ],
    install: true,
)
