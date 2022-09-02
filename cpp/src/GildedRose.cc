#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> &items)
{
    for (auto &item : items)
    {
        this->items.emplace_back(FactoryItem::createItem(item));
    }
}

void GildedRose::updateQuality()
{
    for (auto &item : items)
    {
        item->updateItem();
    }
}