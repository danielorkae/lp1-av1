#include <iostream>
#include <vector>
#include "bus.cpp"

using namespace std;

struct Line
{
    string name;
    int number;
    vector<Bus> buses;
};
