//R.Prithikasri CODSOFT Task4: To-Do-List
#include<iostream>
#include<string>
using namespace std;
const int MAX_TASKS=100;
class Task{
    public:
    string description;
    bool completed;
    Task():description(""),completed(false){}

};
class ToDoList{
    private:
    Task tasks[MAX_TASKS];
    int taskCount;
    public:
    ToDoList():taskCount(0){}
void addTask(const string& taskDescription)
{
    if(taskCount < MAX_TASKS)
    {
        tasks[taskCount].description=taskDescription;
        tasks[taskCount].completed=false;
        taskCount++;
    }

    else{
        cout<<"Task list is full.\n";
    }
}
void viewTasks() const { 
    if (taskCount == 0) 
    { 
 cout << "No tasks available.\n";
  } else {
     for (int i=0;i < taskCount;++i)
      { 
    cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
     } 
     } 
     }
void markTaskAsCompleted(int index)
{
    if(index < 1 || index > taskCount)
    {
        cout<<"Invalid task number.\n";
        return;
    }
    tasks[index-1].completed=true;
}
void removeTask(int index)
{
    if(index < 1 || index > taskCount)
    {
        cout<<"Invalid task number.\n";
        return;
    }
    for(int i=index;i<taskCount;++i)
    {
        tasks[i-1]=tasks[i];
    }
    taskCount--;
}
};
int main()
{
    ToDoList toDoList;
    int choice;
    string taskDescription;
    int taskNumber;
    while(true)
    {
        cout<<"\nTo-Do List Manager\n";
        cout<<"1. Add Task\n";
        cout<<"2. View Taks\n";
        cout<<"3. Mark Task as Completed\n";
        cout<<"4. Remove Task\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter task description: ";
            cin.ignore();
            getline(cin, taskDescription);
            toDoList.addTask(taskDescription);
            break;
            case 2:
            toDoList.viewTasks();
            break;
            case 3:
            cout<<"Enter task number to mark as completed: ";
            cin>>taskNumber;
            toDoList.markTaskAsCompleted(taskNumber);
            break;
            case 4:
            cout<<"Enter task number to remove: ";
            cin>>taskNumber;
            case 5:
            return 0;
            default:
            cout<<"Invalid choice. Please try again.\n";
        }
    }
}
