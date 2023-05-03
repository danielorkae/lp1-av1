#include <fstream>
#include "repositories/bus-repository.hpp"
#include "core/files.hpp"
#include "bus-repository.hpp"

using namespace std;

const string FILE_PATH = "data/buses.txt";

/// @brief Retorna todos os ônibus cadastrados.
/// @return
vector<Bus> get_buses()
{
    vector<Bus> buses;

    vector<string> lines = read_file_lines(FILE_PATH);

    // Transforma as linhas em dados dos ônibus.
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        // A ordem, nesse caso, é importante, pois é a mesma ordem que será salva.
        Bus bus;
        bus.name = lines[i];
        bus.terminal = lines[++i];
        bus.itinerary = lines[++i];

        buses.push_back(bus);
    }

    return buses;
}

/// @brief Retorna um ônibus pelo nome.
/// @param name 
/// @param buses 
/// @return 
Bus get_bus_by_name(string name, vector<Bus> buses)
{
    for (unsigned int i = 0; i < buses.size(); i++)
    {
        if (buses[i].name == name)
        {
            return buses[i];
        }
    }

    return Bus();
}

/// @brief Salva todos os ônibus cadastrados.
/// @param buses
void save_buses(vector<Bus> buses)
{
    vector<string> lines;

    // Transforma os dados dos ônibus em linhas.
    for (unsigned int i = 0; i < buses.size(); i++)
    {
        // A ordem, nesse caso, é importante, pois é a mesma ordem que será lida.
        lines.push_back(buses[i].name);
        lines.push_back(buses[i].terminal);
        lines.push_back(buses[i].itinerary);
    }

    save_file_lines(FILE_PATH, lines);
}

/// @brief Salva ou atualizar um ônibus.
/// @param bus 
/// @param buses 
void save_bus(Bus bus, vector<Bus> buses)
{
    bool exists = false;
    for (unsigned int i = 0; i < buses.size(); i++)
    {
        if (buses[i].name == bus.name)
        {
            buses[i] = bus;
            exists = true;
            break;
        }
    }

    if (!exists)
    {
        buses.push_back(bus);
    }

    save_buses(buses);
}

/// @brief Exclui um ônibus.
/// @param bus 
/// @param buses 
void delete_bus(Bus bus, vector<Bus> buses)
{
    for (unsigned int i = 0; i < buses.size(); i++)
    {
        if (buses[i].name == bus.name)
        {
            buses.erase(buses.begin() + i);
            break;
        }
    }

    save_buses(buses);
}
