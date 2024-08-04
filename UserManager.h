#pragma once
#include <stdc++.h>
#include "User.h"
class UserManager
{
private:
	std::map<std::string, User> user_name_to_UserObject; //should be string to user
	User current_user;
	int last_id;
	
public:
	UserManager();
	void load_data_base();
	void log_in();
	void sign_up();
	void list_user_names_ids();
	std::pair<int, int> read_user_id();
	void update_data_base(User& user);

	std::map<std::string, User> get_user_name_to_UserObject() const;
	void set_user_name_to_UserObject(std::map<std::string, User>& mp);

	User get_current_user();
	void set_current_user(User& user);

	int get_last_id() const;
	void set_last_id(int& id);
};

