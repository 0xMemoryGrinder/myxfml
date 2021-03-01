/*
** EPITECH PROJECT, 2020
** load_text_component.c
** File description:
** load_text_component.c
*/

#include "my_xml.h"
#include "utils/init/entity/components/texts/load_texts_component.h"
#include "my.h"
#include "my_puterr.h"
#include "utils/init/common_tags.h"

int load_texts_toggle(xmlnode_t *node, texts_t *texts)
{
    int status = 1;
    texts->toggle = xml_toggle("toggle", node, &status);

    if (!status)
        return 0;
    return 1;
}

int load_text_rs_linked(xmlnode_t *node, text_t *text)
{
    int status = 1;
    text->is_rslinked = xml_toggle("rs_linked", node, &status);

    if (!status)
        return 0;
    return 1;
}

text_t load_text(xmlnode_t *node, int *status)
{
    text_t text;
    text.text = sfText_create();

    if (!load_text_id(node, &text) || !load_text_toggle(node, &text) ||
    !load_text_rs_linked(node, &text) || !load_text_font(node, &text) ||
    !load_text_position(node, &text) || !load_text_font_size(node, &text) ||
    !load_text_string(node, &text)) {
        *status = 0;
        return text;
    }
    if (text.is_rslinked)
        if (!load_text_offset(node, &text)) {
            *status = (int)*my_puterr("Missing text offset",
            __FILE__, __LINE__);
            return text;
        }
    sfText_setCharacterSize(text.text, text.size);
    sfText_setString(text.text, text.string);
    sfText_setPosition(text.text, text.pos);
    return text;
}

int load_texts_list(xmlnode_t *node, texts_t *texts)
{
    int good = 1;
    texts->count = node->children.size;
    texts->text = malloc_text_array(node->children.size);

    if (texts->text == NULL)
        return 0;
    for (int n = 0; n < node->children.size; n++) {
        if (my_strcmp(node->children.data[n]->tag, "text"))
            return (int)my_puterr("Unknown sound tag", __FILE__, __LINE__);
        texts->text[n] = load_text(node->children.data[n], &good);
        if (!good)
            return 0;
    }
    return 1;
}

int load_texts_component(xmlnode_t *node, components_t *components)
{
    components->texts = malloc_text_struct();

    if (components->texts == NULL ||
        !load_texts_toggle(node, components->texts) ||
        !load_texts_list(node, components->texts))
        return 0;
    return 1;
}