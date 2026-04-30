#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Student structure
typedef struct {
    int id;
    int priority;
} Student;

// Room structure
typedef struct {
    int capacity;
    int occupants[MAX];
    int count;
} Room;

Student students[MAX];
Room rooms[MAX];

int studentCount = 0;
int roomCount = 0;

// 🔹 Add Student
void addStudent() {
    printf("Enter Student ID: ");
    scanf("%d", &students[studentCount].id);

    printf("Enter Priority (Higher = More Priority): ");
    scanf("%d", &students[studentCount].priority);

    studentCount++;
}

// 🔹 Add Room
void addRoom() {
    printf("Enter Room Capacity: ");
    scanf("%d", &rooms[roomCount].capacity);

    rooms[roomCount].count = 0;
    roomCount++;
}

// 🔹 Sort Students by Priority (Greedy Prep)
void sortStudents() {
    for(int i = 0; i < studentCount - 1; i++) {
        for(int j = i + 1; j < studentCount; j++) {
            if(students[i].priority < students[j].priority) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// 🔹 Greedy Allocation
void allocateRooms() {
    sortStudents();

    for(int i = 0; i < studentCount; i++) {
        int placed = 0;

        for(int j = 0; j < roomCount; j++) {
            if(rooms[j].count < rooms[j].capacity) {
                rooms[j].occupants[rooms[j].count++] = students[i].id;
                placed = 1;
                break;
            }
        }

        if(!placed) {
            printf("No space for student %d\n", students[i].id);
        }
    }

    printf("\nRooms Allocated Successfully!\n");
}

// 🔹 Display Rooms
void displayRooms() {
    printf("\nRoom Allocation:\n");

    for(int i = 0; i < roomCount; i++) {
        printf("Room %d (Cap %d): ", i+1, rooms[i].capacity);
        for(int j = 0; j < rooms[i].count; j++) {
            printf("%d ", rooms[i].occupants[j]);
        }
        printf("\n");
    }
}

// 🔹 Search Student
void searchStudent() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < roomCount; i++) {
        for(int j = 0; j < rooms[i].count; j++) {
            if(rooms[i].occupants[j] == id) {
                printf("Student %d is in Room %d\n", id, i+1);
                return;
            }
        }
    }

    printf("Student not found!\n");
}

// 🔹 Analytics
void analytics() {
    int totalCapacity = 0, used = 0;

    for(int i = 0; i < roomCount; i++) {
        totalCapacity += rooms[i].capacity;
        used += rooms[i].count;
    }

    printf("\n--- Analytics ---\n");
    printf("Total Rooms: %d\n", roomCount);
    printf("Used Slots: %d/%d\n", used, totalCapacity);
    printf("Efficiency: %.2f%%\n", (used * 100.0) / totalCapacity);
}

// 🔹 Main Menu
int main() {
    int choice;

    while(1) {
        printf("\n===== Hostel Room Allocation =====\n");
        printf("1. Add Student\n");
        printf("2. Add Room\n");
        printf("3. Allocate Rooms (Greedy)\n");
        printf("4. Display Rooms\n");
        printf("5. Search Student\n");
        printf("6. Analytics\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: addRoom(); break;
            case 3: allocateRooms(); break;
            case 4: displayRooms(); break;
            case 5: searchStudent(); break;
            case 6: analytics(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}