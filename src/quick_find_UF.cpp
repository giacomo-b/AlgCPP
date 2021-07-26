#include "algs/quick_find_UF.h"
#include <numeric>

using namespace Algs;

QuickFindUF::QuickFindUF(int size)
{
    id.resize(size);
    this->size = id.size();
    fillWithIncreasingIds();
}

QuickFindUF::~QuickFindUF()
{

}

void QuickFindUF::fillWithIncreasingIds()
{
    std::iota(std::begin(id), std::end(id), 0);
}

void QuickFindUF::join(int p, int q) {
    assertValidArguments(p, q);
    if (connected(p, q)) return;

    performIndicesSubstitution(id[p], id[q]);
}

void QuickFindUF::assertValidArguments(int p, int q) const
{
    if (outOfRange(p, q))
        throw std::out_of_range("Elements indices out of range");
}

bool QuickFindUF::outOfRange(int p, int q) const
{
    return (negative(p) || exceedsSize(p) ||
            negative(q) || exceedsSize(q) );
}

void QuickFindUF::performIndicesSubstitution(int p_id, int q_id)
{
    for (size_t i = 0; i < size; ++i)
        if (id[i] == p_id)
            id[i] = q_id;
}