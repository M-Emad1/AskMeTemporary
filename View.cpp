#include "View.h"
#include "QuestionManager.h"
#include "UserManager.h"

int View::show_read_menu(std::vector<std::string> choices) {
    std::cout << '\n';
    std::cout << std::setw(40) << std::left << "---------------------------------------------\n";
    std::cout << std::setw(60) << std::left << "Menu\n";

    for (int ch = 0; ch < (int)choices.size(); ++ch)
        std::cout << '\t' << '[' << ch + 1 << "] " << choices[ch] << '\n';

    return read_int(1, (int)choices.size());
}

int View::read_int(int low, int high) {
    std::cout << "Enter number in range " << low << " : " << high << ": ";

    int value;
    std::cin >> value;

    if (low <= value && high >= value)
        return value;

    std::cout << "Invalid number! Try again...\n";
    return read_int(low, high);
}

int View::read_question_id(User& user) {
    QuestionManager question_mange;
    int question_id;
    std::cout << "Enter question ID or -1 for cancel: ";
    std::cin >> question_id;

    if (question_id == -1)
        return -1;

    if (!question_mange.get_question_id_to_QuestionObject().count(question_id)) {
        std::cout << "\n\t Error! No question with such ID. Try again...\n\n";
        return read_question_id(user);
    }

    Question& question = question_mange.get_question_id_to_QuestionObject()[question_id];

    if (question.get_to_user_id() != user.get_user_id()) {
        std::cout << "\n\t Error! Invalid question ID. Try again...\n\n";
        return read_question_id(user);
    }

    return question_id;
}

int View::read_question_id_thread(User& user) {
    QuestionManager question_mange;
    int question_id;
    std::cout << "For thread question: Enter Question ID or -1 for new question: ";
    std::cin >> question_id;

    if (question_id == -1)
        return -1;

    if (!question_mange.get_question_id_to_question_ids_thread().count(question_id)) {
        std::cout << "\n\t Error! No thread question with such ID. Try again...\n\n";
        return read_question_id_thread(user);
    }

    return question_id;
}

void View::access_system() {
    UserManager user_manage;

    int choice = show_read_menu({ "Login", "Sign Up" });
    if (choice == 1)
        user_manage.log_in();
    else
        user_manage.sign_up();
}

std::vector<std::string> View::menu() const {
    std::vector<std::string> menu;
    menu.push_back("Print Questions To Me");
    menu.push_back("Print Questions From Me");
    menu.push_back("Answer Question");
    menu.push_back("Delete Question");
    menu.push_back("Ask Question");
    menu.push_back("List System Users");
    menu.push_back("Feed");
    menu.push_back("Logout");

    return menu;
}
