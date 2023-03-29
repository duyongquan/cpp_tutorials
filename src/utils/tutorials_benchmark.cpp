#include <benchmark/benchmark.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void test_c(size_t count)
{
	char str1[] = "Hello! My name is Jack. What is your name?";
	char str2[] = "Jack";
	size_t i = 0;
	while (i <= count) {
		strstr(str1,str2);
		i++;
	}
}

void demo()
{
    string str = "hello world";
    str.size();
}

void test_cpp_strfind(size_t count)
{
	string str1 = "Hello! My name is Jack. What is your name?";
	string str2 = "Jack";
	size_t i = 0;
	while (i <= count) {
		str1.find(str2);
		i++;
	}
}

void test_cpp_strview_find(size_t count)
{
	string_view str1 = "Hello! My name is Jack. What is your name?";
	string_view str2 = "Jack";
	size_t i = 0;
	while (i <= count) {
		str1.find(str2);
		i++;
	}
}

void test_cpp_strstr(size_t count)
{
	string str1 = "Hello! My name is Jack. What is your name?";
	string str2 = "Jack";
	size_t i = 0;
	while (i <= count) {
		strstr(str1.c_str(),str2.c_str());
		i++;
	}
}

//========BM_xxx
static void BM_demo(benchmark::State& state) {
    for (auto _ : state)
        demo();
}

static void BM_test_c(benchmark::State& state) {
    for (auto _ : state)
        test_c(50000);
}

static void BM_test_cpp_strfind(benchmark::State& state) {
    for (auto _ : state)
        test_cpp_strfind(50000);
}

static void BM_test_cpp_strview_find(benchmark::State& state) {
    for (auto _ : state)
        test_cpp_strview_find(50000);
}

static void BM_test_cpp_strstr(benchmark::State& state) {
    for (auto _ : state)
        test_cpp_strstr(50000);
}


BENCHMARK(BM_demo)->Arg(10);
BENCHMARK(BM_test_c)->Arg(100);
BENCHMARK(BM_test_cpp_strfind)->Iterations(1000);
BENCHMARK(BM_test_cpp_strview_find)->Arg(10000);
BENCHMARK(BM_test_cpp_strstr)->Arg(100000);

BENCHMARK_MAIN();