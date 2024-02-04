#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to represent a process
class process{
 public:
  int pid;     // Process ID
  int at;      //Arrival Time
  int bt;      //Burst Time
//  int st;      //Start Time
//  int ct;      //Completion Time
//  int tat;     //Turn-Around Time
//  int wt;      //Waiting Time
};

// Function to compare processes based on arrival time
bool comapreArrival(process p1,process p2)
{
  return p1.at < p2.at;
}

// Function to compare processes based on Process Id
bool compareID(process p1,process p2)
{
  return p1.pid < p2.pid;
}

int main()
{
  int n;
  process p[100];
  int ct[100],tat[100],st[100];
  int wt[100];
  float avg_tat,avg_wt;
  int total_tat=0;
  int total_wt=0;

  cout<<setprecision(2)<<fixed;

  cout<<"Enter the number of processes : ";
  cin>>n;
 
  //Input Process
  for(int i=0;i<n;i++)
  {
    p[i].pid = i+1;
    cout<<"Enter arrival time of process p"<<p[i].pid<<" : ";
    cin>>p[i].at;

    cout<<"Enter Burst time of process p"<<p[i].pid<<"   : ";
    cin>>p[i].bt;
    cout<<endl;
  }

  // Sort processes based on arrival time
  sort(p,p+n,comapreArrival);
  for(int i=0;i<n;i++)
  {
    st[i]=(i==0)?p[i].at:max(ct[i-1],p[i].at);
    ct[i]=st[i] + p[i].bt;
    tat[i]=ct[i] - p[i].at;
    wt[i] = tat[i] - p[i].bt;

    total_tat+=tat[i];
    total_wt+=wt[i];
  }

  avg_tat = (float)total_tat/n;
  avg_wt  = (float)total_wt/n;

  //sort(p,p+n,compareID);
  cout<<endl;

  cout<<"#P\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"Wt\t"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
  } 

  cout<<endl;
  cout<<"Average TurnAround Time :: "<<avg_tat<<endl;
  cout<<"Average Waiting Time    :: "<<avg_wt<<endl;
  return 0;
}

