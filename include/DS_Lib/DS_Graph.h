#ifndef __DS_GRAPH__H__
#define __DS_GRAPH__H__
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include "DS_Read.h"
#define INF 0x7f7f7f7f
namespace DS
{
    inline bool change_num(int &x, int &y)
    {
        if (x == 0 || y == 0)
            return false;
        if (x < y)
            return true;
        int temp = x;
        x = y;
        y = temp;
        return true;
    }
    class Graph
    {
    public:
        Graph(int size = 10) : size(size){};
        virtual ~Graph() = default;
        bool Insert(int, int, double);
        bool Insert(pubStr &read) { return Insert(read.p.first, read.p.second, read.value); }
        double Get(int x, int y) const { return matrix[x - 1][y - 1]; };
        double Get(std::pair<int, int> pair)
        {
            return matrix[pair.first - 1][pair.second - 1];
        }
        bool Serach(double);
        bool SelfCheck() const;
        bool Delete(int, int);
        void Print();
        void PrintNodeSet();
        std::vector<std::vector<double>> GetMatrix() const { return matrix; }
        std::set<int> GetSet() { return node_set; }
        std::vector<std::pair<int, int>> GetPairLst() { return node_pair; }

    private:
        void PrintPair() { std::cout << "Node1 = " << node_pair_single.first << ", Node2 = " << node_pair_single.second << std::endl; }
        int size;
        std::vector<std::vector<double>> matrix = std::vector<std::vector<double>>(size, std::vector<double>(size, INF));
        std::set<int> node_set;
        std::set<int>::iterator it_node_set;
        std::pair<int, int> node_pair_single;
        std::vector<std::pair<int, int>> node_pair;
        std::vector<std::pair<int, int>>::iterator it_node_pair;
        std::vector<std::vector<double>>::const_iterator it_matrix;
        std::vector<double>::const_iterator it_submatrix;
    };
}
#endif //!__DS_GRAPH__H__