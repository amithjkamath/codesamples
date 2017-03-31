//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 12.5 on page 241
//  Simulating a printer queue
//  NOTE: This example was omitted in the first printing of the book

#include <iostream>  // defines the cout object
#include <queue>     // defines the priority_queue class template
#include "Random.h"  // defines the Random class
using namespace std;

const int TICKS=60;  // 60 seconds
const float MTBA=4;  // mean time between arrivals
const float MNOP=5;  // mean number of pages per job

class Exp : public Random
{ // generates random numbers that are exponentially distributed
  public:
    Exp(float mean) : _mean(mean) {}
    float next() { return -_mean*log(1.0-real()); }
  private:
    float _mean;
};

class Job
{ // instances represent print jobs:
    friend bool operator<(const Job& job1, const Job& job2)
    { // smaller jobs have higher priority:
      return (job1._pages > job2._pages);
    }
    friend ostream& operator<<(ostream& ostr, const Job& job)
    { ostr << "Job #" << job._id << " (" << job._pages << "pp)";
      return ostr;
    }
    static int _n;    // used to number the jobs: #0, #1, #2, etc.
    static Exp _gen;  // generates page counts
  public:
    Job(int time=0) : _id(_n++), _arrived(time), _pages(1+int(_gen.next()))
    { }
    int id() { return _id; }
    void process() { --_pages; }  // simulates printing one page
    bool is_finished() { return (_pages == 0); }
  protected:
    int _id;       // identification number
    int _arrived;  // arrival time number
    int _pages;    // number of pages
};

int Job::_n = 0;      // initializes Job counter
Exp Job::_gen(MNOP);  // defines page count generator

class Source
{ public:
    Source(float iat) : _gen(Exp(iat)), _arrival_time(0) { }
    Job* arrival(int t)
    { // returns pointer to new job if one is scheduled to arrive at time t;
      Job* job = 0;
      if (t == _arrival_time)                 // if it is time for a new print job,
      { job = new Job(t);                     // create it
        _arrival_time += int(_gen.next())+1;  // add random number to arrival time
      }
      return job;
    }
  protected:
    Exp _gen;           // random number generator
    int _arrival_time;  // time of next print job arrival
};

string size(priority_queue<Job>);
// returns a small string that symbolizes the size of the priority queue

int main()
{ Source source(MTBA);     // an object that generates print jobs
  priority_queue<Job> pq;  // the priority queue for the print jobs
  Job* current_job=0;      // the address 0 indicates no current job
  int cjid;                // the current job's identification number
  for (int t=0; t<TICKS; t++)
  { // each iteration represents one tick of the clock
    cout << "\n" << t << ": ";  // print the current time cycle number
    Job* new_job = source.arrival(t);  // get new job if it is due
    if (new_job != 0)
    { pq.push(*new_job);                  // push it onto the queue
      cout << *new_job << " arrived: ";   // and report that it has arrived
    }
    cout << size(pq);                     // report the size of the queue
    if (current_job == 0 && !pq.empty())  // start next job from queue
    { Job job = pq.top();                 // copy the highest priority job in the queue
      pq.pop();                           // remove it from the queue
      current_job = &job;                 // save its address
      cjid = current_job->id();           // save its identification number
      cout << ", start #" << cjid << ": " << size(pq);  // report action and queue size
    }
    if (current_job != 0)  // a current job exists
    { current_job->process();          // process the current job (print one of its pages)
      cout << ", proc #" << cjid;      // report action
      if (current_job->is_finished())  // if the current job has no more pages to be printed
      { current_job = 0;               // delete the current job
        cout << ", end #" << cjid;     // report action
      }
    }
  }
}

string size(priority_queue<Job> pq)
{ string s="[";
  for (int i=0; i<pq.size(); i++)
    s += "*";
  s += "]";
  return s;
}
