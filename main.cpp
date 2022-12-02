#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <map>
#include "util.hpp"
#include "auth.hpp" 
#include "header.hpp"
#include "FileIO.hpp"
#include "stack.hpp"
using namespace std; 

void authScreen();
void menu();
void searchIdInFile();

int main () {

    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    Stack * myStack;
    myStack = createEmptyStack();
    string name, ID, job, newID, gender, attendance, dayOff;
    double salary, average, max1, max2, max3, min, workHours;
    int choice, ch4;
    ifstream file;
    string line;
    string searchID;
   
    
    while (choice != 0)
    {   
        if(isAuth == true) {
            
            system("pause");
            menu();
            push(myStack, "You have been log in to our system");
            SET_CONSOLE_COLOR(GREEN);
            cout<<"\n\tChoice: "; cin>>choice;
           
        }else if (isAuth == false){
            system("cls");
            authScreen();
        }
        switch (choice) 
        {
            case 1:
                system("cls");
                SET_CONSOLE_COLOR(CYAN);
                addEmployee();
                push(myStack, "You use Create Operation");
                break;
            case 2:
                system("cls");
                cout<<"\n\t********************************************************************************************************************************"<<endl;
                SET_CONSOLE_COLOR(YELLOW);
                cout << "\n\n                                                 Employee Data"<<endl;
                readData();
                push(myStack, "You use View Operation");
                cout<<"\n\t********************************************************************************************************************************"<<endl;
                break;
            case 3:
                system("cls");
                cout<<"\n\t******************************"<<endl;
                searchDataById();
                push(myStack, "You use Search Operation");
                cout<<"\n\t******************************"<<endl;
                break;
             case 4:
                system("cls");
                SET_CONSOLE_COLOR(YELLOW);
                cout<<"\n\t********************************************************************************************************************************"<<endl;
                cout<<"\n\tSearch each user by categories"<<endl;
                cout<<"\n\t********************************************************************************************************************************"<<endl;
                cout<<"\n\t1. Filter user by salary"<<endl;
                cout<<"\n\t2. Filter user by age"<<endl;
                cout<<"\n\t3. Filter user by gender"<<endl;
                cout<<"\n\t0. Back"<<endl; cout<<"Choice: "; cin>>ch4;
                if(ch4 == 1){
                    system("cls");                  
                    SET_CONSOLE_COLOR(YELLOW);
                    push(myStack, "You use filter by salary Operation");
                    cout<<"\n\t********************************************************************************************************************************"<<endl;  
                    searchDataBySalary();
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                }else if(ch4 == 2) {
                    system("cls");
                    SET_CONSOLE_COLOR(YELLOW);
                    push(myStack, "You use filter by age Operation");
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    searchDataByAge();
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                }else if(ch4 == 3) {
                    system("cls");
                    push(myStack, "You use filter by gender Operation");
                    SET_CONSOLE_COLOR(YELLOW);
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    searchDataByGender();
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                }else{
                    cout<<"\n\tInvalid input"<<endl;
                }
            
                break;
            case 5:
                system("cls");
                SET_CONSOLE_COLOR(GREEN);
                char ch5;
                cout<<"\n\t*************************************************"<<endl;
                cout<<"\n\tView employeee by Department"<<endl;
                cout<<"\n\t*************************************************"<<endl;
                cout<<"\n\t1. Software Developement"<<endl;
                cout<<"\n\t2. Accounting"<<endl;
                cout<<"\n\t3. Teaching"<<endl; 
                cout<<"\n\tChoice: "; cin>>ch5;
                if(ch5 == '1'){
                    system("cls");
                    SET_CONSOLE_COLOR(GREEN);
                    cout<<"\n\t*************************************************"<<endl;
                    cout<<"\n\tSoftware Development Department Data"<<endl;
                    readDataDeveloper();
                    cout<<"\n\t*************************************************"<<endl;
                    push(myStack, "You used view Development department");
                }else if(ch5 == '2') {
                    system("cls");
                    SET_CONSOLE_COLOR(GREEN);
                    cout<<"\n\t*************************************************"<<endl;
                    cout<<"\n\tAccounting Department Data"<<endl;
                    readDataAccounting();
                    cout<<"\n\t*************************************************"<<endl;
                    
                    push(myStack, "You used view Accounting department");
                }else if(ch5 == '3'){
                    system("cls");
                    SET_CONSOLE_COLOR(GREEN);
                    cout<<"\n\t*************************************************"<<endl;
                    cout<<"\n\tTeaching Department Data"<<endl;
                    readDataTeacher();
                    cout<<"\n\t*************************************************"<<endl;
                    push(myStack, "You used view Teaching department");
                }
                
                break;
            case 6:
                system("cls");
                SET_CONSOLE_COLOR(RED);
                cout<<"\n\t*************************************************"<<endl;
                cout<<"\n\tDelete stop working Employees data"<<endl;
                cout<<"\n\t*************************************************"<<endl;
                deleteData();
                push(myStack, "You used delete operation");
                break;
            case 7:
                    system("cls");
                    SET_CONSOLE_COLOR(CYAN);
                    updateData();
                break;
            case 8:
                    system("cls");
                    push(myStack, "You view the history of operation file");
                    readOperationFile();
                break;
            case 9:
                    system("cls");
                    SET_CONSOLE_COLOR(GREEN);
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    cout<<"                         Employee Report you have been added to the database for today operation"<<endl;
                    readFile();
                    push(myStack, "You use viewed report Operation");
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                break;
            case 10:
                system("cls");
                SET_CONSOLE_COLOR(GREEN);
                readDataRetired();
                break;
            case 0:
                push(myStack, "You have been exit from our system");
                break;
            default:
                system("cls");
                SET_CONSOLE_COLOR(GREEN);
                cout<<"\n\t******************************"<<endl;
                cout<<"\n\tThank for using our program"<<endl;
                cout<<"\n\t******************************"<<endl;
                break;
            }
    }
    return 0;
}

