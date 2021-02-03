/*
** EPITECH PROJECT, 2020
** my_xml.h
** File description:
** header for my_xml.c
*/

#ifndef LIBCSFML_MY_XML_H
#define LIBCSFML_MY_XML_H


typedef struct xmlnode_s{
    char *key;
    char *value;
    char *beacon;
    char *data;
} xmlnode_t;

typedef struct xml_list_s{
    xmlnode_t *node;
    xmlnode_t *parent;
    struct xml_list_s *next;
}xml_list_t;

typedef struct xml_root_s{
    xmlnode_t *node;
    xml_list_t *children;
}xml_root_t;

typedef struct xmldoc_s{
    char *xml_source;
    xml_root_t begin;
    int node_count;
} xmldoc_t;

#endif //LIBCSFML_MY_XML_H
