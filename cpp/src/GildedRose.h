#include <memory>
#include <vector>
#include "Item.h"
#include "GildedRoseItems.h"

class GildedRose
{
public:
    GildedRose(std::vector<Item> &items);

    void updateQuality();

    const Item &getItem(int n) const;

private:
    std::vector<Item> &items;
};