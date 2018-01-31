//
// graph.cpp
// A_STAR
//
// Created by Reb and Santi
// Copyright 2018 Smols. All rights reserved.
//

#include "Graph.hpp"

std::ostream &operator<<(std::ostream &os, const Graph &g) {
	os << "This graph has nodes:" << std::endl;
	for (auto const& entry: g.nodes) {
		os << "\t" << entry.second << std::endl;
	}
}

//istream format
//N \n, number of nodes
//each node has format {
//S \n, name of node
//H \n, heuristic
//E \n, number of neighbors
//e d \n, e name d distance for each one of E neighbors
//}
// first node is starting node
// second node is ending node
std::istream &operator>>(std::istream &is, Graph &g)
{	
	std::vector<Node> all_nodes;
	int N;
	for (int i = 0; i < N, i++) {
		std::string name;
		is >> name;
		int heuristic;
		is >> heuristic;
		int E;
		is >> E;
		std::vector<distances> neighbors;
		for (int j = 0; j < E; j++) {
			std:string neighbor;
			int distance;
			is >> neighbor;
			is >> distance;
			neighbors.push_back(distances(neighbor, distance));
		}
		if (i == 0) {
			g.start = name;
		}
		if (i == 1) {
			g.end = name;
		}
		
		g.nodes[name] = Node(name, heuristic, neighbors);
	}
	return is;
}