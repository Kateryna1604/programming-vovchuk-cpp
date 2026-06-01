#include "list.h"

#include <iostream>

int main()
{
    MailList list;

    Mail mail1(
        "Hello",
        "First message",
        "Ivan Ivanov"
    );

    Mail mail2(
        "Secret",
        "Hidden information",
        "Anna Smith"
    );

    Mail mail3(mail1);

    list.addMail(mail1);
    list.addMail(mail2);
    list.addMail(mail3);

    std::cout << "\nALL MAILS:\n";
    list.print();

    std::cout << "\nMAILS BY IVAN:\n";

    MailList result =
        list.findMessagesByUser("Ivan Ivanov");

    result.print();

    std::cout << "\nREMOVE FIRST MAIL\n";

    list.removeMail(0);

    list.print();

    return 0;
}
