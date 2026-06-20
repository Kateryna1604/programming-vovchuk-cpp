#include "list.h"

#include <iostream>

int main()
{
    MailList list;

    list.addMail(
        new SecretMail(
            false,
            "Secret 2025!",
            "Hidden data 123!",
            "Kateryna Vovchuk",
            "katya@mail.com",
            "Admin",
            "admin@mail.com",
            "UTF-8"
        )
    );

    list.addMail(
        new CompressedMail(
            false,
            "Report",
            "Project completed",
            "Anna Smith",
            "anna@mail.com",
            "Boss",
            "boss@mail.com",
            "UTF-8",
            0.5
        )
    );

    std::cout << "ALL MAILS:\n";
    list.print();

    std::cout << "\nTOTAL SIZE:\n";
    std::cout << list.totalMessagesSize()
              << std::endl;

    std::cout << "\nSECRET MAILS:\n";

    MailList secret =
        list.findSecretMessages();

    secret.print();

    std::cout << "\nMAILS BY Kateryna Vovchuk:\n";

    MailList user =
        list.findMessagesByUser(
            "Kateryna Vovchuk"
        );

    user.print();

    std::cout << "\nFIRST MAIL:\n";

    std::cout << *list[0]
              << std::endl;

    return 0;
}
