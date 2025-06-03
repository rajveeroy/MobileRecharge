#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Recharge {
    char mobile[15];
    float amount;
};

void rechargeMobile() {
    FILE *fp = fopen("recharge.txt", "ab"); // append in binary
    struct Recharge r;

    printf("Enter Mobile Number: ");
    scanf("%s", r.mobile);

    printf("Enter Amount: ");
    scanf("%f", &r.amount);

    fwrite(&r, sizeof(struct Recharge), 1, fp);
    fclose(fp);

    printf("Recharge Successful!\n");
}

void viewHistory() {
    FILE *fp = fopen("recharge.txt", "rb");
    struct Recharge r;

    printf("\nRecharge History:\n");
    printf("--------------------------\n");

    while (fread(&r, sizeof(struct Recharge), 1, fp)) {
        printf("Mobile: %s | Amount: %.2f\n", r.mobile, r.amount);
    }

    fclose(fp);
}

void deleteAllRecords() {
    FILE *fp = fopen("recharge.txt", "wb"); // overwrite file
    if (fp != NULL) {
        fclose(fp);
        printf("All records deleted successfully.\n");
    } else {
        printf("Error deleting records.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n=== Mobile Recharge Management System ===\n");
        printf("1. Recharge Mobile\n");
        printf("2. View Recharge History\n");
        printf("3. Delete All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rechargeMobile();
                break;
            case 2:
                viewHistory();
                break;
            case 3:
                deleteAllRecords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}