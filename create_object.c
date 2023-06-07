/*
** EPITECH PROJECT, 2022
** create_object.c
** File description:
** create_object
*/

#include "include/my.h"
#include "include/my_radar.h"

sfVector2f get_position_circle(sfVector2f position_tower, float radius)
{
    sfVector2f position;

    position.x = (((512 * 0.2) / 2) + position_tower.x - radius);
    position.y = (((512 * 0.2) / 2) + position_tower.y - radius);
    return (position);
}

int create_tower(control_tower *control_array)
{
    sfVector2f scale;

    scale.x = 0.2;
    scale.y = 0.2;
    control_array->radius_final = ((double) (control_array->radius * 1920) /
    100);
    control_array->control_tower_object->texture =
    sfTexture_createFromFile("./texture/tower.png", NULL);
    control_array->control_tower_object->sprite = sfSprite_create();
    sfSprite_setPosition(control_array->control_tower_object->sprite,
    control_array->tower_position);
    sfSprite_setScale(control_array->control_tower_object->sprite, scale);
    control_array->control_area = create_circle(get_position_circle(
        control_array->tower_position, control_array->radius_final),
        control_array->radius_final);
}

sfText *create_text(sfFont *font)
{
    sfText *chrono = sfText_create();
    sfVector2f position;

    font = sfFont_createFromFile("texture/roboto.ttf");
    position.x = 1820;
    position.y = 960;
    sfText_setFont(chrono, font);
    sfText_setPosition(chrono, position);
    sfText_setString(chrono, "0");
    sfText_setCharacterSize(chrono, 45);
    sfText_setColor(chrono, sfWhite);
    sfText_setFillColor(chrono, sfWhite);
    return (chrono);
}

int create_map(object_t *map)
{
    map->texture = sfTexture_createFromFile("./texture/map.png", NULL);
    map->sprite = sfSprite_create();
}

int create_objects(game_t *my_radar)
{
    for (int i = 0; i < my_radar->nb_aircraft; i++) {
        my_radar->aircraft_array[i]->aircraft_object =
        malloc(sizeof(object_t));
        my_radar->aircraft_array[i]->aircraft_time = malloc(sizeof(t__time));
        create_aircraft(my_radar->aircraft_array[i]);
    }
    for (int i = 0; i < my_radar->nb_tower; i++) {
        my_radar->control_array[i]->control_tower_object =
        malloc(sizeof(object_t));
        create_tower(my_radar->control_array[i]);
    }
    my_radar->map = malloc(sizeof(object_t));
    my_radar->chrono = create_text(my_radar->font);
    create_map(my_radar->map);
}
