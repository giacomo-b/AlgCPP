#pragma once

#include <cstdint>

namespace Algs
{
class UnionFind
{
public:
    UnionFind(){}
    virtual ~UnionFind(){}
    virtual void join(int p, int q) = 0;
    virtual bool connected(int p, int q) const = 0;
    virtual std::size_t size() const = 0;
};
}