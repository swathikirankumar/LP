#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	string start,temp;
	int no;
	printf("enter start symbol\n");
	//scanf("%s",start);
	cin>>start;
	printf("enter no. of productions\n");
	//scanf("%d",no);
	cin>>no;
	string rule[no][2];
	for(int i=0;i<no;i++)//gettting grammer
	{
		printf("enter lhs of production\n");
		//scanf("%s",rule[i][0]);
		cin>>rule[i][0];
		printf("enter rhs of production\n");
		//scanf("%s",rule[i][1]);
		cin>>rule[i][1];
	}
	for(int i=0;i<no;i++)
	{
		//printf("%s -> %s",rule[i][0],rule[i][1]);
		cout<<rule[i][0]<<"->"<<rule[i][1]<<"\n";
	}
	string input;
	cout<<"enter string to be tested\n";
	cin>>input;
	int length=1;
	string mat[input.length()][input.length()][input.length()];
	for(int i=0;i<input.length();i++)
	{
		string str=input.substr(i,1);
		//cout<<str;
		int p;
		//cin>>p;
		p=-1;
		for(int j=0;j<no;j++)
		{
			if(rule[j][1]==str)
			mat[length-1][i][++p]=rule[j][0];
		}
	}
	for(int i=0;i<input.length();i++)
	{
		int j=0;
		while(mat[length-1][i][j]!="")
		{
			cout<<mat[length-1][i][j]<<",";
			j++;	
		}
		cout<<"\t";
	}
	cout<<"\n";
	//cout<<"\nfirst level \n";
	for(length=2;length<=input.length();length++)
	{
		for(int j=0;j<=input.length()-length;j++)
		{
			int k=1,l=length-k;	
			int p=-1;
			while(k<length)
			{
				cout<<k<<","<<l<<"\n";
				int it=0;
				string str;
				//int p=-1;
				while(mat[k-1][j][it]!="")
				{
					str=mat[k-1][j][it];
				//	cout<<str<<"\n";
					int it2=0;
					while(mat[l-1][j+k][it2]!="")
					{
						string temp=str+mat[l-1][j+k][it2];
						cout<<"str is "<<str<<"\t";
						cout<<"temp is "<<temp<<"\n";
						int check;
					//	cin>>check;
						for(int n=0;n<no;n++)
						{
							if(rule[n][1]==temp)
							{
								int flag=0;
								for(int z=0;z<=p;z++)
								{
									if(mat[length-1][j][z]==rule[n][0])
									flag=1;
								}
								if(flag==0)
								mat[length-1][j][++p]=rule[n][0];
								//cout<<rule[n][0]<<"\n";;
							}
						}
						it2++;
					}
					it++;
				}
					int check=0;
						while(mat[length-1][j][check]!="")
						{
							cout<<mat[length-1][j][check]<<",";
							check++;
						}
						cout<<"\n";
				k++;
				l--;
			}
		}
	}
	cout<<"graph is \n";
	for(int k=0;k<input.length();k++)
	{
		for(int i=0;i<input.length();i++)
		{
			int j=0;
			while(mat[k][i][j]!="")
			{
				cout<<mat[k][i][j]<<",";
				j++;	
			}
			cout<<"\t";
		}
		cout<<"\n";
	}
	int i=0;
	int flag=0;
	while(mat[input.length()-1][0][i]!="")
	{
		if(mat[input.length()-1][0][i]==start)
		{
			cout<<"string can be generated\n";
			flag=1;
		}
		i++;
	}
	if(flag==0)
	cout<<"string cannot be generated\n";
}
/*
S
8
S AB
S BC
A BA
A a
B CC
B b
C AB
C a
*/
