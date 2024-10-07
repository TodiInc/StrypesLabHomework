#include <iostream>
#include <cmath>
#include <iomanip>

template<typename T>
bool compareAbsolute(T a, T b, T epsilon) {
    return fabs(a - b) < epsilon;
}

template<typename T>
bool compareRelative(T a, T b, T epsilon) {
    return fabs(a - b) / fmax(fabs(a), fabs(b)) < epsilon;
}

template<typename T>
bool compareCombined(T a, T b, T epsilon) {
    return fabs(a - b) < epsilon || fabs(a - b) / fmax(fabs(a), fabs(b)) < epsilon;
}

template<typename T>
bool compareULP(T a, T b, int maxUlps) {
    int intA = *(int*)&a;
    int intB = *(int*)&b;
    if (intA < 0) intA = 0x80000000 - intA;
    if (intB < 0) intB = 0x80000000 - intB;
    return abs(intA - intB) <= maxUlps;
}

void runTests() {
    const int testCount = 1000000;
    int correctAbs = 0, correctRel = 0, correctComb = 0, correctULP = 0;
    float flopat_epsilon = 1e-5;
    double double_epsilon = 1e-5;

    for (int i = 0; i < testCount; i++) {
        float a = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); 
        float b = a + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 1e-7;

        if (compareAbsolute(a, b, flopat_epsilon)) correctAbs++;
        if (compareRelative(a, b, flopat_epsilon)) correctRel++;
        if (compareCombined(a, b, flopat_epsilon)) correctComb++;
        if (compareULP(a, b, 4)) correctULP++;
    }

    std::cout << "Float tests:\n";
    std::cout << "Absolute comparing: " << correctAbs << " correct compares of " << testCount << std::endl;
    std::cout << "Relative comparing: " << correctRel << " correct compares of " << testCount << std::endl;
    std::cout << "Combined comparing: " << correctComb << " correct compares of " << testCount << std::endl;
    std::cout << "ULP comparing: " << correctULP << " correct compares of " << testCount << std::endl;

    correctAbs = 0, correctRel = 0, correctComb = 0, correctULP = 0;

    for (int i = 0; i < testCount; i++) {
        double a = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        double b = a + static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * 1e-9;

        if (compareAbsolute(a, b, double_epsilon)) correctAbs++;
        if (compareRelative(a, b, double_epsilon)) correctRel++;
        if (compareCombined(a, b, double_epsilon)) correctComb++;
        if (compareULP(*(float*)&a, *(float*)&b, 4)) correctULP++;
    }

    std::cout << std::endl;
    std::cout << "Double tests:\n";
    std::cout << "Absolute comparing: " << correctAbs << " correct compares of " << testCount << std::endl;
    std::cout << "Relative comparing: " << correctRel << " correct compares of " << testCount << std::endl;
    std::cout << "Combined comparing: " << correctComb << " correct compares of " << testCount << std::endl;
    std::cout << "ULP comparing: " << correctULP << " correct compares of " << testCount << std::endl;
}

int main() {

    runTests();

    return 0;
}
