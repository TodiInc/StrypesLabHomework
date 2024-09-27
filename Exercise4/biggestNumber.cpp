#include <iostream>

int main() {
	double arr[3];
	for (int i = 0; i < 3; i++)
	{
		std::cin >> arr[i];
	}

	double biggest_number = arr[0];

	for (int i = 1; i < 3; i++)
	{
		if (biggest_number < arr[i])
			biggest_number = arr[i];
	}

	std::cout << "Biggest number is: " << biggest_number << std::endl;

	return 0;
}