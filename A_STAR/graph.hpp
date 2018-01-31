//
// Graph.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

class Graph 
{
  private:
    Node* start;
    Node* end;
    std::vector<Node> nodes;
  public:
    Graph(Node* start, Node* end, std::vector<Node> nodes) : start(start), end(end), nodes(nodes);

    friend Node* start_node();
    friend Node* end_node();
    friend std::ostream &operator<<(std::ostream &os, const Node &n);
    friend std::istream &operator>>(std::istream &is, Node &n);
    friend class Search;
}

#endif /* Graph_hpp */

