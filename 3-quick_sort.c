#include "sort.h"
void swap(listint_t *a, listint_t *b) {
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

listint_t *partition(listint_t *low, listint_t *high) {
    int pivot = high->n;
    listint_t *i = low->prev;

    for (listint_t *j = low; j != high; j = j->next) {
        if (j->n <= pivot) {
            i = (i == NULL) ? low : i->next;
            swap(i, j);
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i, high);
    return i;
}

void quick_sort(listint_t *low, listint_t *high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        listint_t *pivot = partition(low, high);
        quick_sort(low, pivot->prev);
        quick_sort(pivot->next, high);
    }
}

void print_list(const listint_t *list) {
    while (list != NULL) {
        printf("%d", list->n);
        if (list->next != NULL) {
            printf(", ");
        }
        list = list->next;
    }
    printf("\n");
}

