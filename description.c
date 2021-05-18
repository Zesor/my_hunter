/*
** EPITECH PROJECT, 2020
** desp
** File description:
** desp
*/

#include <unistd.h>

void description(void)
{
    write(1, "Welcome to My_Hunter !\n", 23);
    write(1, "I will show you a short description of my game.\n", 47);
    write(1, "The purpose of the game is to shoot on the duck ", 48);
    write(1, "and try to kill them.\n", 22);
    write(1, "To do this you have to use the mouse with the left click.\n", 23);
    write(1, "I know the game isn't perfect but i try my best.\n", 49);
    write(1, "HAVE A NICE GAME !!! :)\n", 23);
}