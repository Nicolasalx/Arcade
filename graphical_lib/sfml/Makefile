##
## EPITECH PROJECT, 2024
## B-OOP-400-PAR-4-1-arcade-thibaud.cathala
## File description:
## Makefile
##

SRC				:=	$(shell find src/ -name "*.cpp") \
					$(shell find ../utils/ -name "*.cpp")

CPPFLAGS		=	-std=c++20 -Wall -Wextra $(GNU_FLAGS) \
					-shared -fpic -lsfml-graphics -lsfml-window -lsfml-system \
					$(ADDITIONAL_FLAGS)

GNU_FLAGS		=	-fno-gnu-unique

INCLUDE_PATH	=	-I../../include/ \
					-I../../include/utils/ \
					-I../../include/graphical/

NAME			=	../../lib/arcade_sfml.so

OBJ				=	$(SRC:.cpp=.o)

%.o: %.cpp
	@g++ $(CPPFLAGS) $(INCLUDE_PATH) -c $< -o $@ && \
	printf "[\e[92mOK\e[0m] g++ $(CPPFLAGS) -c $< -o $@\n" || \
	printf "[\e[1;91mKO\e[0m] g++ $(CPPFLAGS) -c $< -o $@\n"

$(NAME): $(OBJ)
	@if g++ -o $(NAME) $(OBJ) $(LIB_NAME) $(CPPFLAGS) $(INCLUDE_PATH); then \
		printf "[\e[92mCOMPILATION OK\e[0m] "; \
		printf "g++ -o $(NAME) $(OBJ) $(LIB_NAME) $(CPPFLAGS)\n"; \
	else \
		printf "[\e[1;91mCOMPILATION KO\e[0m] "; \
		printf "g++ -o $(NAME) $(OBJ) $(LIB_NAME) $(CPPFLAGS)\n"; \
		exit 1; \
	fi

all: $(NAME)

clean:
	rm -f $(OBJ) $(shell find src/ -name "*.o")
	@rm -f $(shell find src/ -name "*.gcno")
	@rm -f $(shell find src/ -name "*.gcda")
	@rm -f *.gcno *.gcda gmon.out compile_commands.json

fclean: clean
	rm -f $(NAME)

re: fclean all

compilation_database: clean
	bear -- make GNU_FLAGS=""

code_analyse: compilation_database
	clang-tidy -header-filter=.* --use-color $(SRC)

.PHONY: all clean fclean re compilation_database code_analyse
