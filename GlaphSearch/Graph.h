#pragma once
#include "pch.h"
#include <vector>


// ���_�N���X
class Vertex
{
public:
	Vertex(int x, int y);
	int x;
	int y;
	operator CPoint();
};

// �ӃN���X
class Edge
{
public:
	Edge(int from, int to);
	int from;
	int to;
};


// �O���t
class Graph
{
public:
	Graph(std::vector<Vertex> v, std::vector<Edge> e);
	std::vector<Vertex> vlist;
	std::vector<Edge> elist;
	std::vector<int> slist;
	std::vector<int> routelist;
	virtual std::vector<int> GetConnectionVertex(int VertexIndex);
};

