//
// graph.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

class graph 
{
  private:
    node* start;
    node* end;
    std::vector<node> nodes;
  public:
    graph(node* start, node* end, std::vector<node> nodes) : start(start), end(end), nodes(nodes);

    friend node* startNode();
    friend node* endNode();
    friend std::ostream &operator<<(std::ostream &os, const node &n);
    friend std::istream &operator>>(std::istream &is, node &n);
}

#endif /* graph_hpp */

