#include <iostream>
#include <vector>
#include <deque>
#include <list>

// 공통된 인터페이스를 가진 추상 클래스
template<typename T>
class Container {
public:
    virtual void insert(T value) = 0;
    virtual T get() = 0;
    virtual bool isEmpty() const = 0;
};

template<typename T>
class VectorContainer : public Container<T> {
private:
    std::vector<T> data;
public:
    void insert(T value) {
        data.push_back(value);
    }

    T get() {
        T value = data.back();
        data.pop_back();
        return value;
    }

    bool isEmpty() const {
        return data.empty();
    }
};

template<typename T>
class DequeContainer : public Container<T> {
private:
    std::deque<T> data;
public:
    void insert(T value) {
        data.push_back(value);
    }

    T get() {
        T value = data.back();
        data.pop_back();
        return value;
    }

    bool isEmpty() const {
        return data.empty();
    }
};

template<typename T>
class ListContainer : public Container<T> {
private:
    std::list<T> data;
public:
    void insert(T value) {
        data.push_back(value);
    }

    T get() {
        T value = data.back();
        data.pop_back();
        return value;
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    VectorContainer<int> vectorContainer;
    vectorContainer.insert(10);
    vectorContainer.insert(20);

    DequeContainer<int> dequeContainer;
    dequeContainer.insert(30);
    dequeContainer.insert(40);

    ListContainer<int> listContainer;
    listContainer.insert(50);
    listContainer.insert(60);

    // 컨테이너들을 순회하는 for 루프
    Container<int>* containers[] = {&vectorContainer, &dequeContainer, &listContainer};

    for (Container<int>* container : containers) {
        while (!container->isEmpty()) {
            std::cout << container->get() << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
