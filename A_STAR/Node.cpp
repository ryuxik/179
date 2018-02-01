//
// node.cpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Coypright Smols. All rights reserved.
//

#include "Node.hpp"

std::vector<distances> Node::get_neighbors() {
    return this->adjacency_list;
}

int Node::get_heuristic() {
    return this->heuristic;
}

std::string Node::get_parent() {
    return this->parent;
}

void Node::set_parent(std::string p) {
    this->parent = p;
}

std::ostream &operator<<(std::ostream &os, const Node &n) {
	os << "node " << n.name << " / heuristic " << n.heuristic << " / " << sizeof(n.adjacency_list) << " neighbors" << std::endl;  
	for (auto const& edge: n.adjacency_list) {
		os << n.name << "->" << edge.first << ", " << edge.second << std::endl;
		os<<"---------"<<std::endl;
	}
	os << std::endl;
	return os;
}
