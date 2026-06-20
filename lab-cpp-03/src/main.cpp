#include "list.h"

#include <iostream>

int main()
{
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

    Mail mail3;

    mail3 = mail1;

    std::cout << "MAIL1:\n";
    std::cout << mail1 << std::endl;

    std::cout << "\nMAIL3 AFTER ASSIGNMENT:\n";
    std::cout << mail3 << std::endl;

    if (mail1 == mail3) {
        std::cout << "\nmail1 == mail3\n";
    }

    if (mail1 != mail2) {
        std::cout << "mail1 != mail2\n";
    }

    MailList list;

    list.addMail(mail1);
    list.addMail(mail2);
    list.addMail(mail3);

    std::cout << "\nALL MAILS:\n";
    std::cout << list;

    std::cout << "\nFIRST MAIL USING []:\n";
    std::cout << list[0] << std::endl;

    list.writeToFile("mails.txt");

    MailList loaded;

    loaded.readFromFile("mails.txt");

    std::cout << "\nLOADED FROM FILE:\n";
    std::cout << loaded;

    MailList result =
        loaded.findMessagesByUser(
            "Kateryna Vovchuk"
        );

    std::cout << "\nMAILS BY Kateryna Vovchuk:\n";
    std::cout << result;

    return 0;
}
