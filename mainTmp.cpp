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
using namespace std; 

void authScreen();
void menu();
void searchIdInFile();

int main () {

    List * myList;
    myList = createEmptyList();
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
                cout<<"\n\t**************************************"<<endl;

                cout<<"\n\tEnter employee ID: "; SET_CONSOLE_COLOR(GREEN); cin>>ID;
                SET_CONSOLE_COLOR(CYAN);
                cout<<"\n\tEnter employee name: "; SET_CONSOLE_COLOR(GREEN); cin>>name;
                SET_CONSOLE_COLOR(CYAN);
                cout<<"\n\tEnter employee job: "; SET_CONSOLE_COLOR(GREEN); cin>>job;
                SET_CONSOLE_COLOR(CYAN);
                cout<<"\n\tEnter employee salary: "; SET_CONSOLE_COLOR(GREEN); cin>>salary;
                SET_CONSOLE_COLOR(CYAN);
                cout<<"\n\tEnter employee gender: "; SET_CONSOLE_COLOR(GREEN); cin>>gender;
                SET_CONSOLE_COLOR(CYAN);
                cout<<"\n\tEnter employee attendance ('P' present 'A' abasence): "; SET_CONSOLE_COLOR(GREEN); cin>>attendance;
                SET_CONSOLE_COLOR(CYAN);
                cout<<"\n\tEnter employee day off ('M' Monday or 'S' Sunday): "; SET_CONSOLE_COLOR(GREEN); cin>>dayOff;
                SET_CONSOLE_COLOR(CYAN);
                cout<<"\n\tEnter employee work hours: "; SET_CONSOLE_COLOR(GREEN); cin>>workHours;

                if(isIdExist(myList, ID) == 1) cout<<"\n\tThis ID "<<ID<<" is already existed"<<endl;
                 
                if(isIdExist(myList, ID) == 0 && (attendance == "P" || attendance == "A") && (dayOff == "M" || dayOff == "S")) {
                    insertBegin(myList, ID, name, job, salary, gender, attendance, dayOff, workHours);
                }
                else if (attendance != "P" || attendance != "A") cout<<"\n\tPlease input ('P' present 'A' abasence)"<<endl;
                else if (dayOff != "S" || dayOff != "S") cout<<"\n\tPlease input ('M' Monday or 'S' Sunday)"<<endl;
                else
                cout<<"\n\t**************************************"<<endl;
                //loading();
                break;
            case 2:
                system("cls");
                cout<<"\n\t***********************************"<<endl;
                SET_CONSOLE_COLOR(YELLOW);
                //displayData(myList);
                readFile();
                cout<<"\n\t***********************************"<<endl;
                //loading();
                break;
            case 3:
                system("cls");
                cout<<"\n\t******************************"<<endl;
                // cout<<"\n\tEnter user ID: "; cin>>ID;
                int offset;
                
                file.open("data.txt");
                cout<<"Enter employeess ID to search "<<endl; cin>>searchID;

                if(file.is_open()){
                    while (!file.eof())
                    {
                        getline(file, line);
                        if((offset = line.find(searchID, 0)) != string::npos) {
                            cout << line<<endl;
                            
                        }
                    }
                    file.close();
                }
                else{
                    cout<<"Could not open file"<<endl;
                    system("pause");
                }
                
                cout<<"\n\t******************************"<<endl;
                //loading();
                break;
            case 4:
                system("cls");
                SET_CONSOLE_COLOR(YELLOW);
                cout<<"\n\t*************************************************"<<endl;
                cout<<"\n\tSearch each user by categories"<<endl;
                cout<<"\n\t*************************************************"<<endl;
    	
                int ch4;
                do
                {
                    cout<<"\n\t1. Filter user by salary"<<endl;
                    cout<<"\n\t2. Filter user by job"<<endl;
                    cout<<"\n\t0. Back"<<endl; cout<<"Choice: "; cin>>ch4;
                    if (ch4 == 0)
                    {
                        break;
                    }else if(ch4 == 1){
                        system("cls");                        
                        int offset;
                        string mySalary;
                
                        file.open("data.txt");
                        SET_CONSOLE_COLOR(YELLOW);
                        cout<<"\n\tEnter user salary that you want to filter: "; SET_CONSOLE_COLOR(GREEN); cin>>mySalary;
                        SET_CONSOLE_COLOR(YELLOW);

                        if(file.is_open()){
                            while (!file.eof())
                            {
                                getline(file, line);
                                if((offset = line.find(mySalary, 0)) != string::npos) {
                                    cout << line<<endl;
                                    
                                }
                            }
                            file.close();
                        }
                        else{
                            cout<<"Could not open file"<<endl;
                            system("pause");
                        }
                        //filterUserBySalary(myList, salary);
                        cout<<"\n\t*************************************************"<<endl;
                    }else if(ch4 == 2) {
                        system("cls");
                        int offset;
                        string myJob;
                
                        file.open("data.txt");
                        SET_CONSOLE_COLOR(YELLOW);
                        cout<<"\n\tEnter user salary that you want to filter: "; SET_CONSOLE_COLOR(GREEN); cin>>myJob;
                        SET_CONSOLE_COLOR(YELLOW);

                        if(file.is_open()){
                            while (!file.eof())
                            {
                                getline(file, line);
                                if((offset = line.find(myJob, 0)) != string::npos) {
                                    cout << line<<endl;
                                    
                                }
                            }
                            file.close();
                        }
                        else{
                            cout<<"Could not open file"<<endl;
                            system("pause");
                        }
                        //filterUserByJob(myList, job);
                        cout<<"\n\t*************************************************"<<endl;
                        
                    }else{
                        cout<<"\n\tYour input is invalid"<<endl;
                    }
                    
                } while (ch4 != 0);
                
                //loading();
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
                int ch8;
                do
                {
                    SET_CONSOLE_COLOR(RED);
                    cout<<"\n\t******************************"<<endl;
                    cout<<"\n\tPlease select one to delete"<<endl;
                    cout<<"\n\t******************************"<<endl;
                    cout<<"\n\t1. Delete by ID"<<endl;
                    cout<<"\n\t2. Delete newest"<<endl;
                    cout<<"\n\t3. Delete oldest"<<endl;
                    cout<<"\n\t4. Delete all"<<endl;
                    cout<<"\n\t0. Back"<<endl; 
                    cout<<"\n\tChoice: "; cin>>ch8;

                    if (ch8 == 0)
                    {
                        break;
                    }else if(ch8 == 1) {
                        system("cls");

                        SET_CONSOLE_COLOR(RED);
                        cout<<"\n\t******************************"<<endl;
                        cout<<"\n\tEnter user ID to delete: "; SET_CONSOLE_COLOR(GREEN); cin>>ID;
                        cout<<"\n\t******************************"<<endl;
                        searchByIdAndDelete(myList, ID, name, job, salary);

                        //loading();
                    }else if(ch8 == 2) {
                        system("cls");  
                        deleteBegin(myList);
                        //loading();
                    }else if(ch8 == 3) {
                        system("cls");
                        deleteLast(myList);
                        //loading();
                    }else if(ch8 == 4) {
                         system("cls");
                        // deleteAll(myList);
                        remove("data.txt");
                        rename("dataTmp.txt", "data.txt");
                        //loading();
                    }else{
                        cout<<"\n\tYour input is invalid"<<endl;
                    }
                    
                } while (ch8 != 0);
                break;
            case 9:
                    system("cls");
                    SET_CONSOLE_COLOR(CYAN);
                    cout<<"Enter ID to update: "; cin>>ID;
                    if(isIdExist(myList, ID) == 1) {
                        searchByIdAndDelete(myList, ID, name, job, salary);
                        saveData(myList);
                        SET_CONSOLE_COLOR(CYAN);
                        cout<<"Enter new ID: "; SET_CONSOLE_COLOR(GREEN); cin>>ID;
                        SET_CONSOLE_COLOR(CYAN);
                        cout<<"Enter new name: "; SET_CONSOLE_COLOR(GREEN); cin>>name;
                        SET_CONSOLE_COLOR(CYAN);
                        cout<<"Enter new job: "; SET_CONSOLE_COLOR(GREEN); cin>>job;
                        SET_CONSOLE_COLOR(CYAN);
                        cout<<"Enter new salary: "; SET_CONSOLE_COLOR(GREEN); cin>>salary;
                        SET_CONSOLE_COLOR(CYAN);
                        cout<<"\n\tEnter employee gender: "; SET_CONSOLE_COLOR(GREEN); cin>>gender;
                        SET_CONSOLE_COLOR(CYAN);
                        cout<<"\n\tEnter employee attendance ('P' present 'A' abasence): "; SET_CONSOLE_COLOR(GREEN); cin>>attendance;
                        SET_CONSOLE_COLOR(CYAN);
                        cout<<"\n\tEnter employee day off ('M' Monday or 'S' Sunday): "; SET_CONSOLE_COLOR(GREEN); cin>>dayOff;
                        SET_CONSOLE_COLOR(CYAN);
                        cout<<"\n\tEnter employee work hours: "; SET_CONSOLE_COLOR(GREEN); cin>>workHours;
                        
                        if((attendance == "P" || attendance == "A") && (dayOff == "M" || dayOff == "S")) {
                            insertEnd(myList, ID, name, job, salary, gender, attendance, dayOff, workHours);
                        }
                        else if (attendance != "P" || attendance != "A") cout<<"\n\tPlease input ('P' present 'A' abasence)"<<endl;
                        else if (dayOff != "S" || dayOff != "S") cout<<"\n\tPlease input ('M' Monday or 'S' Sunday)"<<endl;   
                    }
                    else{
                        cout<<"This ID is not existed"<<endl;
                    }
                    //loading();
                break;
            case 10:
                    system("cls");
                    int ch13;
                    do
                    {
                        cout<<"\n\t******************************"<<endl;
                        cout<<"\n\tPlease select one to sort"<<endl;
                        cout<<"\n\t******************************"<<endl;
                        cout<<"\n\t1. Sorted small to big"<<endl;
                        cout<<"\n\t2. Sorted small to big"<<endl;
                        cout<<"\n\t0. Back"<<endl;
                        cout<<"\n\tChoice: "; cin>>ch13;
                        if(ch13 == 1) {
                            sort(myList); system("cls"); displayData(myList);
                        }else if(ch13 == 2){
                            sortReverse(myList); system("cls"); displayData(myList);
                        }else if(ch13 == 0) {
                            break;
                        } else{
                            cout<<"\n\tYou input wrong"<<endl;
                        }
                    } while (ch13 != 0);
                break;
            case 11:
                    system("cls");
                    displayDataAndSave(myList);
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
    cout<<"\n\t2. View all users information"<<endl;
    cout<<"\n\t3. Search user by ID"<<endl;
    SET_CONSOLE_COLOR(YELLOW);
    cout<<"\n\t****************Filter**********************"<<endl;
    cout<<"\n\t4. Filter users by categories (Salary, Job, Name)"<<endl;
    SET_CONSOLE_COLOR(GREEN);
    cout<<"\n\t****************Find**********************"<<endl;
    cout<<"\n\t5. Find a user who has top 1 salary"<<endl;
    cout<<"\n\t6. Find a user who has top 3 salary"<<endl;
    cout<<"\n\t7. Find min max and average salary"<<endl;
    SET_CONSOLE_COLOR(RED);
    cout<<"\n\t****************Delete**********************"<<endl;
    cout<<"\n\t8. Delete stop working employees by (ID, newest, oldest, all)"<<endl;
    cout<<"\n\t****************Exit**********************"<<endl;
    SET_CONSOLE_COLOR(CYAN);
    cout<<"\n\t9. Update data"<<endl;
    cout<<"\n\t10. Sort Data"<<endl;
    cout<<"\n\t11. Save data"<<endl;
    cout<<"\n\t0. Exit the console application"<<endl;
}

void authScreen() {
    SET_CONSOLE_COLOR(YELLOW);
    cout << "\n***** Login or Register *****\n\n";
    cout << "===================================\n";
    cout << "\n***** Please write (login) or (register) *****\n\n";
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
            cout << "\n*Please write (login) or (register) correctly*\n" ;
        }
    }
}
