#include <iostream>
#include "../../include/controllers/user-controller.hpp"
#include "../../include/core/io.hpp"
#include "../../include/core/permissions.hpp"
#include "../../include/domain/feedback.hpp"
#include "../../include/presentation/bus-presentation.hpp"
#include "../../include/repositories/bus-repository.hpp"
#include "../../include/repositories/feedback-repository.hpp"
#include "../../include/repositories/feedback-repository.hpp"

using namespace std;

void user_menu()
{
    vector<string> options = {
        "Listar ônibus",
        "Buscar ônibus por terminal",
        "Ver intinerário de ônibus",
        "Deixar um feedback",
    };

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

void leave_feedback()
{
    vector<Feedback> feedbacks = get_feedbacks();
    string content, date;

    title("Deixar um feedback");

    content = prompt_line("Digite o conteúdo do feedback: ");
    date = prompt_line("Digite a data do feedback: ");

    Feedback feedback;
    feedback.content = content;
    feedback.date = date;

    feedbacks.push_back(feedback);

    save_feedbacks(feedbacks);
}
