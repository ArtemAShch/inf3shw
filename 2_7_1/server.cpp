#include <iostream>
#include <boost/asio.hpp>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

bool read(boost::asio::ip::tcp::socket& socket, std::string& message)
{
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket, buffer, '\n');
    std::istream stream(&buffer);
    std::getline(stream, message);
    return message != "EXIT";
}

int main()
{
    auto port = 65000u;
    std::string ip = "127.0.0.1";

    boost::asio::ip::tcp::endpoint endpoint(
            boost::asio::ip::address::from_string(ip), port);
    std::cout << "Endpoint ready.\n";

    boost::asio::io_service io_service;
    std::cout << "IO_SERVICE ready.\n";

    boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint.protocol());
    acceptor.bind(endpoint);
    std::cout << "Acceptor ready.\n";
    acceptor.listen();
    std::cout << "Waiting for connections...\n";

    boost::asio::ip::tcp::socket socket(io_service);
    acceptor.accept(socket);
    std::cout << "Connection accepted.\n";

    std::string message;

    while (read(socket, message)) {
        std::cout << message << std::endl;
    }

    socket.close();
    acceptor.close();
    std::cout << "Disconnected.\n";
}

