#include "../src/list.h"

#include <gtest/gtest.h>

TEST(MailTest, CompareOperators)
{
    SecretMail mail1(
        false,
        "Hello",
        "Body",
        "Kateryna",
        "katya@mail.com",
        "Admin",
        "admin@mail.com",
        "UTF-8"
    );

    SecretMail mail2(
        false,
        "Hello",
        "Body",
        "Kateryna",
        "katya@mail.com",
        "Admin",
        "admin@mail.com",
        "UTF-8"
    );

    EXPECT_TRUE(mail1 == mail2);
    EXPECT_FALSE(mail1 != mail2);
}

TEST(MailTest, CalculateSize)
{
    CompressedMail mail(
        false,
        "Hello",
        "Body",
        "Kateryna",
        "katya@mail.com",
        "Admin",
        "admin@mail.com",
        "UTF-8",
        0.5
    );

    EXPECT_GT(mail.calculateSize(), 0);
}

TEST(MailListTest, AddMail)
{
    MailList list;

    list.addMail(
        new SecretMail(
            false,
            "Hello",
            "Body",
            "Kateryna",
            "katya@mail.com",
            "Admin",
            "admin@mail.com",
            "UTF-8"
        )
    );

    EXPECT_EQ(list.getSize(), 1);
}

TEST(MailListTest, IndexOperator)
{
    MailList list;

    list.addMail(
        new SecretMail(
            false,
            "Hello",
            "Body",
            "Kateryna",
            "katya@mail.com",
            "Admin",
            "admin@mail.com",
            "UTF-8"
        )
    );

    EXPECT_EQ(
        list[0]->getSenderName(),
        "Kateryna"
    );
}

TEST(MailListTest, FindSecretMessages)
{
    MailList list;

    list.addMail(
        new SecretMail(
            false,
            "Secret",
            "Body",
            "Kateryna",
            "katya@mail.com",
            "Admin",
            "admin@mail.com",
            "UTF-8"
        )
    );

    MailList result =
        list.findSecretMessages();

    EXPECT_EQ(result.getSize(), 1);
}
