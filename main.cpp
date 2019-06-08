#include <iostream>
#include <fstream>
#include <conio.h>
#include<numeric>
#include <vector>
using namespace std;
vector<int> credits;
int input(const char *a,int nl=1)
{
    if(nl==1)
    {
        cout<<"\n";
        cout<<a;
        cout<<"\n";
    }
    int x;
    cin>>x;
    return x;
}

vector<int> credit()
{
    credits.clear();
    int subs=input("Enter no. of subjects");
    cout<<"Enter the credits in order\n";
    for(int i=0; i<subs; i++)
    {
        cout<<"\n"<<i+1<<":";
        credits.push_back(input("",0));
    }
    ofstream fout;
    fout.open("credits.txt");
    fout<<subs<<"\n";
    for(int i=0; i<subs; i++)
        fout<<credits[i]<<' ';
    fout.close();
    return credits;
}
int get_grade()
{
    return(11-input("1.O\n2.A+\n3.A\n4.B+\n5.B\n6.C\n7.P\nSelect grade"));
}
void gpa()
{
    int totalcredits=0;
    for(int i=0; i<credits.size(); i++)
    {
        cout<<i+1<<":";
        totalcredits+=credits[i]*get_grade();
    }
    int maxcredits=accumulate(credits.begin(),credits.end(),0);
    cout<<"GPA IS:"<<(float)totalcredits/maxcredits;
}
int main()
{
    ifstream fin;
    fin.open("credits.txt");
    cout<<"Credits feeded:";
    if(fin)
    {
        int subs;
        fin>>subs;
        for(int i=0; i<subs; i++)
        {
            int x;
            fin>>x;
            credits.push_back(x);
            cout<<x<<' ';
        }
    }
    fin.close();
    while(1)
    {
        switch(input("1.enter credits\n2.calculate gpa\n3.exit"))
        {
        case 1:
            credit();
            break;
        case 2:
            gpa();
            break;
        case 3:
            return 0;
        }
    }
}
