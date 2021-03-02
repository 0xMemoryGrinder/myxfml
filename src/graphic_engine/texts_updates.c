/*
** EPITECH PROJECT, 2020
** texts_updates.c
** File description:
** header for texts_updates.c
*/

#include "../../include/my_csfml.h"


sfVector2f add_vectors(sfVector2f v1, sfVector2f v2)
{
    sfVector2f new;

    new.x = v1.x + v2.x;
    new.y = v1.y + v2.y;
    return new;
}

void update_text(game_data_t *data, texts_t *texts, entity_t *entity)
{
    for (int i = 0; i < texts->count; i++) {
        if (texts->text[i].toggle == OFF)
            continue;
        if (texts->text[i].is_rslinked)
            texts->text[i].pos = add_vectors(E_TRANSFORM->position,
            texts->text[i].offset);
        sfText_setPosition(texts->text[i].text, texts->text[i].pos);
        sfRenderWindow_drawText(G_WINDOW, texts->text[i].text, NULL);
    }
}

void get_texts_updates(game_data_t *data, entity_list_t *texts)
{
    entity_list_t *list = texts;

    if (!list || list->entity == NULL)
        return;
    for (; list; list = list->next) {
        if (list->entity->toggle == OFF || list->E_TEXT->toggle == OFF)
            continue;
        update_text(data, list->E_TEXT, list->entity);
    }
}