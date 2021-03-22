#include "pch.h"
#include "BestFirstSearch.h"
#include <cmath>

void BestFirstSearch::init(int StartVertexIndex, int SearchVertexIndex)
{
    this->CurrentVertexIndex = StartVertexIndex;
    this->StartVertexIndex = StartVertexIndex;
    this->SearchVertexIndex = SearchVertexIndex;

    // 探索順リストクリア
    //NextSearchVertexPriQue.empty();

    // 探索済み情報クリア
    for (int i = 0; i < slist.size(); i++)
    {
        slist.at(i) = E_Status_UnExplored;
    }

    // 探索済み情報クリア
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
        // 探索済みの頂点はnextに入れない
        if (slist[next] == E_Status_UnExplored)
        {
            routelist[next] = CurrentVertex;
            // 距離 = sqrt( (p1.x - p2.x)^2 + (p1.y - p2.y)^2 )
            float dx = vlist[next].x - vlist[SearchVertexIndex].x;
            float dy = vlist[next].y - vlist[SearchVertexIndex].y;
            float distans = std::sqrtf((dx * dx) + (dy * dy));
            NextSearchVertexPriQue.push(std::make_pair(distans, next));
            slist[next] = E_Status_Looked;
        }
        index++;
    }

    // ここで一番古い頂点からサーチすると幅優先、一番新しい頂点からサーチすると深さ優先探索になりそう
    nextIndex = NextSearchVertexPriQue.top().second;
    NextSearchVertexPriQue.pop();
    // 次の頂点を計算する
    return nextIndex;
}

bool BestFirstSearch::SearchNext(void)
{
    bool Finish = false;
    if (routelist[SearchVertexIndex] != -1)
    { // 現在地と目的地が一緒なら探索完了
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
