/*
** EPITECH PROJECT, 2023
** ServerClient.hpp
** File description:
** ServerClient
*/

#ifndef SERVER_CLIENT_HPP_
    #define SERVER_CLIENT_HPP_
    #include <asio.hpp>
    #include <chrono>

    class ServerClient {
        public:
            ServerClient(asio::ip::udp::endpoint endpoint): endpoint_(endpoint) {}

            asio::ip::udp::endpoint getEndpoint() const { return endpoint_; }

            bool connected = false;
            bool created = false;
            bool quit = false;
            std::string type;
            std::chrono::steady_clock::time_point lastMessageTime;
            size_t entity_id;
        private:
            asio::ip::udp::endpoint endpoint_;
};

#endif /* !CLIENT_HPP_ */