#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////
//
//
//---------------------STRUCTURES FOR NODE CREATION---------------------
//
//
////////////////////////////////////////////////////////////////////////

//---------------------SINGLY LINEAR LINKED LIST-------------------------
template <class T>
struct node
{
    T data;
    struct node *next;
};

//---------------------DOUBLY LINEAR LINKED LIST-------------------------
template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

//---------------------SINGLY CIRCULAR LINKED LIST-------------------------
template <class T>
struct nodeSC 
{
    T data;
    struct nodeSC *next;
};

//---------------------DOUBLY CIRCULAR LINKED LIST-------------------------
template<class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

//---------------------STACK-------------------------
template <class T>
struct nodeS
{
    int data;
    struct nodeS *next;
};

//---------------------QUEUE------------------------
template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};


/////////////////////////////////////////////////////////////////////////
//
//
//---------------------SINGLY LINEAR LINKED LIST-------------------------
//
//
////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct node<T> * head;
        int iCount;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new node<T>;    
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no , int ipos)
{
    int i = 0;
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;

        for(i =1; i< ipos -1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        head = head -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    int i = 0;
    struct node<T> * temp = NULL;
    struct node<T> * target = NULL;

    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(i =1; i< ipos -1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp -> next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    struct node<T> * temp = head;

    cout<<"Elements of LinkedList are : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

/////////////////////////////////////////////////////////////////////////
//
//
//---------------------DOUBLY LINEAR LINKED LIST-------------------------
//
//
////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLLL
{
    public :
        struct nodeDL<T>* head;        //Characteristics of doubly linear linked list
        int iCount;
        DoublyLLL();         //Constructor        

//----------------------DISPLAY, COUNT FUNCTIONS-----------------------------------
        void Display();
        int Count();

//-----------------------INSERT FUNCTIONS-------------------------------------
        void InsertFirst(T no) ;         //InsertFirst
        void InsertLast(T no) ;           //InsertLast
        void InsertAtPos(T no,int ipos);   //InsertAtPos

//-----------------------DELETE FUNCTIONS-------------------------------------
        void DeleteFirst() ;                 //DeleteFirst
        void DeleteLast() ;                  //DeleteLast
        void DeleteAtPos(int ipos) ;         //DeleteAtPos

};

template <class T>
DoublyLLL<T>::DoublyLLL()         //Constructor        
        {
            head = NULL; 
            iCount=0;  
        }

//----------------------DISPLAY, COUNT FUNCTIONS-----------------------------------

template <class T>
void DoublyLLL<T>:: Display()
        {
            struct nodeDL<T>* temp= head;

            cout<<"ELements in linked list are :\n";
            while(temp != NULL)
            {
                cout<<"|"<<temp->data<<"| -> ";
                temp = temp -> next;
            }
            cout<<"NULL\n";

        }

template <class T>
int DoublyLLL<T>:: Count()
        {
            return iCount;
        }


//-----------------------INSERT FUNCTIONS-------------------------------------

template <class T>
void DoublyLLL<T>:: InsertFirst(T no)            //InsertFirst
        {
            struct nodeDL<T>* newn = NULL;

            newn = new nodeDL<T>;
            newn -> next =  NULL;
            newn -> prev = NULL;
            newn -> data = no;

            if(head==NULL)
            {
                head = newn;
            }
            else
            {
                newn->next = head;
                head = newn;
            }
            iCount++;
        }

template <class T>
void DoublyLLL<T>:: InsertLast(T no)             //InsertLast
        {
            struct nodeDL<T>* newn = NULL;
            struct nodeDL<T>* temp = head;

            newn = new nodeDL<T>;
            newn -> next =  NULL;
            newn -> prev = NULL;
            newn -> data = no;

            if(temp==NULL)
            {
                temp = newn;
            }
            else
            {
               while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                newn->prev = temp;
                temp->next = newn;
            }  
            iCount++; 
        }

template <class T>    
void DoublyLLL<T>:: InsertAtPos(T no,int ipos)   //InsertAtPos
        {
            struct nodeDL<T>* temp = head;
            struct nodeDL<T>* newn = NULL;
            newn = new nodeDL<T>;
            newn->data = no;
            int i = 0;

            if(ipos<=0 && ipos>iCount+1)
            {
                cout<<"Enter valis position"<<"\n";
            }

            if(ipos==1)
            {
                InsertFirst(no);
            }
            else if(ipos==iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                for(i=1; i<ipos-1; i++)
                {
                    temp = temp->next;
                }

                newn->next= temp->next;
                newn->prev = temp;
                temp->next = newn;
            }
            iCount++;                                   
        }

//-----------------------DELETE FUNCTIONS-------------------------------------

template <class T>
void DoublyLLL<T>:: DeleteFirst()                  //DeleteFirst
        {
            struct nodeDL<T>* temp=head;

            if(head==NULL)
            {
                return;
            }
            else if(head->next==NULL)
            {
                delete head;
                head=NULL;
            }
            else
            {
                temp = head->next;
                delete head;
                head = temp;
            }
            iCount--;
        }

template <class T>
void DoublyLLL<T>:: DeleteLast()                   //DeleteLast
        {
            struct nodeDL<T>* temp=head;

            if(head==NULL)
            {
                return;
            }
            else if(head->next==NULL)
            {
                delete head;
                head=NULL;
            }
            else
            {
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                
                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
            
        }

template <class T>
void DoublyLLL<T>:: DeleteAtPos(int ipos)          //DeleteAtPos
        {
            struct nodeDL<T>* temp = head;
            struct nodeDL<T>* target = NULL;

            int i = 0;

            if(ipos<=0 && ipos>iCount)
            {
                return;
            }

            if(ipos==1)
            {
                DeleteFirst();
            }
            else if(ipos==iCount)
            {
                DeleteLast();
            }
            else
            {
                for(i=1; i< ipos-1; i++)
                {
                    temp = temp->next;
                }

                target = temp->next;
                temp->next = target->next;
                target->next->prev = temp;
                delete target;
            }
            iCount--;          
            
        }



/////////////////////////////////////////////////////////////////////////
//
//
//---------------------SINGLY CIRCULAR LINKED LIST-------------------------
//
//
////////////////////////////////////////////////////////////////////////


template <class T>
class SinglyCLL
{
    public :
        struct nodeSC<T>* head;
        struct nodeSC<T>* tail;
        int iCount;

        SinglyCLL();       

//--------------------------------DISPLAY, COUNT-----------------------------
        void Display();

        int Count();

//----------------------------INSERT FUNCTIONS---------------------------
        void InsertFirst(T no) ;       //Insert first
        
        void InsertLast(T no);     //Insert Last
        
        void InsertAtPos(T no,int ipos) ;      //Insert At Pos
        
//--------------------------DELETE FUNCTION---------------------------
        void DeleteFirst() ;              //DeleteFirst
        
        void DeleteLast();               //DeleteLast
        
        void DeleteAtPos(int ipos);      //DeleteAtPos     
        
};


template <class T>
SinglyCLL<T>:: SinglyCLL()
        {
            head=NULL;
            tail=NULL;
            iCount=0;
        }

//--------------------------------DISPLAY, COUNT-----------------------------

template <class T>
void SinglyCLL<T>:: Display()
        {
            struct nodeSC<T>* temp = head;
            if(head==NULL && tail==NULL)
            {
                cout<<"Linked list is empty \n";
            }

            cout<<"Elements of the linked list are : \n";
            do
            {
                cout<<"|"<<temp->data<<"| -> ";
                temp = temp->next;
            }while (temp != head);
            cout<<"\n";
        }

template <class T>
int SinglyCLL<T>:: Count()
        {
            return iCount;
        }

//----------------------------INSERT FUNCTIONS---------------------------

template <class T>
void SinglyCLL<T>:: InsertFirst(T no)        //Insert first
        {
            struct nodeSC<T>* newn = NULL;
            newn = new nodeSC<T>;
            newn->data = no;
            newn->next=NULL;

            if(head==NULL && tail==NULL)
            {
                head =newn;
                tail=newn;
            }
            else
            {
                newn->next = head;
                head = newn;
            }
            tail->next = head;
            iCount++;
        }

template <class T>
void SinglyCLL<T>:: InsertLast(T no)     //Insert Last
        {
            struct nodeSC<T>* newn = NULL;
            newn = new nodeSC<T>;
            newn->data = no;
            newn->next=NULL;

            if(head==NULL && tail==NULL)
            {
                head =newn;
                tail=newn;
            }
            else
            {
                
                newn->next = head;
                tail->next = newn;
                tail = newn;
                
            }
            tail->next = head;
            iCount++;
        }

template <class T>
void SinglyCLL<T>:: InsertAtPos(T no,int ipos)       //Insert At Pos
        {
            if(ipos<=0 || ipos>iCount+1)
            {
                cout<<"Enter valid position\n";
            }

            if(ipos==1)
            {
                InsertFirst(no);
            }
            else if(ipos==(iCount+1))
            {
                InsertLast(no);
            }
            else
            {
                int i=0;
                struct nodeSC<T>* temp=head;
                struct nodeSC<T>* newn = NULL;
                newn = new nodeSC<T>;
                newn->data = no;
                newn->next =NULL;

                for(i=1; i< ipos-1; i++)
                {
                    temp= temp->next;
                }
                newn->next = temp->next;
                temp->next = newn;
            }
            tail->next = head;
            iCount++;
        }

//--------------------------DELETE FUNCTION---------------------------

template <class T>
void SinglyCLL<T>:: DeleteFirst()          //DeleteFirst
        {

            if(head==NULL && tail==NULL)
            {
                return ;
            }
            else if (head==tail)
            {
                delete head;
                head=NULL;
                tail=NULL;
            }
            else
            {
                tail->next = head->next;
                delete head;
                head =tail->next;
            }
            iCount--;
        }

template <class T>
void SinglyCLL<T>:: DeleteLast()       //DeleteLast
        {
            struct nodeSC<T>* temp=NULL;

            

            if(head==NULL && tail==NULL)
            {
                return ;
            }
            else if (head==tail)
            {
                delete head;
                head=NULL;
                tail=NULL;
            }
            else
            {
                temp= head;

                while (temp->next != tail)
                {
                    temp = temp->next;
                }

                delete temp->next;
                tail = temp;
                tail->next=head;
                           
            }
            iCount--;
        }

template <class T>
void SinglyCLL<T>:: DeleteAtPos(int ipos)      //DeleteAtPos
        {
            struct nodeSC<T>* temp=NULL;
            struct nodeSC<T>* target = NULL;
            int i=0;

            if(ipos<=0 || ipos>iCount)
            {
                cout<<"enter valid position\n";
            }

            if(ipos==1)
            {
                DeleteFirst();
            }
            else if (ipos==iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = head; 

                for(i=1; i< ipos-1; i++)
                {
                    temp = temp ->next;
                }
                target = temp -> next;
                temp->next = target->next;
                delete target;
            }
            iCount--;
        } 

/////////////////////////////////////////////////////////////////////////
//
//
//---------------------DOUBLY CIRCULAR LINKED LIST-------------------------
//
//
////////////////////////////////////////////////////////////////////////





template<class T>
class DoublyCLL
{
    public:
        int iCount;
        struct nodeDC<T>* head;
        struct nodeDC<T>* tail;

        DoublyCLL()   ;      //constructor
        
//---------------------display, count-----------------------------
        void Display();  

        int Count();
        
//----------------------insert functions--------------------------

        void InsertFirst(T no) ;       //Insert First
        
        void InsertLast(T no);         //Insert Last
        
        void InsertAtPos(T no,int ipos) ;      //Insert At Pos
        
//----------------------delete functions--------------------------

        void DeleteFirst();      //Delete First
        
        void DeleteLast() ;      //Delete last
        
        void DeleteAtPos(int ipos);    //Delete At Pos
               
};

template<class T>
DoublyCLL<T>:: DoublyCLL()         //constructor
        {
            iCount=0;
            head=NULL;
            tail=NULL;
        }

//---------------------display, count-----------------------------

        template<class T>
        void DoublyCLL<T>:: Display()
        {
            if(head==NULL && tail==NULL)
            {
                cout<<"linked list is empty\n";
            }

            struct nodeDC<T>* temp = head;

            cout<<"Elements in linked list are :\n";

            do
            {
                cout<<"|"<<temp->data<<"| <=> ";
                temp =temp ->next;
            }while(temp != head);
            cout<<"\n";

        }

        template<class T>
        int DoublyCLL<T>:: Count()
        {
            return iCount;
        }
        
//----------------------insert functions--------------------------

        template<class T>
        void DoublyCLL<T>:: InsertFirst(T no)        //Insert First
        {
            struct nodeDC<T>* newn = NULL;
            newn = new nodeDC<T>;
            newn->data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if(head==NULL && tail==NULL)
            {
                head=newn;
                tail=newn;
            }
            else
            {
                newn->next = head;
                head->prev = newn;
                head =newn;
            }
            tail->next =head;
            head->prev = tail;
            iCount++;
        }

        template<class T>
        void DoublyCLL<T>:: InsertLast(T no)         //Insert Last
        {
            struct nodeDC<T>* newn = NULL;
            newn = new nodeDC<T>;
            newn->data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if(head==NULL && tail==NULL)
            {
                head=newn;
                tail=newn;
            }
            else
            {
                tail->next = newn;
                newn->prev = tail;
                tail = newn;
            }
            tail->next =head;
            head->prev = tail;
            iCount++;
        }


        template<class T>
        void DoublyCLL<T>:: InsertAtPos(T no,int ipos)       //Insert At Pos
        {
            struct nodeDC<T>* temp = NULL;

            if(ipos<=0 || ipos>iCount+1)
            {
                cout<<"enter valid position\n";
            }

            if(ipos==1)
            {
                InsertFirst(no);
            }
            else if(ipos==iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                temp = head;

                struct nodeDC<T>* newn = NULL;
                newn = new nodeDC<T>;
                newn->data = no;
                int i =0;

                for(i=1; i<ipos-1; i++)
                {
                    temp = temp->next;
                }

                newn->prev = temp;
                newn->next= temp->next;
                temp->next = newn;
                newn->next->prev = newn;                
            }
            tail->next =head;
            head->prev = tail;
            iCount++;
        }

//----------------------delete functions--------------------------

        template<class T>
        void DoublyCLL<T>:: DeleteFirst()      //Delete First
        {
            struct nodeDC<T>* temp = NULL;

            if(head==NULL && tail==NULL)
            {
                return;
            }
            else if(head==tail)
            {
                delete head;
                head=NULL;
                tail=NULL;
            }
            else
            {
                head= head->next;
                delete tail->next;
            }
            tail->next =head;
            head->prev = tail;
            iCount--;
        }


        template<class T>
        void DoublyCLL<T>:: DeleteLast()       //Delete last
        {
            struct nodeDC<T>* temp = NULL;

            if(head==NULL && tail==NULL)
            {
                return;
            }
            else if(head==tail)
            {
                delete head;
                head=NULL;
                tail=NULL;
            }
            else
            {
                temp = tail->prev;
                delete tail;
                tail = temp;
            }
            tail->next =head;
            head->prev = tail;
            iCount--;
        }


        template<class T>
        void DoublyCLL<T>:: DeleteAtPos(int ipos)      //Delete At Pos
        {
            struct nodeDC<T>* temp = NULL;

            if(ipos<=0 || ipos>iCount)
            {
                cout<<"enter valid position\n";
            }

            if(ipos==1)
            {
                DeleteFirst();
            }
            else if(ipos==iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = head;

                int i =0;

                for(i=1; i<ipos-1; i++)
                {
                    temp = temp->next;
                }

                temp->next = temp->next->next;
                delete temp->next->prev;
                temp->next->prev = temp;
                              
            }
            tail->next =head;
            head->prev = tail;
            iCount--;
        }

/////////////////////////////////////////////////////////////////////////
//
//
//----------------------------------STACK------------------------------
//
//
////////////////////////////////////////////////////////////////////////

template <class T>
class stack
{
    public:
        struct nodeS<T>* head;
        int iCount;

        stack();        

        void push(T no) ;  // InsertFirst
        

        int pop() ;  // DeleteFirst
        

        void Display();
        
        int Count();
        
};

template <class T>
stack<T>:: stack()
        {
            head = NULL;
            iCount = 0;
        }

        template <class T>
        void stack<T>:: push(T no)   // InsertFirst
        {
            struct nodeS<T>* newn = NULL;
            
            newn = new nodeS<T>;
            newn->data = no;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                newn->next = head;
                head = newn;
            }
            iCount++;
        }

        template <class T>
        int stack<T>:: pop()   // DeleteFirst
        {
            int no = -1;
            struct nodeS<T>* temp = NULL;

            if(head == NULL)
            {
                cout<<"Stack is empty\n";
                return -1;
            }
            else if(head->next == NULL)
            {
                no = head->data;
                delete head;
                head = NULL;
            }
            else
            {
                no = head->data;
                temp = head;
                head = head->next;
                delete temp;
            }
            iCount--;
            return no;
        }


        template <class T>
        void stack<T>:: Display()
        {
            cout<<"Elements of stack are : \n";
            struct nodeS<T>* temp = head;

            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" |\n";
                temp = temp -> next;
            }
        }


        template <class T>
        int stack<T>:: Count()
        {
            return iCount;
        }

/////////////////////////////////////////////////////////////////////////
//
//
//----------------------------------QUEUE------------------------------
//
//
////////////////////////////////////////////////////////////////////////




template <class T>
class queue
{
    public:
        struct nodeQ<T>* head;
        int iCount;

        queue();
        

        void enqueue(T no);   // InsertLast
        

        int dequeue();   // DeleteFirst
        

        void Display();
        

        int Count();
       
};


template <class T>
queue<T>:: queue()
        {
            head = NULL;
            iCount = 0;
        }
        
        template <class T>
        void queue<T>::enqueue(T no)   // InsertLast
        {
            struct nodeQ<T>* newn = NULL;
            struct nodeQ<T>* temp = NULL;

            newn = new nodeQ<T>;
            newn->data = no;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                temp = head;
                while(temp->next != NULL)
                {
                    temp = temp -> next;
                }
                temp->next = newn;
            }
            iCount++;
        }

        template <class T>
        int queue<T>:: dequeue()   // DeleteFirst
        {
            T no;
            struct nodeQ<T>* temp = NULL;

            if(head == NULL)
            {
                cout<<"Queue is empty\n";
                return -1;
            }
            else if(head->next == NULL)
            {
                no = head->data;
                delete head;
                head = NULL;
            }
            else
            {
                no = head->data;
                temp = head;
                head = head->next;
                delete temp;
            }
            iCount--;
            return no;
        }

        template <class T>
        void queue<T>:: Display()
        {
            cout<<"Elements of queue are : \n";
            struct nodeQ<T>* temp = head;

            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" |\n";
                temp = temp -> next;
            }
        }


        template <class T>
        int queue<T>:: Count()
        {
            return iCount;
        }



