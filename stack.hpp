#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

string OPERATION_FILE = "operation.txt";

struct Node {
    string operation;
    string time;
    Node *next;
};

struct Stack {
    int size;
    Node *top;
};

Stack * createEmptyStack(){
    Stack * stack;
    stack = new Stack();

    stack->size = 0;
    stack->top = NULL;

    return stack;
}

//insertBegin
void push(Stack *stack, string operation) {
    Node * node;
    node = new Node();
    // generate time
    time_t now = time(0);
    char* dt = ctime(&now);
    node->operation = operation;
    node->time = dt;

    node->next = stack->top;
    stack->top = node;

    if(stack->size == 0) {
        stack->top = node;
    }
    stack->size++; 

    // open file
    fstream file;
    file.open(OPERATION_FILE, ios::app);
    if(file.is_open()) {
        file<<"Operation: "<<node->operation<<"\t At local date time is: "<<dt<<endl;
    }
    file.close();
}

void displayStack(Stack *s) {
    Node *tmp;
    tmp = s->top;
    while (tmp != NULL)
    {
        cout<<"Operation: "<<tmp->operation<<"\t At local date time is: "<<tmp->time<<endl;
        tmp = tmp->next;
    }
}
void readOperationFile() {
    fstream file;
    file.open(OPERATION_FILE, ios::in);
    string myline;
    while (!file.eof())
    {
        if ( file.is_open() ) {
            while ( file ) { 
                getline (file, myline);
                cout << myline << '\n';
            }
        }
        else {
            file.open(OPERATION_FILE, ios::app);
            cout << "Couldn't open file\n";
            break;
        }
    }
    file.close();
}
