### [benchmark] ###
add_executable(cpp_tutorial.benchmark tutorials_benchmark.cpp)
target_link_libraries(cpp_tutorial.benchmark benchmark::benchmark)

### [gperftool] ###
add_executable(cpp_tutorial.gperftool tutorials_gperftool.cpp)
target_link_libraries(cpp_tutorial.gperftool ${GPERFTOOLS_LIBRARIES})