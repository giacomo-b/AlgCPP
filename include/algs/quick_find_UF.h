#pragma once

#include "union_find.h"
#include <vector>
#include <stdexcept>

namespace Algs
{
class QuickFindUF : public UnionFind
{
public:
    QuickFindUF(int size);

    ~QuickFindUF();

    void fillWithIncreasingIds();

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

    inline bool negative(int i) const { return (i < 0); }

    inline bool exceedsSize(int i) const { return ((std::size_t)i >= size); }

    void performIndicesSubstitution(int p_id, int q_id);
};
}