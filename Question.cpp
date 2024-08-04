#include "Question.h"
#include "HelperFunction.h"
//#include <stdc++.h>

Question::Question()
    : question_id(-1),
    parent_question_id(-1),
    from_user_id(-1),
    to_user_id(-1),
    is_anonymous_questions(false),
    question_text(""),
    answer_text("") {}

Question::Question(std::string line) {
    HelperFunction helper_function;
    std::vector<std::string> fields = helper_function.split_string(line);

    assert((int)fields.size() == 7);

    question_id = helper_function.to_int(fields[0]);
    parent_question_id = helper_function.to_int(fields[1]);
    from_user_id = helper_function.to_int(fields[2]);
    to_user_id = helper_function.to_int(fields[3]);
    is_anonymous_questions = helper_function.to_int(fields[4]);
    question_text = fields[5];
    answer_text = fields[6];
}

std::string Question::to_string() const {
    std::ostringstream oss;
    oss << question_id << ',' << parent_question_id << ',' << from_user_id << ',' << to_user_id << ','
        << is_anonymous_questions << ',' << question_text << ',' << answer_text;
    return oss.str();
}

void Question::print_to_question() const {
    if (parent_question_id != -1)
        std::cout << "\n\t\t > Thread: ";

    std::cout << "Question Id[" << question_id << "]   From User Id [" << from_user_id << "] : \n"
        << std::setw(25) << std::left << " > Question : " << question_text;

    if (answer_text != "")
        std::cout << '\n' << std::setw(25) << std::left << "\t > Answer : " << answer_text << '\n';
    else
        std::cout << '\n' << std::setw(25) << std::left << "\t > Not Answered Yet!\n";

    std::cout << "--------------------------------------------------------------\n\n";
}

void Question::print_from_question() const {
    std::cout << "\nQuestion Id [" << question_id << "]  ";

    if (!is_anonymous_questions)
        std::cout << " !AQ ";

    std::cout << " To User Id[" << to_user_id << "] : \n"
        << std::setw(25) << std::left << " > Question : " << question_text;

    if (answer_text != "")
        std::cout << '\n' << std::setw(25) << std::left << "\t > Answer : " << answer_text << '\n';
    else
        std::cout << '\n' << std::setw(25) << std::left << "\t > Not Answered Yet!\n";

    std::cout << "--------------------------------------------------------------\n\n";
}

void Question::print_feed_question() const {
    if (parent_question_id != -1)
        std::cout << "\n\t\tThread Parent Question ID [" << parent_question_id << "] ";

    std::cout << " Question Id [" << question_id << "] ";

    if (!is_anonymous_questions)
        std::cout << "  From User Id[" << from_user_id << "]";

    std::cout << "  To User Id[" << to_user_id << "]"
        << std::setw(25) << std::left << " > Question : " << question_text;

    if (answer_text != "")
        std::cout << '\n' << std::setw(25) << std::left << "\t > Answer : " << answer_text << '\n';
    else
        std::cout << '\n' << std::setw(25) << std::left << "\t > Not Answered Yet!\n";

    std::cout << "--------------------------------------------------------------\n\n";
}

int Question::get_qusetion_id() const {
    return question_id;
}
void Question::set_question_id(int& id) {
    question_id = id;
}

int Question::get_parent_question_id() const {
    return parent_question_id;
}
void Question::set_parent_question_id(int& id) {
    parent_question_id = id;
}

int Question::get_from_user_id() const {
    return from_user_id;
}
void Question::set_from_user_id(int& id) {
    from_user_id = id;
}

int Question::get_to_user_id() const {
    return to_user_id;
}
void Question::set_to_user_id(int& id) {
    to_user_id = id;
}

bool Question::get_is_anonymous_questions() const {
    return is_anonymous_questions;
}
void Question::set_is_anonymous_questions(bool& is_aq) {
    is_anonymous_questions = is_aq;
}

std::string Question::get_question_text() const {
    return question_text;
}
void Question::set_question_text(std::string& text) {
    question_text = text;
}

std::string Question::get_answer_text() const {
    return answer_text;
}
void Question::set_answer_text(std::string& text) {
    answer_text = text;
}