////////////////////////////////////////////////////////////////////////////
//
//------------------------MAIN FUNCTION------------------------------------
//
///////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0;
    int iOption1 =0,iOption2=0, iPosition = 0 ;

    int typeChoice = 0;

    cout<<"\n//////////////////////////////////////////////////////\n";
    cout<<"//\n";
    cout<<"-----WELCOME TO GENERALIZED DATA STRUCTURE LIBRARY-----\n";
    cout<<"//\n//////////////////////////////////////////////////////\n";

    cout<<"\n-------------------------------------------------------\n";
    cout<<"--------------------------DATA TYPES-------------------";
    cout<<"\n-------------------------------------------------------\n";
    cout<<"\n";   
    cout<<"1 : int\n";
    cout<<"2 : float\n";
    cout<<"3 : char\n";
    cout<<"\n-------------------------------------------------------\n";
    cout << "Select Data Type : ";
    cin >> typeChoice;
    cout<<"\n-------------------------------------------------------\n";

    cout<<"\n-------------------------------------------------------\n";
    cout<<"----------------------DATA STRUCTURE-------------------";
    cout<<"\n-------------------------------------------------------\n";
    cout<<"\n";
    cout<<"1.Singly Linear Linked List\n";
    cout<<"2.Doubly Linear Linked List\n";
    cout<<"3.Singly Circular Linked List\n";
    cout<<"4.Doubly Circular Linked List\n";
    cout<<"5.Stack\n";
    cout<<"6.Queue\n";
    cout<<"7.Terminate the application\n";
    cout<<"\n";
    cout<<"-------------------------------------------------------\n";

    cout<<"\nEnter your Choice : ";
    cin>>iOption1;

    
    
    while (1)
    {

        if(iOption1 >= 7)
    {
        if(iOption1 > 7)
        {
            cout<<"\n-------------------------------------------------------\n";
            cout<<"Enter valid Choice\n";
            cout<<"-------------------------------------------------------\n";
            break;
        }
        else
        {
            break;
        }
    }
//---------------for int datatype---------------------------

        if (typeChoice == 1) 
        {
            static SinglyLL<int> sll;
            static DoublyLLL<int> dll;
            static SinglyCLL<int> scll;
            static DoublyCLL<int> dcll;
            static stack<int> stk;
            static queue<int> que;
            int value = 0;
            static int iCount=0;

            //-----------SLL----------

            if(iOption1 <=4 )
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"------------------------OPERATIONS---------------------";
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";
                cout<<"1 : Insert New Element at first position\n";
                cout<<"2 : Insert New Element at last position\n";
                cout<<"3 : Insert New Element at the given position\n";
                cout<<"4 : Delete Element at first position\n";
                cout<<"5 : Delete Element at last position\n";
                cout<<"6 : Delete Element at the given position\n";
                cout<<"7 : Display the elements\n";
                cout<<"8 : Count the elements\n";
                cout<<"9 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }
            else if(iOption1 == 5)
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";   
                cout<<"1 : Push\n";
                cout<<"2 : Pop\n";
                cout<<"3 : Display\n";
                cout<<"4 : Count total number of elements in the stack\n";
                cout<<"5 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }
            else if(iOption1 == 6)
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";   
                cout<<"1 : Enqueue\n";
                cout<<"2 : Dequeue\n";
                cout<<"3 : Display\n";
                cout<<"4 : Count total number of elements in the stack\n";
                cout<<"5 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }

            cout<<"\n-------------------------------------------------------\n";
            cout<<"\nPlease Select targeted operation : ";
            cin>>iOption2;

            cout<<"\n-------------------------------------------------------\n";

            if(iOption1 == 1)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    sll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    sll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    sll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    sll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    sll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    sll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    sll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = sll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------DLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    dll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    dll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    dll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = dll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------SCLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    scll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    scll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    scll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    scll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    scll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    scll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    scll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = scll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------DCLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dcll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dcll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dcll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    dcll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    dcll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dcll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    dcll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = dcll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------STACK----------
            else if(iOption1 == 5)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    stk.push(value);
                }

                else if(iOption2 == 2)
                {
                    iCount = stk.pop();
                    cout<<"Popped element from the Stack is : "<<iCount<<"\n";
                }

                else if(iOption2 == 3)
                {
                    stk.Display();
                }

                else if(iOption2 == 4)
                {
                    iCount = stk.Count();
                    cout<<"Number elements in the Stack are : "<<iCount<<"\n";
                }

                else if(iOption2 == 5)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }

                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------QUEUE---------
            else if(iOption1 == 6)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    que.enqueue(value);
                }

                else if(iOption2 == 2)
                {
                    iCount = que.dequeue();
                    cout<<"Popped element from the Stack is : "<<iCount<<"\n";
                }

                else if(iOption2 == 3)
                {
                    que.Display();
                }

                else if(iOption2 == 4)
                {
                    iCount = que.Count();
                    cout<<"Number elements in the Stack are : "<<iCount<<"\n";
                }

                else if(iOption2 == 5)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }

                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

        } 


