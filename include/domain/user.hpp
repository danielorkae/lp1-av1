#ifndef DOMAIN_USER_HPP
#define DOMAIN_USER_HPP

#include <string>

using namespace std;

struct User
{
    string name;
    string role; // "admin" or "user"
};

#endif
