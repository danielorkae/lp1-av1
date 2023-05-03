#include <iostream>
#include <vector>
#include "controllers/bus-controller.hpp"
#include "core/io.hpp"
#include "domain/bus.hpp"
#include "presentation/bus-presenter.hpp"
#include "repositories/bus-repository.hpp"

using namespace std;

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

    string terminal = prompt_line("Digite o nome do terminal: ");

    vector<Bus> buses_found;

    for (unsigned int i = 0; i < buses.size(); i++)
    {
        if (buses[i].terminal == terminal)
        {
            buses_found.push_back(buses[i]);
        }
    }

    if (buses_found.size() == 0)
    {
        alert("Nenhum ônibus encontrado", true, false);
        return;
    }

    print_buses(buses_found);
}

void show_bus_itinerary()
{
    vector<Bus> buses = get_buses();

    title("Ver intinerário de ônibus");

    string bus_name = prompt_line("Digite o nome do ônibus: ");

    Bus bus;

    for (unsigned int i = 0; i < buses.size(); i++)
    {
        if (buses[i].name == bus_name)
        {
            bus = buses[i];
            break;
        }
    }

    if (bus.name == "")
    {
        alert("Nenhum ônibus encontrado", true, false);
        return;
    }

    print_bus(bus);
}
