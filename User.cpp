#include "User.h"
#include "HelperFunction.h"
#include <stdc++.h>

User::User()
    : user_id(0),
    user_name(""),
    password(""),
    name(""),
    email(""),
    allow_anonymous_questions(0) {}

User::User(std::string line) {
    HelperFunction helper_function;
    std::vector<std::string> fields = helper_function.split_string(line);

    assert((int)fields.size() == 6);

    user_id = helper_function.to_int(fields[0]);
    user_name = fields[1];
    password = fields[2];
    name = fields[3];
    email = fields[4];
    allow_anonymous_questions = helper_function.to_int(fields[5]);
}

std::string User::to_string() const {
    std::ostringstream oss;
    oss << user_id << ',' << user_name << ',' << password << ',' << name << ',' << email << ',' << allow_anonymous_questions;
    return oss.str();
}

void User::print() const {
    std::cout << "User [" << user_id << "]:"
        << "\n\tUser name: " << user_name << "\n\tPassword: " << password
        << "\n\tName: " << name << "\n\tEmail: " << email
        << "\n\tAllow anonymous questions? " << std::boolalpha << allow_anonymous_questions << '\n';
    std::cout << "------------------------------------\n\n";
}

int User::get_user_id() const {
    return user_id;
}

void User::set_user_id(int& id) {
    user_id = id;
}

std::string User::get_user_name() const {
    return user_name;
}

void User::set_user_name(std::string& _user_name) {
    user_name = _user_name;
}

std::string User::get_password() const {
    return password;
}

void User::set_password(std::string& _password) {
    password = _password;
}

std::string User::get_name() const {
    return name;
}

void User::set_name(std::string& _name) {
    name = _name;
}

std::string User::get_email() const {
    return email;
}

void User::set_email(std::string& _email) {
    email = _email;
}

bool User::get_allow_anonymous_questions() const {
    return allow_anonymous_questions;
}

void User::set_allow_anonymous_questions(bool& allow_aq) {
    allow_anonymous_questions = allow_aq;
}

std::vector<int> User::get_question_id_form_me() const {
    return question_id_form_me;
}

void User::set_question_id_form_me(std::vector<int>& vec) {
    question_id_form_me = vec;
}

std::map<int, std::vector<int>> User::get_question_id_to_question_ids_thread() const {
    return question_id_to_question_ids_thread;
}

void User::set_question_id_to_question_ids_thread(std::map<int, std::vector<int>>& mp) {
    question_id_to_question_ids_thread = mp;
}
