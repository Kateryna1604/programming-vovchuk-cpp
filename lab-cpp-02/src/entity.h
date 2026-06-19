#ifndef ENTITY_H
#define ENTITY_H

#include <string>

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

    ~Mail();

    std::string getSubject() const;
    std::string getBody() const;
    std::string getSender() const;

    void setSubject(const std::string& subject);
    void setBody(const std::string& body);
    void setSender(const std::string& sender);

    std::string toString() const;

    static Mail fromString(
        const std::string& data
    );
};

#endif
