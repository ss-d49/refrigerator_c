#ifndef FRIDGEINVENTORY_H_
#define FRIDGEINVENTORY_H_

#define FILEPATH "save.dat"

struct fridgeInventory
{
    int size;
    struct foodItem* foodItem_array;
};

typedef struct fridgeInventory fridgeInventory;

fridgeInventory createNewFridge();
fridgeInventory openFridge();
void growArray(fridgeInventory *fridge);

#endif /* FRIDGEINVENTORY_H_ */