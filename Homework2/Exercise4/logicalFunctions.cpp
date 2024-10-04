#include <iostream>

int main(){

    bool n1,n2,n3;

    std::cin>>n1;
    std::cin>>n2;
    std::cin>>n3;

    if((!n1 && !n2 && !n3) || 
    (!n1 && n2 && !n3) || 
    (!n1 && n2 && n3) || 
    (n1 && n2 && n3)){

        std::cout<<"Synthesized by 1: 1"<< std::endl;
    }
    else
    {
        std::cout<<"Synthesized by 1: 0"<< std::endl;
    }
    
    if((n1 || n2 || !n3) && 
    (!n1 || n2 || n3) && 
    (!n1 || n2 || !n3) && 
    (!n1 || !n2 || n3)){

        std::cout<<"Synthesized by 0: 1"<< std::endl;
    }
    else
    {
        std::cout<<"Synthesized by 0: 0"<< std::endl;
    }

    if((!n1 && !n3) || (!n1 && n2 && n3) || (n1 && n2 && n3)){

        std::cout<<"Minimized: 1"<< std::endl;
    }
    else
    {
        std::cout<<"Minimized: 0"<< std::endl;
    }

    return 0;
}