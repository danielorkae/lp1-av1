#include <iostream>
#include "../core/permissions.cpp"

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
    cout << "Listando ônibus" << endl;
}

void search_bus_by_terminal()
{
    cout << "Buscando ônibus por terminal" << endl;
}

void show_bus_itinerary()
{
    cout << "Mostrando intinerário de ônibus" << endl;
}

void leave_feedback()
{
    cout << "Deixando um feedback" << endl;
}
