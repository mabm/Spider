##
## Makefile for $ in /home/mediav_j/mabm/bomberman
## 
## Made by Jérémy Mediavilla
## Login   <mediav_j@epitech.net>
## 
## Started on  Tue Jun  9 19:35:05 2015 Jérémy Mediavilla
## Last update Wed Oct 21 10:55:24 2015 Joris Bertomeu
##

CXX		=	clang++ -g3

CXXFLAGS	+=	-W -Wextra -Wall -Iincludes

RM		=	rm -f

SRC		=	src/main.cpp				\

OBJ		=	$(SRC:.cpp=.o)

NOM		=	spider_client

all:		$(NOM)

$(NOM):		$(OBJ)
		@echo -e "\n > COMPILATION DES .CPP SPIDER CLIENT EN COURS\n"
		$(CXX) -o $(NOM) $(OBJ) -lboost_system
		@echo -e "\n > COMPILATION DES .CPP SPIDER CLIENT TERMINEE"

clean:
		@echo -e "\t->>> SUPPRESSION DES .o <<<-"
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NOM)

re:		fclean all

.PHONY:		all clean fclean re
