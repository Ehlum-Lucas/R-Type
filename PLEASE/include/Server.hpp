/*
** EPITECH PROJECT, 2023
** Server.hpp
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_
    #include "ServerClient.hpp"
    #include <asio.hpp>
    #include <iostream>

    class Server {
        public:
            Server(asio::io_context& io_context, short port);
        public:
            std::string message;
        private:
            void start_receive();
            void start_send();
            asio::ip::udp::socket _socket;
            asio::ip::udp::endpoint _remote_endpoint;
            std::array<char, 1024> _recv_buffer;
            std::vector<ServerClient> _clients;
            asio::steady_timer _timer;
            std::vector<std::string> _inputs_list;
    };

#endif /* !SERVER_HPP_ */
