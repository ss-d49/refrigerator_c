#ifndef FOODITEM_H_
#define FOODITEM_H_

struct foodItem
{
    char itemName[32];
    int expiryDate;
};
typedef struct foodItem foodItem;

#endif /* FOODITEM_H_ */