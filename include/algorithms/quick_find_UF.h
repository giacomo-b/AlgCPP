#pragma once

#include "union_find.h"
#include <vector>
#include <type_traits>

namespace Algs
{
class QuickFindUF : public UnionFind
{
public:
    QuickFindUF(int size);

    ~QuickFindUF();

    void initializeWithIncreasingIds();

    void join(int p, int q);

    inline bool connected(int p, int q) const
    {
        return (id[p] == id[q]);
    }

    inline std::size_t getSize() const
    {
        return size;
    }

private:
    std::vector<int> id;
    std::size_t size {0};

    void assertValidArguments(int p, int q) const;

    bool outOfRange(int p, int q) const;

    inline bool atLeastOneNegative(int p, int q) const
    {
        return (p < 0 || q < 0);
    }

    inline bool atLeastOneExceedsIdSize(int p, int q) const
    {
        return ( ((std::size_t)p >= size) ||
                 ((std::size_t)q >= size) );
    }

    void performIndicesSubstitution(int p_id, int q_id);
};
}