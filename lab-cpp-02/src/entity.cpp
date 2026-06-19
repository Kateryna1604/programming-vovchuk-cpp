#include "entity.h"

#include <sstream>

Mail::Mail()
    : subject(""),
      body(""),
      sender("")
{
}

Mail::Mail(
    const std::string& subject,
    const std::string& body,
    const std::string& sender
)
    : subject(subject),
      body(body),
      sender(sender)
{
}

Mail::Mail(const Mail& other)
    : subject(other.subject),
      body(other.body),
      sender(other.sender)
{
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

std::string Mail::toString() const
{
    std::stringstream ss;

    ss << subject
       << "|"
       << body
       << "|"
       << sender;

    return ss.str();
}

Mail Mail::fromString(
    const std::string& data
)
{
    std::stringstream ss(data);

    std::string subject;
    std::string body;
    std::string sender;

    getline(ss, subject, '|');
    getline(ss, body, '|');
    getline(ss, sender);

    return Mail(
        subject,
        body,
        sender
    );
}
