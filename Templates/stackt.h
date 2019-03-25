#ifndef STACKT_H
#define STACKT_H

#include <string>

template <class T>
class StackT
{
    /**
     * @brief stackArr acts like a stack
     */
    T * stackArr;
    int ind; // stores index of next inserted element
    int si; // size of the current dynamically allocated array
public:
    /**
     * @brief StackT no arguments constructor
     */
    StackT()
    {
        si = 10;
        stackArr = new T[si];
        ind = 0;
    };

    /**
      * @brief destructor for StackT
      */
    ~StackT()
    {
        delete stackArr;
    }

    /**
     * @brief isEmpty checks to see if stack is empty
     * @return T if empty, F if not
     */
    bool isEmpty()
    {
        return si == 0;
    };

    /**
     * @brief push inserts element into the front
     * @param t elemet to insert
     */
    void push(T t)
    {
        stackArr[ind++] = t;
        if(ind == si)
        {
            si *= 2;
            T * temp = stackArr;
            stackArr = new T[si];
            for(int i = 0; i < si / 2; i++)
            {
                stackArr[i] = temp [i];
            }
            delete temp;
        }
    };

    /**
     * @brief pop remove top element and return it
     * @return top element
     */
    T pop()
    {
        T pop = stackArr[ind--];
        stackArr[ind] = NULL;
        return pop;
    };

    /**
     * @brief size
     * @return size
     */
    int size()
    {
        return ind;
    };

    /**
     * @brief toStack return string of elements
     * @return string of elements in the stack
     */
    std::string toStack()
    {
        std::string ret;
        if (ind == 0)
        {
            return ret;
        }
        int i;
        for(i = 0; i < ind - 1; i++) // last element should not have a comma after
        {
            ret += std::to_string(stackArr[i]);
            ret += ", ";
        }
        ret += std::to_string(stackArr[i]);
        return ret;
    };
};

#endif // STACKT_H
