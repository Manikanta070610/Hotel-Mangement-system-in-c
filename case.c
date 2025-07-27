#include <stdio.h>

void initializerooms(int size);
void displayavailablerooms(int size);
void bookreservation(int size, int roomnumber, char customername[]);
void cancelbooking(int size, int roomnumber);
void displaybookedrooms(int size);
void generatebookingconfirmation(int roomnumber, char customername[]);

int maxrooms = 5;
char customernames[5][50];
int roomnumbers[5];
int roomavailability[5];

int main() {
    int choice, roomnumber;
    char customername[50];
    initializerooms(maxrooms);
    do {
        printf("\n*** Hotel Eastside ***\n");
        printf("1. Display available rooms\n");
        printf("2. Display Booked rooms\n");
        printf("3. Book Room\n");
        printf("4. Cancel Booking\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        switch (choice) {
            case 1: displayavailablerooms(maxrooms); break;
            case 2: displaybookedrooms(maxrooms); break;
            case 3: printf("Enter room number to book: ");
                    scanf("%d", &roomnumber);
                    while (getchar() != '\n');
                    printf("Enter customer name: ");
                    scanf("%49s", customername);
                    bookreservation(maxrooms, roomnumber, customername);
                    generatebookingconfirmation(roomnumber, customername);
                    break;
            case 4: printf("Enter room number to cancel: ");
                    scanf("%d", &roomnumber);
                    cancelbooking(maxrooms, roomnumber);
                    break;
            case 5: printf("Thank you for using the hotel reservation system!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void initializerooms(int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        roomnumbers[i] = i + 1;
        roomavailability[i] = 1;
        for (j = 0; j < 50; j++) {
            customernames[i][j] = ' ';
        }
    }
}

void displayavailablerooms(int size) {
    int i;
    printf("Available rooms:\n");
    for (i = 0; i < size; i++) {
        if (roomavailability[i]) {
            printf("Room %d\n", roomnumbers[i]);
        }
    }
}

void bookreservation(int size, int roomnumber, char customername[]) {
    int i;
    if (roomnumber > 0 && roomnumber <= size && roomavailability[roomnumber - 1]) {
        roomavailability[roomnumber - 1] = 0;
        i = 0;
        while (customername[i] != '\0' && i < 49) {
            customernames[roomnumber - 1][i] = customername[i];
            i++;
        }
        while (i < 50) {
            customernames[roomnumber - 1][i] = ' ';
            i++;
        }
        printf("Room %d has been successfully booked for %s.\n", roomnumber, customername);
    } else {
        printf("Room %d is not available.\n", roomnumber);
    }
}

void cancelbooking(int size, int roomnumber) {
    int i;
    if (roomnumber > 0 && roomnumber <= size && !roomavailability[roomnumber - 1]) {
        roomavailability[roomnumber - 1] = 1; 
        for (i = 0; i < 50; i++) {
            customernames[roomnumber - 1][i] = ' '; 
        }
        printf("Room %d booking has been successfully canceled.\n", roomnumber);
    } else {
        printf("Room %d is not currently booked.\n", roomnumber);
    }
}

void displaybookedrooms(int size) {
    int i, bookedfound = 0;
    printf("Booked rooms:\n");
    for (i = 0; i < size; i++) {
        if (!roomavailability[i]) {
            printf("Room %d is booked by %s\n", roomnumbers[i], customernames[i]);
            bookedfound = 1;
        }
    }
    if (!bookedfound) {
        printf("No rooms are currently booked.\n");
    }
}

void generatebookingconfirmation(int roomnumber, char customername[]) {
    printf("Booking confirmation: Room %d has been booked for %s.\n", roomnumber, customername);
}