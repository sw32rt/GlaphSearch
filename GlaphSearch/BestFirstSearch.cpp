#include "pch.h"
#include "BestFirstSearch.h"
#include <cmath>

void BestFirstSearch::init(int StartVertexIndex, int SearchVertexIndex)
{
    this->CurrentVertexIndex = StartVertexIndex;
    this->StartVertexIndex = StartVertexIndex;
    this->SearchVertexIndex = SearchVertexIndex;

    // �T�������X�g�N���A
    //NextSearchVertexPriQue.empty();

    // �T���ςݏ��N���A
    for (int i = 0; i < slist.size(); i++)
    {
        slist.at(i) = E_Status_UnExplored;
    }

    // �T���ςݏ��N���A
    for (int i = 0; i < routelist.size(); i++)
    {
        routelist.at(i) = -1;
    }
}

int BestFirstSearch::GetNextSearchVertex(int CurrentVertex)
{
    int nextIndex = 0;

    std::vector<int> nextList = GetConnectionVertex(CurrentVertex);
    int index = 0;
    for (auto next : nextList)
    {
        // �T���ς݂̒��_��next�ɓ���Ȃ�
        if (slist[next] == E_Status_UnExplored)
        {
            routelist[next] = CurrentVertex;
            // ���� = sqrt( (p1.x - p2.x)^2 + (p1.y - p2.y)^2 )
            float dx = vlist[next].x - vlist[SearchVertexIndex].x;
            float dy = vlist[next].y - vlist[SearchVertexIndex].y;
            float distans = std::sqrtf((dx * dx) + (dy * dy));
            NextSearchVertexPriQue.push(std::make_pair(distans, next));
            slist[next] = E_Status_Looked;
        }
        index++;
    }

    // �����ň�ԌÂ����_����T�[�`����ƕ��D��A��ԐV�������_����T�[�`����Ɛ[���D��T���ɂȂ肻��
    nextIndex = NextSearchVertexPriQue.top().second;
    NextSearchVertexPriQue.pop();
    // ���̒��_���v�Z����
    return nextIndex;
}

bool BestFirstSearch::SearchNext(void)
{
    bool Finish = false;
    if (routelist[SearchVertexIndex] != -1)
    { // ���ݒn�ƖړI�n���ꏏ�Ȃ�T������
        int count = 0;
        int shortRouteIndex = SearchVertexIndex;
        while (shortRouteIndex != StartVertexIndex)
        {
            slist[shortRouteIndex] = E_Status_ShortestPath;
            shortRouteIndex = routelist[shortRouteIndex];
            count++;
        }
        ShortestPathDistance = count;
        Finish = true;
    }
    else
    {
        slist[CurrentVertexIndex] = E_Status_Searched;
        CurrentVertexIndex = GetNextSearchVertex(CurrentVertexIndex);
        slist[CurrentVertexIndex] = E_Status_Exploring;
    }
    return Finish;
}
