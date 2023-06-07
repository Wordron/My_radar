/*
** EPITECH PROJECT, 2022
** my_radar.c
** File description:
** my_radar
*/
#include <SFML/Window.h>
#include <unistd.h>
#include "include/my_radar.h"

int check_aircaft_is_done(sfRenderWindow *window, aircraft **aircraft_array,
int nb_aircraft)
{
    int nb_aircraft_done = 0;

    for (int i = 0; i < nb_aircraft; i++) {
        if (aircraft_array[i]->is_done == 1)
            nb_aircraft_done++;
    }
    if (nb_aircraft == nb_aircraft_done)
        sfRenderWindow_close(window);
}

int game_loop(sfRenderWindow *window, game_t *my_radar)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        check_colision(my_radar);
        init_display_sprite(my_radar, window);
        while (sfRenderWindow_pollEvent(window, &(my_radar->event)))
            analyse_events(window, my_radar);
        for (int i = 0; i < my_radar->nb_aircraft; i++)
            move_aircraft(my_radar->aircraft_array[i], my_radar->take_off);
        check_aircaft_is_done(window, my_radar->aircraft_array,
        my_radar->nb_aircraft);
        sfRenderWindow_display(window);
    }
}

int game(char *filepath)
{
    game_t *my_radar = malloc(sizeof(game_t));
    sfRenderWindow *window = create_window(1920, 1080);

    my_radar->take_off = malloc(sizeof(t__time));
    my_radar->take_off->clock = sfClock_create();
    my_radar->is_l_pressed = 1;
    my_radar->is_s_pressed = 1;
    my_radar->is_t_pressed = 1;
    if (get_objects_info(my_radar, filepath) != 0) {
        destroy_start(my_radar, window);
        return (84);
    }
    create_objects(my_radar);
    game_loop(window, my_radar);
    destroy_everything(my_radar, window);
    return (0);
}

int main(int ac, char **ag)
{
    if (ac != 2)
        return (84);
    if (ag[1][0] == '-' && ag[1][1] == 'h') {
        display();
        return (0);
    } else {
        if (game(ag[1]) != 0) {
            display_error();
            return (84);
        }
    }
}
