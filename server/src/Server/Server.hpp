/*
** EPITECH PROJECT, 2023
** Server.hpp
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_
    #include "Client.hpp"
    #include <array>
    #include <iostream>
    #include <vector>
    #include "Systems.hpp"
    #include <random>

    class Server {
        public:
            Server(asio::io_context& io_context, short port);
        private:
            void start_receive();
            void start_send();
            void start_server();
            void setup_registry();
            asio::ip::udp::socket _socket;
            asio::ip::udp::endpoint _remote_endpoint;
            std::array<char, 1024> _recv_buffer;
            std::vector<Client> _clients;
            asio::steady_timer _timer;
            Registry _registry;
            std::vector<Entity> _players;
            std::vector<Entity> _enemies;
            std::string _inputs;
    };

#endif /* !SERVER_HPP_ */
