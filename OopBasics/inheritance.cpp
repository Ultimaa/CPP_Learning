#include <iostream>
#include <string>
#include <memory>
#include <fstream>

class Logger
{
    const std::string filename;
public:
    Logger(const std::string& filename) :filename(filename) {}

    virtual void log(const std::string& msg)
    {
        const std::string line = msg + "\n";
        std::ofstream out(filename.c_str(), std::ofstream::app);
        out.write(line.c_str(), line.length());
        out.close();
    }
    virtual ~Logger() = default;
};

class ISender
{
public:
    virtual void send(const std::string& text) = 0;
    virtual ~ISender() = default;
};

class Sender : public ISender, virtual protected Logger
{
public:
    Sender(std::string name) : Logger("sender.txt"), objectName(name)
    {
        std::cout << objectName << " -[Sender] Creating object... \n";
    }
    ~Sender()
    {
        std::cout << objectName << " -[Sender] Object destruction... \n";
    }
    void send(const std::string& text) override
    {
        std::cout << objectName << " -[Sender] Sending: " << text << "\n";
        log("sent: " + text);
    }
protected:
    std::string objectName;
};

struct Receiver : virtual protected Logger
{
    Receiver() : Logger("receiver.txt")
    {
        std::cout << "[Receiver] creating...\n";
    }

    std::string receive()
    {
        std::string text = "Received text.";
        log("received: " + text);
        return text;
    }

    ~Receiver()
    {
        std::cout << "[Receiver] destroying...\n";
    }
};

class Messenger : public Sender, public Receiver, virtual protected Logger
{
public:
    Messenger(std::string name) :Logger("messenger.txt"), Sender(name) {}
    void send(const std::string& text) override
    {
        log("Messenger sent: " + text);
        constexpr int char_to_send = 10;
        for (std::string::size_type i = 0; i < text.length(); i += char_to_send)
        {
            if (i + 10 > text.length())
            {
                Sender::send(text.substr(i, text.length() - i));
            } else
            {
                Sender::send(text.substr(i, char_to_send));
            }
        }
    }
};

int main()
{
    std::unique_ptr<Sender> sender = std::make_unique<Sender>("(Sender)");
    std::unique_ptr<Messenger> messenger = std::make_unique<Messenger>("(Messenger)");
    sender->send("Test a sender class");
    messenger->send("Test a messanger class and say Hello!");
    messenger->receive();
    return 0;
}