void menu(){
    SET_CONSOLE_COLOR(CYAN);
    cout<<"\n\t***************************************"<<endl;
    cout<<  "\t*                                     *"<<endl;
    cout<<  "\t*      Salary Management System       *"<<endl;
    cout<<  "\t*                                     *"<<endl;
    cout<<"\n\t***************************************"<<endl;

    cout<<"\n\t1. Create a new user"<<endl; //done
    cout<<"\n\t2. View all employees information"<<endl; //done
    cout<<"\n\t3. Search employees by ID"<<endl; //done
    SET_CONSOLE_COLOR(YELLOW);
    cout<<"\n\t****************Filter**********************"<<endl;
    cout<<"\n\t4. Filter employees by categories (Salary, Age, Gender)"<<endl; //done
    SET_CONSOLE_COLOR(GREEN);
    cout<<"\n\t****************View Employees by Department**********************"<<endl;
    cout<<"\n\t5. View employees by Department (Developer, Accounting, Teaching)"<<endl; //done
    SET_CONSOLE_COLOR(RED);
    cout<<"\n\t****************Delete**********************"<<endl;
    cout<<"\n\t6. Delete Data by ID"<<endl; //done
    SET_CONSOLE_COLOR(CYAN);
    cout<<"\n\t****************Update**********************"<<endl;
    cout<<"\n\t7. Update users data"<<endl; //done
    cout<<"\n\t**************Other Feature**********************"<<endl;
    cout<<"\n\t8. History of operation"<<endl; //done
    cout<<"\n\t9. Generate employee new report informations daily"<<endl; //done
    cout<<"\n\t10. Show upcomming retired employees"<<endl; 
    SET_CONSOLE_COLOR(GREEN);
    cout<<"\n\t****************Exit**********************"<<endl;
    cout<<"\n\t0. Exit the console application"<<endl; //done
}

void authScreen() {
    SET_CONSOLE_COLOR(YELLOW);
    cout << "\n\t***** Login or Register *****\n\n";
    cout << "===================================\n";
    cout << "\n\t***** Please write (login) or (register) *****\n\n";
    string LoR;
    while(true){
        SET_CONSOLE_COLOR(GREEN);
        getline(cin,LoR);
        if(LoR == "login"){
            login();
            break;
        }else if(LoR == "register"){
            registry();
            break;
        }else{
            cout << "\n\t*Please write (login) or (register) correctly*\n" ;
        }
    }
}
