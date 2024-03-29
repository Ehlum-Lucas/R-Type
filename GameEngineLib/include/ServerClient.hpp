/*
** EPITECH PROJECT, 2023
** ServerClient.hpp
** File description:
** ServerClient
*/

/**
 * @file ServerClient.hpp
 * @brief This file contains the declaration of the `ServerClient` class.
 */

#ifndef SERVER_CLIENT_HPP_
    #define SERVER_CLIENT_HPP_
    #include <asio.hpp>
    #include <chrono>

    class ServerClient {
        public:
            ServerClient(asio::ip::udp::endpoint endpoint): endpoint_(endpoint) {}


            asio::ip::udp::endpoint getEndpoint() const { return endpoint_; }

            void setType(size_t type) { 
                this->type = type;
                this->string_type = std::to_string(type);
            }

            bool created = false;
            bool connected = false;
            size_t type;
            std::string string_type;
            std::chrono::steady_clock::time_point lastMessageTime;
            size_t entity_id;
            std::vector<std::string> entities_sended;
            // bool quit = false;
        private:
            asio::ip::udp::endpoint endpoint_;
};

#endif /* !CLIENT_HPP_ */
