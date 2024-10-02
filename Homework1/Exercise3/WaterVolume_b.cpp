#include <iostream>
#include <math.h>

int main() {
	float r, h, l, area, waterVolume;

	std::cout << "Radius: ";
	std::cin >> r;
	std::cout << std::endl;
	std::cout << "Water height: ";
	std::cin >> h;
	std::cout << std::endl;
	std::cout << "Cylinder length: ";
	std::cin >> l;
	std::cout << std::endl;	

	area = acos((r-h)/r)*pow(r,2)-(r-h)*sqrt(2*r*h-pow(h,2));

	waterVolume = area * l;

	std::cout << "Water volume in cubic metres: " << waterVolume;
	std::cout << std::endl;

	return 0;
}