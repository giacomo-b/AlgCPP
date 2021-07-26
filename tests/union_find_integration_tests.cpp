#include "doctest.h"
#include "algorithms/union_find.h"
#include "algorithms/quick_find.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void connectAccordingToFile(UnionFind* uf, std::ifstream &file);

TEST_CASE("Dynamic-connectivity client")
{
    std::ifstream client_file("union_find_client_file.txt");
    int n_elements;
    client_file >> n_elements;
    
    SUBCASE("Quick-find algorithm")
    {
        UnionFind *union_find = new QuickFind(n_elements);
        connectAccordingToFile(union_find, client_file);
    }
}

void connectAccordingToFile(UnionFind* uf, std::ifstream &file)
{
    int p, q;
    while (file >> p >> q)
    {
        if (!uf->connected(p, q))
        {
            uf->join(p, q);
            std::cout << p << ' ' << q << '\n';
        }
    }
}