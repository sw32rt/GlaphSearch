#pragma once
#include "GraphSearch.h"
#include <vector>
#include <deque>

// [‚³—Dæ’Tõ
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

