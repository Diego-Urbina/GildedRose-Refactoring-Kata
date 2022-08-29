#include "GildedRose.h"

void updateItem(Item &item);

GildedRose::GildedRose(vector<Item> &items) : items(items) {}

void GildedRose::updateQuality()
{
    for (auto &item : items)
    {
        updateItem(item);
    }
}

void updateNormalItem(Item &item)
{
    if (item.sellIn > 0)
        item.quality--;
    else
        item.quality -= 2;

    item.quality = std::max(item.quality, 0);

    item.sellIn--;
}

void updateBrieItem(Item &item)
{
    if (item.sellIn > 0)
        item.quality++;
    else
        item.quality += 2;

    item.quality = std::min(item.quality, 50);

    item.sellIn--;
}

void updatSulfurasItem(Item &item)
{
}

void updateBackstageItem(Item &item)
{
    if (item.sellIn <= 0)
    {
        item.quality = 0;
    }
    else
    {
        int offset = 1;
        if (item.sellIn <= 5)
            offset = 3;
        else if (item.sellIn <= 10)
            offset = 2;

        item.quality += offset;
        item.quality = std::min(item.quality, 50);
    }

    item.sellIn--;
}

bool isAgedBrie(const Item &item)
{
    return item.name == "Aged Brie";
}

bool isSulfuras(const Item &item)
{
    return item.name == "Sulfuras, Hand of Ragnaros";
}

bool isBackstage(const Item &item)
{
    return item.name == "Backstage passes to a TAFKAL80ETC concert";
}

void updateItem(Item &item)
{
    if (isAgedBrie(item))
        updateBrieItem(item);
    else if (isSulfuras(item))
        updatSulfurasItem(item);
    else if (isBackstage(item))
        updateBackstageItem(item);
    else
        updateNormalItem(item);
}