//
// search.cpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//

#include "graph.hpp"
#include "node.hpp"

class nodeComparator
{
    public:
        int operator() (Node* n1, Node* n2)
        {
            return n1->pathLen > n2->pathLen;
        }
};

std::string execute(Graph g)
{
    Node* start = g.start;
    Node* end = g.end;
    std::vector<Node> nodes = g.nodes;

    std::set<Node> visited;
    std::priority_queue<Node, vector<Node>, nodeComparator> agenda;
   
    agenda.push(start);
    while(agenda.empty() == false)
    {
        
    }
}
