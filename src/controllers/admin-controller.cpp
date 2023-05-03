#include "controllers/admin-controller.hpp"
#include "controllers/bus-controller.hpp"
#include "controllers/feedback-controller.hpp"
#include "core/io.hpp"

/// @brief Mostra o menu do administrador
/// @details Pede ao administrador que escolha uma opção e chama a função correspondente
void admin_menu()
{
    title("Admin Menu");

    vector<string> options = {
        "Listar ônibus",
        "Buscar ônibus por nome",
        "Buscar ônibus por terminal",
        "Atualizar terminal de um ônibus",
        "Atualizar intinerário de um ônibus",
        "Excluir ônibus",
        "Listar feedbacks",
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
        search_bus_by_name();
        break;
    case 3:
        search_bus_by_terminal();
        break;
    case 4:
        update_bus_terminal();
        break;
    case 5:
        update_bus_itinerary();
        break;
    case 6:
        delete_bus();
        break;
    case 7:
        list_feedbacks();
        break;
    case 8:
        exit(0);
        break;
    }
    
    pause();
}
