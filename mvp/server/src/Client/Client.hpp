/*
** EPITECH PROJECT, 2023
** Client.hpp
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_
    #include <asio.hpp>
    #include <chrono>

    class Client {
        public:
            Client(asio::ip::udp::endpoint endpoint): endpoint_(endpoint) {}

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
