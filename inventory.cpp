#include "inventory.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

void Inventory::SetStock(int a, float b)
{
    cargo[a] = b;

    if(cargo[a] <= 0)
        cargo.erase(a);
}

void Inventory::AddStock(int a, float b)
{
    if(cargo.count(a) == 0) // Probably unnecessary, but whatever
        cargo[a] = 0;

    cargo[a] += b;
}

void Inventory::RemoveStock(int a, float b)
{
// It doesn't check if b is more than cargo[a], so do your checking before calling RemoveStock

        cargo[a] -= b;
        if(cargo[a] <= 0)
            cargo.erase(a);
}
