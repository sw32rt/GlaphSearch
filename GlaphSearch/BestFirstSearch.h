#pragma once
#include "GraphSearch.h"
#include <vector>
#include <queue>

// �ŗǗD��T��(�ړI�n�܂ł̋������Z�����_��ǂ��Ƃ���)
class BestFirstSearch : public GraphSearch
{
public:
	using GraphSearch::GraphSearch;
	void init(int StartVertexIndex, int SearchVertexIndex);
	bool SearchNext(void);
	std::priority_queue<
		std::pair<float, int>,                // �v�f�̌^��std::pair<float, int>
		std::vector<std::pair<float, int>>,   // �����R���e�i��std::vector (�f�t�H���g�̂܂�)
		std::greater<std::pair<float, int>>   // ���� (�f�t�H���g��std::less<T>)
	> NextSearchVertexPriQue;

private:
	int GetNextSearchVertex(int CurrentVertex);
};



