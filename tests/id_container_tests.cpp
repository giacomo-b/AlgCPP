#include "doctest.h"
#include "algs/utils/id_container.h"

TEST_CASE("IDContainer rejects negative size")
{
    CHECK_THROWS_AS(Algs::Utils::IDContainer(-2), std::out_of_range);
}

TEST_CASE("IDContainer initializes empty container")
{
    const int size = 0;
    Algs::Utils::IDContainer ids(size);
    REQUIRE(ids.size() == (std::size_t)size);
}

TEST_CASE("IDContainer initializes container of the correct size")
{
    const int size = 3;
    Algs::Utils::IDContainer ids(size);
    REQUIRE(ids.size() == (std::size_t)size);
}

TEST_CASE("IDContainer initializes container with increasing values")
{
    Algs::Utils::IDContainer ids(5);
    REQUIRE(ids[ids.size()-1] == ids.size()-1);
}

TEST_CASE("IDContainer assigns values correctly")
{
    const int test_value = 42;
    Algs::Utils::IDContainer ids(5);
    ids[1] = test_value;
    REQUIRE(ids[1] == test_value);
}

TEST_CASE("IDContainer recognizes invalid indices")
{
    const int size = 5;
    Algs::Utils::IDContainer ids(size);
    REQUIRE(!ids.validIndex(-1));
    REQUIRE(!ids.validIndex(size));
}