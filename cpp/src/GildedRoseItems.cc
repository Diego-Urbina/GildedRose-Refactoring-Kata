#include "GildedRoseItems.h"

void NormalItem::updateItem()
{
    decrementQuality(sellIn() > 0 ? 1 : 2);
    decrementSellIn(1);
}

void BrieItem::updateItem()
{
    incrementQuality(sellIn() > 0 ? 1 : 2);
    decrementSellIn(1);
}

void SulfurasItem::updateItem()
{
}

void BackstageItem::updateItem()
{
    if (sellIn() <= 0)
    {
        setQualityToZero();
    }
    else
    {
        incrementQuality(sellIn() <= 5 ? 3 : (sellIn() <= 10 ? 2 : 1));
    }

    decrementSellIn(1);
}

void ConjuredItem::updateItem()
{
    decrementQuality(sellIn() > 0 ? 2 : 4);
    decrementSellIn(1);
}

#define AGED_BRIE "Aged Brie"
#define SULFURAS "Sulfuras, Hand of Ragnaros"
#define BACKSTAGE "Backstage passes to a TAFKAL80ETC concert"
#define CONJURED "Conjured Mana Cake"

NormalItem *FactoryItem::createItem(Item &item)
{
    if (item.name == AGED_BRIE)
        return new BrieItem(item);

    if (item.name == SULFURAS)
        return new SulfurasItem(item);

    if (item.name == BACKSTAGE)
        return new BackstageItem(item);

    if (item.name == CONJURED)
        return new ConjuredItem(item);

    return new NormalItem(item);
}