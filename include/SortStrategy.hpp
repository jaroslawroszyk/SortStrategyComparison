#pragma once
#include <vector>

struct Foo
{
    int operator()(int a,int b)
    {
        return a +b;
    }
};