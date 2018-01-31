//
// node.hpp
// A_STAR
//
// Created by Reb and Santi on 1/30/18
// Copyright 2018 Smol. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

class node
{
	private:
		std::string name;
		double heuristic;
		std::vector<node> adjacency_list;
		node* parent;
	public:
		node() : name(""), heuristic(0.0), adjacency_list(std::vector<node>), parent(NULL);
		node(std::string Name, double Heuristic, std::vector<node> Adjacency_list) : name(Name), heuristic(Heuristic), adjacency_list(Adjacency_list);

		friend node* getParent();
		friend void setParent();
		friend std::vector<node> get_neighbors();
		friend double get_heuristic();
		friend std::ostream &operator<<(std::ostream &os, const node &n);
		friend std::istream &operator>>(std::istream &is, node &n);
}

#endif /* node_hpp */

