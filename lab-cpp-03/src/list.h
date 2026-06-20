#ifndef LIST_H
#define LIST_H

#include "entity.h"

#include <cstddef>
#include <fstream>

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

    Mail& operator[](size_t index);
    const Mail& operator[](size_t index) const;

    MailList findMessagesByUser(
        const std::string& userName
    ) const;

    size_t getSize() const;

    void readFromFile(
        const std::string& fileName
    );

    void writeToFile(
        const std::string& fileName
    ) const;

    friend std::ostream& operator<<(
        std::ostream& out,
        const MailList& list
    );

    friend std::istream& operator>>(
        std::istream& in,
        MailList& list
    );
};

#endif
