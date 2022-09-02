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

std::unique_ptr<NormalItem> FactoryItem::createItem(Item &item)
{
    if (item.name == AGED_BRIE)
        return std::make_unique<BrieItem>(item);

    if (item.name == SULFURAS)
        return std::make_unique<SulfurasItem>(SulfurasItem(item));

    if (item.name == BACKSTAGE)
        return std::make_unique<BackstageItem>(BackstageItem(item));

    if (item.name == CONJURED)
        return std::make_unique<ConjuredItem>(ConjuredItem(item));

    return std::make_unique<NormalItem>(NormalItem(item));
}