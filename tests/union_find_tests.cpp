#include "doctest.h"
#include "algorithms/quick_find.h"

TEST_CASE("Constructor rejects negative problem sizes")
{
    CHECK_THROWS_AS(QuickFind(-2), std::exception);
}

TEST_CASE("Constructor initializes empty vector")
{
    const int vector_size = 0;
    QuickFind quick_find(vector_size);
    REQUIRE(quick_find.getSize() == (std::size_t)vector_size);
}

TEST_CASE("Constructor initializes vector of positive size")
{
    const int vector_size = 3;
    QuickFind quick_find(vector_size);
    REQUIRE(quick_find.getSize() == (std::size_t)vector_size);
}

TEST_CASE("Elements connection operations behave correctly")
{
    QuickFind quick_find(5);

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

// connected() can't be called on negative numbers