//-------------for float datatype--------------------------

        else if (typeChoice == 2) 
        {
            static SinglyLL<float> sll;
            static DoublyLLL<float> dll;
            static SinglyCLL<float> scll;
            static DoublyCLL<float> dcll;
            static stack<float> stk;
            static queue<float> que;
            float value = 0.0f;
            static int iCount=0;

            //-----------SLL----------

            if(iOption1 <=4 )
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"------------------------OPERATIONS---------------------";
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";
                cout<<"1 : Insert New Element at first position\n";
                cout<<"2 : Insert New Element at last position\n";
                cout<<"3 : Insert New Element at the given position\n";
                cout<<"4 : Delete Element at first position\n";
                cout<<"5 : Delete Element at last position\n";
                cout<<"6 : Delete Element at the given position\n";
                cout<<"7 : Display the elements\n";
                cout<<"8 : Count the elements\n";
                cout<<"9 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }
            else if(iOption1 == 5)
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";   
                cout<<"1 : Push\n";
                cout<<"2 : Pop\n";
                cout<<"3 : Display\n";
                cout<<"4 : Count total number of elements in the stack\n";
                cout<<"5 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }
            else if(iOption1 == 6)
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";   
                cout<<"1 : Enqueue\n";
                cout<<"2 : Dequeue\n";
                cout<<"3 : Display\n";
                cout<<"4 : Count total number of elements in the stack\n";
                cout<<"5 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }

            cout<<"\n-------------------------------------------------------\n";
            cout<<"\nPlease Select targeted operation : ";
            cin>>iOption2;

            cout<<"\n-------------------------------------------------------\n";

            if(iOption1 == 1)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    sll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    sll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    sll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    sll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    sll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    sll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    sll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = sll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------DLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    dll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    dll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    dll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = dll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------SCLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    scll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    scll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    scll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    scll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    scll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    scll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    scll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = scll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------DCLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dcll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dcll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dcll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    dcll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    dcll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dcll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    dcll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = dcll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------STACK----------
            else if(iOption1 == 5)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    stk.push(value);
                }

                else if(iOption2 == 2)
                {
                    iCount = stk.pop();
                    cout<<"Popped element from the Stack is : "<<iCount<<"\n";
                }

                else if(iOption2 == 3)
                {
                    stk.Display();
                }

                else if(iOption2 == 4)
                {
                    iCount = stk.Count();
                    cout<<"Number elements in the Stack are : "<<iCount<<"\n";
                }

                else if(iOption2 == 5)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }

                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------QUEUE---------
            else if(iOption1 == 6)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    que.enqueue(value);
                }

                else if(iOption2 == 2)
                {
                    iCount = que.dequeue();
                    cout<<"Popped element from the Stack is : "<<iCount<<"\n";
                }

                else if(iOption2 == 3)
                {
                    que.Display();
                }

                else if(iOption2 == 4)
                {
                    iCount = que.Count();
                    cout<<"Number elements in the Stack are : "<<iCount<<"\n";
                }

                else if(iOption2 == 5)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }

                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }
        }

