#include <iostream>
#include <cmath>

int main() {
	float mass, height, BMI;
	std::cout << "Mass in kilograms: ";
	std::cin >> mass;
	std::cout << std::endl;
	std::cout << "Height in metres: ";
	std::cin >> height;
	std::cout << std::endl;
	BMI = mass / pow(height, 2);
	std::cout << "Body mass index: " << BMI;
	std::cout << std::endl;

	return 0;
}