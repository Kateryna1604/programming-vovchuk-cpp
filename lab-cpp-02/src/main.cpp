#include "list.h"

#include <iostream>

int main()
{
    MailList list;

    Mail mail1(
        "Hello",
        "First message",
        "Kateryna Vovchuk"
    );

    Mail mail2(
        "Secret",
        "Hidden information",
        "Anna Smith"
    );

    Mail mail3(
        "Report",
        "Project completed",
        "Kateryna Vovchuk"
    );

    list.addMail(mail1);
    list.addMail(mail2);
    list.addMail(mail3);

    std::cout << "ALL MAILS\n";
    list.print();

    std::string fileName = "mails.txt";

    list.writeToFile(fileName);

    MailList loaded;

    loaded.readFromFile(fileName);

    std::cout << "\nLOADED FROM FILE\n";
    loaded.print();

    MailList result =
        loaded.findMessagesByUser(
            "Kateryna Vovchuk"
        );

    std::cout << "\nMAILS BY Kateryna Vovchuk\n";
    result.print();

    return 0;
}
