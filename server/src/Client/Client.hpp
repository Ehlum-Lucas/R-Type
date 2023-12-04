/*
** EPITECH PROJECT, 2023
** Client.hpp
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_
    #include <asio.hpp>


    class Client {
        public:
            Client(asio::ip::udp::endpoint endpoint): endpoint_(endpoint) {}

            asio::ip::udp::endpoint getEndpoint() const { return endpoint_; }

        private:
            asio::ip::udp::endpoint endpoint_;
};

#endif /* !CLIENT_HPP_ */
