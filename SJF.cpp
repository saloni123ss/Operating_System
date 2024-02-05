#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits.h>
using namespace std;

// Class to represent a process
class process{
 public:
  int pid;     //Process ID
  int at;      //Arrival Time
  int bt;      //Burst Time
  int st;      //Start TIme
  int ct;      //Completion Time
  int tat;     //Turn-Around Time
  int wt;      //Waiting Time
  
   process()
   {
     wt=ct=tat=0;
   }
};

int main()
{
  int n;
  process p[100];
  float avg_tat,avg_wt;
  int total_tat=0;
  int total_wt=0;
  int burst_remaining[100];
  int is_completed[100]={0};

  cout<<setprecision(2)<<fixed;
 
  cout<<"Saloni Solanki - 21UECC8072"<<endl;
  cout<<"Shortest JOB First - Non-Preemptive - CPU Scheduling"<<endl;   
  
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

    p[i].pid = i+1;
    cout<<endl;
  }

  int current_time = 0;
  int completed = 0;
  
  while(completed != n)
  {
    int idx = -1;
    int mn = INT_MAX;
    for(int i = 0; i < n; i++)
    {
      if(p[i].at <= current_time && is_completed[i] == 0) 
      {
        if(p[i].bt < mn)
        {
          mn = p[i].bt;
          idx = i;
        }

        if(p[i].bt == mn) 
        {
           if(p[i].at < p[idx].at) 
           {
              mn = p[i].bt;
              idx = i;
           }
        }
      }
    }
  

      if(idx != -1) 
      {
        p[idx].st = current_time;
        p[idx].ct  = p[idx].st + p[idx].bt;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt  = p[idx].tat - p[idx].bt;
    
        total_tat += p[idx].tat;
        total_wt  += p[idx].wt;
    
        is_completed[idx] = 1;
        completed++;
        current_time = p[idx].ct;
      }
      else
      {
        current_time++;
      }
   }
             
  avg_tat = (float)total_tat/n;
  avg_wt  = (float)total_wt/n;
  cout<<endl;

  cout<<"#P\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"Wt\t"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<endl;
  } 

  cout<<endl;
  cout<<"Average TurnAround Time :: "<<avg_tat<<endl;
  cout<<"Average Waiting Time    :: "<<avg_wt<<endl;
  return 0;
}

