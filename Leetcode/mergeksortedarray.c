struct Tree
{
    int val;
    struct Tree *left;
    struct Tree *right;
};
void addtolinkedlist(int val, struct ListNode **header)
{
    struct ListNode *node = malloc(sizeof(*node));
    node->val = val;
    node->next = NULL;

    if (*header == NULL)
    {
        *header = node;
    }
    else
    {
        struct ListNode *temp = *header;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

struct Tree*addtotree(struct Tree *header, int val)
{

    if (header == NULL)
    {
        struct Tree *node = malloc(sizeof(*node));
        if (node == NULL)
        {
            printf("error in allocating the memroy \n");
        }
        node->val = val;
        node->left = node->right = NULL;
        return node;
    }
    else if (val > header->val)
    {
        header->right = addtotree(header->right, val);
    }
    else
    {
        header->left = addtotree(header->left, val);
    }

    return header;
}
int sortedarray(struct Tree *header, struct ListNode **headerlinkedlist)
{
    if (header == NULL)
    {
        return -1;
    }
    int val = sortedarray(header->left, headerlinkedlist);

    addtolinkedlist(header->val, headerlinkedlist);
    int vali = sortedarray(header->right, headerlinkedlist);
    return 0;
}
void freetree(struct Tree *header)
{
    if (header == NULL)
    {
        return;
    }
    freetree(header->left);
    freetree(header->right);
    free(header);
}

int value(struct ListNode **header, int *value)
{
    if (*header == NULL)
    {
        return 0;
    }
    *value = (*header)->val;
    (*header) = (*header)->next;
    return 1;
}
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    struct ListNode *header=NULL;
    struct Tree *treeheader=NULL;
    for (int i = 0; i < listsSize; i++)
    {
        int val;
        while (value(lists + i, &val))
        {
            treeheader = addtotree(treeheader, val);
        }
    }
    sortedarray(treeheader,&header);
    return header;
}
