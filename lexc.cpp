#include<iostream>
#include<fstream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
using namespace std;
string data_type[5]={"int","char","string","double","float"};
string k[27]={"auto","break","case","const","continue","do","else","enum","extern","for","goto","if","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
string aop[7]={"+","-","*","%","/","+=","-="};
string lop[2]={"||","&&"};
string rop[7]={"<",">","<=",">=","==","<>","!="};
string paren[6]={"(",")","{","}","[","]"};
int isdatatype(string temp)
{
        for(int i=0;i<5;i++)
        {
        //      cout<<data_type[i];
                if(temp==data_type[i])
                return 1;
        }
        return 0;
}
int iskeyword(string temp)
{
        for(int i=0;i<27;i++)
        {
                if(temp==k[i])
                return 1;
        }
        return 0;
}
int isaop(string str)
{
        for(int i=0;i<7;i++)
        {
                if(str==aop[i])
                return 1;
        }
        return 0;
}
int islop(string str)
{
        for(int i=0;i<2;i++)
        {
                if(str==lop[i])
                return 1;
        }
        return 0;
}
int isp(string str)
{
        for(int i=0;i<6;i++)
        {
                if(str==paren[i])
                return 1;
        }
        return 0;
}
int isrop(string str)
{
        for(int i=0;i<7;i++)
        {
                if(str==rop[i])
                return 1;
        }
        return 0;
}
int isnumber(string str)
{
        for(int i=0;i<str.length();i++)
        {

        }
}
void tokenizer(string temp2)
{
                if(isdatatype(temp2))
                cout<<temp2<<" is "<<"datatype\n";
                else if(iskeyword(temp2))
                cout<<temp2<<" is "<<"keyword\n";
                else
                cout<<temp2<<" is a identifier\n";
}
int containop(string temp)
{
        //cout<<temp<<"\n";
        string temp2="";
        for(int i=0;i<temp.length();i++)
        {
                string str=temp.substr(i,1);
                if(str==";")
                {
                        if(temp2!="")
                        {
                                tokenizer(temp2);
                        }
                        str="";
                        temp2="";
                }
                else if(isrop(str))
                {
                        if(temp2!="")
                        {
                                tokenizer(temp2);
                        }
                        cout<<str<<" is a "<<"relational  operator\n";
                        str="";
                        temp2="";

                }
                else if(str=="=")
                {
                        if(temp2!="")
                        {
                                tokenizer(temp2);
                        }
                        cout<<str<<" is a "<<"assignment operator\n";
                        str="";
                        temp2="";
                }
                else if(isaop(str))
                {
                        if(temp2!="")
                        {
                                tokenizer(temp2);
                        }
                        cout<<str<<" is a "<<"arithmetic operator\n";
                        str="";
                        temp2="";
                }
                else if(islop(str))
                {
                        if(temp2!="")
                        {
                                tokenizer(temp2);
                        }
                        cout<<str<<" is a"<<"logical operator\n";
                        str="";
                        temp2="";
               }
                else if(isp(str))
                {
                        if(temp2!="")
                        {
                                tokenizer(temp2);
                        }
                        cout<<str<<" is a "<<"paranthesis\n";
                        str="";
                        temp2="";
                }
                else
                temp2+=str;
        }
        if(temp2!="")
        {
                tokenizer(temp2);
        }
}
int main()
{
        int fd=open("test.cpp",O_RDONLY);
        char *buffer;
        buffer= new char[1000];
        //const char *delim=",\n ";
        int n=read(fd,buffer,1000);
        cout<<buffer;
        cout<<"buffer length is "<<strlen(buffer)<<"\n";
        for(int i=0;i<strlen(buffer);i++)
        {
                string str="";
                while(buffer[i]!='\n')
                {
                        str=str+buffer[i];
                        i++;
                }
                //cout<<"str is\t"<<str<<"\n";
                if(str[0]=='#')
                cout<<str<<" is "<<"pre processor\n";
                else
                {
                        for(int j=0;j<str.length();j++)
                        {
                                string temp="";
                                while(str.substr(j,1)!=" "&& j<str.length())
                                {
                                        if(str.substr(j,1)!="\t")
                                        temp=temp+str.substr(j,1);
                                        j++;
                                }
                                //cout<<"temp is "<<temp<<"\n";
                                //int k=0;
                                //while(temp.substr(k,1)==" ")
                                //k++;
                                //cout<<"k is "<<k<<"\n";
                                //tokeniser(temp);
                                containop(temp);
                        }
                }
        }
        return 0;
}
                           
