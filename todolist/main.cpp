#include <iostream>
# include <windows.h>
# include <string>
using namespace std;

int main() {
	string task[10] = { "" };
	//counter var -> know how many tasks are in the list
	int taskCount = 0;

	int option = -1;
	while (option != 0) {
		cout << "To-Do List Application" << endl;
		cout << "1. Add Task" << endl;
		cout << "2. View Tasks" << endl;
		cout << "3. Delete Task" << endl;
		cout << "0. Exit" << endl;
		cout << "Select an option: ";
		cin >> option;
		switch (option) {
		case 1:
			if (taskCount < 10) {
				cout << "Enter task: ";
				cin.ignore();
				getline(cin, task[taskCount]);
				taskCount++;
			}
			else {
				cout << "Task list is full!" << endl;
			}
			break;
		case 2:
			cout << "Tasks:" << endl;
			for (int i = 0; i < taskCount; i++) {
				cout << i + 1 << ". " << task[i] << endl;
			}
			break;
		case 3:
			int deleteIndex;
			cout << "Enter task number to delete: ";
			cin >> deleteIndex;
			if (deleteIndex > 0 && deleteIndex <= taskCount) {
				for (int i = deleteIndex - 1; i < taskCount - 1; i++) {
					task[i] = task[i + 1];
				}
				task[taskCount - 1] = "";
				taskCount--;
				cout << "Task deleted." << endl;
			}
			else {
				cout << "Invalid task number!" << endl;
			}
			break;
		case 0:
			cout << "Exiting application." << endl;
			break;
		default:
			cout << "Invalid option!" << endl;
		}
	}
}