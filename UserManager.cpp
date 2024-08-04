#include "UserManager.h"
#include "HelperFunction.h"

// Constructor
UserManager::UserManager() : last_id(0) {}

// Load data from the database (file)
void UserManager::load_data_base() {
    last_id = 0;
    user_name_to_UserObject.clear();

    HelperFunction helper_function;
    std::vector<std::string> lines = helper_function.read_line_from_file("users.txt");

    for (const auto& line : lines) {
        User user(line);
        user_name_to_UserObject[user.get_user_name()] = user;
        last_id = std::max(last_id, user.get_user_id());
    }
}

// Log in a user
void UserManager::log_in() {
    load_data_base();

    std::string user_name;
    std::string password;

    std::cout << "\nUser name: ";
    std::cin >> user_name;
    std::cout << "\nPassword: ";
    std::cin >> password;

    current_user.set_user_name(user_name);
    current_user.set_password(password);

    while (true) {
        if (!user_name_to_UserObject.count(current_user.get_user_name())) {
            std::cout << "Invalid User name...Try again!.\n";
            continue;
        }

        const User& user_exist = user_name_to_UserObject[current_user.get_user_name()];

        if (current_user.get_password() != user_exist.get_password()) {
            std::cout << "Invalid Password...Try again!.\n";
            continue;
        }

        current_user = user_exist;
        break;
    }
}

// Sign up a new user
void UserManager::sign_up() {
    std::string user_name;
    std::string password;
    std::string name;
    std::string email;
    bool allow_aq;

    while (true) {
        std::cout << "\nYour User name: ";
        std::cin >> user_name;

        if (user_name_to_UserObject.count(user_name))
            std::cout << "This user already exists.";
        else
            break;
    }

    std::cout << "\nYour Password: ";
    std::cin >> password;
    std::cout << "\nYour Name: ";
    std::cin >> name;
    std::cout << "\nYour Email: ";
    std::cin >> email;
    std::cout << "\nAre you allow anonymous questions? [1 for yes and 0 for no]: ";
    std::cin >> allow_aq;

    current_user.set_user_name(user_name);
    current_user.set_password(password);
    current_user.set_name(name);
    current_user.set_email(email);
    current_user.set_allow_anonymous_questions(allow_aq);

    current_user.set_user_id(++last_id);
    user_name_to_UserObject[current_user.get_user_name()] = current_user;

    update_data_base(current_user);
}

// List user names and IDs
void UserManager::list_user_names_ids()  {
    std::cout << "\n------------------------------------\n";

    for (const auto& pair : user_name_to_UserObject)
        std::cout << "ID: " << pair.second.get_user_id() << "\t\tName: " << pair.second.get_name() << '\n';

    std::cout << "\n------------------------------------\n";
}

// Read user ID
std::pair<int, int> UserManager::read_user_id() {
    int user_id;
    std::cout << "\nEnter User ID or -1 to cancel: ";
    std::cin >> user_id;

    if (user_id == -1)
        return std::make_pair(-1, -1);

    for (const auto& pair : user_name_to_UserObject) {
        if (pair.second.get_user_id() == user_id)
            return std::make_pair(user_id, pair.second.get_allow_anonymous_questions());
    }

    std::cout << "Invalid User ID. Try again\n";
    return read_user_id();
}

// Update database with user information
void UserManager::update_data_base(User& user) {
    HelperFunction helper_function;
    std::string line = user.to_string();
    std::vector<std::string> lines(1, line);
    helper_function.write_line_on_file("users.txt", lines);
}

// Getters and setters
std::map<std::string, User> UserManager::get_user_name_to_UserObject() const {
    return user_name_to_UserObject;
}

void UserManager::set_user_name_to_UserObject( std::map<std::string, User>& mp) {
    user_name_to_UserObject = mp;
}

User UserManager::get_current_user()  {
    return current_user;
}

void UserManager::set_current_user( User& user) {
    current_user = user;
}

int UserManager::get_last_id() const {
    return last_id;
}

void UserManager::set_last_id(int &id) {
    last_id = id;
}
