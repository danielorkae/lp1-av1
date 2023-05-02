#include <iostream>
#include "include/core/io.hpp"
#include "include/core/permissions.hpp"
// #include "include/repositories/bus-repository.hpp"
#include "include/presentation/bus-presentation.hpp"

using namespace std;

void user_menu()
{
    cout << "1. Listar ônibus" << endl
         << "2. Buscar ônibus por terminal" << endl
         << "3. Ver intinerário de ônibus" << endl
         << "4. Deixar um feedback" << endl
         << "5. Voltar" << endl;

    int option;
    cin >> option;

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
        break;
    default:
        cout << "Opção inválida" << endl;
        break;
    }
}

void list_buses()
{
    vector<Bus> buses = get_buses();

    title("Lista de ônibus");
    print_buses(buses);
}

void search_bus_by_terminal()
{
    vector<Bus> buses = get_buses();

    title("Buscar ônibus por terminal");

    string terminal;
    cout << "Digite o terminal: ";
    cin >> terminal;

    vector<Bus> buses_found;

    for (int i = 0; i < buses.size(); i++)
    {
        if (buses[i].terminal == terminal)
        {
            buses_found.push_back(buses[i]);
        }
    }

    if (buses_found.size() == 0)
    {
        cout << "Nenhum ônibus encontrado" << endl;
        return;
    }

    print_buses(buses_found);
}

void show_bus_itinerary()
{
    cout << "Mostrando intinerário de ônibus" << endl;
}

void leave_feedback()
{
    cout << "Deixando um feedback" << endl;
}
