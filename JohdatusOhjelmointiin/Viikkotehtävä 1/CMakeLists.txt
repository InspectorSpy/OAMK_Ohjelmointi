cmake_minimum_required(VERSION 3.16)

project(Viikko1 LANGUAGES C)

add_executable(Viikko1 main.c)

include(GNUInstallDirs)
install(TARGETS Viikko1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
