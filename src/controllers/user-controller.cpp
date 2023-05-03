#include <iostream>
#include "controllers/user-controller.hpp"
#include "core/io.hpp"
#include "core/permissions.hpp"
#include "domain/feedback.hpp"
#include "repositories/feedback-repository.hpp"
#include "repositories/feedback-repository.hpp"
#include "controllers/bus-controller.hpp"

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
