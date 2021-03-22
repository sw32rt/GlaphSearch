#pragma once
#include "Graph.h"
#include <vector>
#include <deque>

enum SearchStatus {
	E_Status_UnExplored = 0, // –¢’Tõ
	E_Status_Exploring, // ’Tõ’†
	E_Status_Looked, // ƒm[ƒh‚ğŒ©‚Â‚¯‚½B‚Ü‚¾æ‚É‰½‚ª‚Â‚È‚ª‚Á‚Ä‚¢‚é‚©Œ©‚Ä‚¢‚È‚¢
	E_Status_Searched, // ƒm[ƒh‚Ìæ‚É‰½‚ª‚Â‚È‚ª‚Á‚Ä‚¢‚é‚©’²‚×‚½
	E_Status_ShortestPath, // Å’ZŒo˜H
};

// •—Dæ’Tõ
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


