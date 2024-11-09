#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    // Add a new task
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added: " << taskDescription << endl;
    }

    // View all tasks
    void viewTasks() {
        if (tasks.empty()) {
            cout << "Your to-do list is empty." << endl;
            return;
        }
        cout << "To-Do List:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [Status: " << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
        }
    }

    // Mark a task as completed
    void markTaskCompleted(int taskId) {
        if (taskId > 0 && taskId <= tasks.size()) {
            tasks[taskId - 1].isCompleted = true;
            cout << "Task " << taskId << " marked as completed." << endl;
        } else {
            cout << "Invalid task ID." << endl;
        }
    }

    // Remove a task
    void removeTask(int taskId) {
        if (taskId > 0 && taskId <= tasks.size()) {
            tasks.erase(tasks.begin() + taskId - 1);
            cout << "Task " << taskId << " removed." << endl;
        } else {
            cout << "Invalid task ID." << endl;
        }
    }
};

void showMenu() {
    cout << "\n--- To-Do List Manager ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Please choose an option: ";
}

int main() {
    ToDoList todoList;
    int choice;
    string taskDescription;
    int taskId;

    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();  // To ignore any leftover newline characters in the input buffer
        
        switch (choice) {
            case 1: // Add Task
                cout << "Enter the task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;

            case 2: // View Tasks
                todoList.viewTasks();
                break;

            case 3: // Mark Task as Completed
                cout << "Enter the task ID to mark as completed: ";
                cin >> taskId;
                todoList.markTaskCompleted(taskId);
                break;

            case 4: // Remove Task
                cout << "Enter the task ID to remove: ";
                cin >> taskId;
                todoList.removeTask(taskId);
                break;

            case 5: // Exit
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
