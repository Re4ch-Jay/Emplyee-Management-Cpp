#include <iostream>
#include <fstream>
#include<string>

using namespace std;
int ID;

struct Employee {

    int id;
    string name;
    string job;
    int age;
    string gender;
    double salary;
};

void addEmployee() {
    List *ls;
    ls = createEmptyList();
    char choice;
    Employee Employee;
    cout << "\n\tEnter Employee name : ";
    cin.get();
    getline(cin, Employee.name); //Nouman Habib
    cout << "\n\tEnter Employee age : ";
    cin >> Employee.age;
    
    do
    {
        cout << "\n\tEnter Employee job (1. Developer, 2. Teacher, 3. Accounting): ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            Employee.job = "Developer";
            break;
        case '2':
            Employee.job = "Teaching";
            break;
        case '3':
            Employee.job = "Accounting";
            break;
        default:
            cout<<"Wrong input"<<endl;
            break;
        }
        if(Employee.job == "Developer" || Employee.job == "Teaching" || Employee.job == "Accounting") {
            break;
        }
    } while (Employee.job != "Developer" || Employee.job != "Teaching" || Employee.job != "Accounting");
    
    
    do
    {
        cout << "\n\tEnter Employee gender(1. M or 2. F) : ";
        cin >>choice;
        switch (choice)
        {
        case '1':
            Employee.gender = "M";
            break;
        case '2':
            Employee.gender = "F";
            break;
        default:
            cout<<"Wrong input"<<endl;
            break;
        }

        if(Employee.gender == "M" || Employee.gender == "F") {
            break;
        }
        
    } while (Employee.gender != "M" || Employee.gender != "F");
    
    cout << "\n\tEnter Employee salary (e.g. 3000): ";
    cin >> Employee.salary;
    ID++;

    insertToReportFileAndSave(ls, ID, Employee.name, Employee.job, Employee.salary, Employee.gender);
    // store upcomming retired employee
    if(Employee.age >= 50) {
        ofstream write;
        write.open("retired.txt", ios::app);
        write << "\n" << ID;
        write << "\n" << Employee.name ;
        write << "\n" << Employee.age ;
        write << "\n" << Employee.job ;
        write << "\n" << Employee.gender;
        write << "\n" << Employee.salary;

        write.close();
        write.open("id.txt");
        write << ID;
        write.close();
        cout << "\n\tData save to file";
    }

    // store all employee
    ofstream write;
    write.open("Employee.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << Employee.name ;
    write << "\n" << Employee.age ;
    write << "\n" << Employee.job ;
    write << "\n" << Employee.gender;
    write << "\n" << Employee.salary;

    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file";
}

void print(Employee s) {
    cout << s.id<<"\t\t";
    cout << s.name<<"\t\t";
    cout << s.age<<"\t\t";
    cout << s.job<<"\t\t";
    cout << s.gender<<"\t\t\t";
    cout << s.salary<<"\t\t";
    cout <<endl;
}

void readData() {
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    if(!read.is_open()){
        cout<<"\n\tCould not open the file"<<endl;
    }
    cout<<"ID: \t\tName: \t\tAge: \t\tJob title: \t\tGender: \t\tSalary: \t\t"<<endl;
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;     
        print(Employee);
    }
    read.close();
}

void readDataRetired() {
    Employee Employee;
    ifstream read;
    read.open("retired.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;     
        print(Employee);
    }
    read.close();
}

int searchDataById() {
    int id;
    cout << "\n\tEnter Employee id want to search : ";
    cin >> id;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;
        if (Employee.id == id) {
            cout<<"ID: \t\tName: \t\tAge: \t\tJob title: \t\tGender: \t\tSalary: \t\t"<<endl;
            print(Employee);
            return id;
        }
    }
    if(read.eof() && Employee.id != id) {
        cout<<"\n\tNo data found"<<endl;
    }
}

void searchDataBySalary() {
    double salary;
    int count = 0;
    cout << "\n\tEnter Employee salary want to search : ";
    cin >> salary;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    cout<<"ID: \t\tName: \t\tAge: \t\tJob title: \t\tGender: \t\tSalary: \t\t"<<endl;
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;
        if (Employee.salary == salary) {
            print(Employee);
        }
    }
    if(read.eof() && Employee.salary != salary) {
        cout<<"\n\tNo data found"<<endl;
    }
}

void searchDataByGender() {
    string gender;
    cout << "\n\tEnter Employee gender (M or F) want to search : ";
    cin >> gender;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    cout<<"ID: \t\tName: \t\tAge: \t\tJob title: \t\tGender: \t\tSalary: \t\t"<<endl;
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;
        if (Employee.gender == gender) {
            print(Employee);
        }
    }
    if(read.eof() && Employee.gender != gender) {
       cout<<"\n\tNo data found"<<endl;
    }
}


