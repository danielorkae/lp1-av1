#ifndef CORE_IO_HPP
#define CORE_IO_HPP

#include <vector>
#include <string>

using namespace std;

void clear_screen();
void title(string title);
int prompt_menu(vector<string> options, bool clear_screen, bool show_exit_option);
string prompt(string message);
string prompt_line(string message);
void alert(string message, bool warn, bool clear_screen);
void pause();

#endif
