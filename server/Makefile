##
## Makefile for $ in /home/mediav_j/mabm/bomberman
## 
## Made by Jérémy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Tue Jun  9 19:35:05 2015 Jérémy Mediavilla
## Last update Sat Nov  7 18:05:31 2015 Joris Bertomeu
##

CXX		=	g++

CXXFLAGS	+=	-W -Wextra -Wall -Iincludes `pkg-config --cflags libcurl`

RM		=	rm -f

SRC		=	src/main.cpp				\
			src/CurrentWindowCommand.cpp		\
			src/KeyCommand.cpp			\
			src/MouseCommand.cpp			\
			src/ResponseCommand.cpp			\

OBJ		=	$(SRC:.cpp=.o)

NOM		=	spider_server

all:		$(NOM)

$(NOM):		$(OBJ)
		@echo -e "\n > COMPILATION DES .CPP SPIDER SERVER EN COURS\n"
		$(CXX) -o $(NOM) $(OBJ) -lboost_system -lcrypto `pkg-config --libs libcurl` -std=c++11
		@echo -e "\n > COMPILATION DES .CPP SPIDER SERVER TERMINEE"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
