#include<iostream>
#include<stdio.h>
using namespace std;
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
	for(int i=0;i<no;i++)
	{
		for(int j=0;j<i;j++)
		{
			//replace
		}
		int y=-1;
		int flag=0;
		int flag2=0;
		string temp;
		for(int j=1;rule[i][j]!="-1";j++)
		{
			if(rule[i][0]==rule[i][j].substr(0,rule[i][0].length()))
			{
				flag=1;
				if(flag2==0)
				{
					printf("enter lhs\n");
					cin>>temp;
					rule[++z][++y]=temp;
					flag2==1;
				}
				rule[z][++y]=rule[i][j].substr(rule[i][0].length(),rule[i][j].length()-rule[i][0].length())+temp;
				rule[i][j]="-";
			}
			else
			{
				rule[i][j]=rule[i][j]+temp;
			}
			if(flag==1)
			{
				rule[z][++y]="$";
				rule[z][++y]="-1";
			}
		}
	}
	for(int i=0;i<=z;i++)
        {
                cout<<rule[i][0]<<"->";
                for(int j=1;rule[i][j]!="-1";j++)
                {
			if(rule[i][j]!="-")
                        cout<<rule[i][j]<<"/";
                }
                cout<<"\n";
        }

}
