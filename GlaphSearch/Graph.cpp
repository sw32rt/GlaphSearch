#include "pch.h"
#include "Graph.h"

Vertex::Vertex(int x, int y)
	: x(x)
	, y(y)
{
}

Vertex::operator CPoint()
{
	return CPoint(x, y);
}

Edge::Edge(int from, int to)
	: from(from)
	, to(to)
{
}


Graph::Graph(std::vector<Vertex> v, std::vector<Edge> e)
	: vlist(v)
	, elist(e)
{
	slist.resize(vlist.size());
	for (auto& s : slist)
	{
		s = 0;
	}

	routelist.resize(vlist.size());
	for (auto& r : routelist)
	{
		r = 0;
	}
}

std::vector<int> Graph::GetConnectionVertex(int VertexIndex)
{
	std::vector<int> VertexList;
	for (auto e : elist)
	{
		if (e.from == VertexIndex)
		{
			VertexList.push_back(e.to);
		}
		else if (e.to == VertexIndex)
		{
			VertexList.push_back(e.from);
		}
	}
	return VertexList;
}
