#include "GildedRose.h"
#include <stdexcept>

GildedRose::GildedRose(std::vector<Item> &items) : items(items)
{
}

void GildedRose::updateQuality()
{
    for (auto &item : items)
    {
        FactoryItem::createItem(item)->updateItem();
    }
}

const Item &GildedRose::getItem(int n) const
{
    if (n < 0 || n >= items.size())
        throw std::out_of_range("GildedRose::getItem");

    return items[n];
}