#include "DS_Graph.h"
using namespace DS;
bool Graph::Insert(int node1, int node2, double value)
{
    if(!change_num(node1, node2))
        return false;
    if (node1 > size || node2 > size)
        return false;
    matrix[node1 - 1][node2 - 1] = value;
    matrix[node2 - 1][node1 - 1] = value;
    node_set.insert(node1);
    node_set.insert(node2);
    node_pair_single = {node1, node2};
    node_pair.push_back(node_pair_single);
    // std::sort(node_set.begin(), node_set.end());
    return true;
}

void Graph::Print()
{
    std::cout.precision(4);
    for (it_matrix = matrix.begin(); it_matrix != matrix.end(); it_matrix++)
    {
        std::cout << "[ ";
        std::vector<double> submatrix = *it_matrix;
        for (it_submatrix = submatrix.begin(); it_submatrix != submatrix.end(); it_submatrix++)
        {
            if(*it_submatrix!=INF)
            {
                std::cout << std::fixed << *it_submatrix << " ";
            }
            else{
                std::cout << "INF" << " ";
            }
            
        }
        std::cout << "]" << std::endl;
    }
}

void Graph::PrintNodeSet()
{
    std::cout << "Node: [ ";
    for (it_node_set = node_set.begin(); it_node_set != node_set.end(); it_node_set++)
    {
        std::cout << *it_node_set << " ";
    }
    std::cout << "]" << std::endl;
}
bool Graph::Serach(double value)
{
    for (int i = 0; i < node_pair.size(); i++)
    {
        if (Get(node_pair.at(i)) == value)
        {
            node_pair_single = node_pair.at(i);
            PrintPair();
            return true;
        }
    }
    return false;
}

bool Graph::Delete(int node1, int node2)
{
    if(!change_num(node1, node2))
        return false;
    matrix[node1 - 1][node2 - 1] = 0;
    matrix[node2 - 1][node1 - 1] = 0;
    node_set.erase(node1);
    node_set.erase(node2);
    std::pair<int, int> p = {node1, node2};
    for (it_node_pair = node_pair.begin(); it_node_pair != node_pair.end(); it_node_pair++)
    {
        if (*it_node_pair == p)
        {
            node_pair.erase(it_node_pair);
            return true;
        }
    }
    return false;
}