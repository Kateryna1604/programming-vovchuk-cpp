#include <gtest/gtest.h>
#include "../src/entity.h"
#include "../src/list.h"

TEST(MailTest, Constructor)
{
    Mail mail("Hello", "Body", "Ivan");

    EXPECT_EQ(mail.getSubject(), "Hello");
    EXPECT_EQ(mail.getBody(), "Body");
    EXPECT_EQ(mail.getSender(), "Ivan");
}

TEST(MailListTest, AddMail)
{
    MailList list;

    Mail m1("A", "B", "Ivan");

    list.addMail(m1);

    EXPECT_EQ(list.getSize(), 1);
}

TEST(MailListTest, RemoveMail)
{
    MailList list;

    Mail m1("A", "B", "Ivan");
    Mail m2("C", "D", "Anna");

    list.addMail(m1);
    list.addMail(m2);

    list.removeMail(0);

    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.getMail(0).getSender(), "Anna");
}

TEST(MailListTest, FindMessagesByUser)
{
    MailList list;

    Mail m1("A", "B", "Ivan");
    Mail m2("C", "D", "Anna");
    Mail m3("E", "F", "Ivan");

    list.addMail(m1);
    list.addMail(m2);
    list.addMail(m3);

    MailList result = list.findMessagesByUser("Ivan");

    EXPECT_EQ(result.getSize(), 2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
