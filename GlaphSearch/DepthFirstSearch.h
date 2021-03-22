#pragma once
#include "GraphSearch.h"
#include <vector>
#include <deque>

// �[���D��T��
class DepthFirstSearch : public GraphSearch
{
public:
	using GraphSearch::GraphSearch;
	void init(int StartVertexIndex, int SearchVertexIndex);
	bool SearchNext(void);
	std::deque<int> NextSearchVertexStack;
private:
	int GetNextSearchVertex(int CurrentVertex);

};

