##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
## 

INC = 		-I ./src/Server 					\
			-I ./src/Client 					\
			-I ./src/Components 				\
			-I ./src/Entity				 		\
			-I ./src/Systems 					\
			-I ./src/Registry 					\
			-I ./src/SparseArray 				\

SRC = 		src/main.cpp						\
			src/Server/Server.cpp				\
			src/Systems/position_system.cpp		\
			src/Systems/control_system.cpp		\
			src/Systems/serialize_system.cpp	\
			src/Systems/shoot_system.cpp		\
			src/Entity/Entity.cpp				\

OBJ = 		$(SRC:.cpp=.o)

NAME = 		server

CXXFLAGS =  -Wall -std=c++17 $(INC)

CXX = 		g++

all: 		$(OBJ)
			$(CXX) -o $(NAME) $(OBJ)

clean:
			find . -name "*[#,~]" -type f -delete
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all
