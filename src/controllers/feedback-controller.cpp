#include <iostream>
#include "controllers/feedback-controller.hpp"
#include "core/io.hpp"
#include "domain/feedback.hpp"
#include "printers/feedback-printer.hpp"
#include "repositories/feedback-repository.hpp"
#include "repositories/feedback-repository.hpp"

/// @brief Solicita ao usuário que digite o conteúdo e a data de um feedback e o salva
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

/// @brief Lista todos os feedbacks
void list_feedbacks()
{
    vector<Feedback> feedbacks = get_feedbacks();

    title("Lista de Feedbacks");

    if (feedbacks.size() == 0)
    {
        alert("Não há feedbacks cadastrados", true, false);
        return;
    }

    print_feedbacks(feedbacks);
}
