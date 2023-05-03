#ifndef DOMAIN_LINE_HPP
#define DOMAIN_LINE_HPP

#include <string>
#include <vector>
#include "bus.hpp"

using namespace std;

struct Line
{
    string name;
    int number;
    vector<Bus> buses;
};

#endif
