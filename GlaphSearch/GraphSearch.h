#pragma once
#include "Graph.h"
#include <vector>
#include <deque>

enum SearchStatus {
	E_Status_UnExplored = 0, // 未探索
	E_Status_Exploring, // 探索中
	E_Status_Looked, // ノードを見つけた。まだ先に何がつながっているか見ていない
	E_Status_Searched, // ノードの先に何がつながっているか調べた
	E_Status_ShortestPath, // 最短経路
};

// 幅優先探索
class GraphSearch : public Graph
{
public:
	using Graph::Graph;
	int CurrentVertexIndex = 0;
	int StartVertexIndex = 0;
	int SearchVertexIndex = 0;
	int ShortestPathDistance = 0;
	virtual void init(int StartVertexIndex, int SearchVertexIndex) = 0;
	virtual bool SearchNext(void) = 0;
	int GetShortestPathDistance(void) { return ShortestPathDistance;  };

private:
	virtual int GetNextSearchVertex(int CurrentVertex) = 0;

};


