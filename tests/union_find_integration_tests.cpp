#include "doctest.h"
#include "algorithms/union_find.h"
#include "algorithms/quick_find.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const std::string expected_output = "4 3, 3 8, 6 5, 9 4, 2 1, 5 0, 7 2, 6 1s";

std::string connectAccordingToFile(UnionFind* uf, std::ifstream &file);

TEST_CASE("Dynamic-connectivity client")
{
    std::ifstream client_file("./../tests/union_find_client_file.txt");
    if (client_file.is_open())
    {
        int n_elements;
        client_file >> n_elements;
    
        SUBCASE("Quick-find algorithm")
        {
            UnionFind *union_find = new QuickFind(n_elements);
            std::string output = connectAccordingToFile(union_find, client_file);
        }
    }
}

std::string connectAccordingToFile(UnionFind* uf, std::ifstream &file)
{
    std::string output = "";
    int p, q;
    while (file >> p >> q)
    {
        if (!uf->connected(p, q))
        {
            uf->join(p, q);
            output += std::to_string(p) + ' ' + std::to_string(q) + ", ";
        }
    }
    return output;
}