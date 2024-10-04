#include <iostream>
#include <cmath>
#include <limits>

bool compareAbsolute(float a, float b, float epsilon) {
    return std::fabs(a - b) < epsilon;
}

bool compareRelative(float a, float b, float epsilon) {
    return std::fabs(a - b) < epsilon * std::max(std::fabs(a), std::fabs(b));
}

bool compareULP(float a, float b, int maxUlps) {
    int intDiff = *(int*)&a - *(int*)&b;
    return std::abs(intDiff) <= maxUlps;
}

template <typename T>
void runTests(T epsilon) {
    int correctCount = 0, incorrectCount = 0;
    T values[] = {1.0f, 1.0000001f, 1.000001f, 1.00001f, 0.9999999f, 0.99999f, -1.0f, -1.00001f, 0.0f, -0.0f};
    const int numTests = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numTests; i++) {
        for (int j = 0; j < numTests; j++) {
            bool result = compareAbsolute(values[i], values[j], epsilon);
            if (i == j && result || i != j && !result){
                correctCount++;
            }
            else incorrectCount++;
        }
    }
    std::cout << "Absolute difference (epsilon = " << epsilon << "): Correct = " << correctCount
              << ", Incorrect = " << incorrectCount << std::endl;

    correctCount = incorrectCount = 0;
    for (int i = 0; i < numTests; i++) {
        for (int j = 0; j < numTests; j++) {
            bool result = compareRelative(values[i], values[j], epsilon);
            if (i == j && result) correctCount++;
            else if (i != j && !result) correctCount++;
            else incorrectCount++;
        }
    }
    std::cout << "Relative difference (epsilon = " << epsilon << "): Correct = " << correctCount
              << ", Incorrect = " << incorrectCount << std::endl;

    int maxUlps = 4;
    correctCount = incorrectCount = 0;
    for (int i = 0; i < numTests; i++) {
        for (int j = 0; j < numTests; j++) {
            bool result = compareULP(values[i], values[j], maxUlps);
            if (i == j && result) correctCount++;
            else if (i != j && !result) correctCount++;
            else incorrectCount++;
        }
    }
    std::cout << "ULP comparing (maxUlps = " << maxUlps << "): Correct = " << correctCount
              << ", Incorrect = " << incorrectCount << std::endl;
}

int main() {
    std::cout << "Float tests:\n";
    runTests<float>(1e-6f);
    runTests<float>(1e-5f);

    std::cout << "\n Double tests:\n";
    runTests<double>(1e-10);
    runTests<double>(1e-9);

    return 0;
}
