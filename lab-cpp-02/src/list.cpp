#include "list.h"

#include <fstream>
#include <iostream>

MailList::MailList()
    : size(0),
      capacity(10)
{
    mails = new Mail[capacity];
}

MailList::MailList(const MailList& other)
    : size(other.size),
      capacity(other.capacity)
{
    mails = new Mail[capacity];

    for (size_t i = 0; i < size; i++) {
        mails[i] = other.mails[i];
    }
}

MailList::~MailList()
{
    delete[] mails;
}

void MailList::resize()
{
    capacity *= 2;

    Mail* temp = new Mail[capacity];

    for (size_t i = 0; i < size; i++) {
        temp[i] = mails[i];
    }

    delete[] mails;

    mails = temp;
}

void MailList::addMail(const Mail& mail)
{
    if (size >= capacity) {
        resize();
    }

    mails[size++] = mail;
}

void MailList::removeMail(size_t index)
{
    if (index >= size) {
        return;
    }

    for (size_t i = index; i < size - 1; i++) {
        mails[i] = mails[i + 1];
    }

    size--;
}

Mail& MailList::getMail(size_t index)
{
    return mails[index];
}

void MailList::print() const
{
    for (size_t i = 0; i < size; i++) {
        std::cout
            << mails[i].toString()
            << std::endl;
    }
}

MailList MailList::findMessagesByUser(
    const std::string& userName
) const
{
    MailList result;

    for (size_t i = 0; i < size; i++) {

        if (mails[i].getSender() == userName) {
            result.addMail(mails[i]);
        }
    }

    return result;
}

size_t MailList::getSize() const
{
    return size;
}

void MailList::writeToFile(
    const std::string& fileName
) const
{
    std::ofstream file(fileName);

    for (size_t i = 0; i < size; i++) {
        file << mails[i].toString()
             << std::endl;
    }
}

void MailList::readFromFile(
    const std::string& fileName
)
{
    delete[] mails;

    size = 0;
    capacity = 10;

    mails = new Mail[capacity];

    std::ifstream file(fileName);

    std::string line;

    while (getline(file, line)) {

        if (size >= capacity) {
            resize();
        }

        mails[size++] =
            Mail::fromString(line);
    }
}
