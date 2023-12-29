cmake_minimum_required (VERSION 3.21)

project ("benches" LANGUAGES CXX)

add_subdirectory ("benchmark")

add_executable (benches
    "bench_malloc.cpp")
target_link_libraries (benches PRIVATE benchmark::benchmark)

