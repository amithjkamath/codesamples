#ifndef MYCLASS_HEADER
#define MYCLASS_HEADER

class myClass
{
	public:
		myClass();
		~myClass();
		
		int getVal();
		void setVal(int x);
		
		const int* getPtr() const;
	private:
		int myVal;	
};

#endif