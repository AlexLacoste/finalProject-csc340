CFLAGS		=	-Wall

CXXFLAGS	+= "-std=c++17"

CPPFLAGS	=	-I./include/

CC			=	clang++
CXX			=	clang++

LD			=	clang++

NAME		=	finalProject

MAIN		=	src/main.cpp

SRC			=	src/Course.cpp		\
				src/Person.cpp		\
				src/Professor.cpp	\
				src/Student.cpp		\


OBJ		=	$(SRC:.cpp=.o)  $(MAIN:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LD) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:		clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re