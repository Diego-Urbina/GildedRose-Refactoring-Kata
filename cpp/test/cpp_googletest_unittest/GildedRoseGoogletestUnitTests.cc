#include <gtest/gtest.h>
#include "GildedRose.h"
#include "GildedRoseItems.h"

using namespace std;

TEST(FooItemTest, DecreasedQuality)
{
    vector<Item> items;
    items.push_back({"Foo", 10, 20});
    GildedRose app(items);

    EXPECT_EQ(10, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(9, app.getItem(0).sellIn);
    EXPECT_EQ(19, app.getItem(0).quality);
}

TEST(FooItemTest, QualityNeverNegative)
{
    vector<Item> items;
    items.push_back({"Foo", 10, 1});
    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(0, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(0, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(0, app.getItem(0).quality);
}

TEST(FooItemTest, TwiceDegradation)
{
    vector<Item> items;
    items.push_back({"Foo", 1, 10});
    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(9, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(7, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(5, app.getItem(0).quality);
}

TEST(AgedBrieTest, IncreasedQuality)
{
    vector<Item> items;
    items.push_back({"Aged Brie", 10, 20});
    GildedRose app(items);

    EXPECT_EQ(10, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(9, app.getItem(0).sellIn);
    EXPECT_EQ(21, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(8, app.getItem(0).sellIn);
    EXPECT_EQ(22, app.getItem(0).quality);
}

TEST(AgedBrieTest, MaxQuality50)
{
    vector<Item> items;
    items.push_back({"Aged Brie", 10, 49});
    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(50, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(50, app.getItem(0).quality);
}

TEST(AgedBrieTest, TwiceImprovement)
{
    vector<Item> items;
    items.push_back({"Aged Brie", 1, 10});
    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(11, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(13, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(15, app.getItem(0).quality);
}

TEST(SulfurasTest, Immutability)
{
    vector<Item> items;
    items.push_back({"Sulfuras, Hand of Ragnaros", 10, 20});
    GildedRose app(items);

    EXPECT_EQ(10, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(10, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(10, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);
}

TEST(BackstageTest, IncreasedQuality)
{
    vector<Item> items;
    items.push_back({"Backstage passes to a TAFKAL80ETC concert", 13, 20});
    GildedRose app(items);

    EXPECT_EQ(13, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(12, app.getItem(0).sellIn);
    EXPECT_EQ(21, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(11, app.getItem(0).sellIn);
    EXPECT_EQ(22, app.getItem(0).quality);
}

TEST(BackstageTest, IncreasedQualityByTwo)
{
    vector<Item> items;
    items.push_back({"Backstage passes to a TAFKAL80ETC concert", 11, 20});
    GildedRose app(items);

    EXPECT_EQ(11, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(10, app.getItem(0).sellIn);
    EXPECT_EQ(21, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(9, app.getItem(0).sellIn);
    EXPECT_EQ(23, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(8, app.getItem(0).sellIn);
    EXPECT_EQ(25, app.getItem(0).quality);
}

TEST(BackstageTest, IncreasedQualityByThree)
{
    vector<Item> items;
    items.push_back({"Backstage passes to a TAFKAL80ETC concert", 6, 20});
    GildedRose app(items);

    EXPECT_EQ(6, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(5, app.getItem(0).sellIn);
    EXPECT_EQ(22, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(4, app.getItem(0).sellIn);
    EXPECT_EQ(25, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(3, app.getItem(0).sellIn);
    EXPECT_EQ(28, app.getItem(0).quality);
}

TEST(BackstageTest, MaxQuality50)
{
    vector<Item> items;
    items.push_back({"Backstage passes to a TAFKAL80ETC concert", 10, 49});
    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(50, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(50, app.getItem(0).quality);
}

TEST(BackstageTest, Expiration)
{
    vector<Item> items;
    items.push_back({"Backstage passes to a TAFKAL80ETC concert", 1, 10});
    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(0, app.getItem(0).sellIn);
    EXPECT_EQ(13, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(-1, app.getItem(0).sellIn);
    EXPECT_EQ(0, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(-2, app.getItem(0).sellIn);
    EXPECT_EQ(0, app.getItem(0).quality);
}

TEST(ConjuredTest, DecreasedQuality)
{
    vector<Item> items;
    items.push_back({"Conjured Mana Cake", 10, 20});
    GildedRose app(items);

    EXPECT_EQ(10, app.getItem(0).sellIn);
    EXPECT_EQ(20, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(9, app.getItem(0).sellIn);
    EXPECT_EQ(18, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(8, app.getItem(0).sellIn);
    EXPECT_EQ(16, app.getItem(0).quality);
}

TEST(ConjuredTest, QualityNeverNegative)
{
    vector<Item> items;
    items.push_back({"Conjured Mana Cake", 10, 1});
    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(0, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(0, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(0, app.getItem(0).quality);
}

TEST(ConjuredTest, TwiceDegradation)
{
    vector<Item> items;
    items.push_back({"Conjured Mana Cake", 1, 10});
    GildedRose app(items);

    app.updateQuality();
    EXPECT_EQ(8, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(4, app.getItem(0).quality);

    app.updateQuality();
    EXPECT_EQ(0, app.getItem(0).quality);
}

TEST(ExceptionTest, OutOfRange)
{
    vector<Item> items;
    items.push_back({"Conjured Mana Cake", 1, 10});
    GildedRose app(items);

    EXPECT_NO_THROW(app.getItem(0));
    EXPECT_THROW(app.getItem(1), std::out_of_range);
}