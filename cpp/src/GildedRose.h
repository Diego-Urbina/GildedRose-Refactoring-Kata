#include <memory>
#include <vector>
#include "Item.h"
#include "GildedRoseItems.h"

class GildedRose
{
public:
    GildedRose(std::vector<Item> &items);

    void updateQuality();

    std::vector<std::unique_ptr<NormalItem>> items;
};