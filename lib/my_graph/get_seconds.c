/*
** EPITECH PROJECT, 2022
** get_seconds.c
** File description:
** get the time that as passed in seconds
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "./my_graph.h"

float get_seconds(struct time *time)
{
    time->time = sfClock_getElapsedTime(time->clock);
    time->seconds = time->time.microseconds / 1000000.0;
    return (time->seconds);
}
