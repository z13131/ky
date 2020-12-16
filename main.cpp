#include<iostream>
using namespace std;
template<class ElemType>
struct Node
{
    ElemType date;
    Node<ElemType> *next;
    Node();
    Node(ElemType item,Node<ElemType> *Link=NULL);
};
template<class ElemType>
Node<ElemType>::Node()
{
    next=NULL;
}
template<class ElemType>
Node<ElemType>::Node(ElemType item,Node<ElemType> *Link)
{
    date =item;
    next=Link;
}
template<class ElemType>
class SimpleLinklist
{
protected:
    Node<ElemType> *head;
     Node<ElemType> *GetElemPtr( int position) const;
public:
    SimpleLinklist();
    virtual~SimpleLinklist();
    int Length()const;
    void Traverse(void(*visit)(const ElemType &))const;
    bool GetElem(int position,ElemType &e)const;
     bool SetElem(int pos,const ElemType &e);
     bool Insert(int position,const ElemType &e);
};
template<class ElemType>
Node<ElemType> *SimpleLinklist<ElemType>::GetElemPtr(int position) const
{
Node<ElemType> *tmpPtr=head;
int pos=0;
while(tmpPtr!=NULL&&pos<position)
 {tmpPtr=tmpPtr->next;
 pos++;}
if(tmpPtr!=NULL&&pos==position)
{return tmpPtr;}
else {return NULL;}
}
template<class ElemType>
SimpleLinklist<ElemType>::SimpleLinklist()
{head=new Node<ElemType>;}
template<class ElemType>
SimpleLinklist<ElemType>::~SimpleLinklist()
{
    delete head;
}
template<class ElemType>
int SimpleLinklist<ElemType>::Length() const
{int count=0;
for(Node<ElemType> *tmpPtr=head->next;tmpPtr!=NULL;tmpPtr=tmpPtr->next)
    {
      count++;
    }
    return count;
}
template<class ElemType>
void SimpleLinklist<ElemType>::Traverse(void(*visit)(const ElemType &))const
{
    for(Node<ElemType> *temPtr=head->next;temPtr!=NULL;temPtr=temPtr->next)
    {
        (*visit)(temPtr->date);
    }
}
template<class ElemType>
       bool SimpleLinklist<ElemType>::GetElem(int position, ElemType &e) const
       {
           if (position<1||position>Length())
           {
               return false;
           }
           else
           {
               Node<ElemType> * tmpPtr;
               tmpPtr=GetElemPtr(position);
               e=tmpPtr->date;
               return true;
           }
       }
template<class ElemType>
bool SimpleLinklist<ElemType>::SetElem(int pos,const ElemType &e)
{
    if(pos<1||pos>Length())
    {
        return false;
    }
    else{
        Node<ElemType> *temPtr;
        temPtr=GetElemPtr(pos);
        temPtr->date=e;
        return true;
    }
}
template<class ElemType>
       bool SimpleLinklist<ElemType>::Insert(int position,const ElemType &e)
       {
           if (position<1||position>Length()+1)
           {//cout<<"1";
               return false;
           }
           else
           {//cout<<"2";
               Node<ElemType> * tmpPtr;
               tmpPtr=GetElemPtr(position-1);
               Node<ElemType> *newPtr;
               newPtr=new Node<ElemType>(e, tmpPtr->next);
               tmpPtr->next=newPtr;
               return true;
           }
       }
   template<class ElemType>
void print(const ElemType &i)
{

    cout<<i<<endl;

}
template<class ElemType>
void Reverse(SimpleLinklist<ElemType> &la)
{
    ElemType a,b;
    for(int pos=1;pos<=la.Length()/2;pos++)
    {
        la.GetElem(pos, a);
        la.GetElem(la.Length()-pos+1, b);
        la.SetElem(pos, b);
        la.SetElem(la.Length()-pos+1,a);
    }
}
int main(int argc,char *argv[])
{
    SimpleLinklist<int> simplelinklist;
    simplelinklist.Insert(1,10);
    simplelinklist.Insert(2,20);
    simplelinklist.Insert(3,30);
    simplelinklist.Insert(4,40);
    simplelinklist.Insert(5,50);
    simplelinklist.Insert(6,60);
    simplelinklist.Length();
    cout<<"First£»"<<endl;
    simplelinklist.Traverse(print);
    cout<<endl;
    Reverse(simplelinklist);
    cout<<"Changed:"<<endl;
    simplelinklist.Traverse(print);
    return 0;
}
