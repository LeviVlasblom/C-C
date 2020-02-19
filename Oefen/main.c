struct vriend {
    char naam[MAX_NAME_LENGTH];
    int geboortedatum; //inde vorm van yyyymmdd, bijvb. 20001205
};

struct node
{
    struct vriend;
    struct node *next;
    struct node *prev;
};

