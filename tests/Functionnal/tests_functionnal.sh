#!/bin/bash

RETURN_VALUE=0

check_return_success()
{
    if [ $? -eq 0 ]; then
        echo -e "[\e[92mPASS\e[0m]"
    else
        echo -e "[\e[91mFAIL\e[0m]"
        RETURN_VALUE=1
    fi
}

check_return_failure()
{
    if [ $? -eq 84 ]; then
        echo -e "[\e[92mPASS\e[0m]"
    else
        echo -e "[\e[91mFAIL\e[0m]"
        RETURN_VALUE=1
    fi
}

i_test=1

test_name()
{
    echo -e "Test[\e[95m$i_test\e[0m] $1"
    ((i_test++))
}

make

test_name "Check arcade_pacman.so"
ls ./lib/arcade_pacman.so &> /dev/null
check_return_success

test_name "Check arcade_snake.so"
ls ./lib/arcade_snake.so &> /dev/null
check_return_success

test_name "Check arcade_sdl2.so"
ls ./lib/arcade_sdl2.so &> /dev/null
check_return_success

test_name "Check arcade_sfml.so"
ls ./lib/arcade_sfml.so &> /dev/null
check_return_success

test_name "Check arcade_ncurses.so"
ls ./lib/arcade_ncurses.so &> /dev/null
check_return_success

test_name "Check arcade_menu.so"
ls ./lib/arcade_menu.so &> /dev/null
check_return_success

exit $RETURN_VALUE
