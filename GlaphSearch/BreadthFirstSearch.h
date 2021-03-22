#pragma once
#include "GraphSearch.h"
#include <vector>
#include <deque>

// •—Dæ’Tõ
class BreadthFirstSearch : public GraphSearch
{
public:
	using GraphSearch::GraphSearch;
	void init(int StartVertexIndex, int SearchVertexIndex);
	bool SearchNext(void);
	std::deque<int> NextSearchVertexStack;
private:
	int GetNextSearchVertex(int CurrentVertex);

};

