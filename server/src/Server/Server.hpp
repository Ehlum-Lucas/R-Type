/*
** EPITECH PROJECT, 2023
** Server.hpp
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_
    #include "Client.hpp"
    #include "Game.hpp"

    class Server {
        public:
            Server(asio::io_context& io_context, short port);
        private:
            void start_receive();
            void start_send();
            void game();
            int get_client_type() { return next_client_type++; };
            asio::ip::udp::socket _socket;
            asio::ip::udp::endpoint _remote_endpoint;
            std::array<char, 1024> _recv_buffer;
            std::vector<Client> _clients;
            asio::steady_timer _timer;
            std::vector<std::string> _inputs_list;
            Game _game;
            bool _in_room = true;
            int next_client_type = 1;
    };

#endif /* !SERVER_HPP_ */
