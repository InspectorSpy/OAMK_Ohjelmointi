cmake_minimum_required(VERSION 3.16)

project(C_Ohjelmointi_git LANGUAGES C)

add_executable(C_Ohjelmointi_git main.c)

include(GNUInstallDirs)
install(TARGETS C_Ohjelmointi_git
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
