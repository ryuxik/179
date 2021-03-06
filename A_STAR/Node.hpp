//
// Node.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smol. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <vector>
#include <string>
#include <iostream>

typedef std::pair<std::string, int> distances; 

class Node
{
    private:
        std::string name;
        int heuristic;
        std::vector<distances> adjacency_list;
        std::string parent;
        int pathLen;
    public:
        Node() : name(""), heuristic(0), adjacency_list(std::vector<distances>()), parent(""), pathLen(9999) {};
        Node(std::string Name, int Heuristic, std::vector<distances> Adjacency_list) : name(Name), heuristic(Heuristic), adjacency_list(Adjacency_list), parent(""), pathLen(9999){};

        std::string get_parent();
        void set_parent(std::string p);
        std::vector<distances> get_neighbors();
        int get_heuristic();
        friend std::ostream &operator<<(std::ostream &os, const Node &n);
        friend class Graph;
        friend class nodeComparator;
        friend class Search;
        friend bool operator<(const Node &lhs, const Node &rhs);
};

#endif /* Node_hpp */

