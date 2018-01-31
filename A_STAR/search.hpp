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
        std::vector<std::string> path;
        Graph g;
    public:
        Search(Graph g) : g(g),

        //friend std::vector<std::string> get_path();
        friend std::istream &operator>>(std::istream &is, Node &n);
        friend std::string execute(Graph g);
}

#endif /* Search_hpp */

