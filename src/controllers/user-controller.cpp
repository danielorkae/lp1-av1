#include <iostream>
#include "controllers/bus-controller.hpp"
#include "controllers/feedback-controller.hpp"
#include "controllers/user-controller.hpp"
#include "core/io.hpp"

using namespace std;

void user_menu()
{
    vector<string> options = {
        "Listar ônibus",
        "Buscar ônibus por terminal",
        "Ver intinerário de ônibus",
        "Deixar um feedback",
    };

    title("Menu do Usuário");

    int option = prompt_menu(options, true, true);
    clear_screen();

    switch (option)
    {
    case 1:
        list_buses();
        break;
    case 2:
        search_bus_by_terminal();
        break;
    case 3:
        show_bus_itinerary();
        break;
    case 4:
        leave_feedback();
        break;
    case 5:
        exit(0);
        break;
    }
    pause();
}
