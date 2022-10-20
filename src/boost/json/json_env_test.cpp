#include <boost/json.hpp>
#include <iostream>
#include <string>

using namespace boost::json;

namespace cpp_tutorial {
namespace boost {
namespace json {

void Test001_CreateJsonFile() {
  object obj;                // construct an empty object
  obj["pi"] = 3.141;         // insert a double
  obj["happy"] = true;       // insert a bool
  obj["name"] = "Boost";     // insert a string
  obj["nothing"] = nullptr;  // insert a null
  obj["answer"].emplace_object()["everything"] =
      42;                   // insert an object with 1 element
  obj["list"] = {1, 0, 2};  // insert an array with 3 elements
  obj["object"] = {{"currency", "USD"},
                   {"value", 42.99}};  // insert an object with 2 elements
}

void Run() {
  // Test001
  Test001_CreateJsonFile();
}

}  // namespace json
}  // namespace boost
}  // namespace cpp_tutorial

int main(int argc, char **argv) {
  cpp_tutorial::boost::json::Run();
  return 0;
}