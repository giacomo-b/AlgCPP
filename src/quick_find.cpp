#include "algorithms/quick_find.h"
#include <iostream>
#include <numeric>

QuickFind::QuickFind(int size)
    : id(size)
{
    this->size = id.size();
    std::iota(std::begin(id), std::end(id), 0);
}

QuickFind::~QuickFind()
{

}

void QuickFind::join(int p, int q) {
    if (outOfRange(p, q))
        throw std::out_of_range("Elements indices out of range");
    
    if (connected(p, q))
        return;
    
    const int p_id = id[p],
              q_id = id[q];
    
    // TODO: check that they are not already connected
    for (size_t i = 0; i < id.size(); ++i)
        if (id[i] == p_id)
            id[i] = q_id;
}

bool QuickFind::outOfRange(int p, int q) const
{
    return (atLeastOneNegative(p, q) || atLeastOneExceedsIdSize(p, q));
}