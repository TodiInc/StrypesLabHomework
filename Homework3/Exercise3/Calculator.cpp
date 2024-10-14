#include <iostream>
#include <string>
#include <iomanip>

int main(int argc,char *argv[])
{
    std::string _operand = argv[2];

    if(_operand.compare("x") == 0 || _operand.compare("X") == 0){
        std::cout<<"Result = "<<std::fixed<<std::setprecision(2)<<atof(argv[1]) * atof(argv[3])<<std::endl;
    }
    else if(_operand.compare("/") == 0){
        std::cout<<"Result = "<<std::fixed<<std::setprecision(2)<<atof(argv[1]) / atof(argv[3])<<std::endl;
    }
    else if(_operand.compare("+") == 0){
        std::cout<<"Result = "<<std::fixed<<std::setprecision(2)<<atof(argv[1]) + atof(argv[3])<<std::endl;
    }
    else if(_operand.compare("-") == 0){
        std::cout<<"Result = "<<std::fixed<<std::setprecision(2)<<atof(argv[1]) - atof(argv[3])<<std::endl;
    }
    else{
        std::cerr<<"Invalid operation."<<std::endl;
    }
    
    return 0;
}