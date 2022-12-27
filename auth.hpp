#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>

using namespace std;
bool isAuth = false;
string salt = "aksjfalksfdjlkasjfdjlkas1a414afs41fd";
//Login function
bool login(){
string UserName,Password;
string UseEnter,PassEnter;
bool On_Off = true;
bool Off = true;
int countt = 0;
int left = 3;
int ch;
cout << "\n**** Login to your Account **** \n";
while(On_Off){
    //********************************************
    fstream user;
    user.open("users.txt", ios::in);
    if(countt < 3 && Off && user.is_open()){
        if(countt > 0){
        cout << "\nPassword or Username are not correct!!" << endl;
        left--;
        cout << "You have *" << left << "* attempts left \n" << endl;
        }
        
        do
        {
            SET_CONSOLE_COLOR(YELLOW);
            cout<<"\n\tEnter UserName: ";
            SET_CONSOLE_COLOR(GREEN);
            getline(cin,UseEnter);
            SET_CONSOLE_COLOR(YELLOW);
        } while (UseEnter == "");
        
        SET_CONSOLE_COLOR(YELLOW);
        cout<<"\n\tEnter Password: ";
        ch = getch();
        while (ch != 13)
        {
            PassEnter.push_back(ch);
            cout<<"x";
            ch = getch();
        }
        SET_CONSOLE_COLOR(YELLOW);
   
        
        countt++;
        string read;
        //====================================================*
        while(getline(user,read)){
            stringstream convertor(read);
            convertor >> UserName >> Password;
            if(UseEnter == UserName && salt+PassEnter+salt == Password){
                Off = false;}}
        //=====================================================*
            }
    else if(!Off){
        cout << "\n**** Welcome! ****\n\n";
        isAuth = true;
        user.close();
        On_Off = false;
}
    else {
        cout << "\n**** Try again later!! **** \n\n";
        isAuth = false;
        user.close();
        On_Off = false;
    }
}
}

// Registry function
void registry(){
string newName,checkName,newPass,confirmPass;
int MiniPass ;
bool if_ON = true;
bool oo = true;
int ch;
cout << "\n\t**** Create New Account **** \n";

//UserName Validation
while(oo){
    cout << "\n\tEnter New UserName: ";
    getline(cin, newName);
    MiniPass = newName.length();
    fstream yusers;
    yusers.open("Users.txt",ios::in);
    if(if_ON && MiniPass >= 1 && yusers.is_open()){
        string readd;
        while(getline(yusers,readd)){
            stringstream OnlyUsers(readd);
            OnlyUsers >> checkName;
            if(newName == checkName){
                cout <<"\n*"<< newName <<"* UserName already exists Try another one\n" << endl;
                if_ON = false;
            }
    }
    yusers.close();
    if(!if_ON){
       if_ON = true;
    }
    else{
        oo = false;
    }
    }
}
//Password Validation
while(true){
    cout << "\n\tEnter New password: ";
    ch = getch();
    while (ch != 13)
    {
        newPass.push_back(ch);
        cout<<"x";
        ch = getch();
    }
    cout << "\n\tConfirm the password: ";
    ch = getch();
    while (ch != 13)
    {
        confirmPass.push_back(ch);
        cout<<"x";
        ch = getch();
    }
    MiniPass = newPass.length();

    if (MiniPass < 5){
        cout << "\n\tYour password is weak at least 5 letters\n \n";
    }
    else if(confirmPass == newPass){
        fstream users;
        users.open("Users.txt",ios::app);
        if(users.is_open()){
            users << newName +" "+salt+newPass+salt<< endl;
            users.close();
        }
        cout << "\n===================================\n";
        cout << "\nSuccessfully new account created! \n \n";
        cout << "===================================\n";
        break;}
    else{
        cout << "\n\tPassword confirmation not correct! \n" << endl;

        }
        }
    login();

}
