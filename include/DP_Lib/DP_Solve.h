#ifndef __DP_SOLVE__H__
#define __DP_SOLVE__H__
#include <algorithm>
#include <iterator>
#include <vector>
#include "../DS_Lib/DS_Graph.h"
#define INF 0x7f7f7f7f
const int N = 105; // 点的个数上限
namespace DP
{
    struct Dis
    {
        std::string path;
        double value;
        bool visit;
        Dis()
        {
            visit = false;
            value = 0;
            path = "";
        }
    };

    class Solve
    // from A to B
    {
    public:
        Solve(DS::Graph graph)
        {
            this->arc = graph.GetMatrix();
            this->vexnum = graph.GetSet().size();
            this->edge = graph.GetPairLst().size();
            dis = new Dis[this->vexnum];
        };
        ~Solve() 
        {
            delete[] dis;
        };
        void Dijkstra(int begin);
        void PrintPath(int begin);
    private:
        std::vector<std::vector<double>> arc;
        int vexnum; // 图的顶点个数
        int edge;   // 图的边数
        Dis *dis;
        // bool vis[N];
    };


}

#endif //!__DP_SOLVE__H__