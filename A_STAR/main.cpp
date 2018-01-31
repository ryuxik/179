// 
// main.cpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//

#include "graph.hpp"
#include "search.hpp"

int main (int argc, char* argv[])
{
  std::vector graphs<Graph>;
  std::vector searches<Search>;
  for (int i=1; i<argc; i++) {
    Graph g;
    Graph g << argv[i];
    graphs.push_back(g);
  }
	Search s{g};
	std::cout << s;
	return 0;
}

