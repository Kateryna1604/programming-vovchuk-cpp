#include <gtest/gtest.h>

#include "../src/entity.h"
#include "../src/list.h"

TEST(MailTest, Constructor)
{
    Mail mail(
        "Hello",
        "Message",
        "Kateryna Vovchuk"
    );

    EXPECT_EQ(
        mail.getSubject(),
        "Hello"
    );

    EXPECT_EQ(
        mail.getSender(),
        "Kateryna Vovchuk"
    );
}

TEST(MailTest, AssignmentOperator)
{
    Mail mail1(
        "Hello",
        "Message",
        "Kateryna Vovchuk"
    );

    Mail mail2;

    mail2 = mail1;

    EXPECT_TRUE(mail1 == mail2);
}

TEST(MailTest, CompareOperators)
{
    Mail mail1(
        "Hello",
        "Message",
        "Kateryna Vovchuk"
    );

    Mail mail2(
        "Hello",
        "Message",
        "Kateryna Vovchuk"
    );

    Mail mail3(
        "Other",
        "Text",
        "Anna Smith"
    );

    EXPECT_TRUE(mail1 == mail2);
    EXPECT_TRUE(mail1 != mail3);
}

TEST(MailListTest, AddMail)
{
    MailList list;

    Mail mail(
        "Hello",
        "Message",
        "Kateryna Vovchuk"
    );

    list.addMail(mail);

    EXPECT_EQ(
        list.getSize(),
        1
    );
}

TEST(MailListTest, IndexOperator)
{
    MailList list;

    Mail mail(
        "Hello",
        "Message",
        "Kateryna Vovchuk"
    );

    list.addMail(mail);

    EXPECT_EQ(
        list[0].getSubject(),
        "Hello"
    );
}

TEST(MailListTest, FindMessagesByUser)
{
    MailList list;

    Mail m1(
        "Hello",
        "Text",
        "Kateryna Vovchuk"
    );

    Mail m2(
        "Secret",
        "Text",
        "Anna Smith"
    );

    list.addMail(m1);
    list.addMail(m2);

    MailList result =
        list.findMessagesByUser(
            "Kateryna Vovchuk"
        );

    EXPECT_EQ(
        result.getSize(),
        1
    );
}
