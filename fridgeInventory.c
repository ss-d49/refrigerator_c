#include <stdio.h>
#include <stdlib.h>
#include "ObjectIO.h"
#include "foodItem.h"

fridgeInventory createNewFridge() {
    fridgeInventory fridge = {0};
    return fridge;
}

fridgeInventory openFridge() {
    fridgeInventory fridge = ReadObjectFromFile(FILEPATH);
    return fridge;
}

void growArray(fridgeInventory *fridge)
{

    foodItem *temp = (foodItem*) realloc(fridge->foodItem_array, ((fridge->size + 1) * sizeof(foodItem)));
    if (temp == NULL)
    {
        printf("Cannot allocate more memory.\n");
    }
    else
    {
        fridge->foodItem_array = temp;
        fridge->size++;
    }
}
