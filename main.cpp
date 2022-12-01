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

    List * myList;
    myList = createEmptyList();
    Stack * myStack;
    myStack = createEmptyStack();
    string name, ID, job, newID, gender, attendance, dayOff;
    double salary, average, max1, max2, max3, min, workHours;
    int choice;
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
    	
                int ch4;
                do
                {
                    cout<<"\n\t1. Filter user by salary"<<endl;
                    cout<<"\n\t2. Filter user by job"<<endl;
                    cout<<"\n\t3. Filter user by name"<<endl;
                    cout<<"\n\t0. Back"<<endl; cout<<"Choice: "; cin>>ch4;
                    if (ch4 == 0)
                    {
                        break;
                    }else if(ch4 == 1){
                        system("cls");                  
                        SET_CONSOLE_COLOR(YELLOW);
                        cout<<"\n\t********************************************************************************************************************************"<<endl;  
                        searchDataBySalary();
                        push(myStack, "You use filter by salary Operation");
                        cout<<"\n\t********************************************************************************************************************************"<<endl;
                    }else if(ch4 == 2) {
                        system("cls");
                        SET_CONSOLE_COLOR(YELLOW);
                        cout<<"\n\t********************************************************************************************************************************"<<endl;
                        searchDataByJob();
                        push(myStack, "You use filter by job Operation");
                        cout<<"\n\t********************************************************************************************************************************"<<endl;
                    }else if(ch4 == 3) {
                        system("cls");
                        SET_CONSOLE_COLOR(YELLOW);
                        cout<<"\n\t********************************************************************************************************************************"<<endl;
                        searchDataByName();
                        push(myStack, "You use filter by name Operation");
                        cout<<"\n\t********************************************************************************************************************************"<<endl;
                    }
                } while (ch4 != 0);
                break;
            case 5:
                system("cls");
                if(myList->head != NULL){
                    max1 = findMax1(myList);
                    SET_CONSOLE_COLOR(YELLOW);
                    cout<<"\n\t*************************************"<<endl;
                    cout<<"\n\tTop 1 salary is: "<<endl;
                    displayMax(myList, max1);
                    cout<<"\n\t*************************************"<<endl;
                }
                
                break;
            case 6:
                system("cls");
                SET_CONSOLE_COLOR(GREEN);
                if(myList->head != NULL) {
                    max1 = findMax1(myList);
                    max2 = findMax2(myList);
                    max3 = findMax3(myList);
                    if(counter == 3) {
                        displayMax(myList, max1);
                        
                    }else if(counter == 2){
                        displayMax(myList, max2);
                    }else if(counter == 1) {
                        displayMax(myList, max3);
                    }

                }
                //loading();
                break;
            case 7:
                system("cls");
                SET_CONSOLE_COLOR(GREEN);
                if(myList->head != NULL) {
                    average = findAverageSalary(myList);
                    max1 = findMax1(myList);
                    min = findMin(myList);
                    
                    cout<<"\n\t*************************************"<<endl;
                    cout<<"\n\tAverage salary of users is "<<average<<endl;
                    cout<<"\n\tMax salary of users is "<<max1<<endl;
                    cout<<"\n\tMin salary of users is "<<min<<endl;
                    cout<<"\n\t*************************************"<<endl;
                }
               
                //loading();
                break;
            case 8:
                system("cls");
                SET_CONSOLE_COLOR(RED);
                cout<<"\n\t*************************************************"<<endl;
                cout<<"\n\tDelete stop working Employees data"<<endl;
                cout<<"\n\t*************************************************"<<endl;
                deleteData();
                push(myStack, "You used delete operation");
                break;
            case 9:
                    system("cls");
                    SET_CONSOLE_COLOR(CYAN);
                    updateData();
                break;
            case 10:
                    system("cls");
                    push(myStack, "You view the history of operation file");
                    readOperationFile();
                break;
            case 11:
                    system("cls");
                    SET_CONSOLE_COLOR(GREEN);
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    cout<<"                         Employee Report you have been added to the database for today operation"<<endl;
                    readFile();
                    push(myStack, "You use viewed report Operation");
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
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

    cout<<"\n\t1. Create a new user"<<endl;
    cout<<"\n\t2. View all employees information"<<endl;
    cout<<"\n\t3. Search employees by ID"<<endl;
    SET_CONSOLE_COLOR(YELLOW);
    cout<<"\n\t****************Filter**********************"<<endl;
    cout<<"\n\t4. Filter employees by categories (Salary, Job, Name)"<<endl;
    SET_CONSOLE_COLOR(GREEN);
    cout<<"\n\t****************Find**********************"<<endl;
    cout<<"\n\t5. Find a employees who has top 1 salary"<<endl;
    cout<<"\n\t6. Find a employees who has top 3 salary"<<endl;
    cout<<"\n\t7. Find min max and average salary"<<endl;
    SET_CONSOLE_COLOR(RED);
    cout<<"\n\t****************Delete**********************"<<endl;
    cout<<"\n\t8. Delete Data"<<endl;
    SET_CONSOLE_COLOR(CYAN);
    cout<<"\n\t****************Update**********************"<<endl;
    cout<<"\n\t9. Update users data"<<endl;
    cout<<"\n\t**************Other Feature**********************"<<endl;
    cout<<"\n\t10. History of operation"<<endl;
    cout<<"\n\t11. Generate employee new report informations"<<endl;
    SET_CONSOLE_COLOR(GREEN);
    cout<<"\n\t****************Exit**********************"<<endl;
    cout<<"\n\t0. Exit the console application"<<endl;
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
