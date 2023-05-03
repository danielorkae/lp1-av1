#include <iostream>
#include "include/core/io.hpp"
#include "include/core/permissions.hpp"
#include "include/presentation/bus-presentation.hpp"
#include "include/repositories/bus-repository.hpp"
#include "../../include/repositories/feedback-repository.hpp"

using namespace std;

void user_menu()
{
    vector<string> options = {
        "1. Listar ônibus",
        "2. Buscar ônibus por terminal",
        "3. Ver intinerário de ônibus",
        "4. Deixar um feedback",
        "5. Voltar",
    };

    int option = prompt_menu(options, true, true);

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
        return;
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
