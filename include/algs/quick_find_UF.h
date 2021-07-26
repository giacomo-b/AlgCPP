#pragma once

#include "union_find.h"
#include "utils/id_container.h"

namespace Algs
{
class QuickFindUF : public UnionFind
{
public:
    QuickFindUF(int size);

    ~QuickFindUF();

    void join(int p, int q);

    inline bool connected(int p, int q) const
    {
        return (ids[p] == ids[q]);
    }

    inline std::size_t size() const
    {
        return ids.size();
    }

private:
    Utils::IDContainer ids;

    void assertValidArguments(int p, int q) const;

    void performIdsSubstitution(int p_id, int q_id);
};
}