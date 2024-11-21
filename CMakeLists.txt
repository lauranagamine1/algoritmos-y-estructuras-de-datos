cmake_minimum_required(VERSION 3.28)
project(algoritmos_y_estructruas_de_datos_git)

set(CMAKE_CXX_STANDARD 14)

include_directories("s2 ForwardList")

add_executable(main main.cpp)
add_executable(dfs s13-busqueda-en-grafos/DFS.cpp)
add_executable(bfs s13-busqueda-en-grafos/BFS.cpp)
add_executable(sparse-matrix s14-matriz-dispersa/sparse-matrix.cpp)
