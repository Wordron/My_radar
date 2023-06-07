/*
** EPITECH PROJECT, 2023
** rand.c
** File description:
** rand
*/
#include <stdio.h>
#include <stdlib.h>

void main(int ac, char **av)
{
    for (int i = 0; i < atoi(av[1]); i++) {
        int departure_x = rand() % 1920;
        int departure_y = rand() % 1920;
        int arrival_x = rand() % 1080;
        int arrival_y = rand() % 1080;
        int speed = rand() % 1000;
        int delay = rand() % 40;
    
        printf("A   %i %i   %i %i   %i  %i\n", departure_x, departure_y, arrival_x, arrival_y, speed, delay);
        fflush(stdout);
    }
    int position_x = rand() % 1920;
    int position_y = rand() % 1080;
    int radius = rand() % 30;

    printf("T   %i %i   %i\n", position_x, position_y, radius);
    fflush(stdout);
}
