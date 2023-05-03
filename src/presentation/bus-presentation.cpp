#include <iostream>
#include "presentation/bus-presentation.hpp"

void print_bus(Bus bus)
{
    cout << "Nome: " << bus.name << endl
         << "Terminal: " << bus.terminal << endl
         << "Itinerário: " << bus.intinerary
         << endl;
}

void print_buses(vector<Bus> buses)
{
    for (int i = 0; i < buses.size(); i++)
    {
        cout << "Ônibus " << i + 1 << endl;
        print_bus(buses[i]);
        cout << endl;
    }
}
