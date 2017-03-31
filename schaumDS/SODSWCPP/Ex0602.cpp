//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.2 page 112
//  Simulation of toll plaza

#include <iostream>
#include <list>         // defines the list<T> class template
#include <queue>        // defines the queue<T> class template
#include "Random.h"     // defines the Random class
using namespace std;
const int BOOTHS=4;     // 4 toll booths
const int TICKS=36000;  // 3600 seconds = 1 hour
const float IAT=20;     // average arrival every 2 seconds
const float ST=80;      // average 8 seconds per service

class Exp : public Random
{ public:
    Exp(float mean) : _mean(mean) {}
    float time() { return -_mean*log(1.0-real()); }
  private:
    float _mean;
};

class Car
{   friend class TollBooth;
    friend ostream& operator<<(ostream& ostr, const Car& car)
    { ostr << "#" << car._id << "(" << car._arrive
           << "," << car._service << "," << car._server
           << "," << car._exit << ")";
      return ostr;
    }
    static int _count;
  public:
    Car(int time=0) : _id(_count++), _arrive(time),
      _service(0), _remaining(0.0), _exit(0) {}
    int id() { return _id; }
    bool finished() { return _remaining <= 0.0; }
  protected:
    int _id;
    int _arrive;
    int _service;
    float _remaining;
    int _exit;
    char _server;
};

class TollBooth
{   static Exp _service;  // generates random service times
  public:
    TollBooth() : _serving(false), _p(0) {}
    void setId(char ch) { _id = ch; }
    bool isServing() { return _serving; }
    Car& car() { return *_p; }
    void enter(Car* p, int time)
    { _serving = true;
      _p = p;
      p->_service = time;
      p->_remaining = _service.time();
      p->_server = _id;
    }
    void serviceCar() { _p->_remaining -= 1.0; }
    void vacate(int time)
    { _serving = false;
      _p->_exit = time;
    }
  private:
    char _id;
    bool _serving;
    Car* _p;
};

int Car::_count = 0;          // initializes Car counter
Exp TollBooth::_service(ST);  // initializes service time generator

int main()
{ vector<TollBooth> booth(BOOTHS);
  for (int i=0; i<BOOTHS; i++)
    booth[i].setId('A'+i);  // name booths as 'A', 'B', 'C', etc.
  queue<Car*> line;
  Exp arrival(IAT);         // generates random arrival intervals
  float timeToNextArrival=0.0;
  for (int t=0; t<TICKS; t++, timeToNextArrival -= 1.0)
  { if (timeToNextArrival <= 0.0)  // a car has arrived
    { Car* p = new Car(t);         // construct new Car object
      line.push(p);                // move car to back of line
      timeToNextArrival = arrival.time();
    }
    for (int i=0; i<BOOTHS; i++)
      if (booth[i].isServing())
      { Car& car=booth[i].car();
        booth[i].serviceCar();
        if (car.finished())
        { booth[i].vacate(t);      // move car out of booth
          out << car << "\n";
        }
      }
      else if (!line.empty())      // move front car to booth
      { Car* p=line.front();
        booth[i].enter(p,t);
        line.pop();
      }
  }
}
