##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
## 

INC = 		-I ./src/Menu 						\
			-I ./src/Game 						\
			-I ./src/Client		 				\
			-I ./src/Object

SRC = 		src/main.cpp						\
			src/Menu/Menu.cpp					\
			src/Game/Game.cpp					\
			src/Object/Object.cpp				\

OBJ = 		$(SRC:.cpp=.o)

NAME = 		client

CXXFLAGS =  -Wall -std=c++17 $(INC) #-W

LDFLAGS = 	-L /path/to/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

all: 		$(OBJ)
			g++ -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			find . -name "*[#,~]" -type f -delete
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all