#ifndef LIST_H
#define LIST_H

#include "entity.h"
#include <cstddef>

class MailList {
private:
    Mail* mails;
    size_t size;
    size_t capacity;

    void resize();

public:
    MailList();
    MailList(const MailList& other);
    ~MailList();

    void addMail(const Mail& mail);
    void removeMail(size_t index);

    Mail& getMail(size_t index);

    void print() const;

    MailList findMessagesByUser(const std::string& userName) const;

    size_t getSize() const;
};

#endif
