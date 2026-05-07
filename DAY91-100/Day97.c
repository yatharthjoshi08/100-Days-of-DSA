// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compareMeetings(const void* a, const void* b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

int minMeetingRooms(Meeting meetings[], int n) {
    if (n == 0) return 0;

    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    int *rooms = (int*)malloc(n * sizeof(int));
    int roomCount = 0;

    for (int i = 0; i < n; i++) {
        int foundRoom = 0;
        for (int j = 0; j < roomCount; j++) {
            if (rooms[j] <= meetings[i].start) {
                rooms[j] = meetings[i].end;
                foundRoom = 1;
                break;
            }
        }
        if (!foundRoom) {
            rooms[roomCount++] = meetings[i].end;
        }
    }

    int result = roomCount;
    free(rooms);
    return result;
}

int main() {
    Meeting meetings[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(meetings) / sizeof(meetings[0]);
    printf("Minimum rooms required: %d\n", minMeetingRooms(meetings, n));
    return 0;
}
