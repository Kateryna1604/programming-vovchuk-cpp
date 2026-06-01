#include "list.h"

#include <iostream>

MailList::MailList()
    : size(0),
      capacity(10)
{
    mails = new Mail[capacity];
    std::cout << "List constructor\n";
}

MailList::MailList(const MailList& other)
    : size(other.size),
      capacity(other.capacity)
{
    mails = new Mail[capacity];

    for (size_t i = 0; i < size; i++) {
        mails[i] = other.mails[i];
    }

    std::cout << "List copy constructor\n";
}

MailList::~MailList()
{
    delete[] mails;
    std::cout << "List destructor\n";
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
        mails[i].print();
        std::cout << std::endl;
    }
}

MailList MailList::findMessagesByUser(const std::string& userName) const
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
