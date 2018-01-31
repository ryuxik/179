//
// Node.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smol. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

typdedef std::pair<std::string, int> distances; 

class Node
{
    private:
        std::string name;
        int heuristic;
        std::vector<distances> adjacency_list;
        std::string parent;
        int pathLen;
    public:
        Node() : name(""), heuristic(0.0), adjacency_list(std::vector<Node>), parent(NULL), pathLen(std::numeric_limits<int>::max());
        Node(std::string Name, int Heuristic, std::vector<std::string> Adjacency_list) : name(Name), heuristic(Heuristic), adjacency_list(Adjacency_list), parent(NULL), pathLen(std::numeric_limits<int>::max());

        friend std::string get_parent();
        friend void set_parent(std::string p);
        friend std::vector<std::string> get_neighbors();
        friend int get_heuristic();
        friend std::ostream &operator<<(std::ostream &os, const Node &n);
        friend class Graph;
        friend class nodeComparator;
}

#endif /* Node_hpp */

