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
#include "stack.hpp"
#include "FileIO.hpp"
using namespace std; 

void authScreen();
void menu();
void clearReportFile();

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
    int choice, ch4, ch12;
    
    while (choice != 0)
    {   
        if(isAuth == true) {
            
            system("pause");
            system("cls");
            loading();
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
                push(myStack, "You used Create Operation");
                break;
            case 2:
                system("cls");
                SET_CONSOLE_COLOR(YELLOW);
                cout << "\n\n                                                 Employee Data"<<endl<<endl;
                readData();
                push(myStack, "You used Viewing Operation");
                break;
            case 3:
                system("cls");
                cout<<"\n\t******************************"<<endl;
                searchDataById();
                push(myStack, "You used Searching Operation");
                cout<<"\n\t******************************"<<endl;
                break;
             case 4:
                system("cls");
                SET_CONSOLE_COLOR(YELLOW);
                do
                {
                    system("cls");
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    cout<<"\n\tSearch each user by categories"<<endl;
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    cout<<"\n\t1. Filter employees by salary"<<endl;
                    cout<<"\n\t2. Filter employees by age"<<endl;
                    cout<<"\n\t3. Filter employees by gender (M or F)"<<endl;
                    cout<<"\n\t0. Back"<<endl; cout<<"Choice: "; cin>>ch4;
                    if(ch4 == 1){
                        system("cls");                  
                        SET_CONSOLE_COLOR(YELLOW);
                        push(myStack, "You used filtering by salary Operation");
                        searchDataBySalary();
                        system("pause");
                    }else if(ch4 == 2) {
                        system("cls");
                        SET_CONSOLE_COLOR(YELLOW);
                        push(myStack, "You used filtering by age Operation");
                        searchDataByAge();
                        system("pause");
                    }else if(ch4 == 3) {
                        system("cls");
                        push(myStack, "You used filtering by gender Operation");
                        SET_CONSOLE_COLOR(YELLOW);
                        searchDataByGender();
                        system("pause");
                    }
                } while (ch4 != 0);
                
            
                break;
            case 5:
                system("cls");
                SET_CONSOLE_COLOR(GREEN);
                char ch5;
                do
                {
                    cout<<"\n\t*************************************************"<<endl;
                    cout<<"\n\tView employeee by Department"<<endl;
                    cout<<"\n\t*************************************************"<<endl;
                    cout<<"\n\t1. Software Developement"<<endl;
                    cout<<"\n\t2. Accounting"<<endl;
                    cout<<"\n\t3. Teaching"<<endl; 
                    cout<<"\n\t0. Back"<<endl; 
                    cout<<"\n\tChoice: "; cin>>ch5;
                    if(ch5 == '1'){
                        system("cls");
                        SET_CONSOLE_COLOR(GREEN);
                        cout<<"\n\t*************************************************"<<endl;
                        cout<<"\n\tSoftware Development Department Data"<<endl;
                        viewDeveloperDepartment();
                        cout<<"\n\t*************************************************"<<endl;
                        push(myStack, "You viewed Development department");
                    }else if(ch5 == '2') {
                        system("cls");
                        SET_CONSOLE_COLOR(GREEN);
                        cout<<"\n\t*************************************************"<<endl;
                        cout<<"\n\tAccounting Department Data"<<endl;
                        viewAccountingDepartment();
                        cout<<"\n\t*************************************************"<<endl;
                        push(myStack, "You viewed Accounting department");
                    }else if(ch5 == '3'){
                        system("cls");
                        SET_CONSOLE_COLOR(GREEN);
                        cout<<"\n\t*************************************************"<<endl;
                        cout<<"\n\tTeaching Department Data"<<endl;
                        viewTeachingDepartment();
                        cout<<"\n\t*************************************************"<<endl;
                        push(myStack, "You viewed Teaching department");
                    }
                } while (ch5 != '0');
                
                
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
                    char ch7;
                    push(myStack, "You used update operation");
                    do
                    {
                        cout<<"\n\t*************************************************"<<endl;
                        cout<<"\n\tUpdate Employees data"<<endl;
                        cout<<"\n\t*************************************************"<<endl;
                        cout<<"\n\t1. Update name"<<endl;
                        cout<<"\n\t2. Update age"<<endl;
                        cout<<"\n\t3. Update salary"<<endl;
                        cout<<"\n\t4. Update gender"<<endl;
                        cout<<"\n\t0. Exit"<<endl;
                        
                        cout<<"\n\tChoice: "; cin>>ch7;
                        if(ch7 == '1') {
                            updateDataName();
                        }else if(ch7 == '2'){
                            updateDataAge();
                            
                        }
                        else if(ch7 == '3'){
                            updateDataSalary();
                        
                        }else if(ch7 == '4'){
                            updateDataGender();
                        
                        }
                        else if(ch7 == '0'){
                            cout<<"\n\tBack"<<endl;
                        }
                    } while (ch7 != '0');
                    

                break;
            case 8:
                    system("cls");
                    char ch8;
                    do
                    {
                        cout<<"\n\t1. Read histroy operation from file (Can be few days ago)"<<endl;
                        cout<<"\n\t2. Read history operation daily"<<endl;
                        cout<<"\n\t3. Filter history of add operation"<<endl;
                        cout<<"\n\t4. Filter history of search operation"<<endl;
                        cout<<"\n\t5. Filter history of delete operation"<<endl;
                        cout<<"\n\t6. Filter history of update operation"<<endl;
                        cout<<"\n\t7. Filter history of view employees operation"<<endl;
                        cout<<"\n\t0. Back"<<endl;
                        cout<<"\n\tChoice: "; cin>>ch8;
                        if(ch8 == '1'){
                            readOperationFile();
                        }else if(ch8 == '2'){
                            displayStack(myStack);
                        }else if(ch8 == '3'){
                            searchAdd(myStack);
                        }else if(ch8 == '4'){
                            searchSearch(myStack);
                        }else if(ch8 == '5'){
                            searchDelete(myStack);
                        }else if(ch8 == '6'){
                            searchUpdate(myStack);
                        }else if(ch8 == '7'){
                            searchView(myStack);
                        }else if(ch8 == '0'){
                            cout<<"\n\tBack"<<endl;
                        }else{
                            cout<<"\n\tInvalid input"<<endl;
                        }
                    } while (ch8 != '0');
                    
                    
                break;
            case 9:
                    system("cls");
                    SET_CONSOLE_COLOR(GREEN);
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    cout<<"                         Employee Report you have been added to the database for today operation"<<endl;
                    readFile();
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                break;
            case 10:
                system("cls");
                SET_CONSOLE_COLOR(GREEN);
                cout<<"\n\t********************************************************************************************************************************"<<endl;
                cout<<"                                                  Employees of upcomming retired"<<endl;
                push(myStack, "You viewed upcomming retired");
                readDataRetired();    
                cout<<"\n\t********************************************************************************************************************************"<<endl;
                break;
            case 11:
                    system("cls");
                    SET_CONSOLE_COLOR(GREEN);
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    cout<<"                                                  Feature to copy"<<endl;
                    cout<<"\n\t********************************************************************************************************************************"<<endl;
                    do
                    {
                        cout<<"\n\t1. Copy all employees from database"<<endl;
                        cout<<"\n\t2. Copy all upcomming retired employees"<<endl;
                        cout<<"\n\t0. Back"<<endl;
                        cout<<"\n\tChoice: "; cin>>ch12;
                        if(ch12 == 0){
                            break;
                        }
                        else if(ch12 == 1){
                            system("cls");
                            copyFileEmployees();
                            push(myStack, "You have been copy file employees from our system");
                        }else if(ch12 == 2){
                            system("cls");
                            copyFileRetired();
                            push(myStack, "You have been copy file retired from our system");
                        }else {
                            system("cls");
                            cout<<"\n\tInvalid input"<<endl;
                        }
                    } while (ch12 != 0);
                break;
            case 0:
                system("cls");
                cout<<"\n\t******************************"<<endl;
                cout<<"\n\tThank for using our program"<<endl;
                cout<<"\n\t******************************"<<endl;
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
    cout<<"\n\t1. Create a new employee"<<endl; //done
    cout<<"\n\t2. View all employees information"<<endl; //done
    cout<<"\n\t3. Search each employees by ID"<<endl; //done
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
    cout<<"\n\t7. Update employees data"<<endl; //done
    cout<<"\n\t**************Other Features**********************"<<endl;
    cout<<"\n\t8. History of operation"<<endl; //done
    cout<<"\n\t9. Generate employee new report informations daily"<<endl; //done
    cout<<"\n\t10. Show upcomming retired employees"<<endl;  // done
    cout<<"\n\t11. Copy employees data to your own file."<<endl; //done
    SET_CONSOLE_COLOR(GREEN);
    cout<<"\n\t****************Exit**********************"<<endl;
    cout<<"\n\t0. Exit the console application"<<endl; //done
}

void authScreen() {
    clearReportFile();
    SET_CONSOLE_COLOR(YELLOW);
    SET_CONSOLE_COLOR(CYAN);
    cout<<"\n\t***************************************"<<endl;
    cout<<  "\t*                                     *"<<endl;
    cout<<  "\t*      Employee Management System     *"<<endl;
    cout<<  "\t*                                     *"<<endl;
    cout<<"\n\t***************************************"<<endl;
    cout << "\n\t***** Login or Register *****\n\n";
    cout << "===================================\n";
    cout << "\n\t***** Please write (login) or (register) *****\n\n";
    string LoR;
    while(true){
        SET_CONSOLE_COLOR(GREEN);
        cout<<"\t";
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


void clearReportFile() {
    fstream write;
    write.open("reportData.txt", ios::out);
    write << "" ;
    write.close();
}
