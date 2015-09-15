// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.

struct node
{
    int key;
    int val;
    struct node *next;
    struct node *prev;
};


class LeastRecentlyUsed
{
map<int, struct node *> mp;
struct node *head=NULL;
struct node *tail=NULL;
int total;
int current=0;
public:
LeastRecentlyUsed(int c)
{
    total=c;
    
}

int get(int key)
{
    struct node *x=mp[key];
    if(!x)
    {
        mp.erase(key);
        return -1;
    }
    else if(x==head && x!=tail)
    {
        head=x->next;
        tail=x;
    }
    else if(x!=tail)
    {
        x->prev->next=x->next;
        x->next->prev=x->prev;
        tail->next=x;
        x->next=head;
        x->prev=tail;
        head->prev=x;
        tail=x;
    }
    return x->val;
}

void set(int key,int value)
{
    if(total==0)
        return;
    struct node *y=mp[key];
    if(!y)
    {
        if(current<total)
        {
            if(current==0)
            {
                struct node *temp=new struct node;
                temp->key=key;
                temp->val=value;
                temp->next=temp;
                temp->prev=temp;
                mp[key]=temp;
                head=temp;
                tail=temp;
            }
            else
            {
                struct node *temp=new struct node;
                temp->key=key;
                temp->val=value;
                temp->next=head;
                temp->prev=tail;
                tail->next=temp;
                mp[key]=temp;
                //head=temp;
                tail=temp;
                head->prev=temp;
            }
        }
        else
        {
                struct node *x=head;
                head=head->next;
                struct node *temp=new struct node;
                temp->key=key;
                temp->val=value;
                temp->next=head;
                temp->prev=tail;
                head->prev=temp;
                tail->next=temp;
                mp[key]=temp;
                tail=temp;
                mp.erase(x->key);
                delete x;
        }
        current++;
    }
    else
    {
        y->val=value;
        int r=get(y->key);
        return;
    }
}
}



