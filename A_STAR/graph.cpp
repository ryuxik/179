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
//e \n, for each one of E neighbors then 
//}
// first node is starting node
// second node is ending node
std::istream &operator>>(std::istream &is, Graph &g)
{	
	std::ifstream myFile;
	std::string filename;
	is >> filename;
	myFile.open(filename);
	std::vector<Node> all_nodes;
	int N;
	for (int i = 0; i < N, i++) {
		std::string name;
		myFile >> name;
		int heuristic;
		myFile >> heuristic;
		int E;
		myFile >> E;
		std::vector<distances> neighbors;
		for (int j = 0; j < E; j++) {
			std:string neighbor;
			int distance;
			myFile >> neighbor;
			myFile >> distance;
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
	myFile.close();
	return is;
}