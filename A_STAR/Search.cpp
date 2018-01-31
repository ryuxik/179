//
// search.cpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//

#include "Graph.hpp"
#include "Node.hpp"
#include "Search.hpp"

#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <queue>

class nodeComparator
{
    public:
        int operator() (Node& n1, Node& n2)
        {
            return (n1.pathLen + n1.heuristic) > (n2.pathLen + n2.heuristic);
        }
};

bool operator<(const Node& lhs, const Node& rhs) {
    return lhs.heuristic < rhs.heuristic;
}

std::vector<std::string> Search::execute(Graph g)
{
    std::string start = g.start;
    std::string end = g.end;
    std::map<std::string, Node> nodes = g.nodes;

    std::set<Node> visited;
    std::set<Node> open;
    std::priority_queue<Node, std::vector<Node>, nodeComparator> agenda;

    Node startNode = nodes[start];
    startNode.pathLen = 0;
    startNode.parent = "NONE";
    agenda.push(startNode);
    open.insert(startNode);

    while(agenda.empty() == false)
    {
        Node current = agenda.top();
        if (current.name == end) {
           return this->get_path(current, nodes);
        }
        agenda.pop();
        visited.insert(current);
        std::vector<distances> neighbors = current.adjacency_list;
        for (distances &pair : neighbors) {
            std::string nodeName = pair.first;
            int distFromCurrent = pair.second;
            Node n = nodes[nodeName];
            if (visited.count(n)) {
                continue;
            }
            if (!open.count(n)) {
                open.insert(n);
            }
            int newPathLen = current.pathLen + distFromCurrent; 
            if (newPathLen >= n.pathLen + n.heuristic) {
                continue;
            }
            n.parent = current.name;
            n.pathLen = newPathLen;
        }
    }
}

std::vector<std::string> Search::get_path(Node n, std::map<std::string, Node> nodes) {
    std::vector<std::string> path;
    while (nodes.count(n.name)) {
        path.push_back(n.name);
        n = nodes[n.parent];
    }
    return path;
}

std::ostream &operator<<(std::ostream &os, Search &s)
{
    std::vector<std::string> path = s.execute(s.g);
    for (auto s : path) {
        os << s;
    }
    os << std::endl;
    //os << path << std::endl; 
    return os;
}
