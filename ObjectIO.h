#ifndef OBJECTIO_H_
#define OBJECTIO_H_
#include "fridgeInventory.h"

void WriteObjectToFile(fridgeInventory *fridge, char filepath[]);
fridgeInventory ReadObjectFromFile(char filepath[]);

#endif /* OBJECTIO_H_ */