#include "algorithms/quick_find.h"
#include <iostream>
#include <numeric>

QuickFind::QuickFind(int size)
    : id(size)
{
    std::iota(std::begin(id), std::end(id), 0);
}

QuickFind::~QuickFind()
{

}

void QuickFind::join(int p, int q) {
    const int p_id = id[p],
              q_id = id[q];
    
    // TODO: check that they are not already connected
    for (size_t i = 0; i < id.size(); ++i)
        if (id[i] == p_id)
            id[i] = q_id;
}