/*
** EPITECH PROJECT, 2022
** mylist.h
** File description:
** contains a strusture for linked list
*/

#ifndef MYLIST_H_
    #define MYLIST_H_

    typedef struct linked_list {
        void *data;
        struct linked_list *next;
    } linked_list_t;

#endif /* !MYLIST_H_ */
