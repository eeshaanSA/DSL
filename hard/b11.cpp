#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char k[20];
    char m[20];
    node *lt, *rt;
};

class Dict
{

public:
    node *root;
    
    void create()
    {
        int n;
        cout << "enter the no> of keywords you want to enter : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            insert();
        }
    }
    void insert()
    {
        node *curr, *temp;
        curr = new node;
        cout << "Enter the key;";
        cin >> curr->k;
        cout << "Enter the meaning :";
        cin >> curr->m;
        curr->lt = curr->rt = NULL;
        if (root == NULL)
        {
            root = curr;
        }
        else
        {
            temp = root;
            while (1)
            {
                if (strcmp(temp->k, curr->k) < 0)
                {
                    if (temp->rt == NULL)
                    {
                        temp->rt = curr;
                        break;
                    }
                    else
                    {
                        temp = temp->rt;
                    }
                }
                else
                {
                    if (temp->lt == NULL)
                    {
                        temp->lt = curr;
                        break;
                    }
                    else
                    {
                        temp = temp->lt;
                    }
                }
            }
        }
    }
    void display(node *r1)
    {
        if (r1 != NULL)
        {
            display(r1->lt);
            cout << r1->k << " : " << r1->m << endl;
            display(r1->rt);
        }
    }
    void search(node *r1)
    {
        cout << "enter the element :";
        char b[20];
        cin >> b;
        node *temp;
        int cnt = 0;
        temp = r1;
        while (temp != NULL)
        {
            cnt++;
            if (strcmp(b, temp->k) == 0)
            {
                cout << "Key found" << endl;
                cout << temp->k << ":" << temp->m << endl;
                cout << "comparisaons : " << cnt;
                break;
            }
            else
            {
                if (strcmp(b, temp->k) < 0)
                {
                    temp = temp->lt;
                }
                else
                {
                    temp = temp->rt;
                }
            }
        }
        if (temp == NULL)
        {
            cout << "NO NUMBER FOUND" << endl;
        }
    }

    void update(node *r1)
    {
        char a[20];
        cout << "ENter the key you want to update : ";
        cin >> a;
        node *temp;
        temp = r1;
        while (temp != NULL)
        {
            if (strcmp(a, temp->k) == 0)
            {
                cout << "Key found" << endl;
                cout << "Enter the new meaning  : ";
                cin >> temp->m;
                break;
            }
            else
            {
                if (strcmp(a, temp->k) < 0)
                {
                    temp = temp->lt;
                }
                else
                {
                    temp = temp->rt;
                }
            }
        }
        if (temp == NULL)
        {
            cout << "NO NUMBER FOUND" << endl;
        }
    }
    node *delete1(node *r1, char c[20])
    {

         node *temp;
        if (r1 == NULL)
        {
            cout << "NO ELEMENT FOUND" << endl;
            return r1;
        }
        if (strcmp(c, r1->k) < 0)
        {

            r1->lt = delete1(r1->lt, c);
            return r1;
        }
        if (strcmp(c, r1->k) > 0)
        {

            r1->rt = delete1(r1->rt, c);
            return r1;
        }
        if (r1->rt == NULL && r1->lt == NULL)
        {
            temp = r1;
            delete temp;
            return NULL;
        }
        if (r1->rt == NULL)
        {
            temp = r1;
            r1 = r1->lt;
            delete temp;
            return r1;
        }
        else if (r1->lt == NULL)
        {
            temp = r1;
            r1 = r1->rt;
            delete temp;
            return r1;
        }
        temp = min(r1->rt);
        strcpy(r1->k, temp->k);
        r1->rt = delete1(r1->rt, temp->k);
        return r1;
    }
    node *min(node *q)
    {
        while (q->lt != NULL)
        {
            q = q->lt;
        }
        return q;
    }
};

int main()
{
    Dict d;
    d.root=NULL;
    int ch;
    int ch1;
    do
    {
        cout << "enter a choice : "
             << "\n"
             << "1.create,2.insert,3.display,4.update,5.search,6.delete" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            d.create();
            break;
        case 2:
            d.insert();
            break;
        case 3:
            d.display(d.root);
            break;
        case 4:
            cout << "in" << endl;
            d.update(d.root);
            break;
        case 5:
            d.search(d.root);
            break;
        case 6:
            char c[20];
            cout << "Enter the key to be deleted";
            cin >> c;
            d.root=d.delete1(d.root, c);

            break;
        }
        cout << "Do you want to continue(1 for continue) : ";
        cin >> ch1;
    } while (ch1 == 1);
    return 0;
}