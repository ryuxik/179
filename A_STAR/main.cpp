// 
// main.cpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

#include "Graph.hpp"
#include "Search.hpp"

int main (int argc, char* argv[])
{
    Graph g;
    std::vector<Search> searches;
    std::ifstream file(argv[1]);
    file >> g;
    Search s{g};
    std::cout << s;
    return 0;
}

