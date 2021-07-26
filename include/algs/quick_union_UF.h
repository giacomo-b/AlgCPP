#pragma once

#include "union_find.h"
#include <vector>
#include <iostream> // TODO: remove if unused

namespace Algs
{
class QuickUnionUF : public UnionFind
{
public:
    QuickUnionUF(int size);

    ~QuickUnionUF();

    void join(int p, int q) { std::cout << p+q; };
    bool connected(int p, int q) const { return (p && q); };
    std::size_t getSize() const { return 2; };

private:

};
}