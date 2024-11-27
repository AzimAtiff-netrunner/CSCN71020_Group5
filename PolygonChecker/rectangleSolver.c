#include "main.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "rectangleSolver.h"


// Function to calculate the distance between two points
float calculateDistance(float point1[2], float point2[2]) {
    return sqrt(pow(point2[0] - point1[0], 2) + pow(point2[1] - point1[1], 2));
}

// Function to check if two vectors are perpendicular
bool isPerpendicular(float point1[2], float point2[2], float point3[2]) {

    float dx1 = point2[0] - point1[0];  //first (x,y) pair

    float dy1 = point2[1] - point1[1];  //second (x,y) pair

    float dx2 = point3[0] - point2[0];  //third (x,y) pair

    float dy2 = point3[1] - point2[1];  //fourth (x,y) pair

    // Dot product of the vectors (0 for perpendicular vectors)
    return fabs(dx1 * dx2 + dy1 * dy2) < 1e-6;
}

// Function to get the points for the rectangle
float(*getRectanglePoints(float rectanglePoints[4][2]))[2] {
    for (int i = 0; i < 4; i++) {
        printf_s("Enter x and y for Point %d: ", i + 1); //ask user for x and y points
        if (scanf_s("%f %f", &rectanglePoints[i][0], &rectanglePoints[i][1]) != 2) {
            printf_s("Invalid input. Please enter numeric values.\n");  //for invalid inputs
            rectanglePoints[0][0] = -1; // Signal invalid input
            break;
        }
    }
    return rectanglePoints;
}


// Function to check if the four points form a rectangle
char* analyzeRectangle(float rectanglePoints[4][2]) {
    if (rectanglePoints[0][0] == -1) {
        return "Invalid input for points.";
    }