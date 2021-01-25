#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "foodItem.h"
#include "ObjectIO.h"

void WriteObjectToFile(fridgeInventory *fridge, char filepath[]) {
    FILE *outfile;
    outfile = fopen(filepath,"w");
    for (int i=0;i<fridge->size;i++) {
        fprintf(outfile,"%s;%d\n",fridge->foodItem_array[i].itemName, fridge->foodItem_array[i].expiryDate);
    }
    fclose(outfile);
}

fridgeInventory ReadObjectFromFile(char filepath[]) {
    fridgeInventory fridge = {0};

    FILE *infile;
    infile = fopen(filepath, "r");
    char buffer[40];
    while (fgets(buffer, 40, infile)) {
        char *token = strtok(buffer, ";");
        if (token) {
            growArray(&fridge);
            strcpy(fridge.foodItem_array[fridge.size - 1].itemName, token);
            token = strtok(NULL, ";");
            fridge.foodItem_array[fridge.size - 1].expiryDate = atoi(token);
        }
    }
    fclose(infile);
    return fridge;
}
