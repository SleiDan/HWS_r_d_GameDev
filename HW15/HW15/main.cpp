#include <iostream>
#include <algorithm>

const int numOfMarks = 4;  // Constant for marks size

struct Student {
    std::string name;
    int marks[numOfMarks];
};

// Function to calculate the average grade of a student
float calculateAverage(const Student& student) {
    int sum = 0;
    for (int i = 0; i < numOfMarks; ++i) {
        sum += student.marks[i];
    }
    return static_cast<float>(sum) / numOfMarks;
}

// Function to sort an array of students by their average grade
void sortStudentsByAverage(Student students[], int size) {
    std::sort(students, students + size, [](const Student& a, const Student& b) {
        return calculateAverage(a) > calculateAverage(b);
    });
}

// Function to return a pointer to the top-performing student in the array
const Student* getTopStudent(const Student students[], int size) {
    if (size > 0) {
        const Student* topStudent = &students[0];
        float maxAverage = calculateAverage(students[0]);

        for (int i = 1; i < size; ++i) {
            float currentAverage = calculateAverage(students[i]);
            if (currentAverage > maxAverage) {
                topStudent = &students[i];
                maxAverage = currentAverage;
            }
        }

        return topStudent;
    }

    return nullptr;
}
}

// Function to count the number of students with an average grade above a specified threshold
int countStudentsAboveThreshold(const Student students[], int size, float threshold) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (calculateAverage(students[i]) > threshold) {
            ++count;
        }
    }
    return count;
}

int main() {
    const int numberOfStudents = 3;
    Student students[numberOfStudents] = {
        {"Student1", {64, 85, 41, 53}},
        {"Student2", {75, 78, 80, 88}},
        {"Student3", {90, 92, 88, 85}}
    };

    // Display the initial array of students
    std::cout << "Initial array of students:\n";
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << students[i].name << ": " << calculateAverage(students[i]) << "\n";
    }

    // Sort students by average marks
    sortStudentsByAverage(students, numberOfStudents);

    // Display the sorted array of students
    std::cout << "\nArray of students sorted by average marks:\n";
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << students[i].name << ": " << calculateAverage(students[i]) << "\n";
    }

    // Display the top-performing student
    const Student* topStudent = getTopStudent(students, numberOfStudents);
    if (topStudent != nullptr) {
        std::cout << "\nTop student: " << topStudent->name << " with an average of " << calculateAverage(*topStudent) << "\n";
    }

    // Count the number of students with an average above 75%
    int countAbove75 = countStudentsAboveThreshold(students, numberOfStudents, 75.0f);
    std::cout << "\nNumber of students with an average above 75%: " << countAbove75 << "\n";

    return 0;
}
