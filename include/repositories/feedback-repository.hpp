#ifndef REPOSITORIES_FEEDBACK_REPOSITORY_HPP
#define REPOSITORIES_FEEDBACK_REPOSITORY_HPP

#include <vector>
#include "../domain/feedback.hpp"

using namespace std;

vector<Feedback> get_feedbacks();
void save_feedbacks(vector<Feedback> feedbacks);

#endif
