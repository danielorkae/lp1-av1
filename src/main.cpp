#include <iostream>

#include "controllers/auth-controller.hpp"
#include "controllers/user-controller.hpp"
#include "controllers/admin-controller.hpp"

using namespace std;

int main()
{
    string user_role;

    auth_menu(user_role);

    while (true)
    {
        if (user_role == "passenger")
        {
            user_menu();
        }
        else if (user_role == "admin")
        {
            admin_menu();
        }
        else
        {
            exit(1);
        }
    }

    return 0;
}
