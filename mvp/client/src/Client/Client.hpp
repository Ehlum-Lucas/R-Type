/*
** EPITECH PROJECT, 2023
** Client.hpp
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_
    #include <asio.hpp>
    #include <thread>

    // void receiveMessageThread(std::shared_ptr<Client> client)
    // {
    //     client->receiveMessage();
    // }

    // // Utilisation du thread
    // std::shared_ptr<Client> client = std::make_shared<Client>(ip, port);
    // std::thread thread(receiveMessageThread, client);

    // // Attendre la fin du thread
    // thread.join();


    class Client {
        public:
            std::string _message;
            std::thread _thread;
            std::string _playerId;
            bool _server_know = false;
            Client(const std::string& host, const std::string& port) : _io_service(), _socket(_io_service, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0)), _resolver(_io_service), _query(asio::ip::udp::v4(), host, port), _receiver_endpoint(*_resolver.resolve(_query)) {}

            ~Client() {
                _socket.close();
            }
            void connectToServer() {
                while (true) {
                    sendMessage("NEW CLIENT");
                    std::string message = receiveMessage();
                    if (message.substr(0, 8) == "YOU ARE ") {
                        _playerId = message.substr(8);
                        std::cout << "OK I AM " << _playerId << std::endl;
                        // message = "OK";
                        break;
                    }
                }
            }
            std::string getMessage() { return _message; }
            void sendMessage(std::string message) {
                // std::cout << "SENDING " << message << std::endl;
                _socket.send_to(asio::buffer(message), _receiver_endpoint);
            }
            std::string receiveMessage() {
                char buf[100000];
                asio::ip::udp::endpoint sender_endpoint;
                size_t len = _socket.receive_from(asio::buffer(buf), sender_endpoint);
                return std::string(buf, len);
            }

        private:
            asio::io_service _io_service;
            asio::ip::udp::socket _socket;
            asio::ip::udp::resolver _resolver;
            asio::ip::udp::resolver::query _query;
            asio::ip::udp::endpoint _receiver_endpoint;
    };

#endif /* !CLIENT_HPP_ */
