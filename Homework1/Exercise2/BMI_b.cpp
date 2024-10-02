#include <iostream>
#include <math.h>

int main() {
	float mass, height, BMI;
	std::cout << "Mass in kilograms: ";
	std::cin >> mass;
	std::cout << std::endl;
	std::cout << "Height in metres: ";
	std::cin >> height;
	std::cout << std::endl;

	BMI = 1.3 * mass / pow(height, 2.5);
	
	std::cout << "Body mass index: " << BMI;
	std::cout << std::endl;

	return 0;
}