//
// search.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smols. All rights reserved.
//

#ifndef search_hpp
#define search_hpp

class search
{
  private:
    std::vector<std::string> path;
    graph g;
  public:
    search(graph g) : g(g),

    friend std::vector<std::string> get_path();
    friend std::istream &operator>>(std::istream &is, node &n);
    friend std::string execute(graph g);
}

#endif /* search_hpp */

