#ifndef FISH_LIST
#define FISH_LIST


struct Fish {
    char name[50];
    char habitat[50];
    char rarity[20];
    char time[20];
    double recordSize;
    int price;
    char dishName[100];
    char specialNote[100];
};

void saveFishData(struct Fish fishList[], int fishCount);
int loadFishData(struct Fish fishList[]);

#endif