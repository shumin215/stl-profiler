#ifndef __TESTCASE_HPP__
#define __TESTCASE_HPP__

using namespace std;
#include <vector>
#include "test1_linear_read.hpp"

class TestCase
{
public:
    TestCase() 
    {
        _tests.push_back();
    }

    vector<void(*)> getTests(void)
    {
        return _tests;
    }

    vector<void(*)> _tests;
};

#endif