##
## EPITECH PROJECT, 2024
## B-OOP-400-PAR-4-1-arcade-thibaud.cathala
## File description:
## Makefile
##

SRC		=	./ncurses/ \
			./sfml/ \
			./sdl2/

all: $(SRC)
	@for graphical_lib in $^ ; do \
		cd $${graphical_lib} && $(MAKE) all; \
		cd - &> /dev/null; \
	done

clean: $(SRC)
	@for graphical_lib in $^ ; do \
		cd $${graphical_lib} && $(MAKE) clean; \
		cd - &> /dev/null; \
	done

fclean: $(SRC)
	@for graphical_lib in $^ ; do \
		cd $${graphical_lib} && $(MAKE) fclean; \
		cd - &> /dev/null; \
	done

re: fclean all

code_analyse: $(SRC)
	@for graphical_lib in $^ ; do \
		cd $${graphical_lib} && $(MAKE) code_analyse; \
		cd - &> /dev/null; \
	done

.PHONY: all clean fclean re code_analyse