//--------------        
        else if (typeChoice == 3) 
        {
            static SinglyLL<char> sll;
            static DoublyLLL<char> dll;
            static SinglyCLL<char> scll;
            static DoublyCLL<char> dcll;
            static stack<char> stk;
            static queue<char> que;
            char value = '\0';
            static int iCount=0;

            //-----------SLL----------

            if(iOption1 <=4 )
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"------------------------OPERATIONS---------------------";
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";
                cout<<"1 : Insert New Element at first position\n";
                cout<<"2 : Insert New Element at last position\n";
                cout<<"3 : Insert New Element at the given position\n";
                cout<<"4 : Delete Element at first position\n";
                cout<<"5 : Delete Element at last position\n";
                cout<<"6 : Delete Element at the given position\n";
                cout<<"7 : Display the elements\n";
                cout<<"8 : Count the elements\n";
                cout<<"9 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }
            else if(iOption1 == 5)
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";   
                cout<<"1 : Push\n";
                cout<<"2 : Pop\n";
                cout<<"3 : Display\n";
                cout<<"4 : Count total number of elements in the stack\n";
                cout<<"5 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }
            else if(iOption1 == 6)
            {
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\n";   
                cout<<"1 : Enqueue\n";
                cout<<"2 : Dequeue\n";
                cout<<"3 : Display\n";
                cout<<"4 : Count total number of elements in the stack\n";
                cout<<"5 : Terminate the loop\n";
                cout<<"\n-------------------------------------------------------\n";
            }

            cout<<"\n-------------------------------------------------------\n";
            cout<<"\nPlease Select targeted operation : ";
            cin>>iOption2;

            cout<<"\n-------------------------------------------------------\n";

            if(iOption1 == 1)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    sll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    sll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    sll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    sll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    sll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    sll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    sll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = sll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------DLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    dll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    dll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    dll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = dll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------SCLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    scll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    scll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    scll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    scll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    scll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    scll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    scll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = scll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------DCLL----------
            else if(iOption1 == 2)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dcll.InsertFirst(value);
                }
                else if(iOption2 == 2)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    dcll.InsertLast(value);
                }
                else if(iOption2 == 3)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dcll.InsertAtPos(value,iPosition);
                }
                else if(iOption2 == 4)
                {
                    dcll.DeleteFirst();
                }
                else if(iOption2 == 5)
                {
                    dcll.DeleteLast();
                }
                else if(iOption2 == 6)
                {
                    cout<<"\nEnter the position : ";
                    cin>>iPosition;
                    dcll.DeleteAtPos(iPosition);
                }
                else if(iOption2 == 7)
                {
                    dcll.Display();
                }
                else if(iOption2 == 8)
                {
                    iCount = dcll.Count();
                    cout<<"Number elements in the Singly Linked List are : "<<iCount<<"\n";
                }
                else if(iOption2 == 9)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }
                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------STACK----------
            else if(iOption1 == 5)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    stk.push(value);
                }

                else if(iOption2 == 2)
                {
                    iCount = stk.pop();
                    cout<<"Popped element from the Stack is : "<<iCount<<"\n";
                }

                else if(iOption2 == 3)
                {
                    stk.Display();
                }

                else if(iOption2 == 4)
                {
                    iCount = stk.Count();
                    cout<<"Number elements in the Stack are : "<<iCount<<"\n";
                }

                else if(iOption2 == 5)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }

                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }

            //--------QUEUE---------
            else if(iOption1 == 6)
            {
                if(iOption2 == 1)
                {
                    cout<<"Enter the data you want to insert : ";
                    cin>>value;
                    que.enqueue(value);
                }

                else if(iOption2 == 2)
                {
                    iCount = que.dequeue();
                    cout<<"Popped element from the Stack is : "<<iCount<<"\n";
                }

                else if(iOption2 == 3)
                {
                    que.Display();
                }

                else if(iOption2 == 4)
                {
                    iCount = que.Count();
                    cout<<"Number elements in the Stack are : "<<iCount<<"\n";
                }

                else if(iOption2 == 5)
                {
                    cout<<"Operation Terminated Sucessfully.\n";
                    break;
                }

                else
                {
                    cout<<"Enter valid operation\n";
                    break;
                }
            }
        }

        else {
            cout << "Invalid data type choice!";
            break;
        }
  
    }
    return 0;
}