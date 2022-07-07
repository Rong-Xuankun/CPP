#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int val;
    struct Node *next;
} ListNode;

ListNode *findIntersectionListNode(ListNode *head1, ListNode *head2)
{
    ListNode *p1, *p2;
    int len1 = 0, len2 = 0, diff = 0;
    int tmp;

    p1 = head1->next;
    p2 = head2->next;
    while (p1 != NULL)
    {
        len1++;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        len2++;
        p2 = p2->next;
    }

    if (len1 < len2)
    {
        diff = len2 - len1;
        p1 = head2->next;
        p2 = head1->next;
    }
    else if (len1 > len2)
    {
        diff = len1 - len2;
        p1 = head1->next;
        p2 = head2->next;
    }
    while (diff != 0 && p1 != NULL && p2 != NULL)
    {
        p1 = p1->next;
        diff--;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
        {
            return p1;
        }
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return NULL;
}
