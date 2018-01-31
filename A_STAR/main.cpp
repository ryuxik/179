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

#include "Graph.hpp"
#include "Search.hpp"

int main (int argc, char* argv[])
{
    std::vector<Graph> graphs;
    std::vector<Search> searches;
    for (int i=1; i<argc; i++) {
        Graph g;
        argv[i] >> g;
        graphs.push_back(g);
    }
    for (auto const& g : graphs) {
        Search s{g};
        std::cout << s;
    }
    return 0;
}

