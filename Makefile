##
## EPITECH PROJECT, 2024
## B-OOP-400-PAR-4-1-arcade-thibaud.cathala
## File description:
## Makefile
##

SRC				:=	$(shell find src/ -name "*.cpp")

CPPFLAGS		=	-std=c++20 -Wall -Wextra $(GNU_FLAGS) \
					$(ADDITIONAL_FLAGS)

GNU_FLAGS		=	-fno-gnu-unique

INCLUDE_PATH	=	-I./include/ \
					-I./include/utils/

NAME			=	arcade

GAME_LIB		=	./game_lib/

GRAPHICAL_LIB	=	./graphical_lib/

SRC_TESTS		:=	$(shell find tests/ -name "*.cpp")

RUN_TEST		=	--coverage -lcriterion

NAME_TESTS		=	unit_tests

OBJ				=	$(SRC:.cpp=.o)

.DEFAULT_GOAL = build_all

%.o: %.cpp
	@g++ $(CPPFLAGS) $(INCLUDE_PATH) -c $< -o $@ && \
	printf "[\e[92mOK\e[0m] g++ $(CPPFLAGS) -c $< -o $@\n" || \
	printf "[\e[1;91mKO\e[0m] g++ $(CPPFLAGS) -c $< -o $@\n"

$(NAME): $(OBJ)
	@if g++ -o $(NAME) $(OBJ) $(CPPFLAGS) $(INCLUDE_PATH); then \
		printf "[\e[92mCOMPILATION OK\e[0m] "; \
		printf "g++ -o $(NAME) $(OBJ) $(CPPFLAGS)\n"; \
	else \
		printf "[\e[1;91mCOMPILATION KO\e[0m] "; \
		printf "g++ -o $(NAME) $(OBJ) $(CPPFLAGS)\n"; \
		exit 1; \
	fi

all: build_all

core_clean:
	rm -f $(OBJ) $(shell find src/ -name "*.o")
	@rm -f $(shell find src/ -name "*.gcno")
	@rm -f $(shell find src/ -name "*.gcda")
	rm -f *.gcno *.gcda gmon.out compile_commands.json

clean: core_clean
	cd $(GAME_LIB) && $(MAKE) clean
	cd $(GRAPHICAL_LIB) && $(MAKE) clean

fclean: core_clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)
	cd $(GAME_LIB) && $(MAKE) fclean
	cd $(GRAPHICAL_LIB) && $(MAKE) fclean

re: fclean all

core: $(NAME)

games:
	cd $(GAME_LIB) && $(MAKE)

graphicals:
	cd $(GRAPHICAL_LIB) && $(MAKE)

build_all: core games graphicals

unit_tests: SRC := $(patsubst src/main.cpp%,%,$(SRC))
unit_tests: fclean
	@if g++ -o $(NAME_TESTS) $(SRC_TESTS) $(SRC) \
		$(CPPFLAGS) $(RUN_TEST) $(INCLUDE_PATH); then \
		printf "[\e[92mCOMPILATION OK\e[0m] "; \
		printf "g++ -o -o $(NAME_TESTS) $(SRC_TESTS) $(SRC)"; \
		printf " $(CPPFLAGS) $(RUN_TEST)\n"; \
	else \
		printf "[\e[1;91mCOMPILATION KO\e[0m] "; \
		printf "g++ -o -o $(NAME_TESTS) $(SRC_TESTS) $(OBJ)"; \
		printf " $(CPPFLAGS) $(RUN_TEST)\n"; \
		exit 1; \
	fi

tests_run: unit_tests
	./$(NAME_TESTS)

gcovr:
	@gcovr --sort-percentage --exclude tests/
	@gcovr --sort-percentage --exclude tests/ --branches

debug: CPPFLAGS += -g3
debug: clean all
	gdb -ex "run $(arg)" -ex "bt full" -ex "detach" -ex "quit" $(NAME)

profiling: CPPFLAGS += -pg
profiling: clean all
	@printf "\e[0m------------------------------\e[0m\n"
	./$(NAME) $(arg)
	@printf "\e[0m------------------------------\e[0m\n"
	gprof $(NAME) gmon.out

compilation_database: clean
	bear -- make core GNU_FLAGS=""

code_analyse: compilation_database
	clang-tidy -header-filter=.* --use-color $(SRC)
	cd $(GAME_LIB) && $(MAKE) code_analyse
	cd $(GRAPHICAL_LIB) && $(MAKE) code_analyse

.PHONY: all clean fclean re unit_tests tests_run gcovr \
	debug profiling compilation_database code_analyse
