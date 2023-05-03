#ifndef REPOSITORIES_BUS_REPOSITORY_HPP
#define REPOSITORIES_BUS_REPOSITORY_HPP

#include <vector>
#include "domain/bus.hpp"

using namespace std;

vector<Bus> get_buses();
void save_buses(vector<Bus> buses);

#endif
