//
// node.cpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Coypright Smols. All rights reserved.
//

#include "node.hpp"

std::vector<node> node::get_neighbors() {
    return this->adjacency_list;
}

double node::get_heuristic() {
    return this->heuristic;
}

node* node::get_parent() {
    return this->parent;
}

void node::set_parent(*node p) {
    this->parent = p;
}
