#include "entity.h"

#include <sstream>
#include <cctype>

/* ================= MAIL ================= */

Mail::Mail(
    bool isDraft,
    const std::string& subject,
    const std::string& body,
    const std::string& senderName,
    const std::string& senderEmail,
    const std::string& receiverName,
    const std::string& receiverEmail,
    const std::string& encoding
)
    : isDraft(isDraft),
      subject(subject),
      body(body),
      senderName(senderName),
      senderEmail(senderEmail),
      receiverName(receiverName),
      receiverEmail(receiverEmail),
      encoding(encoding)
{
}

std::string Mail::getSenderName() const
{
    return senderName;
}

std::string Mail::toString() const
{
    std::stringstream ss;

    ss << subject
       << "|"
       << body
       << "|"
       << senderName;

    return ss.str();
}

bool Mail::operator==(const Mail& other) const
{
    return subject == other.subject
        && body == other.body
        && senderName == other.senderName;
}

bool Mail::operator!=(const Mail& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(
    std::ostream& os,
    const Mail& mail
)
{
    os << mail.toString();
    return os;
}

/* ================= SECRET MAIL ================= */

SecretMail::SecretMail(
    bool isDraft,
    const std::string& subject,
    const std::string& body,
    const std::string& senderName,
    const std::string& senderEmail,
    const std::string& receiverName,
    const std::string& receiverEmail,
    const std::string& encoding
)
    : Mail(
        isDraft,
        subject,
        body,
        senderName,
        senderEmail,
        receiverName,
        receiverEmail,
        encoding
    )
{
}

std::string SecretMail::buildMessage() const
{
    std::stringstream ss;

    ss << senderName
       << receiverName
       << subject
       << body;

    std::string result = ss.str();

    for (char& c : result) {

        if (std::isdigit(c)) {
            c = '*';
        }

        if (std::ispunct(c)) {
            c = ' ';
        }
    }

    return result;
}

int SecretMail::calculateSize() const
{
    return static_cast<int>(buildMessage().length());
}

/* ================= COMPRESSED MAIL ================= */

CompressedMail::CompressedMail(
    bool isDraft,
    const std::string& subject,
    const std::string& body,
    const std::string& senderName,
    const std::string& senderEmail,
    const std::string& receiverName,
    const std::string& receiverEmail,
    const std::string& encoding,
    double compression
)
    : Mail(
        isDraft,
        subject,
        body,
        senderName,
        senderEmail,
        receiverName,
        receiverEmail,
        encoding
    ),
      compression(compression)
{
}

std::string CompressedMail::buildMessage() const
{
    std::stringstream ss;

    ss << senderName
       << receiverName
       << subject
       << body;

    return ss.str();
}

int CompressedMail::calculateSize() const
{
    return static_cast<int>(
        buildMessage().length() * compression
    );
}

double CompressedMail::getCompression() const
{
    return compression;
}
