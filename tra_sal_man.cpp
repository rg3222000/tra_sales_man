#include<bits/stdc++.h>
using namespace std;
/*function that picks up the minimum distance node from every node given a starting node that can be any of the given nodes it chooses closest node which has not yet been explored ,if the closest node is a visi-ted node then it backtracks and chooses the second closest node this will be continued until he has visited all the nodes*/ 
int count_min_dist(vector <int> *v,int n)
{
	int check[n+1]={0};
	int sum=0,k=1,i=0;	

	for(;;)
	{
	       auto min1=min_element(v[i].begin(),v[i].end());
	       int min=distance(v[i].begin(),min1);
	       check[i]=1;
	       if(count(check,check+n,1)==n)
		{
			return sum+v[i][0];
		        exit(0);
		}
	       else
	       {
		       for(;;)
		       {
		       v[i][min]=INT_MAX;
		       auto min2=min_element(v[i].begin(),v[i].end());
                       int min3=distance(v[i].begin(),min2);
	       if(check[min3]!=1)
	       {
		       sum=sum+v[i][min3];
		       i=min3;
		       break;
	       }
	       min=min3;
	               }
	       }

	}
	          	    
}  
int main()
{
	int num,i,n,j;
        cin>>n;
	vector <int> v[n];
        for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>num;
			v[i].push_back(num);

		}
	}

cout<<count_min_dist(v,n);
return 0;
}
