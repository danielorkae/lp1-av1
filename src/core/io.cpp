#include <iostream>
#include "headers/io.hpp"

/// @brief Mostra um menu de opções para o usuário e retorna a opção escolhida
/// @param options 
/// @param clear_screen Limpa a tela antes de mostrar o menu
/// @param show_exit_option Mostra a opção de sair no menu
/// @return 
int prompt_menu(vector<string> options, bool clear_screen, bool show_exit_option = true)
{
    int option;

    if (clear_screen)
    {
        system("clear || cls");
    }

    cout << "===== Menu =====" << endl
         << endl;

    for (int i = 0; i < options.size(); i++)
    {
        cout << i + 1 << ". " << options[i] << endl;
    }

    if (show_exit_option)
    {
        cout << endl
             << options.size() + 1 << ". Sair" << endl;
    }

    cout << endl
         << "Escolha uma opção: ";
    cin >> option;

    if (option < 1 || option > options.size() + 1)
    {
        cout << "Opção inválida" << endl;
        return prompt_menu(options, clear_screen, show_exit_option);
    }

    return option;
}