void searchDataByAge() {
    int age;
    cout << "\n\tEnter Employee age want to search : ";
    cin >> age;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    cout<<"ID: \t\tName: \t\tAge: \t\tJob title: \t\tGender: \t\tSalary: \t\t"<<endl;
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;
        if (Employee.age == age) {
            print(Employee);
        }
    }
    if(read.eof() && Employee.age != age) {
        cout<<"\n\tNo data found"<<endl;
    }
}

void viewDeveloperDepartment() {
    string department = "Developer" ;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;
        if (Employee.job == department) {
            print(Employee);
        }
    }
}

void viewTeachingDepartment() {
    string department = "Teaching" ;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;
        if (Employee.job == department) {
            print(Employee);
        }
    }
}

void viewAccountingDepartment() {
    string department = "Accounting" ;
    Employee Employee;
    ifstream read;
    read.open("Employee.txt");
    while (!read.eof()) {
        read >> Employee.id;
        read.ignore();
        getline(read, Employee.name);
        read >> Employee.age;
        read >> Employee.job;
        read >> Employee.gender;
        read >> Employee.salary;
        if (Employee.job == department) {
            print(Employee);
        }
    }
}

void deleteData() {
    int id = searchDataById();
    if(id == 0) {
        cout<<endl;
    }else{
        cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Employee Employee;
        // delete from upcomming retired file
        ofstream tempFile2;
        tempFile2.open("temp2.txt");
        ifstream read2;
        
        read2.open("retired.txt");
        while (!read2.eof()) {
            read2 >> Employee.id;
            read2.ignore();
            getline(read2, Employee.name);
            read2 >> Employee.age;
            read2 >> Employee.job;
            read2 >> Employee.gender;
            read2 >> Employee.salary;
            if (Employee.id != id) {
                tempFile2 << "\n" << Employee.id;
                tempFile2 << "\n" << Employee.name;
                tempFile2 << "\n" << Employee.age;
                tempFile2 << "\n" << Employee.job;
                tempFile2 << "\n" << Employee.gender;
                tempFile2 << "\n" << Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData deleted successfuly";

        // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

        // delete from all employees file
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Employee.txt");
        while (!read.eof()) {
            read >> Employee.id;
            read.ignore();
            getline(read, Employee.name);
            read >> Employee.age;
            read >> Employee.job;
            read >> Employee.gender;
            read >> Employee.salary;
            if (Employee.id != id) {
                tempFile << "\n" << Employee.id;
                tempFile << "\n" << Employee.name;
                tempFile << "\n" << Employee.age;
                tempFile << "\n" << Employee.job;
                tempFile << "\n" << Employee.gender;
                tempFile << "\n" << Employee.salary;
            }
            // check if Id is equal than saved it to reportData.txt
            if(Employee.id == id) {
                writeToReport << "\tDelete data: ID: " << Employee.id <<"\tName: "<< Employee.name <<"\tJob: "<< Employee.job <<"\tGender: "<< Employee.gender <<"\tAttendance: "<<"\tSalary: $"<< Employee.salary<<"\tAge: "<< Employee.age<<endl;
            }
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData deleted successfuly";
       
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
}

void updateData() {
    int id = searchDataById();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter Employee age : ";
        cin >> newData.age;
        cout << "\n\tEnter Employee gender : ";
        cin >> newData.gender;
        cout << "\n\tEnter Employee salary : ";
        cin >> newData.salary;
        
        Employee Employee;

        // uppdate upcomming retired file
        ofstream tempFile2;
        tempFile2.open("temp2.txt");
        ifstream read2;
        read2.open("retired.txt");
        while (!read2.eof()) {
            read2 >> Employee.id;
            read2.ignore();
            getline(read2, Employee.name);
            read2 >> Employee.age;
            read2 >> Employee.job;
            read2 >> Employee.gender;
            read2 >> Employee.salary;
            if (Employee.id != id) {
                tempFile2 << "\n" << Employee.id;
                tempFile2 << "\n" << Employee.name;
                tempFile2 << "\n" << Employee.age;
                tempFile2 << "\n" << Employee.job;
                tempFile2 << "\n" << Employee.gender;
                tempFile2 << "\n" << Employee.salary;
            }
            else {
                tempFile2 << "\n"<< Employee.id;
                tempFile2 << "\n"<< newData.name;
                tempFile2 << "\n"<< newData.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< newData.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";

        // update all employees from employee file
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Employee.txt");
        while (!read.eof()) {
            read >> Employee.id;
            read.ignore();
            getline(read, Employee.name);
            read >> Employee.age;
            read >> Employee.job;
            read >> Employee.gender;
            read >> Employee.salary;
            if (Employee.id != id) {
                tempFile << "\n" << Employee.id;
                tempFile << "\n" << Employee.name;
                tempFile << "\n" << Employee.age;
                tempFile << "\n" << Employee.job;
                tempFile << "\n" << Employee.gender;
                tempFile << "\n" << Employee.salary;
            }
            else {
                tempFile << "\n"<< Employee.id;
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< newData.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< newData.gender;
                tempFile << "\n"<< newData.salary;
            }
        }
        read.close();
        tempFile.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void updateDataName() {
    int id = searchDataById();
    if(id == 0) {
        cout<<endl;
    }else{
        cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee name : ";
        cin.get();
        getline(cin, newData.name);
        
        Employee Employee;

        // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

        // uppdate upcomming retired file
        ofstream tempFile2;
        tempFile2.open("temp2.txt");
        ifstream read2;
        read2.open("retired.txt");
        while (!read2.eof()) {
            read2 >> Employee.id;
            read2.ignore();
            getline(read2, Employee.name);
            read2 >> Employee.age;
            read2 >> Employee.job;
            read2 >> Employee.gender;
            read2 >> Employee.salary;
            if (Employee.id != id) {
                tempFile2 << "\n" << Employee.id;
                tempFile2 << "\n" << Employee.name;
                tempFile2 << "\n" << Employee.age;
                tempFile2 << "\n" << Employee.job;
                tempFile2 << "\n" << Employee.gender;
                tempFile2 << "\n" << Employee.salary;
            }
            else {
                tempFile2 << "\n"<< Employee.id;
                tempFile2 << "\n"<< newData.name;
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< Employee.salary;
                
            }
               
        
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // update all employees from employee file
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Employee.txt");
        while (!read.eof()) {
            read >> Employee.id;
            read.ignore();
            getline(read, Employee.name);
            read >> Employee.age;
            read >> Employee.job;
            read >> Employee.gender;
            read >> Employee.salary;
            if (Employee.id != id) {
                tempFile << "\n" << Employee.id;
                tempFile << "\n" << Employee.name;
                tempFile << "\n" << Employee.age;
                tempFile << "\n" << Employee.job;
                tempFile << "\n" << Employee.gender;
                tempFile << "\n" << Employee.salary;
            }
            else {
                tempFile << "\n"<< Employee.id;
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< Employee.salary;
                writeToReport << "\tUpdate name with ID: "<<Employee.id <<"\t New name: "<<newData.name<<endl;
            }
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not updated";
    }
    }
    
}

void updateDataAge() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
        cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee age : ";
        cin >> newData.age;
        
        Employee Employee;

         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);
        // uppdate upcomming retired file
        ofstream tempFile2;
        tempFile2.open("temp2.txt");
        ifstream read2;
        read2.open("retired.txt");
        while (!read2.eof()) {
            read2 >> Employee.id;
            read2.ignore();
            getline(read2, Employee.name);
            read2 >> Employee.age;
            read2 >> Employee.job;
            read2 >> Employee.gender;
            read2 >> Employee.salary;
            if (Employee.id != id) {
                tempFile2 << "\n" << Employee.id;
                tempFile2 << "\n" << Employee.name;
                tempFile2 << "\n" << Employee.age;
                tempFile2 << "\n" << Employee.job;
                tempFile2 << "\n" << Employee.gender;
                tempFile2 << "\n" << Employee.salary;
            }
            else {
                tempFile2 << "\n"<< Employee.id;
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< newData.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< Employee.salary;
                
            }
        }
        read2.close();
        tempFile2.close();
        writeToReport.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // update all employees from employee file
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Employee.txt");
        while (!read.eof()) {
            read >> Employee.id;
            read.ignore();
            getline(read, Employee.name);
            read >> Employee.age;
            read >> Employee.job;
            read >> Employee.gender;
            read >> Employee.salary;
            if (Employee.id != id) {
                tempFile << "\n" << Employee.id;
                tempFile << "\n" << Employee.name;
                tempFile << "\n" << Employee.age;
                tempFile << "\n" << Employee.job;
                tempFile << "\n" << Employee.gender;
                tempFile << "\n" << Employee.salary;
            }
            else {
                tempFile << "\n"<< Employee.id;
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< newData.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< Employee.salary;
                writeToReport << "\tUpdate age with ID: "<<Employee.id <<"\t New age: "<<newData.age<<endl;
            }
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
}

void updateDataGender() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
        cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        
        do
        {
            cout << "\n\tEnter Employee gender : ";
            cin >> newData.gender;
            if(newData.gender == "M" || newData.gender == "F") {
                break;
            }else {
                cout<<"\n\tInvalid Input"<<endl;
            }
        } while (newData.gender != "M" || newData.gender != "F");
        
        Employee Employee;

         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);

        // uppdate upcomming retired file
        ofstream tempFile2;
        tempFile2.open("temp2.txt");
        ifstream read2;
        read2.open("retired.txt");
        while (!read2.eof()) {
            read2 >> Employee.id;
            read2.ignore();
            getline(read2, Employee.name);
            read2 >> Employee.age;
            read2 >> Employee.job;
            read2 >> Employee.gender;
            read2 >> Employee.salary;
            if (Employee.id != id) {
                tempFile2 << "\n" << Employee.id;
                tempFile2 << "\n" << Employee.name;
                tempFile2 << "\n" << Employee.age;
                tempFile2 << "\n" << Employee.job;
                tempFile2 << "\n" << Employee.gender;
                tempFile2 << "\n" << Employee.salary;
            }
            else {
                tempFile2 << "\n"<< Employee.id;
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< newData.gender;
                tempFile2 << "\n"<< Employee.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";


        // update all employees from employee file
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Employee.txt");
        while (!read.eof()) {
            read >> Employee.id;
            read.ignore();
            getline(read, Employee.name);
            read >> Employee.age;
            read >> Employee.job;
            read >> Employee.gender;
            read >> Employee.salary;
            if (Employee.id != id) {
                tempFile << "\n" << Employee.id;
                tempFile << "\n" << Employee.name;
                tempFile << "\n" << Employee.age;
                tempFile << "\n" << Employee.job;
                tempFile << "\n" << Employee.gender;
                tempFile << "\n" << Employee.salary;
            }
            else {
                tempFile << "\n"<< Employee.id;
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< newData.gender;
                tempFile << "\n"<< Employee.salary;
                writeToReport << "\tUpdate gender with ID: "<<Employee.id <<"\t New gender: "<<newData.gender<<endl;
            }
                
            
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
    
}

void updateDataSalary() {
    int id = searchDataById();
    if(id == 0){
        cout<<endl;
    }else{
        cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        // input new data
        Employee newData;
        cout << "\n\tEnter Employee salary : ";
        cin >> newData.salary;
        
        Employee Employee;
         // save the data that has been delete to reportData file
        fstream writeToReport;
        writeToReport.open("reportData.txt", ios::app);
        // uppdate upcomming retired file
        ofstream tempFile2;
        tempFile2.open("temp2.txt");
        ifstream read2;
        read2.open("retired.txt");
        while (!read2.eof()) {
            read2 >> Employee.id;
            read2.ignore();
            getline(read2, Employee.name);
            read2 >> Employee.age;
            read2 >> Employee.job;
            read2 >> Employee.gender;
            read2 >> Employee.salary;
            if (Employee.id != id) {
                tempFile2 << "\n" << Employee.id;
                tempFile2 << "\n" << Employee.name;
                tempFile2 << "\n" << Employee.age;
                tempFile2 << "\n" << Employee.job;
                tempFile2 << "\n" << Employee.gender;
                tempFile2 << "\n" << Employee.salary;
            }
            else {
                tempFile2 << "\n"<< Employee.id;
                tempFile2 << "\n"<< Employee.name;
                tempFile2 << "\n"<< Employee.age;
                tempFile2 << "\n"<< Employee.job;
                tempFile2 << "\n"<< Employee.gender;
                tempFile2 << "\n"<< newData.salary;
            }
        }
        read2.close();
        tempFile2.close();
        remove("retired.txt");
        rename("temp2.txt", "retired.txt");
        cout << "\n\tData updated successfuly";

        // update all employees from employee file
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("Employee.txt");
        while (!read.eof()) {
            read >> Employee.id;
            read.ignore();
            getline(read, Employee.name);
            read >> Employee.age;
            read >> Employee.job;
            read >> Employee.gender;
            read >> Employee.salary;
            if (Employee.id != id) {
                tempFile << "\n" << Employee.id;
                tempFile << "\n" << Employee.name;
                tempFile << "\n" << Employee.age;
                tempFile << "\n" << Employee.job;
                tempFile << "\n" << Employee.gender;
                tempFile << "\n" << Employee.salary;
            }
            else {
                tempFile << "\n"<< Employee.id;
                tempFile << "\n"<< Employee.name;
                tempFile << "\n"<< Employee.age;
                tempFile << "\n"<< Employee.job;
                tempFile << "\n"<< Employee.gender;
                tempFile << "\n"<< newData.salary;
                writeToReport << "\tUpdate salary with ID: "<<Employee.id <<"\t New salary: "<<newData.salary<<endl;
            }
        
                
        }
        read.close();
        tempFile.close();
        writeToReport.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
    }
    
}
