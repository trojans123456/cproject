#include <stdio.h>


#include <string.h>
#include <stdlib.h>

#include "event.h"


#if 0
#include "avl.h"
/**** avl test ****/

#define OUT(fmt, ...) do { \
    fprintf(stdout, "%s: " fmt, __func__, ## __VA_ARGS__); \
} while (0);

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

struct node {
    struct avl_node avl;
};

int
avl_strcmp(const void *k1, const void *k2, void *ptr)
{
    return strcmp(k1, k2);
}

static void test_basics()
{
    size_t i;
    struct avl_tree t;
    struct node *temp;
    struct node *elem;
    struct node *last;
    struct node *first;
    const char *vals[] = {
        "zero", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine", "ten", "eleven", "twelve"
    };

    avl_init(&t, avl_strcmp, false, NULL);

    OUT("insert: ");
    for (i=0; i<ARRAY_SIZE(vals); i++) {
        struct node *n = malloc(sizeof(struct node));
        n->avl.key = vals[i];

        int r = avl_insert(&t, &n->avl);
        fprintf(stdout, "%d=%s ", r, (char *)n->avl.key);
    }
    fprintf(stdout, "\n");

    OUT("insert duplicate: ");
    for (i=0; i<ARRAY_SIZE(vals); i++) {
        struct node *n = malloc(sizeof(struct node));
        n->avl.key = vals[i];

        int r = avl_insert(&t, &n->avl);
        fprintf(stdout, "%d=%s ", r, (char *)n->avl.key);

        if (r)
            free(n);
    }
    fprintf(stdout, "\n");

    first = avl_first_element(&t, first, avl);
    last = avl_last_element(&t, last, avl);
    OUT("first=%s last=%s\n", (char*)first->avl.key, (char*)last->avl.key);

    OUT("for each element: ");
    avl_for_each_element(&t, elem, avl) {
        fprintf(stdout, "%s ", (char*)elem->avl.key);
    }
    fprintf(stdout, "\n");

    OUT("delete 'one' element\n");
    elem = avl_find_element(&t, "one", elem, avl);
    avl_delete(&t, &elem->avl);
    free(elem);

    OUT("for each element reverse: ");
    avl_for_each_element_reverse(&t, elem, avl) {
        fprintf(stdout, "%s ", (char*)elem->avl.key);
    }
    fprintf(stdout, "\n");

    OUT("delete all elements\n");
    avl_for_each_element_safe(&t, elem, avl, temp) {
        avl_delete(&t, &elem->avl);
        free(elem);
    }
}
#endif

void timeout_fun(struct event_timeout *ev)
{
    printf("xxxx\n");
    event_timeout_set(ev,500);
}

int main(int argc,char *argv[])
{
#if 0
    test_basics();
#endif
    struct event_timeout timeout;
    timeout.cb = timeout_fun;



    event_loop_init();

    event_timeout_add(&timeout);
    event_timeout_set(&timeout,1000);

    event_loop_run();

    return 0;
}