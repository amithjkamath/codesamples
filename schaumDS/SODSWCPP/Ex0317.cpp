//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.17 on page 60
//  Implementation of Deck class

Deck::Deck()
{ _card = new Card*[_SIZE];
  int r=13, s=3;
  for (int i=0; i<_SIZE; i++)
  { if (r==0)
    { r = 12;
      s = (s-1)%4;
    }
    else --r;
    _card[i] = new Card(r,s);
  }
}

void Deck::print() const
{ for (int i=0; i<_SIZE; i++)
    cout << _card[i]->abbr() << (i%13==12?"\n":" ");
  cout << "\n";
}

void Deck::shuffle() const
{ for (int i=0; i<_SIZE; i++)
  { int j = _random.integer(_SIZE)-1;
    Card* p = _card[i];
    _card[i] = _card[j];
    _card[j] = p;
  }
}

const int Deck::_SIZE=52;

Random Deck::_random;
