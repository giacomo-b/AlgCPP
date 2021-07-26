#include "algs/quick_find_UF.h"
#include <stdexcept>

using namespace Algs;

QuickFindUF::QuickFindUF(int size)
    : ids(size)
{
    
}

QuickFindUF::~QuickFindUF()
{

}

void QuickFindUF::join(int p, int q) {
    assertValidArguments(p, q);
    if (connected(p, q)) return;

    performIdsSubstitution(ids[p], ids[q]);
}

void QuickFindUF::assertValidArguments(int p, int q) const
{
    if (!(ids.validIndex(p) && ids.validIndex(q)))
        throw std::out_of_range("Elements indices invalid.");
}

void QuickFindUF::performIdsSubstitution(int p_id, int q_id)
{
    for (size_t i = 0; i < ids.size(); ++i)
        if (ids[i] == p_id)
            ids[i] = q_id;
}