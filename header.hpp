#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

struct Element {
    string ID;
    int id;
    string name;
    string job;
    string gender;
    string attendance;
    string dayOff;
    double workHours;
    double salary;

    Element *next;
};


struct List {
    int size;
    Element *head, *tail;
};

List * createEmptyList(){
    List *ls;
    ls = new List();

    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}


void copyFileEmployees() {
    string line, filename;
    ifstream ini_file{ "Employee.txt"};
    cout<<"Input filename: "; cin>>filename;
    ofstream out_file{ filename + ".txt" };
    if (ini_file && out_file) {
  
        while (getline(ini_file, line)) {
            out_file << line << "\n";
        }
        cout << "Your file has been created\n";
    }
    else {
        printf("Cannot read File");
    }
    ini_file.close();
    out_file.close();
}

void copyFileDevelopment() {
    string line, filename;
    ifstream ini_file{ "Developer.txt"};
    cout<<"Input filename: "; cin>>filename;
    ofstream out_file{ filename + ".txt" };
    if (ini_file && out_file) {
  
        while (getline(ini_file, line)) {
            out_file << line << "\n";
        }
        cout << "Your file has been created\n";
    }
    else {
        printf("Cannot read File");
    }
    ini_file.close();
    out_file.close();
}

void copyFileAccounting() {
    string line, filename;
    ifstream ini_file{ "Accounting.txt"};
    cout<<"Input filename: "; cin>>filename;
    ofstream out_file{ filename + ".txt" };
    if (ini_file && out_file) {
  
        while (getline(ini_file, line)) {
            out_file << line << "\n";
        }
        cout << "Your file has been created\n";
    }
    else {
        printf("Cannot read File");
    }
    ini_file.close();
    out_file.close();
}

void copyFileTeaching() {
    string line, filename;
    ifstream ini_file{ "Teacher.txt"};
    cout<<"Input filename: "; cin>>filename;
    ofstream out_file{ filename + ".txt" };
    if (ini_file && out_file) {
  
        while (getline(ini_file, line)) {
            out_file << line << "\n";
        }
        cout << "Your file has been created\n";
    }
    else {
        printf("Cannot read File");
    }
    ini_file.close();
    out_file.close();
}



void copyFileReport() {
    string line, filename;
    ifstream ini_file{ "reportData.txt"};
    cout<<"Input filename: "; cin>>filename;
    ofstream out_file{ filename + ".txt" };
    if (ini_file && out_file) {
  
        while (getline(ini_file, line)) {
            out_file << line << "\n";
        }
        cout << "Your file has been created\n";
    }
    else {
        printf("Cannot read File");
    }
    ini_file.close();
    out_file.close();
}


void readFile() {
    fstream file;
    file.open("reportData.txt");
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
            file.open("reportData.txt", ios::in);
            cout << "Couldn't open file\n";
            break;
        }
    }
    file.close();
    char choice;
    cout<<"Do you want to save this file? [y/n]"; cin>>choice;
    if(choice == 'y') {
        copyFileReport();
    }else{
        cout<<"\n\tFile not save"<<endl;
    }
    
}

void saveData(List *ls){
    fstream file;
    file.open("reportData.txt", ios::app);
    Element * tmp;
    tmp = ls->head;
    if(file.is_open()) {
        while (tmp != NULL)
        {
            file<<"\tID: "<<tmp->ID<<"\tName: "<<tmp->name<<"\tJob: "<<tmp->job<<"\tSalary: $"<<tmp->salary<<"\tGender: "<<tmp->gender<<"\tAttendance: "<<tmp->attendance<<"\tDay off: "<<tmp->dayOff<<"\tWork Hours: "<<tmp->workHours<<endl;
            tmp = tmp->next;
        }
    }
    file.close();
}

void saveFile(string ID, string name, string job, double salary, string gender, string attendance, string dayOff, double workHours) {
    fstream file;
    file.open("data.txt", ios::app);
    if(file.is_open()) {
        file<<"\tID: "<<ID<<"\tName: "<<name<<"\tJob: "<<job<<"\tSalary: $"<<salary<<"\tGender: "<<gender<<"\tAttendance: "<<attendance<<"\tDay off: "<<dayOff<<"\tWork Hours: "<<workHours<<endl;
    }
    file.close();
}

void saveReportFile(int ID, string name, string job, double salary, string gender, string attendance, string dayOff, double workHours) {
    fstream file;
    file.open("reportData.txt", ios::app);
    if(file.is_open()) {
        file<<"Added data: \tID: "<<ID<<"\tName: "<<name<<"\tJob: "<<job<<"\tSalary: $"<<salary<<"\tGender: "<<gender<<"\tAttendance: "<<attendance<<"\tDay off: "<<dayOff<<"\tWork Hours: "<<workHours<<endl;
    }
    file.close();
}


void insertToReportFileAndSave(List *ls, int ID, string name, string job, double salary, string gender, string attendance, string dayOff, double workHours) {

    Element * e;
    e = new Element();
    e->salary = salary;
    e->ID = ID;
    e->name = name;
    e->job = job;
    e->attendance = attendance;
    e->gender = gender;
    e->dayOff = dayOff;
    e->workHours = workHours;


    e->next = ls->head;
    ls->head = e;
    if(ls->size == 0) {
        ls->tail = e;
    }
    ls->size++;       
    saveReportFile(ID, name, job, salary, gender, attendance, dayOff, workHours);
}


void displayData(List *ls){
    Element * tmp;
    tmp = ls->head;
    if(ls->size == 0) cout<<"\n\tThere is no data right now"<<endl;
    while (tmp != NULL)
    {
        ShowMessage("\n\tAll data in the list", CYAN);
        cout<<"\tID: "<<tmp->ID<<"\tName: "<<tmp->name<<"\tJob: "<<tmp->job<<"\tSalary: $"<<tmp->salary<<"\tGender: "<<tmp->gender<<"\tAttendance: "<<tmp->attendance<<"\tDay off: "<<tmp->dayOff<<"\tWork Hours: "<<tmp->workHours<<endl;
        tmp = tmp->next;
    }
}


int loading(){
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "\n\tLoading\n";
    long long k = 0;
    while (1 && k < 1) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
        k += 1;
    }
    return 0;
}
