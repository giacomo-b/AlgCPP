#include "doctest.h"
#include "algs/quick_find_UF.h"

TEST_CASE("Elements connection operations behave correctly")
{
    const int size = 5;
    Algs::QuickFindUF quick_find(size);

    SUBCASE("QuickFindUF initializes ids of the correct size")
    {
        REQUIRE(quick_find.size() == (std::size_t)size);
    }

    SUBCASE("An element is connected to itself (reflexive property)")
    {
        REQUIRE(quick_find.connected(1, 1));
        REQUIRE(quick_find.connected(3, 3));
    }

    SUBCASE("Different elements are initially disconnected")
    {
        REQUIRE(!quick_find.connected(1, 2));
        REQUIRE(!quick_find.connected(2, 3));
        REQUIRE(!quick_find.connected(3, 4));
    }

    SUBCASE("Elements get connected correctly")
    {
        quick_find.join(1, 2);
        REQUIRE(quick_find.connected(1, 2));
    }

    SUBCASE("If p is connected to q, then q is connected to p (symmetric property)")
    {
        quick_find.join(2, 3);
        REQUIRE(quick_find.connected(2, 3));
        REQUIRE(quick_find.connected(3, 2));
    }

    SUBCASE("If p is connected to q and q is connected to r, then p is connected to r (transitive property)")
    {
        quick_find.join(0, 1);
        quick_find.join(1, 3);
        REQUIRE(quick_find.connected(0, 3));
    }

    SUBCASE("Invalid to join negative-index elements")
    {
        CHECK_THROWS_AS(quick_find.join(-1, 3), std::exception);
        CHECK_THROWS_AS(quick_find.join(4, -2), std::exception);
    }

    SUBCASE("Invalid to join elements greater than problem size")
    {
        CHECK_THROWS_AS(quick_find.join(2, 5), std::exception);
        CHECK_THROWS_AS(quick_find.join(7, 1), std::exception);
    }
}

// TODO: connected() can't be called on negative numbers