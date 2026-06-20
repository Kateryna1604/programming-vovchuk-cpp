#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Mail {
private:
    std::string subject;
    std::string body;
    std::string sender;

public:
    Mail();

    Mail(
        const std::string& subject,
        const std::string& body,
        const std::string& sender
    );

    Mail(const Mail& other);

    Mail& operator=(const Mail& other);

    bool operator==(const Mail& other) const;
    bool operator!=(const Mail& other) const;

    std::string getSubject() const;
    std::string getBody() const;
    std::string getSender() const;

    void setSubject(const std::string& subject);
    void setBody(const std::string& body);
    void setSender(const std::string& sender);

    std::string toString() const;
    void fromString(const std::string& str);

    friend std::ostream& operator<<(
        std::ostream& out,
        const Mail& mail
    );

    friend std::istream& operator>>(
        std::istream& in,
        Mail& mail
    );

    ~Mail();
};

#endif
