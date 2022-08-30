#include <vector>
#include "Item.h"
#include "GildedRoseItems.h"

class GildedRose
{
public:
    GildedRose(std::vector<Item> &items);

    ~GildedRose();

    void updateQuality();

    std::vector<NormalItem *> items;
};