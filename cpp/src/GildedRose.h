#include <memory>
#include <vector>
#include "Item.h"
#include "GildedRoseItems.h"

class GildedRose
{
public:
    GildedRose(std::vector<Item> &items);

    void updateQuality();

    const std::unique_ptr<NormalItem> &getItem(int n) const;

private:
    std::vector<std::unique_ptr<NormalItem>> items;
};