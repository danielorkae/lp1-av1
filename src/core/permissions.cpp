#include "permissions.hpp"

map<string, vector<string>> policies;

void load_permissions()
{
    vector<string> admin_permissions;
    vector<string> user_permissions;

    admin_permissions.push_back("list_buses");

    user_permissions.push_back("list_buses");

    policies["admin"] = admin_permissions;
    policies["user"] = user_permissions;
}

bool can(string role, string permission)
{
    if (policies.find(role) != policies.end())
    {
        vector<string> permissions = policies[role];
        for (int i = 0; i < permissions.size(); i++)
        {
            if (permissions[i] == permission)
            {
                return true;
            }
        }
    }

    return false;
}
