/*
** EPITECH PROJECT, 2022
** get_info_aircraft.c
** File description:
** get_info_aircraft
*/
#include "include/my_radar.h"

int get_position_departure(game_t *my_radar, char *buffer, int i)
{
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->aircraft_array[my_radar->curent_aircaft]->departure.x =
        my_radar->aircraft_array[my_radar->curent_aircaft]->departure.x * 10
        + (buffer[i] - 48);
        i++;
    }
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->aircraft_array[my_radar->curent_aircaft]->departure.y =
        my_radar->aircraft_array[my_radar->curent_aircaft]->departure.y * 10
        + (buffer[i] - 48);
        i++;
    }
    if (check_char(buffer[i] == -1))
        return (-1);
    return (i);
}

int get_position_arrival(game_t *my_radar, char *buffer, int i)
{
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->aircraft_array[my_radar->curent_aircaft]->arrival.x =
        my_radar->aircraft_array[my_radar->curent_aircaft]->arrival.x * 10
        + (buffer[i] - 48);
        i++;
    }
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->aircraft_array[my_radar->curent_aircaft]->arrival.y =
        my_radar->aircraft_array[my_radar->curent_aircaft]->arrival.y * 10
        + (buffer[i] - 48);
        i++;
    }
    if (check_char(buffer[i] == -1))
        return (-1);
    return (i);
}

int get_speed_and_delay(game_t *my_radar, char *buffer, int i)
{
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->aircraft_array[my_radar->curent_aircaft]->speed =
        my_radar->aircraft_array[my_radar->curent_aircaft]->speed
        * 10 + (buffer[i] - 48);
        i++;
    }
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i++;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        my_radar->aircraft_array[my_radar->curent_aircaft]->delay_take_off =
        my_radar->aircraft_array[my_radar->curent_aircaft]->delay_take_off
        * 10 + (buffer[i] - 48);
        i++;
    }
    if (check_char(buffer[i] == -1))
        return (-1);
    return (i);
}

int get_info_aircraft(game_t *my_radar, char *buffer, int i)
{
    my_radar->aircraft_array[my_radar->curent_aircaft]->departure.x = 0;
    my_radar->aircraft_array[my_radar->curent_aircaft]->departure.y = 0;
    my_radar->aircraft_array[my_radar->curent_aircaft]->arrival.x = 0;
    my_radar->aircraft_array[my_radar->curent_aircaft]->arrival.y = 0;
    my_radar->aircraft_array[my_radar->curent_aircaft]->speed = 0;
    my_radar->aircraft_array[my_radar->curent_aircaft]->delay_take_off = 0;
    i = get_position_departure(my_radar, buffer, i);
    if (i == -1)
        return (-1);
    i = get_position_arrival(my_radar, buffer, i);
    if (i == -1)
        return (-1);
    i = get_speed_and_delay(my_radar, buffer, i);
    if (i == -1)
        return (-1);
    return (i + 1);
}
