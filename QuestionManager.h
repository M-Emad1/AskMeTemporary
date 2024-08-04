#pragma once
#include "Question.h"
#include "User.h"


class QuestionManager
{
private:
	std::map<int, std::vector<int>> question_id_to_question_ids_thread;
	std::map<int, Question> question_id_to_QuestionObject;
	int last_id;
public:
	QuestionManager();
	void load_data_base();
	void fill_user_question(User& user);
	void print_user_to_question(User& user);
	void print_user_from_question(User& user);
	void ask_question(User& user, std::pair<int, bool> to_user_pair);
	void answer_question(User& user);
	void delete_question(User& user);
	void list_feed() const;
	void update_data_base();

	std::map<int, std::vector<int>> get_question_id_to_question_ids_thread() const;
	void set_question_id_to_question_ids_thread(std::map<int, std::vector<int>>& mp);

	std::map<int, Question> get_question_id_to_QuestionObject() const;
	void set_question_id_to_QuestionObject(std::map<int, Question>& mp);

	int get_last_id() const;
	void set_last_id(int& id);
};

