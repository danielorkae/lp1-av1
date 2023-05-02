#ifndef CORE_PERMISSIONS_HPP
#define CORE_PERMISSIONS_HPP

#include <vector>
#include <map>
#include <string>

using namespace std;

bool can(string role, string permission);
void load_permissions();

#endif
