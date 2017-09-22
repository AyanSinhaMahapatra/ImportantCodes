#include<iostream>
#include<cmath>
using namespace std;
void merge(int *,int *,int ,int );
void mergesort(int *,int *,int ,int );
int main()
{
	int n;
	cout<<"Enter the number of terms in the Array to be Merge_Sorted : "<<endl;
	cin>>n;	
	
	int array[n+1];
	int array_subs[n+1];
	
	cout<<"Enter the Array"<<endl;
	for(int i=1;i<=n;i++)
		cin>>array[i];
		
	cout<<endl<<"UnSorted Array "<<endl;
	for(int i=1;i<=n;i++)
		cout<<array[i]<<" ";
	
	mergesort(array,array_subs,1,n);
	
	cout<<"Merge_Sorted Array "<<endl;
	for(int i=1;i<=n;i++)
		cout<<array[i]<<" ";
		
    return 0;       
}
void mergesort(int *start_pointer,int *start_pointer_2,int start,int end)
{
	if(start!=end)
	{
	   int length=(end-start)+1;
	   int a_start=start;
	   int a_end=start+(length/2)-1;
	   int b_start=0;
	    if(length%2==0)
	        b_start=end-(length/2)+1;
	    else
	        b_start=end-(length/2);
	    int b_end=end;
	      
		mergesort(start_pointer,start_pointer_2,a_start,a_end);
	      
		mergesort(start_pointer,start_pointer_2,b_start,b_end);
	      
		merge(start_pointer,start_pointer_2,a_start,b_end);
		  
    }
}
void merge(int *start_pointer,int *start_pointer_2,int start,int end)
{
	int length=(end-start)+1;
	int a_start=start;
	int a_end=start+(length/2)-1;
	int b_start=0;
	if(length%2==0)
	    b_start=end-(length/2)+1;
	else
	    b_start=end-(length/2);
	int b_end=end;

	//Copies to another Array
	for(int i=a_start;i<=b_end;i++)
	{
		start_pointer_2[i]=start_pointer[i];
	}
	//This Merges the Two Parts
	int i=a_start,j=b_start;
	
	for(int k=a_start;k<=b_end;k++)
	{
		
		if(i==(a_end+1))
		{
		    if(j!=(b_end+1))
			{
				start_pointer[k]=start_pointer_2[j];
			    j++;
		    }
		}
		else if(j==(b_end+1))
		{
			if(i!=(a_end+1))
			{
				start_pointer[k]=start_pointer_2[i];
			    i++;
		    }
		}
		else
		{
		       if(start_pointer_2[i]<=start_pointer_2[j])
		       {
			         start_pointer[k]=start_pointer_2[i];
			         i++;
	           }
		       else if(start_pointer_2[i]>start_pointer_2[j])
		       {
		 	         start_pointer[k]=start_pointer_2[j];
			         j++;
		       }
 	    }
	}
}
