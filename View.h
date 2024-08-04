#pragma once
#include <stdc++.h>
class View
{
public:
	int show_read_menu(std::vector<std::string> choices);
	int read_int(int low, int high);
	int read_question_id(User& user);
	int read_question_id_thread(User& user);
	void access_system();
	std::vector<std::string> menu() const;
};

