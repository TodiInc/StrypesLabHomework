#include <iostream>
#include <string>
#include <iomanip>

int main (int argc, char *argv[])
{
    int count = 1;

    std::string str = argv[1], compareString;

    while(!std::cin.eof()){
        getline(std::cin,compareString);
        if(str == compareString){
            count++;
        }
    }

    std::cout<<"Count = "<<count<<std::endl;
    
}

//Защо трябва да броим с едно повече (от примера към задачата)?