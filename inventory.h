#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include <map>
#include <iterator>

#include "inventoryindex.h"

//#include "resource.h"

struct Inventory
{
    std::map<int,int>cargo;

    Inventory();
    ~Inventory();

    void SetStock(int a, int b);
    void AddStock(int a, int b);
    void RemoveStock(int a, int b);

    //void DrawVertical(int rows, float x, float y);
    //void DrawHorizontal(int cols, float x, float y);

    //void RefreshCargoInTab();
    //int GetItemTypeAtInput(unsigned input);


};

#endif // INVENTORY_H_INCLUDED
