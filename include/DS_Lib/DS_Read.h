#ifndef __DS_READ__H__
#define __DS_READ__H__
#include <string>
#include <vector>
#include <iterator>
#include <cmath>
namespace DS
{
    struct pubStr
    {
        std::pair<int, int> p;
        double value;
    };
    class Read
    {
    public:
        void read_Method(std::string &);
        pubStr read;
    };

    int StrToInt(std::string);
    double StrToDouble(std::string);
    
}

#endif  //!__DS_READ__H__