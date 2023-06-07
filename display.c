/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display
*/
#include "include/my.h"

void display_error(void)
{
    my_putstr("The path to the script or the script itself is incorrect\n");
    my_putstr("Retry using :\t./my_radar -h\n");
}

void display(void)
{
    my_putstr("Flight simulation program\nUsage :\t./my_radar [path and n");
    my_putstr("ame to the script]\nThe script is a text file containing the");
    my_putstr(" informations about the control towers and aircrafts\n");
    my_putstr("You can press L to hide/show or show the planes hit-boxes ");
    my_putstr("and towers area\nYou can press S to hide/show planes and tow");
    my_putstr("ers\nYou can press T to hide/show the timer\nThe simulati");
    my_putstr("on will stop automatically once all aircraft have landed\n");
}
