#include <iostream>
#include <cmath>

int circle(double radius, double& perimeter, double& area){

    std::string input;

    getline(std::cin,input);

    try
    {
        size_t idx;
        radius = std::stod(input, &idx);

        if (idx != input.length()) {
            return 1;
        }
    }
    catch(const std::invalid_argument& ia)
    {
        if(std::cin.eof())
        {
            return 2;
        }
        return 1;
    }

    if(radius <= 0)
    {
        return 1;
    }

    perimeter = 2*M_PI*radius;
    area = M_PI*std::pow(radius,2);

    return 0;
}

int main()
{
    double radius = 0, perimeter = 0, area = 0;

    while(!std::cin.eof()){

        int success = circle(radius, perimeter, area);

        switch (success){
            case 0:
                std::cout<<"P= "<<perimeter<<" S= "<< area <<std::endl;
                break;
            case 1:
                std::cerr<<"Invalid input data." <<std::endl;
                break;
            default:
                std::cout<<"Exited." <<std::endl;
                break;
            }
        }

    return 0;
}