#include "list.h"

#include <fstream>
#include <iostream>

/* CONSTRUCTOR */

MailList::MailList()
    : size(0),
      capacity(10)
{
    mails = new Mail*[capacity];
}

/* DESTRUCTOR */

MailList::~MailList()
{
    delete[] mails;
}

/* RESIZE */

void MailList::resize()
{
    capacity *= 2;

    Mail** temp = new Mail*[capacity];

    for (size_t i = 0; i < size; i++) {
        temp[i] = mails[i];
    }

    delete[] mails;

    mails = temp;
}

/* ADD */

void MailList::addMail(Mail* mail)
{
    if (size >= capacity) {
        resize();
    }

    mails[size++] = mail;
}

/* REMOVE */

void MailList::removeMail(size_t index)
{
    if (index >= size) {
        return;
    }

    delete mails[index];

    for (size_t i = index; i < size - 1; i++) {
        mails[i] = mails[i + 1];
    }

    size--;
}

/* INDEX OPERATOR */

Mail* MailList::operator[](size_t index)
{
    return mails[index];
}

/* PRINT */

void MailList::print() const
{
    for (size_t i = 0; i < size; i++) {
        std::cout << *mails[i] << std::endl;
    }
}

/* FIND BY USER */

MailList MailList::findMessagesByUser(
    const std::string& userName
) const
{
    MailList result;

    for (size_t i = 0; i < size; i++) {

        if (mails[i]->getSenderName() == userName) {

            result.addMail(mails[i]);
        }
    }

    return result;
}

/* SECRET MAILS */

MailList MailList::findSecretMessages() const
{
    MailList result;

    for (size_t i = 0; i < size; i++) {

        SecretMail* secret =
            dynamic_cast<SecretMail*>(mails[i]);

        if (secret != nullptr) {
            result.addMail(mails[i]);
        }
    }

    return result;
}

/* TOTAL SIZE */

int MailList::totalMessagesSize() const
{
    int total = 0;

    for (size_t i = 0; i < size; i++) {
        total += mails[i]->calculateSize();
    }

    return total;
}

/* FILE WRITE */

void MailList::writeToFile(
    const std::string& fileName
) const
{
    std::ofstream fout(fileName);

    for (size_t i = 0; i < size; i++) {
        fout << mails[i]->toString() << std::endl;
    }
}

/* FILE READ */

void MailList::readFromFile(
    const std::string& fileName
)
{
    std::ifstream fin(fileName);

    std::string line;

    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
    }
}

/* GET SIZE */

size_t MailList::getSize() const
{
    return size;
}
