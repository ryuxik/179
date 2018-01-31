//
// Node.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smol. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

class Node
{
    private:
        std::string name;
        double heuristic;
        std::vector<Node> adjacency_list;
        node* parent;
    public:
        Node() : name(""), heuristic(0.0), adjacency_list(std::vector<Node>), parent(NULL);
        Node(std::string Name, double Heuristic, std::vector<Node> Adjacency_list) : name(Name), heuristic(Heuristic), adjacency_list(Adjacency_list), parent(NULL);

        friend Node* get_parent();
        friend void set_parent(*node p);
        friend std::vector<Node> get_neighbors();
        friend double get_heuristic();
        friend std::ostream &operator<<(std::ostream &os, const Node &n);
        friend std::istream &operator>>(std::istream &is, Node &n);
        friend class Graph;
}

#endif /* Node_hpp */

