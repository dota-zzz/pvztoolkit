cmake_minimum_required(VERSION 3.24)
project(test2)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories("C:\\Program Files (x86)\\wxWidgets\\include")
include_directories("C:\\Program Files (x86)\\wxWidgets\\lib\\gcc_x64_dll\\mswud")
link_directories("C:\\Program Files (x86)\\wxWidgets\\lib\\gcc_x64_dll")
aux_source_directory(${PROJECT_SOURCE_DIR}/src srcs)
add_executable(${PROJECT_NAME}
    ${srcs}
)
target_link_libraries(${PROJECT_NAME} wxbase32ud wxmsw32ud_core)