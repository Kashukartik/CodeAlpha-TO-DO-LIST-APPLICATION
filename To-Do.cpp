#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        tasks.push_back(Task(desc));
        cout << "Task added: " << desc << endl;
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void displayTasks() {
        cout << "Current Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
        cout << endl;
    }
};

int main() {
    ToDoList todo;
    int choice;

    do {
        cout << "===== To-Do List Application =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Completed" << endl;
        cout << "3. View Current Tasks" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter task description: ";
                cin.ignore(); // To consume the newline character left in the input buffer
                getline(cin, task);
                todo.addTask(task);
                break;
            }
            case 2: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markTaskAsCompleted(index - 1); // Adjust index to 0-based
                break;
            }
            case 3:
                todo.displayTasks();
                break;
            case 4:
                cout << "Exiting application." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
