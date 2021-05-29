#include<stdio.h> 

int main() 
{ 
    int t;
    scanf("%d", &t);
	
	while(t>0)
	{
	    int n,rever=0,temp;
	    
	    scanf("%d", &n);
	    temp=n;
	    
	    while(temp!=0)
	    {
	        rever = (rever*10) + (temp%10);
	        temp = temp/10;
	    }
	    
	    if(rever==n)
	        printf("wins\n");
	    else
	        printf("losses\n");
	    
	    t--;
	}
	
	return 0; 
} 
