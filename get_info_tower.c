/*
** EPITECH PROJECT, 2022
** get_info_tower.c
** File description:
** get_info_tower
*/
#include "include/my_radar.h"

int check_char(char buffer)
{
    if (buffer != ' ' && buffer != '\t' && buffer != '\n' && buffer != '\0'
    && (buffer < '0' || buffer > '9'))
        return (-1);
    return (0);
}

int get_tower_position(game_t *my_radar, char *buffer, int i)
{
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->control_array[my_radar->curent_tower]->tower_position.x =
        my_radar->control_array[my_radar->curent_tower]->tower_position.x * 10
        + (buffer[i] - 48);
        i++;
    }
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->control_array[my_radar->curent_tower]->tower_position.y =
        my_radar->control_array[my_radar->curent_tower]->tower_position.y * 10
        + (buffer[i] - 48);
        i++;
    }
    if (check_char(buffer[i] == -1))
        return (-1);
    return (i);
}

int get_info_tower(game_t *my_radar, char *buffer, int i)
{
    my_radar->control_array[my_radar->curent_tower]->tower_position.x = 0;
    my_radar->control_array[my_radar->curent_tower]->tower_position.y = 0;
    my_radar->control_array[my_radar->curent_tower]->radius = 0;
    i = get_tower_position(my_radar, buffer, i);
    if (i == -1)
        return (84);
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->control_array[my_radar->curent_tower]->radius =
        my_radar->control_array[my_radar->curent_tower]->radius * 10
        + (buffer[i] - 48);
        i++;
    }
    if (check_char(buffer[i] == -1))
        return (-1);
    return (i + 1);
}
