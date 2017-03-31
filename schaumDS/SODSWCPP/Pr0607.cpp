//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.7 page 121
//  A modification of Example 6.2

void queue::clear()
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
    int arrived() { return _arrive; }
    int served() { return _service; }
    bool finished() { return _remaining <= 0.0; }
    int timeInLine() { return int(_service) - _arrive; }
    int serviceTime() { return _exit - int(_service); }
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
    char id() { return _id; }
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
Exp TollBooth::_service(ST);  // initializes _service generator

int main()
{ ofstream fout("Simulation.out");
  float sumLineLength=0.0;
  float sumTimeInLine=0.0;
  int numCarsInLine=0;
  float sumServiceTime[BOOTHS]={0.0};
  int numCarsServed[BOOTHS]={0};
  vector<TollBooth> booth(BOOTHS);
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
          fout << car << "\n";
          sumServiceTime[i] += car.serviceTime();
          ++numCarsServed[i];
        }
      }
      else if (!line.empty())      // move front car to booth
      { Car* p=line.front();
        booth[i].enter(p,t);
        line.pop();
        sumTimeInLine += p->timeInLine();
        ++numCarsInLine;
      }
    sumLineLength += line.size();
  }
  cout << "\nAverage number of cars in line: "
       << sumLineLength/TICKS;
  cout << "\nAverage time in line: "
       << sumTimeInLine/numCarsInLine/10 << " seconds.";
  float sumST=0.0;
  int numCS=0;
  for (int i=0; i<BOOTHS; i++)
    cout << "\nNumber of cars served by booth " << booth[i].id()
         << ": "  << numCarsServed[i];
  for (int i=0; i<BOOTHS; i++)
  { cout << "\nAverage service time for booth " << booth[i].id()
         << ": " << sumServiceTime[i]/numCarsServed[i]/10
         << " seconds.";
    sumST += sumServiceTime[i];
    numCS += numCarsServed[i];
  }
  cout << "\nAverage service time per car: "
       << sumST/numCS/10 << " seconds.";
  for (int i=0; i<BOOTHS; i++)
    cout << "\nBooth " << booth[i].id() << " idle: "
         << int(100-100*sumServiceTime[i]/TICKS) << "% of time.";
  cout << "\n";
}
