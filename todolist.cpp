#include "todolistt.h"
#include <chrono>

void TodoList::addTask(const std::string& description) {
    tasks.push_back({description, false});
}

void TodoList::completeTaskRecursively(int index) {
    if (index < tasks.size()) {
        tasks[index].completed = true;
        completeTaskRecursively(index + 1);
    }
}

void TodoList::completeAllTasks() {
    completeTaskRecursively(0);
}

void TodoList::printTasksRecursively(size_t index) const {
    if (index == tasks.size()) return;
    const Task& task = tasks[index];
    std::cout << (task.completed ? "[X] " : "[ ] ") << task.description << std::endl;
    printTasksRecursively(index + 1);
}

void TodoList::printTasks() const {
    printTasksRecursively(0);
}

bool TodoList::allTasksCompleted() const {
    for (const Task& task : tasks) {
        if (!task.completed) return false;
    }
    return true;
}

void testTodoListOperations(int numTasks) {
    TodoList myList;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numTasks; i++) {
        myList.addTask("Task " + std::to_string(i + 1));
    }

    myList.completeAllTasks();
    myList.printTasks();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Number of tasks (Rekrusif): " << numTasks << std::endl;
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;
}
