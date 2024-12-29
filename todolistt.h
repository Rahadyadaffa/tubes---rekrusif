#ifndef TODOLISTT_H_INCLUDED
#define TODOLISTT_H_INCLUDED


#include <iostream>
#include <vector>
#include <string>


struct Task {
    std::string description;
    bool completed;
};


class TodoList {
private:
    std::vector<Task> tasks;
    void completeTaskRecursively(int index);
    void printTasksRecursively(size_t index) const;
public:
    void addTask(const std::string& description);
    void completeAllTasks();
    void printTasks() const;
    bool allTasksCompleted() const;
};

void testTodoListOperations(int numTasks);


#endif // TODOLISTT_H_INCLUDED
