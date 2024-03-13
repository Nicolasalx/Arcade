##
## EPITECH PROJECT, 2024
## B-OOP-400-PAR-4-1-arcade-thibaud.cathala
## File description:
## Makefile
##

SRC		=	./Pacman/ \
			./Snake/ \
			./Menu/

all: $(SRC)
	@for game_dir in $^ ; do \
		cd $${game_dir} && $(MAKE) all; \
		cd - &> /dev/null; \
	done

clean: $(SRC)
	@for game_dir in $^ ; do \
		cd $${game_dir} && $(MAKE) clean; \
		cd - &> /dev/null; \
	done

fclean: $(SRC)
	@for game_dir in $^ ; do \
		cd $${game_dir} && $(MAKE) fclean; \
		cd - &> /dev/null; \
	done

re: fclean all

.PHONY: all clean fclean re
