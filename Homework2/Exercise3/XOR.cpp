#include <iostream>
#include <string>

int main(){

    bool n1,n2;

    for (int i = 0; i < 4; i++)
    {
        std::cin>>n1;
        std::cin>>n2;

        if(n1 == n2){
            std::cout<<"0"<<std::endl;
        }
        else{
            std::cout<<"1"<<std::endl;
        }
    }
    
    std::cout<<std::endl;

    return 0;
}