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

#include <set>

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

    std::map<std::string, std::string> parents;
    std::set<Node> visited;
    std::set<Node> open;
    std::priority_queue<Node, std::vector<Node>, nodeComparator> agenda;

    parents.insert(std::pair<std::string, std::string>(start, "NONE"));
    Node startNode = nodes[start];
    startNode.pathLen = 0;
    agenda.push(startNode);
    open.insert(startNode);

    while(agenda.empty() == false)
    {
        Node current = agenda.top();
        if (current.name == end) {
            std::cout << "path len: " << current.pathLen << std::endl;
            return this->get_path(end, parents);
        }
        agenda.pop();
        open.erase(current);
        visited.insert(current);
        std::vector<distances> neighbors = current.adjacency_list;
        for (distances &pair : neighbors) {
            std::string nodeName = pair.first;
            int distFromCurrent = pair.second;
            //std::cout << "neighbor " << nodeName << " w/ distance " << distFromCurrent << std::endl;
            Node n = nodes[nodeName];
            if (visited.count(n)) {
                //std::cout << "node " << nodeName << " already visited" <<std::endl;
                continue;
            }
            int newPathLen = current.pathLen + distFromCurrent; 
            if (newPathLen >= n.pathLen + n.heuristic) {
                //std::cout << "worse path found";
                continue;
            }
            parents[nodeName] = current.name;
            n.pathLen = newPathLen;
            if (!open.count(n)) {
                open.insert(n);
                agenda.push(n);
            }
        }
    }
    std::vector<std::string> u_suck;
    u_suck.push_back("u r bad adn this map is bad too");
    return u_suck;
}

std::vector<std::string> Search::get_path(std::string endNode, std::map<std::string, std::string> parents)
{
    std::vector<std::string> path;
    std::string current = endNode;
    path.push_back(current);
    while (parents[current] != "NONE") {
        path.push_back(parents[current]);
        current = parents[current];
    }
    return path;
}


std::ostream &operator<<(std::ostream &os, Search &s)
{
    std::vector<std::string> path = s.execute(s.g);
    os << "path: ";
    for (auto s : path) {
        os << s << ", ";
    }
    os << std::endl;
    //os << path << std::endl; 
    return os;
}
