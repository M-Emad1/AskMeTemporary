#pragma once
#include <stdc++.h>

class Question
{
private:
	int question_id;
	int parent_question_id;
	int from_user_id;
	int to_user_id;
	bool is_anonymous_questions;
	std::string question_text;
	std::string answer_text;

public:
	Question();
	Question(std::string line);
	std::string to_string() const;
	void print_to_question() const;
	void print_from_question() const;
	void print_feed_question() const;
	
	int get_qusetion_id() const;
	void set_question_id(int& id);
	
	int get_parent_question_id() const;
	void set_parent_question_id(int& id);
	
	int get_from_user_id() const;
	void set_from_user_id(int& id);
	
	int get_to_user_id() const;
	void set_to_user_id(int& id);
	
	bool get_is_anonymous_questions() const;
	void set_is_anonymous_questions(bool& is_aq);
	
	std::string get_question_text() const;
	void set_question_text(std::string& text);
	
	std::string get_answer_text() const;
	void set_answer_text(std::string& text);
};

