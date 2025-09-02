cmake_minimum_required(VERSION 3.16)

project(C_Ohjelmointi_MAIN LANGUAGES C)

add_executable(C_Ohjelmointi_MAIN main.c)

include(GNUInstallDirs)
install(TARGETS C_Ohjelmointi_MAIN
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
