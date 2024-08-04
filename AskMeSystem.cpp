#include "AskMeSystem.h"
#include "View.h"

void AskMeSystem::load_data_base(bool fill_user_questions) {
	userManager.load_data_base();
	questionManager.load_data_base();

	if (fill_user_questions) { // first time, waiting for login
		User user = userManager.get_current_user();
		questionManager.fill_user_question(user);
	}
}

void AskMeSystem::run() {
	load_data_base();
	View view;
	view.access_system();
	User user = userManager.get_current_user();
	questionManager.fill_user_question(user);

	while (true) {
		int choice = view.show_read_menu(view.menu());
		load_data_base(true);

		if (choice == 1)
			questionManager.print_user_to_question(user);
		else if (choice == 2)
			questionManager.print_user_from_question(user);
		else if (choice == 3) {
			questionManager.answer_question(user);
			questionManager.update_data_base();
		}
		else if (choice == 4) {
			questionManager.delete_question(user);
			// Let's build again (just easier, but slow)
			questionManager.fill_user_question(user);
			questionManager.update_data_base();
		}
		else if (choice == 5) {
			std::pair<int, int> to_user_pair = userManager.read_user_id();
			if (to_user_pair.first != -1) {
				questionManager.ask_question(user, to_user_pair);
				questionManager.update_data_base();
			}
		}
		else if (choice == 6)
			userManager.list_user_names_ids();
		else if (choice == 7)
			questionManager.list_feed();
		else
			break;
	}
}