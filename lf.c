#include<iostream>
#include<stdio.h>
using namespace std;
int geth(string cmp1[],int c1[],int length)
{
	int min=0;
	for(int i=0;i<=length;i++)
	{
		if(c1[i]>min)
		{
			min=c1[i];
		}
	}
	return min;
}
string getcmn(string temp[])
{
	int i=1;
	int length=0;
	string cmn;
	string cmnp;
	int cmnl=0;
	int cmnll=0;
	while(temp[i]!="-1")
	{
		length++;
		i++;
	}
	//cout<<"length is "<<length<<"\n";
	string cmp1[length];
	int c1[length];
	int size=1;
	while(1)
	{
		int z=-1;
		for(i=0;i<length;i++)
		{
			c1[i]=0;
		}
		for(i=1;i<=length;i++)
		{
			if(temp[i].length()>=size)
			{
				string sub=temp[i].substr(0,size);
				//cout<<"sub string is "<<sub<<"\n";
				if(z==-1)
				{
					cmp1[++z]=temp[i].substr(0,size);
					c1[z]++;
				}
				else
				{
					int flag=0;
					for(int k=0;k<=z;k++)
					{
						if(cmp1[k]==temp[i].substr(0,size))
						{
							c1[k]++;
							flag=1;
						}			
					}
					if(flag==0)
					{
						cmp1[++z]=temp[i].substr(0,size);
						c1[z]++;
					}
				}
			}
		}
	//	for(i=0;i<=z;i++)
	//	{
	//		cout<<cmp1[i]<<"\t"<<c1[i]<<"\n";
	//	}
		cmnl=geth(cmp1,c1,z);
	//	cout<<"size is "<<size<<"\tcommon length is "<<cmnl<<"\n";
		for(int i=0;i<=z;i++)
		{
			if(cmnl==c1[i])
			{
				cmn=cmp1[i];
				break;
			}
		}
	//	cout<<"cmn is "<<cmn<<"\n";
	//	cout<<"cmnl is "<<cmnl<<" cmnll is "<<cmnll<<"\n";
		if(cmnll==0)
		{
			cmnll=cmnl;
			cmnp=cmn;
			size++;
		}
		else if(cmnl==cmnll)
		{
			cmnp=cmn;
			size++;
		}
		else
		break;
	}
	if(cmnll>1)
	return cmnp;
	else
	{
		string t="";
		return t;
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
	for(int i=0;i<no;i++)
	{
		printf("enter lhs of production\n");
		cin>>rule[i][0];
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
	int z=no-1;
	int y;
	for(int i=0;i<=z;i++)
	{
		y=-1;
		cout<<rule[i][0]<<"\n";
		cout<<"z is "<<z<<"\n";
		string com=getcmn(rule[i]);
		cout<<"common string is "<<com<<"\n";
		int flag=0;
		int flag2=0;
		if(com!="")
		{
			for(int j=1;rule[i][j]!="-1";j++)
			{
	//			cout<<"entered\n";
				if(rule[i][j].length()>=com.length())
				{
	//				cout<<"enter 2 \n";
					if(com==rule[i][j].substr(0,com.length()))
					{
						string temp=rule[i][j].substr(com.length(),rule[i][j].length()-com.length());
						cout<<"temp is "<<temp<<"\n";
						if(flag2==0)
						{
							printf("enter new lhs\n");
							string lhs;
							cin>>lhs;
							rule[++z][++y]=lhs;
							flag2=1;
						}
						if(temp=="")
						rule[z][++y]="$";
						else
						rule[z][++y]=temp;
					}
					if(flag==0)
					{
						rule[i][j]=com+rule[z][0];
	//					cout<<"change is "<<rule[i][j]<<"\n";
						flag=1;
					}
					else
					{
						rule[i][j]="-";
					}
				}
			}
			rule[z][++y]="-1";
			cout<<rule[i][0]<<"->";
                	for(int j=1;rule[i][j]!="-1";j++)
                	cout<<rule[i][j]<<"/";
                	cout<<"\n";
		}
	}
	for(int i=0;i<=z;i++)
        {
                cout<<rule[i][0]<<"->";
                for(int j=1;rule[i][j]!="-1";j++)
                cout<<rule[i][j]<<"/";
                cout<<"\n";
        }                                                                                                                
}
/*
S
5
E
+TaE
+TaEG
b
-1
T
*idF
*idH
d
-1
F
(E)
id
-1
H
aE
ab
-1
G
$
-1
*/
