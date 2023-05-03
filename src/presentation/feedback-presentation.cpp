#include <iostream>
#include "presentation/feedback-presentation.hpp"

void print_feedback(Feedback feedback)
{
    cout << "Conteúdo: " << feedback.content << endl
         << "Data: " << feedback.date << endl
         << endl;
}

void print_feedbacks(vector<Feedback> feedbacks)
{
    for (int i = 0; i < feedbacks.size(); i++)
    {
        cout << "Feedback " << i + 1 << endl;
        print_feedback(feedbacks[i]);
        cout << endl;
    }
}
