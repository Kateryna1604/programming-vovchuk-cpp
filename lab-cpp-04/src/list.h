#ifndef LIST_H
#define LIST_H

#include "entity.h"

#include <string>

class MailList {
private:
    Mail** mails;

    size_t size;
    size_t capacity;

    void resize();

public:
    MailList();

    ~MailList();

    void addMail(Mail* mail);

    void removeMail(size_t index);

    Mail* operator[](size_t index);

    void print() const;

    MailList findMessagesByUser(
        const std::string& userName
    ) const;

    MailList findSecretMessages() const;

    int totalMessagesSize() const;

    void writeToFile(
        const std::string& fileName
    ) const;

    void readFromFile(
        const std::string& fileName
    );

    size_t getSize() const;
};

#endif
