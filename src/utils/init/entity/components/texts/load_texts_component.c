/*
** EPITECH PROJECT, 2020
** load_text_component.c
** File description:
** load_text_component.c
*/

#include <stdbool.h>
#include "../../../../../../include/utils/init/entity/components/texts/load_texts_component.h"
#include "../../../../../../include/utils/init/load_file.h"
#include "../../../../../../include/my.h"
#include "../../../../my_puterr.h"
#include "../../../common_tags.h"
#include "set_text_properties.h"

void set_texts_toggle(char *content, int *i, texts_t *texts)
{
    texts->toggle = fill_toogle(content, i);
}

void set_text_rs_linked(char *content, int *i, text_t *text)
{
    text->rs_linked = fill_toogle(content, i);
}

text_t load_text(char *content, int *i)
{
    text_t text;
    int k;

    skip_to_next_tag(content, i, false);
    while (my_strncmp(content + *i, "</text>", 7)) {
        k = 0;
        while (text_conf_tag_action[k].tag && my_strncmp(content + *i,
                                                         text_conf_tag_action[k].tag, text_conf_tag_action[k].tag_len))
            k++;
        if (!text_conf_tag_action[k].tag)
            my_puterr("Unrecognized texts tag", __FILE__, __LINE__);
        *i += text_conf_tag_action[k].tag_len;
        text_conf_tag_action[k].action(content, i, &text);
        *i += text_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, false);
    }
    text.text = sfText_create();
    return text;
}

void load_texts_list(char *content, int *i, texts_t *texts)
{
    texts->count = my_getnbr(content + *i);
    texts->text = malloc_text_array(texts->count);

    skip_to_next_tag(content, i, false);
    for (int n = 0; n < texts->count; n++) {
        texts->text[n] = load_text(content, i);
    }
}

void load_texts_component(char *content, int *i, components_t *components)
{
    components->texts = malloc_text_struct();
    int k;

    skip_to_next_tag(content, i, false);
    while (my_strncmp(content + *i, "</texts>", 8)) {
        k = 0;
        while (texts_conf_tag_action[k].tag && my_strncmp(content + *i,
        texts_conf_tag_action[k].tag, texts_conf_tag_action[k].tag_len))
            k++;
        if (!texts_conf_tag_action[k].tag)
            my_puterr("Unrecognized texts tag", __FILE__, __LINE__);
        *i += texts_conf_tag_action[k].tag_len;
        texts_conf_tag_action[k].action(content, i, components->texts);
        *i += texts_conf_tag_action[k].tag_len + 1;
        skip_to_next_tag(content, i, false);
    }
}