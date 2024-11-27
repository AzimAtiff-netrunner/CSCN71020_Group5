#include "main.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "rectangleSolver.h"



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

