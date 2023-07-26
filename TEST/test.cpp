#include "../include/DP_Lib/DP_Solve.h"
#include "../include/DS_Lib/DS_Graph.h"
#include "../include/DS_Lib/DS_Read.h"
#include <iostream>
class Solution
{
public:
    void solve()
    {
        DS::Graph graph;
        DS::Read read;

        int times;
        std::string str;
        std::cin >> times;
        while(times --)
        {
        std::cin >> str;
         read.read_Method(str);
        graph.Insert(read.read);
        }
        graph.Print();
        DP::Solve sol(graph);
        sol.Dijkstra(1);
        sol.PrintPath(1);
        
    }
};
int main()
{
    freopen("..\\IO\\in.txt", "r", stdin);
    freopen("..\\IO\\out.txt", "w", stdout);
    Solution sol;
    sol.solve();
}