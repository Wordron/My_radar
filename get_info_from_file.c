/*
** EPITECH PROJECT, 2022
** get_info_from_file.c
** File description:
** get_info_from_file
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "include/my_radar.h"

int get_info_from_line(game_t *my_radar, char *buffer, int i)
{
    if (buffer[i] == 'A') {
        i++;
        i = get_info_aircraft(my_radar, buffer, i);
        if (i == -1)
            return (-1);
        my_radar->curent_aircaft++;
        return (i);
    }
    if (buffer[i] == 'T') {
        i++;
        i = get_info_tower(my_radar, buffer, i);
        if (i == -1)
            return (-1);
        my_radar->curent_tower++;
        return (i);
    }
    return (-1);
}

int get_nb_aircraft_and_tower(game_t *my_radar, char *buffer)
{
    my_radar->nb_tower = 0;
    my_radar->nb_aircraft = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'A')
            my_radar->nb_aircraft++;
        if (buffer[i] == 'T')
            my_radar->nb_tower++;
    }
}

void allocate_tower_and_aircraft(game_t *my_radar, char *buffer)
{
    get_nb_aircraft_and_tower(my_radar, buffer);
    my_radar->aircraft_array = malloc(sizeof(aircraft *)
    * my_radar->nb_aircraft);
    for (int i = 0; i < my_radar->nb_aircraft; i++)
        my_radar->aircraft_array[i] = malloc(sizeof(aircraft));
    my_radar->control_array = malloc(sizeof(control_tower *)
    * my_radar->nb_tower);
    for (int i = 0; i < my_radar->nb_tower; i++)
        my_radar->control_array[i] = malloc(sizeof(control_tower));
    my_radar->curent_aircaft = 0;
    my_radar->curent_tower = 0;
}

void free_and_close(int fd, char *buffer)
{
    close(fd);
    free(buffer);
}

int get_objects_info(game_t *my_radar, char *filepath)
{
    struct stat stock;
    int error = stat(filepath, &stock);
    char *buffer = malloc(sizeof(char) * (stock.st_size + 1));
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        free(buffer);
        return (84);
    }
    error = read(fd, buffer, stock.st_size);
    allocate_tower_and_aircraft(my_radar, buffer);
    for (int i = 0; buffer[i] != '\0';) {
        i = get_info_from_line(my_radar, buffer, i);
        if (i == -1) {
            free_and_close(fd, buffer);
            return (84);
        }
    }
    free_and_close(fd, buffer);
    return (0);
}
