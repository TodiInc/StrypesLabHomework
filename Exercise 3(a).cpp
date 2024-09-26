#include <iostream>
#include <math.h>

int main() {
	float r, h, waterVolume;
	std::cout << "Radius: ";
	std::cin >> r;
	std::cout << std::endl;
	std::cout << "Water height: ";
	std::cin >> h;
	std::cout << std::endl;
	waterVolume = M_PI * pow(r, 2) * h;
	std::cout << "Water volume in cubic metres: " << waterVolume;
	std::cout << std::endl;

	return 0;
}