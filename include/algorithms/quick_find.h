#pragma once

#include "union_find.h"
#include <vector>


class QuickFind : public UnionFind
{
private:
    std::vector<int> id;

public:
    QuickFind(int size);
    ~QuickFind();
    void join(int p, int q);
    inline bool connected(int p, int q) const
    {
        return (id[p] == id[q]);
    }

    inline std::size_t size() const
    {
        return id.size();
    }
};