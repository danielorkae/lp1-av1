#include <vector>
#include <fstream>
#include "../domain/bus.cpp"
#include "../utils/files-utils.cpp"

using namespace std;

/// @brief Retorna todos os ônibus cadastrados.
/// @return
vector<Bus> get_buses()
{
    vector<Bus> buses;

    vector<string> lines = read_file_lines("data/buses.txt");

    // Transforma as linhas em dados dos ônibus.
    for (int i = 0; i < lines.size(); i++)
    {
        // A ordem, nesse caso, é importante, pois é a mesma ordem que será salva.
        Bus bus;
        bus.code = lines[i];
        bus.terminal = lines[++i];

        buses.push_back(bus);
    }

    return buses;
}

/// @brief Salva todos os ônibus cadastrados.
/// @param buses
void save_buses(vector<Bus> buses)
{
    vector<string> lines;

    // Transforma os dados dos ônibus em linhas.
    for (int i = 0; i < buses.size(); i++)
    {
        // A ordem, nesse caso, é importante, pois é a mesma ordem que será lida.
        lines.push_back(buses[i].code);
        lines.push_back(buses[i].terminal);
    }

    save_file_lines("data/buses.txt", lines);
}
