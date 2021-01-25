#include <stdio.h>
#include <string.h>
#include "foodItem.h"
#include "fridgeInventory.h"
#include "ObjectIO.h"
#include "main.h"

void addToFridge(fridgeInventory *fridge) {
    while (1) {

        char foodItemName[32];
        printf("%s\n", "Enter Food Item Name: ");
        scanf("%s", &foodItemName);

        int date;
        printf("%s\n", "Enter Expiry Date: ");
        scanf("%d",&date);

        growArray(fridge);
        strcpy(fridge->foodItem_array[fridge->size-1].itemName, foodItemName);
        fridge->foodItem_array[fridge->size-1].expiryDate = date;


        printf("%s\n", "Add More Items?: Y / N");
        char input;
        scanf(" %c",&input);
        if (input == 'y') {
        }
        else if (input == 'n') {
            WriteObjectToFile(fridge, FILEPATH);
            break;
        }
    }
}

void editFridge(fridgeInventory *fridge) {
    for (int i=0;i<fridge->size;i++) {
        printf("%s %d\n",fridge->foodItem_array[i].itemName, fridge->foodItem_array[i].expiryDate);
        printf("%s %d\n", "Is this the Item?: Y / N");
        char input;
        scanf(" %c",&input);
        if (input == 'y') {
            printf("%s\n", "Edit Name or Expiry Date?: N / E");
            scanf(" %c",&input);
            if (input == 'n') {
                char foodItemName[32];
                printf("%s\n", "Enter Food Item Name: ");
                scanf("%s", &foodItemName);
                strcpy(fridge->foodItem_array[i].itemName, foodItemName);
            } else if (input == 'e') {
                int date = 0;
                printf("%s\n", "Enter Expiry Date: ");
                scanf("%d",date);
                fridge->foodItem_array[i].expiryDate = date;
            }
        }
        else if (input == 'n') {
            printf("%s %d\n",fridge->foodItem_array[i].itemName, fridge->foodItem_array[i].expiryDate);
        }
    }
}
void displayFridgeContents(struct fridgeInventory *fridge) {
    for (int i=0;i<fridge->size;i++) {
        printf("%s %d\n",fridge->foodItem_array[i].itemName, fridge->foodItem_array[i].expiryDate);
    }
}

int main() {
    fridgeInventory fridge;
    printf("%s\n","Create New Fridge or Open Existing?: N / O");
    char input;
	scanf("%c",&input);

    if (input == 'n') {
        fridge = createNewFridge();
        addToFridge(&fridge);
    }
    else if (input == 'o'){
        fridge = openFridge();
    }

    printf("%s\n","Edit Fridge Contents?: Y / N");
    scanf(" %c",&input);
    if (input == 'y') {
       printf("%s\n","Add Items to Fridge?: Y / N");
        scanf(" %c",&input);
        if (input == 'y') {
            addToFridge(&fridge);
        }

        else if (input == 'n') {
            printf("%s\n", "Edit Items in Fridge?: Y / N");
            scanf( "%c",&input);
            if (input == 'y') {
                editFridge(&fridge);
            }
        }
    }
    printf("%s\n","Display Fridge Contents?: Y / N");
    scanf(" %c",&input);
    if (input == 'y') {
        displayFridgeContents(&fridge);
    }
}