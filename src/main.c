/*
** EPITECH PROJECT, 2020
** window
** File description:
** window try
*/

#include "libmy.h"

typedef struct o_s {
    sfVideoMode vide_m;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfTexture *texture_back;
    sfSprite *sprite_back;
    sfClock *clock;
    sfTime time;
    sfVector2f pos;
} o_t;

o_t initialize(o_t o)
{
    o.vide_m.width = 1920;
    o.vide_m.height = 1080;
    o.vide_m.bitsPerPixel = 32;
    o.window = sfRenderWindow_create(o.vide_m, "Rock", sfDefaultStyle, NULL);
    o.event;
    o.texture = sfTexture_createFromFile("src/notes.png", NULL);
    o.sprite = sfSprite_create();
    o.rect.top = 0;
    o.rect.left = 0;
    o.rect.width = 85;
    o.rect.height = 85;
    o.texture_back = sfTexture_createFromFile("src/black.png", NULL);
    o.sprite_back = sfSprite_create();
    o.clock = sfClock_create();
    o.time;
    o.pos.x = 800;
    o.pos.y = 450;

    return (o);
}

sfVector2f is_open(o_t o)
{
    sfRenderWindow_clear(o.window, sfBlack);
    sfSprite_setTexture(o.sprite_back, o.texture_back, sfFalse);
    sfSprite_setTextureRect(o.sprite, o.rect);
    sfSprite_setTexture(o.sprite, o.texture, sfFalse);
    o.pos.y = o.pos.y + 2.5;
    if (o.pos.y > 970) {
        o.pos.x = rand() % (1000 + 50 - 800) + 800;
        o.pos.y = 450;
    }
    sfSprite_setPosition(o.sprite, o.pos);
    sfRenderWindow_drawSprite(o.window, o.sprite_back, NULL);
    sfRenderWindow_drawSprite(o.window, o.sprite, NULL);
    return (o.pos);
}

int start(int i, float seconds, o_t o)
{
    o = initialize(o);

    while (sfRenderWindow_isOpen(o.window)) {
        sfRenderWindow_display(o.window);
        o.time = sfClock_getElapsedTime(o.clock);
        seconds = (o.time.microseconds / 1000000.0);
        if(seconds > 0.10) {
            move_rect(&o.rect, 85, 425);
            sfClock_restart(o.clock);
        }
        o.pos = is_open(o);
        while (sfRenderWindow_pollEvent(o.window, &o.event)) {
            o.pos = handle_events(o.event, o.pos);
            if (o.pos.y == 450)
                i++;
            if (o.event.type == sfEvtClosed || o.event.key.code == sfKeyEscape)
                sfRenderWindow_close(o.window);
        }
    }
    return (i);
}

int main(int ac, char **av)
{
    o_t o;
    int i = 0;
    float seconds = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'
    && (my_strlen(av[1]) == 2)) {
        my_putstr("Welcome to Rock Hard!\nRules:\n");
        my_putstr("-Press the notes before they go\n-Have fun\n");
        my_putstr("*Use left click to press the notes*\n");
        return (0);
    }
    i = start(i, seconds, o);
    my_putstr("Final Score = ");
    my_put_nbr(i);
    my_putchar('\n');
    return (0);
}
