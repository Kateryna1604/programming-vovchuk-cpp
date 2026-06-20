#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Mail {
protected:
    bool isDraft;

    std::string subject;
    std::string body;

    std::string senderName;
    std::string senderEmail;

    std::string receiverName;
    std::string receiverEmail;

    std::string encoding;

public:
    Mail(
        bool isDraft,
        const std::string& subject,
        const std::string& body,
        const std::string& senderName,
        const std::string& senderEmail,
        const std::string& receiverName,
        const std::string& receiverEmail,
        const std::string& encoding
    );

    virtual ~Mail() = default;

    virtual std::string buildMessage() const = 0;

    virtual int calculateSize() const = 0;

    std::string getSenderName() const;

    virtual std::string toString() const;

    bool operator==(const Mail& other) const;
    bool operator!=(const Mail& other) const;

    friend std::ostream& operator<<(
        std::ostream& os,
        const Mail& mail
    );
};

class SecretMail final : public Mail {
public:
    SecretMail(
        bool isDraft,
        const std::string& subject,
        const std::string& body,
        const std::string& senderName,
        const std::string& senderEmail,
        const std::string& receiverName,
        const std::string& receiverEmail,
        const std::string& encoding
    );

    std::string buildMessage() const override;

    int calculateSize() const override;
};

class CompressedMail final : public Mail {
private:
    double compression;

public:
    CompressedMail(
        bool isDraft,
        const std::string& subject,
        const std::string& body,
        const std::string& senderName,
        const std::string& senderEmail,
        const std::string& receiverName,
        const std::string& receiverEmail,
        const std::string& encoding,
        double compression
    );

    std::string buildMessage() const override;

    int calculateSize() const override;

    double getCompression() const;
};

#endif
