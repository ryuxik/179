//
// node.cpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Coypright Smols. All rights reserved.
//

#include "Node.hpp"

std::vector<std::string> Node::get_neighbors() {
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
	os << "Node: " << n.name << " has heuristic: " << n.heuristic << " and has neighbors: " << n.adjacency_list << std::endl;
	return os;
}
