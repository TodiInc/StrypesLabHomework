#include <iostream>
#include <cstdint>

const int TOTAL_STUDENTS = 64;

void showMenu() {
    std::cout << "\nMENU:\n";
    std::cout << "1. Mark student present\n";
    std::cout << "2. Mark student absent\n";
    std::cout << "3. Show absent students\n";
    std::cout << "4. Show present students\n";
    std::cout << "5. Toggle student status\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

void addPresence(uint64_t &attendanceMask){

    int student;
    std::cout<<"Choose student: ";
    std::cin>>student;
    while(student < 1 || student > 64){
        std::cout<<"No such student number!";
        std::cin>>student;
    }
    attendanceMask |=(1<<student);
}

void removePresence(uint64_t &attendanceMask){

    int student;
    std::cout<<"Choose student: ";
    std::cin>>student;
    while(student < 1 || student > 64){
        std::cout<<"No such student number!";
        std::cin>>student;
    }
    attendanceMask &=~(1<<student);
}

void showAbsentStudents(uint64_t &attendanceMask){

    bool flag = true;
    std::cout<<"Absent students: ";
    for (int i = 0; i < 64; i++)
    {
        if(!((attendanceMask&(1<<i))>>i)){
            std::cout<<i+1<<" ";
            flag = false;
        }
    }
    if(flag){
        std::cout<<" None.";
    }
}

void showPresentStudents(uint64_t &attendanceMask){

    bool flag = true;
    std::cout<<"Present students: ";
    for (int i = 0; i < 64; i++)
    {
        if(((attendanceMask&(1<<i))>>i)){
            std::cout<<i+1<<" ";
            flag = false;
        }
    }
    if(flag){
        std::cout<<" None.";
    }
}

void toggleStudentStatus(uint64_t &attendanceMask){

    int student;
    std::cout<<"Choose student: ";
    std::cin>>student;
    while(student < 1 || student > 64){
        std::cout<<"No such student number!";
        std::cin>>student;
    }
    attendanceMask ^=(1<<student);
}

int main() {
    uint64_t attendanceMask = 0;
    int option;

    do {
        showMenu();
        std::cin >> option;

        switch (option) {
            case 1:
                addPresence(attendanceMask);
                break;
            case 2:
                removePresence(attendanceMask);
                break;
            case 3:
                showAbsentStudents(attendanceMask);
                break;
            case 4:
                showPresentStudents(attendanceMask);
                break;
            case 5:
                toggleStudentStatus(attendanceMask);
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option! Try again.\n";
                break;
        }
    } while (option != 0);

    return 0;
}
