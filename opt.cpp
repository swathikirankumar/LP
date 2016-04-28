#include<stdio.h>
#include<iostream>

using namespace std;
int geti(string temp,string *term,int n)
{
	for(int i=0;i<n;i++)
	{
		if(term[i]==temp)
		return i;
	}
	return -1;
}
void insert(string &input,string *term,string **opt,int n)
{
	for(int i=0;i<input.length()-1;i++)
	{
		int j=geti(input.substr(i,1),term,n);
		int k=geti(input.substr(i+1,1),term,n);
		cout<<j<<" "<<k<<"\n";
		input.insert(i+1,opt[j][k]);
		i++;	
	}
	cout<<input<<"\n";	
}
int getgs(string input)
{
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='>')
		return i;
	}
	return -1;
}
int getls(string input,int n)
{
        for(int i=n;i>=0;i--)
        {
                if(input[i]=='<')
                return i;
        }
        return -1;
}
int issubstr(string handle,string temp)
{
	for(int i=0;i<=temp.length()-handle.length();i++)
	{
		if(temp.substr(i,handle.length())==handle)
		return 1;
	}
	return 0;
}
int getpno(string handle,string **gram,int np)
{
	for(int i=0;i<np;i++)
	{
		if(issubstr(handle,gram[i][1]))
		return i;
	}
	return -1;
}
void parse(string di,string input,string **gram,string **opt,string *term,int np,int n)
{
	while(1)
	{
		int i=getgs(input);
		if(i==-1)
		break;
		int j=getls(input,i);
		if(j==-1)
		{
			cout<<"error\n";
			break;
		}
		string handle=input.substr(j+1,i-j-1);
		cout<<handle<<"\n";
		int pno=getpno(handle,gram,np);
		cout<<input<<"|"<<"reduce "<<gram[pno][0]<<"->"<<gram[pno][1]<<"|";
		int k=(j-1)/2;
		di[k]=gram[pno][0][0];
		cout<<di<<"\n";
		input.erase(j,i-j+1);
		int p=geti(input.substr(j-1,1),term,n);
		int q=geti(input.substr(j,1),term,n);
		input.insert(j,opt[p][q]);
		cout<<input<<"\n";
	}
	cout<<input<<"\n";
}
int main()
{
	printf("enter no of productions in grammer\n");
	int np;
	cin>>np;
	string **gram;
	gram=new string*[np];
	for(int i=0;i<np;i++)
	gram[i]=new string[2];
	for(int i=0;i<np;i++)
	{
		cout<<"enter lhs of grammer\n";
		cin>>gram[i][0];
		cout<<"enter rhs of gram\n";
		cin>>gram[i][1];
	}
	printf("enter no of terminals\n");
	int n;
	cin>>n;
	string *term=new string[n];
	string **opt;
	opt=new string*[n];
	for(int i=0;i<n;i++)
	{
		opt[i]=new string[n];
	}
	for(int i=0;i<n;i++)
	{
		printf("enter terminal %d :",i+1);
		cin>>term[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"enter precedence of "<<term[i]<<" with "<<term[j]<<" : ";
			cin>>opt[i][j];
		}
	}
	cout<<"\t";
	for(int i=0;i<n;i++)
	cout<<term[i]<<"\t";
	cout<<"\n";
	for(int i=0;i<n;i++)
        {
		cout<<term[i]<<"\t";
                for(int j=0;j<n;j++)
                {
                        cout<<opt[i][j]<<"\t";
                }
		cout<<"\n";
        }
	cout<<"\n";
	string input;
	printf("enter input string\n");
	cin>>input;
	string di=input;
	input="$"+input+"$";
	cout<<input<<"\n";
	insert(input,term,opt,n);
	cout<<input<<"\n";
	parse(di,input,gram,opt,term,np,n);
}
