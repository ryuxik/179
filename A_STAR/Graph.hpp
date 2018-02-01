//
// Graph.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include "Node.hpp"
#include <string>
#include <iostream>
#include <map>

class Graph 
{
    private:
        std::string start;
        std::map<std::string, Node> nodes;
    public:
        std::string end;
        friend std::ostream &operator<<(std::ostream &os, const Graph &g);
        friend std::istream &operator>>(std::istream &is, Graph &g);
        friend class Search;
        //friend std::ostream &operator<<(std::ostream &os, Search &s);
    
};

#endif /* Graph_hpp */

