find_package(Boost 1.8.0)
include_directories(${Boost_INCLUDE_DIRS})


message(${Boost_INCLUDE_DIRS})


### [JSON] demo1 ####
add_executable(cpp_tutorial.boost.json.json_env_test json_env_test.cpp)
target_link_libraries(cpp_tutorial.boost.json.json_env_test ${Boost_LIBRARIES})