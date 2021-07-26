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
    // virtual int find(int p) = 0; // TODO:
    // virtual int count() = 0;     // TODO:
    virtual std::size_t getSize() const = 0;
};
}