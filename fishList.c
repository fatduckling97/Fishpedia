#include <stdio.h>
#include "fishList.h"


void saveFishData(struct Fish fishList[], int fishCount) {
    FILE *file = fopen("fish_data.txt", "w");

    if (file == NULL) {
        printf("Failed to save fish data.\n");
        return;
    }

    for(int i = 0; i < fishCount; i++) {
        fprintf(
            file, 
            "%s|%s|%s|%s|%.2f|%d|%s|%s\n",
            fishList[i].name, 
            fishList[i].habitat, 
            fishList[i].rarity, 
            fishList[i].time, 
            fishList[i].recordSize, 
            fishList[i].price, 
            fishList[i].dishName,
            fishList[i].specialNote
        );
    }

    fclose(file);
}


int loadFishData(struct Fish fishList[]) {
    FILE *file = fopen("fish_data.txt", "r");

    if (file == NULL) {
        return 0;
    }

    int fishCount = 0;

    while (
        fscanf(
            file,
            " %49[^|]|%49[^|]|%19[^|]|%19[^|]|%f|%d|%99[^|]|%99[^\n]",
            fishList[fishCount].name,
            fishList[fishCount].habitat,
            fishList[fishCount].rarity,
            fishList[fishCount].time,
            &fishList[fishCount].recordSize,
            &fishList[fishCount].price,
            fishList[fishCount].dishName,
            fishList[fishCount].specialNote
        ) == 8
    )
    {
        fishCount++;
    }

    fclose(file);

    return fishCount;
}