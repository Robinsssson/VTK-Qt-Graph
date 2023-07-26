#include "DS_Read.h"
#include <iostream>
void DS::Read::read_Method(std::string &str)
{
    std::vector<int> v;
    std::string::iterator it_str;
    for (it_str = str.begin(); it_str != str.end(); it_str++)
    {
        if (*it_str == ' ')
        {
            str.erase(it_str);
        }
    }
    for (it_str = str.begin(); it_str != str.end(); it_str++)
    {
        if (*it_str == ',' || *it_str == '\n')
        {
            v.push_back(it_str - str.begin());
        }
    }
    read.p.first = StrToInt(str.substr(0, v.at(0)));
    read.p.second = StrToInt(str.substr(v.at(0) + 1, v.at(1) - v.at(0) - 1));
    read.value = StrToDouble(str.substr(v.at(1) + 1, v.at(2) - v.at(1) - 1));
}

int DS::StrToInt(std::string str)
{
    return (int)atoi(str.c_str());
}
double DS::StrToDouble(std::string str)
{
    double sign = 0;
    int x = 0;
    const char *cstr = str.c_str();
    for (int i = 0; i < str.size(); i++)
    {
        if (cstr[i] == '.')
        {
            x = StrToInt(str.substr(0, i));
            sign += (double)x;
            sign += StrToInt(str.substr(i + 1, str.size() - i)) * pow(0.1, str.size() - i - 1);
            return sign;
        }
    }
    sign = StrToInt(str);
    return sign;
}