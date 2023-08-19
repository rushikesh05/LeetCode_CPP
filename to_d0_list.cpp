#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string& description) : description(description), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    std::string getDescription() const {
        return description;
    }

private:
    std::string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
        }
    }

    void displayTasks() const {
        std::cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << (i + 1) << "] ";
            if (tasks[i].isCompleted()) {
                std::cout << "[done] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].getDescription() << "\n";
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. Display Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::string description;
                std::cin.ignore(); // Clear newline from previous input
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2: {
                std::cout << "Enter task index to mark as completed: ";
                int index;
                std::cin >> index;
                toDoList.markTaskCompleted(index - 1);
                break;
            }
            case 3:
                toDoList.displayTasks();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
