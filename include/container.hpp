#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

using namespace std;
#include <string>

template <typename T>
class Container
{
public:
    Container() {}

    string getName(void)
    {
        return _name;
    }

private:
    string _name;
};

#endif