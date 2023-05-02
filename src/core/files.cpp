#include <fstream>
#include "../../include/core/files.hpp"

/// @brief Lê um arquivo e retorna suas linhas em um vetor de strings.
/// @details Facilita a leitura, e permite reutilização em divesos pontos do código.
/// @param file_path
/// @return
vector<string> read_file_lines(string file_path)
{
    fstream file;
    file.open(file_path, ios::in | ios::app);

    if (file.is_open())
    {
        vector<string> lines;
        string line;

        while (getline(file, line))
        {
            lines.push_back(line);
        }

        return lines;
    }

    return vector<string>();
}

/// @brief Salva um conjunto de linhas em um arquivo.
/// @details Facilita a escrita, e permite reutilização em divesos pontos do código.
/// @param file_path
/// @param lines
void save_file_lines(string file_path, vector<string> lines)
{
    fstream file;
    file.open(file_path, ios::out | ios::trunc);

    if (file.is_open())
    {
        for (int i = 0; i < lines.size(); i++)
        {
            file << lines[i] << endl;
        }
    }

    file.close();
}
