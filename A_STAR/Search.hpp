//
// Search.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//

#ifndef Search_hpp
#define Search_hpp

class Search
{
    private:
        Graph g;
    public:
        Search(Graph g) : g(g) {};

        friend std::ostream &operator<<(std::ostream &os, Search &s);
        std::vector<std::string> execute(Graph g);
        std::vector<std::string> get_path(Node n, std::map<std::string, Node> nodes);
};

#endif /* Search_hpp */

