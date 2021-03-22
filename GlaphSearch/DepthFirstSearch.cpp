#include "pch.h"
#include "DepthFirstSearch.h"

void DepthFirstSearch::init(int StartVertexIndex, int SearchVertexIndex)
{
    this->CurrentVertexIndex = StartVertexIndex;
    this->StartVertexIndex = StartVertexIndex;
    this->SearchVertexIndex = SearchVertexIndex;

    // �T�������X�g�N���A
    NextSearchVertexStack.clear();

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

int DepthFirstSearch::GetNextSearchVertex(int CurrentVertex)
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
            NextSearchVertexStack.push_back(next);
            slist[next] = E_Status_Looked;
        }
        index++;
    }

    // �����ň�ԌÂ����_����T�[�`����ƕ��D��A��ԐV�������_����T�[�`����Ɛ[���D��T���ɂȂ肻��
    nextIndex = NextSearchVertexStack.back();
    NextSearchVertexStack.pop_back();
    // ���̒��_���v�Z����
    return nextIndex;
}

bool DepthFirstSearch::SearchNext(void)
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

