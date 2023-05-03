#include <iostream>
#include "../../include/core/io.hpp"

/// @brief Limpa a tela
void clear_screen()
{
    system("clear || cls");
}

/// @brief Mostra um título na tela
/// @param title
void title(string title)
{
    cout << "===== " << title << " =====" << endl
         << endl;
}

/// @brief Mostra um menu de opções para o usuário e retorna a opção escolhida
/// @param options
/// @param clear_screen Limpa a tela antes de mostrar o menu
/// @param show_exit_option Mostra a opção de sair no menu
/// @return
int prompt_menu(vector<string> options, bool clear_screen, bool show_exit_option)
{
    int option;

    if (clear_screen)
    {
        system("clear || cls");
    }

    title("Menu");

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

/// @brief Mostra uma mensagem e retorna o valor digitado pelo usuário
/// @param message
/// @return
string prompt(string message)
{
    string text;

    cout << message;
    cin >> text;

    return text;
}

/// @brief Mostra uma mensagem e retorna o texto digitado pelo usuário
/// @param message
/// @return
string prompt_line(string message)
{
    string text;

    cout << message;
    getline(cin, text);

    return text;
}

/// @brief Mostra uma mensagem
/// @param message
void alert(string message, bool warn, bool clear_screen)
{
    if (clear_screen)
    {
        system("clear || cls");
    }

    if (warn)
    {
        cout << "!!! ";
    }

    cout << message;

    if (warn)
    {
        cout << " !!!";
    }

    cout << endl;
}

/// @brief Pausa a execução do programa
void pause()
{
    cout << endl
         << "Pressione ENTER para continuar...";
    cin.ignore();
    cin.get();
}
