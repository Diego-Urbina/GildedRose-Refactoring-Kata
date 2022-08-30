#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> &items)
{
    FactoryItem factory;
    for (auto &item : items)
    {
        this->items.push_back(factory.createItem(item));
    }
}

GildedRose::~GildedRose()
{
    for (auto item : items)
    {
        delete item;
    }
}

void GildedRose::updateQuality()
{
    for (auto &item : items)
    {
        item->updateItem();
    }
}