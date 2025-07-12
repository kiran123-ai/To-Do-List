#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}

    std::string toString() contt'r3wst {
        return (completed ? "[X] " : "[ ] ") + description;
    }
};

class ToDoList {
private:
    std::vector<Task> tasks;
    const std::string filename = "tasks.txt";

    void loadTasks() {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                bool completed = (line[0] == '[X]');
                std::string description = line.substr(4); // Skip "[ ] " or "[X] "
                Task task(description);
                task.completed = completed;
                tasks.push_back(task);
            }
            file.close();
        }
    }

    void saveTasks() {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& task : tasks) {
                file << task.toString() << std::endl;
            }
            file.close();
        }
    }

public:
    ToDoList() {
        loadTasks();
    }

    ~ToDoList() {
        saveTasks();
    }

    void addTask(const std::string& description) {
        tasks.emplace_back(description);
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].toString() << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        tasks[index - 1].completed = true;
    }

    void deleteTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main() {
    ToDoList todoList;
    int choice;
    std::string taskDescription;

    do {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                size_t completeIndex;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> completeIndex;
                todoList.markTaskCompleted(completeIndex);
                break;
            case 4:
                size_t deleteIndex;
                std::cout << "Enter task number to delete: ";
                std::cin >> deleteIndex;
                todoList.deleteTask(deleteIndex);
                break;
            case 5:
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
