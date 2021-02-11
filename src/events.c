/*
** EPITECH PROJECT, 2020
** events
** File description:
** move and close
*/

#include "libmy.h"

sfVector2f handle_events(sfEvent event, sfVector2f pos)
{
    sfTime time;

    time.microseconds = 50000;
    if (event.type == sfEvtMouseButtonPressed) {
        if ((event.mouseButton.x > (pos.x - 10))
        && (event.mouseButton.x < (pos.x + 95))
        && (event.mouseButton.y > (pos.y - 10))
        && (event.mouseButton.y < (pos.y + 95))) {
            sfSleep(time);
            pos.x = rand() % (1000 + 50 - 800) + 800;
            pos.y = 450;
        }
    }
    return (pos);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}