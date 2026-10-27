cmake_minimum_required(VERSION 3.19)

project(barqode LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(PkgConfig REQUIRED)
pkg_check_modules(DMTX REQUIRED IMPORTED_TARGET libdmtx)
pkg_check_modules(QRENCODE REQUIRED IMPORTED_TARGET libqrencode)
qt_standard_project_setup()
set(CMAKE_AUTORCC ON)

qt_add_executable(barqode WIN32 MACOSX_BUNDLE
	main.cpp
	barqode.cpp barqode.h
	barqodewidget.ui
	barqode.qrc
)

if(WIN32)
	target_sources(barqode PRIVATE barqode.rc)
endif()

target_link_libraries(barqode PRIVATE Qt6::Widgets PkgConfig::DMTX PkgConfig::QRENCODE)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	target_compile_options(barqode PRIVATE -Wall -Wextra)
endif()

install(TARGETS barqode
	BUNDLE DESTINATION .
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
