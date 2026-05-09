// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int compareCars(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), compareCars);

    int fleetCount = 0;
    double prevArrivalTime = 0.0;

    for (int i = 0; i < n; i++) {
        double arrivalTime = (double)(target - cars[i].pos) / cars[i].speed;
        
        if (arrivalTime > prevArrivalTime) {
            fleetCount++;
            prevArrivalTime = arrivalTime;
        }
    }
    return fleetCount;
}

int main() {
    int target = 12;
    int pos[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;
    
    printf("Number of fleets: %d\n", carFleet(target, pos, speed, n));
    return 0;
}
