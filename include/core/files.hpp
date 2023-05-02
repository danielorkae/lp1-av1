#ifndef CORE_FILES_HPP
#define CORE_FILES_HPP

#include <vector>
#include <string>

using namespace std;

vector<string> read_file_lines(string file_path);
void save_file_lines(string file_path, vector<string> lines);

#endif
