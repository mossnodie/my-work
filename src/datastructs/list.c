/**
 * @description  C语言泛型链表 C language generic list
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         list.c
 * @date         2019-01-06
 */

#include "list.h"

STATUS _new_list(list *_self, int data_size) {
    p_list pl = (p_list) malloc(sizeof(list));
    if (!pl) return OVERFLOW;
    pl->data_size = data_size;
    pl->length = 0;
    pl->head = NULL;
    *_self = *pl;
    free(pl);
    return SUCCESS;
}

STATUS _list_head_push(list *_self, void *data) {
    return _list_insert(_self, data, 1);
}

STATUS _list_back_push(list *_self, void *data) {
    /*return _list_insert(_self, data, _list_get(_self->length));*/
    if (!_self->head) {
        list_node *pn = (list_node *) malloc(sizeof(list_node));
        if (!pn) return OVERFLOW;
        pn->data = malloc(_self->data_size);
        if (!pn->data) return OVERFLOW;
        pn->next = NULL;
        memcpy(pn->data, data, _self->data_size);
        _self->head = pn;
        ++_self->length;
        return SUCCESS;
    }
    list_node *pn = (list_node *) malloc(sizeof(list_node));
    if (!pn) return OVERFLOW;
    pn->data = malloc(_self->data_size);
    if (!pn->data) return OVERFLOW;
    pn->next = NULL;
    memcpy(pn->data, data, _self->data_size);
    list_node *ln = _self->head;
    while (ln->next) { ln = ln->next; }
    ln->next = pn;
    ++_self->length;
    return SUCCESS;
}

void *_list_get(list _self, int i) {
    if (i > _self.length || i <= 0) {
        return NULL;
    }
    void *res = malloc(sizeof(_self.data_size));
    list_node *n = _self.head;
    while (i - 1 > 0) {
        n = n->next;
        i--;
    }
    memcpy(res, n->data, _self.data_size);
    return res;
}

STATUS _list_remove(list *_self, int i) {
    if (i > _self->length || i <= 0) {
        return ERROR;
    }
    list_node *n = _self->head;
    if (i == 1) {
        if (_self->length == 1) {
            free(_self->head);
            _self->head = NULL;
            --_self->length;
            return SUCCESS;
        } else {
            _self->head = _self->head->next;
            free(n);
            --_self->length;
            return SUCCESS;
        }
    } else {
        while (i - 2 > 0) {
            n = n->next;
            i--;
        }
        free(n->next);
        n->next = n->next->next;
        --_self->length;
        return SUCCESS;
    }
}

STATUS _list_insert(list *_self, void *data, int i) {
    if (i == 1 && _self->length == 0) {
        list_node *pn = (list_node *) malloc(sizeof(list_node));
        pn->data = malloc(_self->data_size);
        memcpy(pn->data, data, _self->data_size);
        _self->head = pn;
        _self->head->next = NULL;
        ++_self->length;
        return SUCCESS;
    }
    if (i > _self->length || i <= 0) {
        return ERROR;
    }
    list_node *n = _self->head;
    list_node *pn = (list_node *) malloc(sizeof(list_node));
    pn->data = malloc(_self->data_size);
    memcpy(pn->data, data, _self->data_size);
    if (i == 1) {
        pn->next = n;
        _self->head = pn;
        ++_self->length;
        return SUCCESS;
    }
    while (i - 2 > 0) {
        n = n->next;
        i--;
    }
    pn->next = n->next;
    n->next = pn;
    ++_self->length;
    return SUCCESS;
}