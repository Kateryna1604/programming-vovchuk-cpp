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

bool Mail::operator==(const Mail& other) const
{
    return
        subject == other.subject &&
        body == other.body &&
        sender == other.sender;
}

bool Mail::operator!=(const Mail& other) const
{
    return !(*this == other);
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

void Mail::fromString(const std::string& str)
{
    std::stringstream ss(str);

    std::getline(ss, subject, '|');
    std::getline(ss, body, '|');
    std::getline(ss, sender, '|');
}

std::ostream& operator<<(
    std::ostream& out,
    const Mail& mail
)
{
    out << mail.toString();

    return out;
}

std::istream& operator>>(
    std::istream& in,
    Mail& mail
)
{
    std::cout << "Subject: ";
    std::getline(in >> std::ws, mail.subject);

    std::cout << "Body: ";
    std::getline(in, mail.body);

    std::cout << "Sender: ";
    std::getline(in, mail.sender);

    return in;
}

Mail::~Mail()
{
}
