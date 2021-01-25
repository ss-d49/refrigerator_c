#ifndef MAIN_H_
#define MAIN_H_
#include "fridgeInventory.h"

void addToFridge(fridgeInventory *fridge);
void editFridge(fridgeInventory *fridge);
void displayFridgeContents(struct fridgeInventory *fridge);
int main();

#endif /* MAIN_H_ */