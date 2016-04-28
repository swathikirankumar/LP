#include<iostream>
#include<stdio.h>
using namespace std;
int ispresent(string temp,string nterm[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(temp==nterm[i])
		return 1;
	}
	return 0;
}
int getterm(string rule[][10],string term[],string nterm[],int n)
{
	int z=-1;
	for(int i=0;i<n/2;i++)
	{
		for(int j=1;rule[i][j]!="-1";j++)
		{
			string temp=rule[i][j];
			if(temp=="$")
			continue;
			else if(temp=="id")
			{
				int k;
				for(k=0;k<=z;k++)
				{
					if(term[z]==temp)
					break;
				}
				if(k==z+1)
				term[++z]=temp;
			}
			else
			{
				for(int l=0;l<temp.length();l++)
				{
					string tem=temp.substr(l,1);
					if(!ispresent(tem,nterm,n/2))
					{
						int k;
	                        	        for(k=0;k<=z;k++)
        	                	        {
                	                	        if(term[z]==tem)
                        	        	        break;
                        	       	 	}
                  	                	if(k==z+1)
                        	        	term[++z]=tem;
					}
				}
			}
		}
	}
	return z;
}
int ep(string nt,string rule[][10],int n)
{
	for(int i=0;i<n/2;i++)
	{
		if(nt==rule[i][0])
		{
			for(int j=1;rule[i][j]!="-1";j++)
			{
				if(rule[i][j]=="$")
				return 1;
			}
		}	
	}
	return 0;
}
void fill(string **first,string rule[][10],string term[],string nterm[],int n,int p,int r)
{
	int z=0;
	if(first[r][1]!="")
	return ;
	cout<<"here\n";
	string nt=first[r][0];
	if(ep(nt,rule,n))
	{
		first[r][++z]="$";
	}
	else
	{
		for(int i=0;i<n/2;i++)
          	{
                  	if(nt==rule[i][0])
                  	{
                         	for(int j=1;rule[i][j]!="-1";j++)
                         	{
					int fp=0;
                                  	string temp=rule[i][j].substr(fp,1);
					if(ispresent(temp,term,p+1))
					{
						int j;
						for(j=0;j<=z;j++)
						{
							if(first[i][j]==temp)
							break;
						}
						if(j==z+1)
						first[r][++z]=temp;
					}
					else
					{	for(fp;fp<rule[i][j].length();fp++ )
						{
							temp=rule[i][j].substr(fp,1);
							int k;
							for(k=0;k<n/2;k++)
							{
								if(nterm[k]==temp)
								break;	
							}
							int row=z+1+k;
							fill(first,rule,term,nterm,n,p,row);
							if(first[row][1]=="$")
							{
								for(int l=2;l<z+3;l++)
								first[r][++z]=first[row][l];
								if(ispresent(rule[i][j].substr(fp+1,0),term,p+1))
								break;
							}
							else
							{
								for(int l=1;l<z+3;l++)
                                        	                first[r][++z]=first[row][l];
								break;
							}
						}	
                          		}
                  		}
          		}
		}

	}
}
int main()
{
        string start,temp;
        int no;
        printf("enter start symbol\n");
        cin>>start;
        printf("enter no. of productions\n");
        cin>>no;
        string rule[no+no][10];
	string term[2*no],nterm[2*no];
        for(int i=0;i<no;i++)
        {
                printf("enter lhs of production\n");
                cin>>rule[i][0];
		nterm[i]=rule[i][0];
                printf("enter rhs of production\n");
                int j=1;
                while(j<10)
                {
                        cin>>rule[i][j];
                        if(rule[i][j]=="-1")
                        break;
                        j++;
                }
        }
        for(int i=0;i<no;i++)
        {
                cout<<rule[i][0]<<"->";
                for(int j=1;rule[i][j]!="-1";j++)
                {
                        cout<<rule[i][j]<<"/";
                }
                cout<<"\n";
        }
	int z=getterm(rule,term,nterm,2*no);
	for(int i=0;i<=z;i++)
	{
		cout<<term[i]<<"|";
	}
	cout<<"\n";
	string **first;
	first=new string*[z+no+1];
	for(int i=0;i<z+no+1;i++)
	{
		first[i]=new string[z+3];
		for(int j=0;j<z+3;j++)
		first[i][j]="";
	}
	for(int i=0;i<=z;i++)
	{
		first[i][0]=term[i];
		first[i][1]=term[i];
	}
	for(int i=z+1;i<z+no+1;i++)
	{
		first[i][0]=nterm[i];
	}
	for(int i=z+1;i<z+no+1;i++)
	{
		fill(first,rule,term,nterm,2*no,z,i);
	}
	for(int i=0;i<z+no+1;i++)
	{
		for(int j=0;j<z+3;j++)
		{
			cout<<first[i][j]<<" ";
		}
		cout<<"\n";
	}
}
