#include <iostream>
#include <chrono>
#include "testcase.hpp"
#include "vector_container.hpp"
#include "deque_container.hpp"
#include "list_container.hpp"
#include "array_container.hpp"
#include "stack_container.hpp"
#include "queue_container.hpp"
#include "unorderedmap_container.hpp"

using namespace std;

#define MAX_ELEM_NUM 10000
#define TEST_SIZE 100000

VectorContainer<int> vectorContainer;
DequeContainer<int> dequeContainer;
ListContainer<int> listContainer;
ArrayContainer<int> arrayContainer;
StackContainer<int> stackContainer;
QueueContainer<int> queueContainer;
UnorderedMapContainer<int> unorderedMapContainer;

Container<int>* containers[] = {&vectorContainer, &dequeContainer, &listContainer, &arrayContainer, &stackContainer, &queueContainer, &unorderedMapContainer};

// <Container name, execuion time>
vector<pair<string, chrono::duration<double> > > executionTimes;

TestCase tc;

template <typename T>
void initContainer(Container<T> &container)
{

}

template <typename T>
void resetContainer(Container<T> &container)
{

}

int main()
{
    cout << "C++ Container Performance Profiling Test" << endl;

    for (Container<int>* container : containers) {
        cout << "[INFO] " << container->getName() << " profiling starts" << endl;

        initContainer(*container);
        
        for (auto& test: tc.getTests()) {
            auto start = chrono::high_resolution_clock::now();
            test.runTest(TEST_SIZE);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            cout << "[INFO] (" << test.tname << ") Execution time: " << duration.count() << " [sec]" << endl;
        }

        cout << "[INFO] " << container->name() << " profiling ends" << endl;
        cout << "[INFO] Execution time: " << duration.count() << " [sec]" << endl;
        resetContainer(*container);
    }

    return 0;
}
