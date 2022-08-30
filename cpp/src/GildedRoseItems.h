#pragma once
#include <string>
#include "Item.h"

#define MIN_QUALITY 0
#define MAX_QUALITY 50

class NormalItem
{
public:
    NormalItem(Item &item) : item{item} {}

    virtual void updateItem();

    std::string name() { return item.name; }
    int sellIn() { return item.sellIn; }
    int quality() { return item.quality; }

protected:
    void decrementSellIn(int n) { item.sellIn -= n; }
    void decrementQuality(int n) { item.quality = std::max(item.quality - n, MIN_QUALITY); }
    void incrementQuality(int n) { item.quality = std::min(item.quality + n, MAX_QUALITY); }
    void setQualityToZero() { item.quality = 0; }

private:
    Item &item;
};

class BrieItem : public NormalItem
{
public:
    BrieItem(Item &item) : NormalItem(item) {}
    void updateItem() override;
};

class SulfurasItem : public NormalItem
{
public:
    SulfurasItem(Item &item) : NormalItem(item) {}
    void updateItem() override;
};

class BackstageItem : public NormalItem
{
public:
    BackstageItem(Item &item) : NormalItem(item) {}
    void updateItem() override;
};

class ConjuredItem : public NormalItem
{
public:
    ConjuredItem(Item &item) : NormalItem(item) {}
    void updateItem() override;
};

class FactoryItem
{
public:
    NormalItem *createItem(Item &item);
};