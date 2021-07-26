#pragma once

#include <vector>
#include <numeric>
#include <cstddef>
#include <stdexcept>

namespace Algs
{
namespace Utils
{
class IDContainer
{
public:
    IDContainer()
        : IDContainer(0)
    {

    }

    IDContainer(int size)
    {
        if (isNegative(size))
            throw std::out_of_range("The container cannot have a negative size.");

        container.resize(size);
        fillWithIncreasingValues();
    }
    
    inline int &operator[](int idx)
    {
        return container[idx];
    }

    inline int operator[](int idx) const
    {
        return container[idx];
    }

    inline std::size_t size() const
    {
        return container.size();
    }

    bool validIndex(int p) const
    {
        return (!isNegative(p) && !exceedsSize(p));
    }

private:
    std::vector<int> container;

    void fillWithIncreasingValues()
    {
        std::iota(std::begin(container), std::end(container), 0);
    }

    inline bool isNegative(int i) const
    {
        return (i < 0);
    }

    inline bool exceedsSize(int i) const
    {
        return ((std::size_t)i >= this->size());
    }
};
}
}