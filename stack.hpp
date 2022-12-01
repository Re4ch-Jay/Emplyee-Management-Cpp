#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

string OPERATION_FILE = "operation.txt";

struct Node {
    string operation;
    Node *next;
};

struct Stack {
    int size;
    Node *head, *tail;
};

Stack * createEmptyStack(){
    Stack * stack;
    stack = new Stack();

    stack->size = 0;
    stack->head = NULL;
    stack->tail = NULL;

    return stack;
}

//insertBegin
void push(Stack *stack, string operation) {
    Node * node;
    node = new Node();
    node->operation = operation;
    node->next = stack->head;
    stack->head = node;
    if(stack->size == 0) {
        stack->tail = node;
    }
    stack->size ++; 
    // generate time
    time_t now = time(0);
    char* dt = ctime(&now);
    // open file
    fstream file;
    file.open(OPERATION_FILE, ios::app);
    if(file.is_open()) {
        file<<"Operation: "<<node->operation<<"\t At local date time is: "<<dt<<endl;
    }
    file.close();
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
