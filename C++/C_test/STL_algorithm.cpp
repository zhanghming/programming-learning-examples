/**
 * The usage of STL algorithm to process the STL containers
 * 
 **/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &vec)
{
    for (const auto &o : vec)
    {
        s << o << " ";
    }
    return (s);
}

/**
 * http://www.java2s.com/Tutorial/Cpp/0260__template/templatefunctiontoprintelementsofanSTLcontainer.htm
 **/
template <typename T>
void printcoll(T const &coll)
{
    typename T::const_iterator pos;             // iterator to iterate over coll
    typename T::const_iterator end(coll.end()); // end position

    for (pos = coll.begin(); pos != end; ++pos)
    {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

/**
 * @brief std::copy and std::merge function usage
 **/
void CopyFunction()
{
    /// std::copy function usage
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {6, 7, 8, 9, 10};
    std::vector<int> c;
    std::copy(a.begin(), a.end(), std::back_inserter(c));
    std::copy(b.begin(), b.end(), std::back_inserter(c));
    std::cout << c << std::endl;

    /// above process can be implemented by std::merge
    // need allocate size in advance, otherwise segmentation fault!
    std::vector<int> c1(a.size() + b.size());
    std::merge(a.begin(), a.end(), b.begin(), b.end(), c1.begin());
    std::cout << c1 << std::endl;
}

void PrintFunction()
{
    std::vector<float> a = {1.67, 2.0, 3.5};
    std::cout << a << std::endl;
    printcoll(a);
}

void MaxMinFunction()
{
    std::vector<int> height = {1, 6, 4, 5, 10, 8, 9};
    //1)找到最高士兵的位置
    auto it_max = max_element(height.begin(), height.end());
    int pos = distance(height.begin(), it_max);
    int sum = 0; //能看到的士兵数量
    while (pos != 0)
    {
        sum += 1;
        it_max = max_element(height.begin(), it_max);
        pos = distance(height.begin(), it_max);
    }
    sum += 1;
    cout << sum << endl;
}

int main()
{
    CopyFunction();
    PrintFunction();
    cout << "MaxMinFunction test:" << endl;
    MaxMinFunction();
}