##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
## 

INC = 		-I ./src/Registry/  				\
			-I ./src/SparseArray/ 				\
			-I ./src/Entity/					\
			-I ./src/Components/				\
			-I ./src/Systems/					\
			-I ./src/GameEngine					\

SRC = 		src/main.cpp						\
			src/Entity/Entity.cpp				\
			src/Systems/position_system.cpp		\
			src/Systems/draw_system.cpp			\
			src/Systems/controller_system.cpp	\
			src/Systems/quit_system.cpp			\
			src/Systems/gravity_system.cpp		\
			src/Systems/shoot_system.cpp		\
			src/Systems/collide_system.cpp		\
			src/GameEngine/GameEngine.cpp		\

OBJ = 		$(SRC:.cpp=.o)

NAME = 		ecs

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
