// Queue based approach for first non-repeating character in a stream

// Method : 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct qNode
{
    char ch;
    struct qNode *next;
};

struct qNode *front,*rear;

struct qNode* new_node(char c)
{
    struct qNode *node;

    node = (struct qNode*)malloc(sizeof(struct qNode));

    node->ch = c; 

    node->next = NULL;

    return node;
}

void enqueue(char c)
{
    if(!front)
    {
        front = rear = new_node(c);
    }
    else
    {
        rear->next = new_node(c);
        rear = rear->next;
    }
}

void dequeue(char c)
{
    struct qNode *ptr = front,*prev = NULL;
    
    while( ptr && ptr->ch!=c)
    {
	    prev = ptr;
	    ptr = ptr->next;
    }
    if(ptr)
    {
	    if(ptr->next==NULL)
	    {
	        if(prev)
	    	    prev->next = NULL;
	        else
	            front = NULL;

	        rear = prev;
	        free(ptr);
	    }
	    else
        {
		    if(front == ptr)
			    front = ptr->next;
		    else
			    prev->next = ptr->next;
		    free(ptr);
	    }	
    }
}

void init(bool *arr)
{
	int i = 26;
	
	while(i--)
		arr[i] = false;
}

void check_stream(char *alphabet,int n)
{
	bool arr[26];
	int i;
	
	init(arr);
    
    front = rear = NULL;
    for(i=0;i<n;i++)
    {
        if(arr[alphabet[i] - 97] == false)
        {
            enqueue(alphabet[i]);
            arr[alphabet[i] - 97] = true;
        }
        else
            dequeue(alphabet[i]);
        if(!front)
            printf("-1 ");
        else
            printf("%c ",front->ch);
    }
    
    printf("\n");
    
    if(front)
        free(front);
}

int main() 
{
	    //code
	    int i,t,n;
	    char alphabet[500];
	    scanf("%d",&t);
	    while(t--)
	    {
	            scanf("%d",&n);
		          getchar();
	            for(i=0;i<n;i++)
	            {
	                scanf("%c",alphabet+i);
			            getchar();
	            }
	       check_stream(alphabet,n);
	    }
	    
	    return 0;
}
