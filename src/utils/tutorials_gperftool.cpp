#include <stdio.h>
#include <stdlib.h>
#include <gperftools/profiler.h>

int b()
{
    int count = 500000000;
    int i = 0;
    for(i = 0;i<count;++i)
    {
        
    }
    return 0;
}

int a()
{
    int count = 1000000000;
    int i = 0;
    for(i = 0;i<count;++i)
    {
    }
    b();
    return 0;
}

int main ()
{
    ProfilerStart("test_capture.prof");
    a();
    ProfilerStop();
    return 0;
}
