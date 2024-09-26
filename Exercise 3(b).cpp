#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	float r, h, l, area, waterVolume, result, angle = 90;

	std::cout << "Radius: ";
	std::cin >> r;
	std::cout << std::endl;
	std::cout << "Water height: ";
	std::cin >> h;
	std::cout << std::endl;
	std::cout << "Cylinder length: ";
	std::cin >> l;
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	result = angle * M_PI / 180;
	

	area = (pow(cos((r - h) / r), -1) * pow(r, 2) ) -( (r - h) * sqrt(2 * r * h - pow(h, 2)));
	waterVolume = area * l;

	std::cout << "Water volume in cubic metres: " << waterVolume;
	std::cout << std::endl;

	return 0;
}