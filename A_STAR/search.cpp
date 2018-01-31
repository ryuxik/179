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
            return (n1->pathLen + n1->heuristic) > (n2->pathLen + n2->heuristic);
        }
};

std::vector<std::string> execute(Graph g)
{
    std::string start = g.start;
    std::string end = g.end;
    std::map<std::string, Node> nodes = g.nodes;

    std::set<Node> visited;
    std::set<Node> open;
    std::priority_queue<Node, vector<Node>, nodeComparator> agenda;

    Node startNode = nodes[start];
    startNode.pathLen = 0;
    startNode.parent = "NONE";
    agenda.push(startNode);
    open.insert(startNode);

    while(agenda.empty() == false)
    {
        Node current = agenda.top();
        if (current.name == end) {
           return get_path(current);
        }
        agenda.pop();
        visited.insert(current);
        std::vector<std::string> neighbors = current.adjacency_list;
        for (auto nodeName : neighbors) {
            Node n = nodes[nodeName];
            if (visited.count(n)) {
                continue;
            }
            if (!open.count(n)) {
                open.insert(n);
            }
            int newPathLen = current.pathLen + /*TODO*/ current.distanceToNeighbor(n);
            if (newPathLen >= n.pathLen + n.heuristic) {
                continue
            }
            n.parent = current.name;
            n.pathLen = newPathLen;
        }
    }
}

std::vector<std::string> get_path(Node n, std::map<std::string, Node> nodes) {
    std::vector<std::string> path;
    while (nodes.count(n.name)) {
        path.push_back(n.name);
        n = nodes[n.parent];
    }
    return path;
}
