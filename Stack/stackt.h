#ifndef STACKT_H
#define STACKT_H

#include <vector>
#include <string>

template <class T>
class StackT
{
    /**
     * @brief stackVector acts like a stack
     */
    std::vector<T> stackVector;
public:
    /**
     * @brief StackT empty constructor
     */
    StackT();

    /**
     * @brief isEmpty checks to see if stack is empty
     * @return T if empty, F if not
     */
    bool isEmpty() {
        return stackVector.size() == 0;
    }

    /**
     * @brief push inserts element into the front
     * @param t elemet to insert
     */
    void push(T t) {
        stackVector[0] = t;
    }

    /**
     * @brief pop remove top element and return it
     * @return top element
     */
    T pop() {
        T pop = stackVector[0];
        for(int i = 0; i < stackVector.size(); i++) {
            stackVector[i - 1] = stackVector[i];
        }
        stackVector[stackVector.size() - 1] = NULL;
        return pop;
    }

    /**
     * @brief size
     * @return size
     */
    int size() {
        return stackVector.size();
    }

    /**
     * @brief toStack return string of elements
     * @return string of elements in the stack
     */
    std::string toStack() {
        std::string ret;
        for(int i = 0; i < stackVector.size(); i++) {
            ret += std::to_string(stackVector[i]);
            ret += ", ";
        }
        return ret;
    }
};

#endif // STACKT_H
