#include "GildedRose.h"
#include <stdexcept>

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

const std::unique_ptr<NormalItem> &GildedRose::getItem(int n) const
{
    if (n < 0 || n >= items.size())
        throw std::out_of_range("GildedRose::getItem");

    return items[n];
}