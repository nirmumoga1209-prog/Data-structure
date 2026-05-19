#include <stdio.h>

int main() {
    int arr[100], n, i, value, choice, found;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
 
    do {
        printf("\n--- Menu ---\n");
        printf("1. Traverse\n2. Insert\n3. Delete\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Traverse
                printf("Array elements are: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2: // Insert
                if (n < 10) { // Check if array is full
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    arr[n] = value;
                    n++;
                    printf("Value inserted successfully.\n");
                } else {
                    printf("Array is full!\n");
                }
                break;

            case 3: // Delete   
                printf("Enter value to delete: ");
                scanf("%d", &value);
                found = -1; 
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        found = i;
                        break;
                    }
                }
                if (found != -1) {
                    for (i = found; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Value deleted successfully.\n");
                } else {
                    printf("Value not found in array.\n");
                }
                break;

            case 4: // Search
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = -1;
                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        found = i; // Store the actual index
                        break;
                    }
                }
                if (found != -1) {
                    printf("Value found at index %d.\n", found);
                } else {
                    printf("Value not found in array.\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // This was the missing part

    return 0;
}