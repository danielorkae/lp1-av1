#include "controllers/auth-controller.hpp"
#include "core/io.hpp"

/// @brief Mostra o menu de autenticação e retorna o tipo de usuário escolhido
/// @details O tipo de usuário é retornado por referência. Caso o usuário escolha 
/// uma opção inválida, o menu é mostrado novamente.
/// @param user_role 
void auth_menu(string &user_role)
{
    title("Menu de Autenticação");

    alert("Você é?", false, false);

    vector<string> options = {
        "Passageiro",
        "Administrador",
    };

    int option = prompt_menu(options, true, true);

    if (option == 1)
    {
        user_role = "passenger";
        return;
    }

    if (option == 2)
    {
        user_role = "admin";
        return;
    }

    alert("Opção inválida", true, false);
    pause();
    auth_menu(user_role);
}
