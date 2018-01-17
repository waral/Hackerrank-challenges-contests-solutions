#include <iostream>
using namespace std;
int top = -1; //Globally defining the value of top as the stack is empty

    void push (char stack[ ] , char x , int n)
    {
        if ( top == n-1 )       //If the top position is the last of position of the stack, this means that the stack is full.
        {
            cout << "Stack is full.Overflow condition!"<<endl;
        }
        else
        {
            top = top +1 ;            //Incrementing the top position 
            stack[ top ] = x ;       //Inserting an element on incremented position  
        }
    }
    bool isEmpty ( )
    {
        if ( top == -1 )  //Stack is empty
            return true ; 
        else
            return false;
    }
    void pop (char stack[ ]) 
    {

        if( isEmpty ( ) )
        {
            cout << "Stack is empty" << endl ;
        }
        else    
        {
             //cout << stack[top] << endl;
             top = top - 1 ; //Decrementing top’s position will detach last element from stack            
        }
    }
    int size ( )
    {
        return top + 1;
    }
    int topElement (char stack[])
    {
        return stack[ top ];
    }
    //Let's implement these functions on the stack given above 

    int main( )
    {
        int n;
        char stack[1000];
        int answer[1000];
        string s;
        int ans=1;
        
        // pushing element 5 in the stack .
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            ans=1;
            top=-1;
            for (char & c : s)
            {
            	if (c =='{' || c=='(' || c=='[')
            	{
            		push(stack,c,1000);
            	}
            	if (c =='}')
            	{
            		if (isEmpty()==false && stack[top]=='{')
            		{
            			pop(stack);
            			
            		}
            		else
            		{
            			ans=0;
            			break;
            		} 
            			
            	}
            	if (c ==')')
            	{
            		if (isEmpty()==false && stack[top]=='(')
            		{
            			pop(stack);
            			
            		}
            		else
            		{
            			ans=0;
            			break;
            		} 
            			
            	}
            	if (c ==']')
            	{
            		if (isEmpty()==false && stack[top]=='[')
            		{
            			pop(stack);
            			
            		}
            		else
            		{
            			ans=0;
            			break;
            		} 
            			
            	}
            }
            if (isEmpty()==false)
            {
            	ans=0;
            }
            answer[i]=ans;
        }

        for (int i = 0; i < n; ++i)
        {
        	if (answer[i]==1)
        	{
        		cout<<"YES"<<endl;
        	}
        	else cout<<"NO"<<endl;
        }
        

    }