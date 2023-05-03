#include <iostream>
#include "core/io.hpp"
#include "domain/feedback.hpp"
#include "repositories/feedback-repository.hpp"
#include "repositories/feedback-repository.hpp"

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
