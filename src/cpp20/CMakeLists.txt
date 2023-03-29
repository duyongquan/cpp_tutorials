### [template_meta]  ####
add_executable(cpp_tutorial.cpp20.template_meta_test tutorial_cpp20_template_meta_test.cpp)
target_link_libraries(cpp_tutorial.cpp20.template_meta_test)

### [tuple_test] ###
add_executable(cpp_tutorial.cpp20.tuple_test tutorial_cpp20_tuple_test.cpp)
target_link_libraries(cpp_tutorial.cpp20.tuple_test)
target_include_directories(cpp_tutorial.cpp20.tuple_test SYSTEM PUBLIC ${EIGEN3_INCLUDE_DIR})