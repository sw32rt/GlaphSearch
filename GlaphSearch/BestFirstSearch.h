#pragma once
#include "GraphSearch.h"
#include <vector>
#include <queue>

// 最良優先探索(目的地までの距離が短い頂点を良いとする)
class BestFirstSearch : public GraphSearch
{
public:
	using GraphSearch::GraphSearch;
	void init(int StartVertexIndex, int SearchVertexIndex);
	bool SearchNext(void);
	std::priority_queue<
		std::pair<float, int>,                // 要素の型はstd::pair<float, int>
		std::vector<std::pair<float, int>>,   // 内部コンテナはstd::vector (デフォルトのまま)
		std::greater<std::pair<float, int>>   // 昇順 (デフォルトはstd::less<T>)
	> NextSearchVertexPriQue;

private:
	int GetNextSearchVertex(int CurrentVertex);
};



