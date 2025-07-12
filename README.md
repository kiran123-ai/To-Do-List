# To-Do-List
A simple command-line To-Do List application written in C++ that allows users to add, view, mark as completed, and delete tasks. Tasks are saved persistently in a text file (tasks.txt), so your list is preserved between sessions.
# Features
Add new tasks with descriptions

View all tasks with completion status

Mark tasks as completed

Delete tasks by their number

Persistent storage using a text file (tasks.txt)

Simple and user-friendly menu-driven interfac

 # How to Use
  - Requirements
C++ compiler supporting C++11 or later (e.g., g++, clang++)
Compile the code
g++ -o todo todo.cpp
 # Run the application
./todo
# Menu options
Add Task: Enter a task description to add it to the list.

View Tasks: Displays all tasks with their completion status.

Mark Task as Completed: Enter the task number to mark it as done.

Delete Task: Enter the task number to remove it from the list.

Exit: Saves the tasks to tasks.txt and closes the application.
 # Code Overview
Task class: Represents an individual task with a description and completion status.

ToDoList class: Manages a vector of Task objects, handles loading from and saving to the file.

Main function: Provides the menu and user interaction logic.
File Persistence
Tasks are saved in tasks.txt in  format:

[ ] Task description  # For incomplete tasks
[X] Task description  # For completed tasks
When the app starts, it loads existing tasks from this file.

When exiting, it saves the current tasks back to the file.

