#include <iostream>
#include <vector>
#include "controllers/bus-controller.hpp"
#include "core/io.hpp"
#include "domain/bus.hpp"
#include "printers/bus-printer.hpp"
#include "repositories/bus-repository.hpp"
#include "bus-controller.hpp"

using namespace std;

/// @brief Lista todos os ônibus
/// @details Usa a função get_buses() do repository para obter a lista de ônibus e a imprime
void list_buses()
{
    vector<Bus> buses = get_buses();

    title("Lista de ônibus");
    print_buses(buses);
}

/// @brief Busca um ônibus pelo nome
/// @details Solicita ao usuário o nome do ônibus e busca na lista de ônibus
void search_bus_by_name()
{
    vector<Bus> buses = get_buses();

    title("Buscar ônibus por nome");

    string name = prompt_line("Digite o nome do ônibus: ");

    Bus bus = get_bus_by_name(name, buses);

    if (bus.name == "")
    {
        alert("Nenhum ônibus encontrado", true, false);
        return;
    }

    print_bus(bus);
}

/// @brief Busca um ônibus pelo terminal
/// @details Solicita ao usuário o nome do terminal e busca na lista de ônibus
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

/// @brief Mostra o itinerário de um ônibus
/// @details Solicita ao usuário o nome do ônibus e busca na lista de ônibus
void show_bus_itinerary()
{
    vector<Bus> buses = get_buses();

    title("Ver intinerário de ônibus");

    string bus_name = prompt_line("Digite o nome do ônibus: ");

    Bus bus = get_bus_by_name(bus_name, buses);

    if (bus.name == "")
    {
        alert("Nenhum ônibus encontrado", true, false);
        return;
    }

    print_bus(bus);
}

/// @brief Atualiza o terminal de um ônibus
/// @details Solicita o nome do ônibus e o novo terminal e atualiza na lista de ônibus
void update_bus_terminal()
{
    vector<Bus> buses = get_buses();

    title("Atualizar terminal de ônibus");

    string bus_name = prompt_line("Digite o nome do ônibus: ");

    Bus bus = get_bus_by_name(bus_name, buses);

    if (bus.name == "")
    {
        alert("Nenhum ônibus encontrado", true, false);
        return;
    }

    string new_terminal = prompt_line("Digite o novo terminal: ");

    bus.terminal = new_terminal;

    save_bus(bus, buses);
}

/// @brief Atualiza o itinerário de um ônibus
/// @details Solicita o nome do ônibus e o novo itinerário e atualiza na lista de ônibus
void update_bus_itinerary()
{
    vector<Bus> buses = get_buses();

    title("Atualizar itinerário de ônibus");

    string bus_name = prompt_line("Digite o nome do ônibus: ");

    Bus bus = get_bus_by_name(bus_name, buses);

    if (bus.name == "")
    {
        alert("Nenhum ônibus encontrado", true, false);
        return;
    }

    string new_itinerary = prompt_line("Digite o novo itinerário: ");

    bus.itinerary = new_itinerary;

    save_bus(bus, buses);
}

/// @brief Deleta um ônibus
/// @details Solicita o nome do ônibus e o deleta da lista de ônibus
void delete_bus()
{
    vector<Bus> buses = get_buses();

    title("Deletar ônibus");

    string bus_name = prompt_line("Digite o nome do ônibus: ");

    Bus bus = get_bus_by_name(bus_name, buses);

    if (bus.name == "")
    {
        alert("Nenhum ônibus encontrado", true, false);
        return;
    }

    delete_bus(bus, buses);
}
