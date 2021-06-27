project('tutorial', 'cpp')

gedw_dependencies = [
  dependency('glfw3'),
  dependency('glew'),
]

gedw_sources = [
  'src/Main.cpp',
]

add_project_arguments('-DTESTDEF', language: 'cpp')

executable(
  'demo',
  gedw_sources,
  dependencies: gedw_dependencies,
  install: true,
  cpp_pch: 'src/pch.h',
)
