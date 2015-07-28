#ifndef DIE_HEADER 
#define DIE_HEADER

class die
{
	public:
		die();
		~die();

		int get_face_value();
		void roll();

	private: // methods
		void set_face_value(int inFaceValue);

	private: // data members.
		int my_face_value;
};
#endif
