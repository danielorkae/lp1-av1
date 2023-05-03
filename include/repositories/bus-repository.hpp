#ifndef REPOSITORIES_BUS_REPOSITORY_HPP
#define REPOSITORIES_BUS_REPOSITORY_HPP

#include <vector>
#include "domain/bus.hpp"

using namespace std;

vector<Bus> get_buses();
Bus get_bus_by_name(string name, vector<Bus> buses);
void save_buses(vector<Bus> buses);
void save_bus(Bus bus, vector<Bus> buses);
void drop_bus(Bus bus, vector<Bus> buses);

#endif
