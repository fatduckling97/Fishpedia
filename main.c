#include <stdio.h>
#include <string.h>
#include "fishList.h"

#define MAX_FISH 10000


int main() {

    static struct Fish fishList[MAX_FISH];
    int fishCount = loadFishData(fishList);
    int choose;
    int input;

    while (1) {
        printf("=== FISHPEDIA ===\n");
        printf("1. Add fish\n");
        printf("2. Show all fish\n");
        printf("3. Search fish\n");
        printf("4. Delete fish\n");
        printf("5. Exit Fishpedia\n\n");

        printf("Choose: ");
        input = scanf("%d", &choose);
        printf("\n");

        if (input != 1) {
            printf("Invalid input! Please choose 1-5 only!\n\n");

            while (getchar() != '\n');
            continue;
        }

        if (choose < 1 || choose > 5) {
            printf("Invalid input! Please choose 1-5 only!\n\n");
            continue;
        }

        if (choose == 1) {
            if (fishCount >= MAX_FISH) {
                printf("Fishpedia is full!\n\n");
                continue;
            }

            printf("Enter fish name    : ");
            scanf(" %49[^\n]", fishList[fishCount].name);
            
            printf("Enter habitat      : ");
            scanf(" %49[^\n]", fishList[fishCount].habitat);

            printf("Enter rarity       : ");
            scanf(" %19[^\n]", fishList[fishCount].rarity);

            printf("Enter time         : ");
            scanf(" %19[^\n]", fishList[fishCount].time);

            printf("Enter record size  : ");
            scanf(" %lf", &fishList[fishCount].recordSize);

            printf("Enter fish price   : ");
            scanf(" %d", &fishList[fishCount].price);

            printf("Enter dish name    : ");
            scanf(" %99[^\n]", fishList[fishCount].dishName);

            printf("Enter special note : ");
            scanf(" %99[^\n]", fishList[fishCount].specialNote);

            fishCount++;

            printf("Fish added successfully!\n\n");
        }
        else if (choose == 2) {
            printf("=== FISH LIST ===\n");

            if (fishCount == 0) {
                printf("No fish data yet.\n\n");
            }
            else {
                for(int i = 0; i < fishCount; i++) {
                    printf("Name    : %s\n", fishList[i].name);
                    printf("Habitat : %s\n", fishList[i].habitat);
                    printf("Rarity  : %s\n", fishList[i].rarity);
                    printf("Time    : %s\n", fishList[i].time);
                    printf("Record  : %.4f kg\n", fishList[i].recordSize);
                    printf("Price   : $%d\n", fishList[i].price);
                    printf("Dishes  : %s\n", fishList[i].dishName);
                    printf("Notes   : %s\n", fishList[i].specialNote);
                    printf("+++++++++++++++++++++++++++++++++++++++++++++\n\n");
                }
            }
        }
        else if (choose == 3) {
            char searchName[50];
            int found = 0;

            printf("Search fish name : ");
            scanf(" %49[^\n]", searchName);

            for (int i = 0; i < fishCount; i++) {
                if (strcmp(fishList[i].name, searchName) == 0) {
                    printf("Name    : %s\n", fishList[i].name);
                    printf("Habitat : %s\n", fishList[i].habitat);
                    printf("Rarity  : %s\n", fishList[i].rarity);
                    printf("Time    : %s\n", fishList[i].time);
                    printf("Record  : %.4f kg\n", fishList[i].recordSize);
                    printf("Price   : $%d\n", fishList[i].price);
                    printf("Dishes  : %s\n", fishList[i].dishName);
                    printf("Notes   : %s\n\n", fishList[i].specialNote);

                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("Fish not found.\n\n");
            }
        }
        else if (choose == 4) {
            char deleteName[50];
            int found = 0;
            int deleteIndex = -1;

            printf("Enter fish name to delete : ");
            scanf(" %49[^\n]", deleteName);

            for(int i = 0; i < fishCount; i++) {
                if (strcmp(fishList[i].name, deleteName) == 0) {
                    found = 1;
                    deleteIndex = i;
                    break;
                }
            }

            if (found == 0) {
                printf("Fish not found.\n\n");
            }
            else {
                for (int i = deleteIndex; i < fishCount - 1; i++) {
                    fishList[i] = fishList[i+1];
                }
                fishCount--;

                printf("Fish deleted successfully.\n\n");
            }
        }
        else if (choose == 5) {
            saveFishData(fishList, fishCount);
            printf("Fish data saved successfully.\n");
            printf("Closing Fishpedia...\n");
            break;
        }
    }

    return 0;
}