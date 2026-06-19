#include <gtest/gtest.h>

#include "../src/entity.h"
#include "../src/list.h"

TEST(MailTest, Constructor)
{
    Mail mail(
        "Hello",
        "Test body",
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

TEST(MailListTest, AddMail)
{
    MailList list;

    Mail mail(
        "Test",
        "Body",
        "Kateryna Vovchuk"
    );

    list.addMail(mail);

    EXPECT_EQ(
        list.getSize(),
        1
    );
}

TEST(MailListTest, RemoveMail)
{
    MailList list;

    list.addMail(
        Mail(
            "A",
            "B",
            "Kateryna Vovchuk"
        )
    );

    list.removeMail(0);

    EXPECT_EQ(
        list.getSize(),
        0
    );
}

TEST(MailListTest, FindMessagesByUser)
{
    MailList list;

    list.addMail(
        Mail(
            "Mail1",
            "Body1",
            "Kateryna Vovchuk"
        )
    );

    list.addMail(
        Mail(
            "Mail2",
            "Body2",
            "Anna Smith"
        )
    );

    MailList result =
        list.findMessagesByUser(
            "Kateryna Vovchuk"
        );

    EXPECT_EQ(
        result.getSize(),
        1
    );
}