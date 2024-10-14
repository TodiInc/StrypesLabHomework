#include <iostream>
#include <string>

int main (int argc, char *argv[])
{
    int count = 1;

    std::string str = argv[1];
    std::cout<<"Str = "<<argv[1]<<std::endl;
    std::string compareString;

    while(getchar()!=EOF){
        std::cin>>compareString;
        std::cout<<"compareString = "<<compareString<<std::endl;
        if(str == compareString){
            count++;
        }
    }

    std::cout<<"Count: "<<count<<std::endl;
    
}

//защо трябва да броим и самия str?