class Exp : public Random
{ public:
    Exp(float mean) : _mean(mean) {}
    float time() { return -_mean*log(1.0-real()); }
  private:
    float _mean;
};

const int BOOTHS=4;     // 4 toll booths
const int TICKS=18000;  // 1800 seconds = 30 minutes
const float IAT=20;     // average 1 arrival every 2 seconds
const float ST=160;     // average 16 seconds per service
Exp arrival(IAT);       // generates random arrival intervals
Exp service(ST);        // generates random service times
  
class Car
{   friend class TollBooth;
    friend ostream& operator<<(ostream& ostr, const Car& car)
    { ostr << "#" << car._id << "(" << car._arrive
           << "," << car._service << "," << car._server
           << "," << car._exit << ")";
      return ostr;
    }
  protected:
    static int _count;
  public:
    Car(int time=0) : _id(_count++), _arrive(time),
      _service(0), _remaining(0), _exit(0) {}
    int arrived() { return _arrive; }
    bool finished() { return _remaining == 0; }
  protected:
    int _id;
    int _arrive;
    int _service;
    int _remaining;
    int _exit;
    char _server;
};
int Car::_count = 0;

class TollBooth
{ public:
    TollBooth() : _serving(false) {}
    void setId(char i) { _id = i; }
    bool isServing() { return _serving; }
    Car& car() { return _car; }
    void enter(Car& car, int time)
    { _serving = true;
      _car = car;
      _car._service = time;
      _car._remaining = service.time();
      _car._server = _id;
    }
    void serviceCar() { --_car._remaining; }
    void vacate(int time)
    { _serving = false;
      _car._exit = time;
    }
  private:
    char _id;
    bool _serving;
    Car _car;
};
