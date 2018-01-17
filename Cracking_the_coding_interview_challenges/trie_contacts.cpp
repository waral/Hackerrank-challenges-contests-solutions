#include <iostream>
using namespace std;
//int counter=0;
struct node
    {
         char data;
         //bool FullWord;                 //Data element
         struct node * alph[26];          //Pointer to left node
         int WordsStartingWith;				         
    };

    struct node * root;
    struct node * newnode(char letter)
    {
        struct node * temp=(node * )malloc(sizeof(node));
        (*temp).data=letter;
        (*temp).WordsStartingWith=0;
        for (int i = 0; i < 26; ++i)
        {
        	(*temp).alph[i]=NULL;
        }
        return temp;
    }
    void insert(struct node* root, string s)
    {
    	struct node* temp=root;
    	for (char & c : s)
    	{
    		if (temp->alph[c-'a']==NULL)
    		{
    			temp->alph[c-'a']=newnode(c);
    		}
    		temp=temp->alph[c-'a'];
    		temp->WordsStartingWith++;
    	}
    	//temp->FullWord=true;	
    }

    bool search(struct node* root, string s)
    {
    	struct node* temp=root;
    	for (char & c : s)
    	{
    		if (temp->alph[c-'a']==NULL)
    		{
    			return false;
    		}
    		temp=temp->alph[c-'a'];
    	}
    	return true;	
    }

    struct node * FindRootPartial(struct node* root, string s)
    {
    	struct node* temp=root;
    	for (char & c : s)
    	{
    		if (temp->alph[c-'a']==NULL)
    		{
    			return NULL;
    		}
    		temp=temp->alph[c-'a'];
    	}
    	return temp;	
    }

    // void CardinalityTree(struct node* root)
    // {
    // 	struct node* temp=root;
    // 	if (root!= NULL)
    // 	{
    // 		for (int i = 0; i < 26; ++i)
    // 		{
    // 			if (temp->alph[i]!=NULL)
    // 			{
    // 				if (temp->alph[i]->FullWord==true)
    // 				{
    // 					counter++;
    // 				}
    // 				CardinalityTree(temp->alph[i]);
    // 			}
    // 		}
    // 	}
    		
    // }

    
    int main( )
    {
        int n;
    	cin >> n;
    	struct node* root;
    	struct node* temp=(node * )malloc(sizeof(node));
    	root=newnode('0');
    	int ans[100000];
    	int i=0;
    	// insert(root,"hack");
    	// insert(root,"hackerrank");
    	// counter=0;
    	// temp=FindRootPartial(root,"hac");
    	// CardinalityTree(temp);
    	// cout<<counter<<endl;
    	// counter=0;
    	// temp=FindRootPartial(root,"hak");
    	// CardinalityTree(temp);
    	// cout<<counter<<endl;
    for(int a0 = 0; a0 < n; a0++)
    {
        string op;
        string contact;
        cin >> op >> contact;
        if (op=="add")
        {
        	insert(root,contact);
        }
        else
        {
        	temp =FindRootPartial(root,contact);
        	if (temp==NULL)
        	{
        		ans[i]=0;
        	}
        	else
        	{ 
        	ans[i]=temp->WordsStartingWith;
        	}
        	i++;

        }

    }

    for (int k = 0; k < i; ++k)
    {
    	cout<<ans[k]<<endl;
    }
        return 0;
        

    }