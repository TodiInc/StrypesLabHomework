#include <iostream>
#include <cstdint>

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

void checkInput(int &number)
{
    bool shouldLoop = true;
    do
    {
        std::string input;

        getline(std::cin,input);
        try
        {
            size_t idx;
            number = std::stod(input, &idx);

            if (idx != input.length()) {
                std::cerr<<"Invalid input. Try again: ";
            }else{
                shouldLoop = false;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr<<"Invalid input. Try again: ";
        }

    } while (shouldLoop);
    
}

void addPresence(uint64_t &attendanceMask){

    int student;
    std::cout<<"Choose student: ";

    checkInput(student);

    while(student < 1 || student > 64){
        std::cerr<<"No such student number! Try again: ";
        checkInput(student);
    }
    attendanceMask = attendanceMask | (1ULL<<(student-1));
}

void removePresence(uint64_t &attendanceMask){

    int student;
    std::cout<<"Choose student: ";
    checkInput(student);

    while(student < 1 || student > 64){
        std::cerr<<"No such student number! Try again: ";
        checkInput(student);
    }
    attendanceMask = attendanceMask & ( ~ (1ULL<<(student-1)));
}

void showAbsentStudents(uint64_t &attendanceMask){

    bool flag = true;
    std::cout<<"Absent students: ";
    for (int i = 0; i < 64; i++)
    {
        if(!((attendanceMask & (1ULL<<i))>>i)){
            std::cout<<i+1<<" ";
            flag = false;
        }
    }
    std::cout << std::endl;
    if(flag){
        std::cout<<" None.";
    }
}

void showPresentStudents(uint64_t &attendanceMask){

    bool flag = true;
    std::cout<<"Present students: ";
    for (int i = 0; i < 64; i++)
    {
        if((attendanceMask&(1ULL<<i))>>i){
            std::cout<<i+1<<" ";
            flag = false;
        }
    }
    std::cout << std::endl;
    if(flag){
        std::cout<<" None.";
    }
}

void toggleStudentStatus(uint64_t &attendanceMask){

    int student;
    std::cout<<"Choose student: ";
    checkInput(student);

    while(student < 1 || student > 64){
        std::cerr<<"No such student number! Try again: ";
        checkInput(student);
    }
    attendanceMask = attendanceMask ^ (1ULL<<(student-1));
}

int main() {
    uint64_t attendanceMask = 0;
    int option;

    do {
        showMenu();

        checkInput(option);

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
            std::cout << "Exited\n";
            break;
        default:
            std::cerr<<"Invalid option.";
            break;
        }
        
    } while (option != 0);

    return 0;
}