#include <vector>
#include <fstream>
#include "../domain/feedback.cpp"
#include "../core/files.cpp"

using namespace std;

const string FILE_PATH = "data/feedbacks.txt";

/// @brief Retorna todas as reclamações cadastradas.
/// @return
vector<Feedback> get_feedbacks()
{
    vector<Feedback> feedbacks;

    vector<string> lines = read_file_lines(FILE_PATH);

    // Transforma as linhas em dados das reclamações.
    for (int i = 0; i < lines.size(); i++)
    {
        // A ordem, nesse caso, é importante, pois é a mesma ordem que será salva.
        Feedback feedback;
        feedback.content = lines[i];
        feedback.date = lines[++i];

        feedbacks.push_back(feedback);
    }

    return feedbacks;
}

/// @brief Salva todas as reclamações cadastradas.
/// @param feedbacks
void save_feedbacks(vector<Feedback> feedbacks)
{
    vector<string> lines;

    // Transforma os dados das reclamações em linhas.
    for (int i = 0; i < feedbacks.size(); i++)
    {
        // A ordem, nesse caso, é importante, pois é a mesma ordem que será lida.
        lines.push_back(feedbacks[i].content);
        lines.push_back(feedbacks[i].date);
    }

    save_file_lines(FILE_PATH, lines);
}
