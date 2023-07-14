#pragma once
template<class N>

class Graph {

public:
	Graph() {};
	Graph(std::vector<N> nodes, std::vector<std::pair<N, N>> edges)
	{};

	virtual ~Graph() {};
	virtual bool adjacent(N x, N y) = 0;
	virtual std::vector<N> neighbors(N x) = 0;
	virtual void addNode(N x) = 0;
	virtual void addEdge(N x, N y) = 0;
	virtual void deleteEdge(N x, N y) = 0;

};