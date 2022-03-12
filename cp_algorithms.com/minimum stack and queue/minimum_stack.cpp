#include <iostream>
#include <stack>
#include <utility>

template<typename T, T INF>
struct min_stack
{
    std::stack<std::pair<T, T>> st;

    T min()
    {
        return st.empty() ? INF : st.top().second;
    }
    void push(T elem)
    {
        st.push({elem, this.min()});
    }
    void pop()
    {
        st.pop();
    }
};