#include "entity.h"

#include <iostream>

Mail::Mail()
    : subject(""),
      body(""),
      sender("")
{
    std::cout << "Default constructor\n";
}

Mail::Mail(const std::string& subject,
           const std::string& body,
           const std::string& sender)
    : subject(subject),
      body(body),
      sender(sender)
{
    std::cout << "Param constructor\n";
}

Mail::Mail(const Mail& other)
    : subject(other.subject),
      body(other.body),
      sender(other.sender)
{
    std::cout << "Copy constructor\n";
}

Mail& Mail::operator=(const Mail& other)
{
    if (this != &other) {
        subject = other.subject;
        body = other.body;
        sender = other.sender;
    }

    return *this;
}

Mail::~Mail()
{
    std::cout << "Destructor\n";
}

std::string Mail::getSubject() const
{
    return subject;
}

std::string Mail::getBody() const
{
    return body;
}

std::string Mail::getSender() const
{
    return sender;
}

void Mail::setSubject(const std::string& subject)
{
    this->subject = subject;
}

void Mail::setBody(const std::string& body)
{
    this->body = body;
}

void Mail::setSender(const std::string& sender)
{
    this->sender = sender;
}

void Mail::print() const
{
    std::cout << "Subject: " << subject << std::endl;
    std::cout << "Body: " << body << std::endl;
    std::cout << "Sender: " << sender << std::endl;
}
