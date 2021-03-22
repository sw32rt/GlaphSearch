#pragma once
#include "Graph.h"
#include <vector>
#include <deque>

enum SearchStatus {
	E_Status_UnExplored = 0, // ���T��
	E_Status_Exploring, // �T����
	E_Status_Looked, // �m�[�h���������B�܂���ɉ����Ȃ����Ă��邩���Ă��Ȃ�
	E_Status_Searched, // �m�[�h�̐�ɉ����Ȃ����Ă��邩���ׂ�
	E_Status_ShortestPath, // �ŒZ�o�H
};

// ���D��T��
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


