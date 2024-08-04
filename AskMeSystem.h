#pragma once
#include "UserManager.h"
#include "QuestionManager.h"

class AskMeSystem
{
private:
	UserManager userManager;
	QuestionManager questionManager;

public:
	void load_data_base(bool fill_user_questions = false);
	void run();
};

