#include "../src/list.hpp"

#include <gtest/gtest.h>
#include <string>

TEST(ListTest, AddElement)
{
    List<int> list;

    list.add(10);
    list.add(20);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(ListTest, FindIndex)
{
    List<int> list;

    list.add(5);
    list.add(8);
    list.add(10);

    EXPECT_EQ(list.findIndex(8), 1);
}

TEST(ListTest, GetMin)
{
    List<int> list;

    list.add(7);
    list.add(2);
    list.add(9);

    EXPECT_EQ(list.getMin(), 2);
}

TEST(ListTest, RemoveElement)
{
    List<int> list;

    list.add(1);
    list.add(2);
    list.add(3);

    list.remove(1);

    EXPECT_EQ(list.getSize(), 2);
    EXPECT_EQ(list[1], 3);
}

TEST(ListTest, SortElements)
{
    List<int> list;

    list.add(5);
    list.add(1);
    list.add(3);

    list.sort();

    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 3);
    EXPECT_EQ(list[2], 5);
}
