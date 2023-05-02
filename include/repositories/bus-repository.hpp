#ifndef REPOSITORIES_BUS_REPOSITORY_HPP
#define REPOSITORIES_BUS_REPOSITORY_HPP

#include <vector>
#include "../../src/domain/bus.cpp"

using namespace std;

vector<Bus> get_buses();
void save_buses(vector<Bus> buses);

#endif
