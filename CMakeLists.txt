# CMakeList.txt : CMake project for bpc-pc1t-rezervacni-system, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("bpc-pc1t-rezervacni-system")

# Add source to this project's executable.
add_executable (bpc-pc1t-rezervacni-system "main.cpp" "main.h" "zpracovani_kinosalu.h")

# TODO: Add tests and install targets if needed.
