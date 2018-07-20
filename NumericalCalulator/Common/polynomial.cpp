#include "Common/polynomial.h"

double LinkList::compute(double x) const
{
    Link *current = head;
    double result = 0;
    while (current != nullptr) {
        result += current->Num * pow(x, current->Index);
        current = current->Next;
    }
    return result;
}


LinkList::LinkList(string Equation)
{
    MAX = 0;
    for(int i =0;i<Equation.length();i++)
    {
        if(Equation[i] != ' ')
        equation+=Equation[i];
    }
    head = tail = (Link*)malloc(sizeof(Link));
    head =tail = NULL;
    try{
        if(this->analyze()==1)
            throw "abc";
        this->get();
        this->print();
    }
    catch(char *)
    {
        cout<<"incrroct input"<<endl;
    }
}
int LinkList::analyze()
{
    int t=-1;
    size_t size;
    size = equation.length();
    for(int j=0;j<size;j++)
    {
        if(t==-1&&((equation[j]>='a'&&equation[j]<='z')||(equation[j]>='A'&&equation[j]<='Z')))
        t=j;
    }
    for(int M=0;M<size;M++)
     {
        if(!((equation[M]>='0'&&equation[M]<='9')||equation[M]==equation[t]||equation[M]=='+'||equation[M]=='-'||equation[M]=='='||equation[M]=='^'))
        return 1;
     }
    if((equation[0]>'0'&&equation[0]<='9')||equation[0]==equation[t])
    {
        for(int i = 0;i<size-1;i++)
    {
        if(equation[i]>='0'&&equation[i]<='9')
        {
             if(!(equation[i+1]>'0'&&equation[i+1]<='9'||equation[i+1]==equation[t]||equation[i+1]=='='||equation[i+1]=='+'||equation[i+1]=='-'))
             return 1;
        }
         else if(equation[i]=='^')
        {
             if(!(equation[i+1]>0&&equation[i+1]<='9'))
             return 1;
         }
         else if(equation[i]=='+'||equation[i]=='-')
         {
             if(!((equation[i+1]>'0'&&equation[i+1]<='9')||equation[i+1]==equation[t]||'('))
             return 1;
         }
         else if(equation[i]==equation[t])
         {
            if(!(equation[i+1]=='^'||equation[i+1]=='+'||equation[i+1]=='-'||equation[i+1]=='='))
            return 1;
         }
         else if(equation[i]=='=')
         {
            if(!(equation[i+1]==equation[t]||(equation[i+1]>'0'&&equation[i+1]<='9')))
            return 1;
         }

    }
    return 0;
    }
    else
    return 1;
}
int LinkList::Get(int i,char x,Link *head)
{
    Link *node;
    node = head;
    while(node)
    {
        if(node->Index ==i&&node->X==x)
        return node->Num;
        node=node->Next;
    }
    return 0;
}
double LinkList::Get_coefficient(int i)
{
    return get_coefficient[i];
}
void LinkList::print()
{
    Link *node;
    node = head;
    while(node)
    {
        cout<<node->Num<<" "<<node->X<<" "<<node->Index<<endl;
        node = node->Next;
        }
}
Link * LinkList::get(){
    int j = 0,m = 0,k =1 ,Operator = 1;
    for(int i = 0; i < equation.length(); i ++)
    {

            Link *newLinkList;
            newLinkList = (Link*)malloc(sizeof(Link));
            newLinkList->Next = NULL;
            while(equation[i]<='9'&&equation[i]>='0'){i++;j++;}
            while(j>0){m+=(equation[i-j]-48)*pow(10,j-1);j--;}
            if(!m) m = 1;
            newLinkList->Num = m * k *Operator;
            m = 0;
            if((equation[i]>='a'&&equation[i]<='z')||(equation[i]>='A'&&equation[i]<='Z'))
            {
                newLinkList->X = equation[i];
                i++;
                if(equation[i]=='^') {newLinkList->Index=equation[i+1]-48;i+=2;}
                else newLinkList->Index = 1;
            }
            else{newLinkList->X = 0;newLinkList->Index=0;}
            if(equation[i]=='-')k = -1;
            if(equation[i]=='+')k = 1;
            else if(equation[i]=='=')
            Operator = -Operator;
            MAX =( MAX>newLinkList->Index) ? MAX:newLinkList->Index;
            get_coefficient[newLinkList->Index]=newLinkList->Num;
            head = Rank(head,newLinkList);
    }
            return head;
}
Link * LinkList::Rank(Link *head,Link *node)
{
    Link * temp = head;
    if(head == NULL)
    {
        head = node;
    }
    else{
        if(node->Index>temp->Index)
        {
            node->Next = head;
            head = node;
        }
        else
        {
           while(temp->Next!=NULL)
            {
               if(node->Index<temp->Index&&node->Index>temp->Next->Index)
               {
                   node->Next=temp->Next;
                   temp->Next=node;
                   break;
               }
               temp=temp->Next;
            }
            if(temp->Next == NULL)
            temp->Next = node;
        }
    }
    return head;
}
