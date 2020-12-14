#define BOOST_PYTHON_STATIC_LIB
#define BOOST_DISABLE_PRAGMA_MESSAGE
#include <boost/python.hpp>
#include <iostream>

struct Numbers{
	int d;
	float f;

	Numbers(){
		d = 10;
		f = 0.22;
	}

	void setd(int _d){d = _d;}
	void setf(float _f){f = _f;}
	void print(){std::cout <<d <<", " <<f <<std::endl;}
};

int greet(int x) {
	std::cout <<"Hello, World!" <<std::endl;
	return x*x;
}

// module name must match the file name
BOOST_PYTHON_MODULE(test) {
	using namespace boost::python;
	def("greet", greet);
	class_<Numbers>("Numbers")
		.def("print", &Numbers::print)
		.def("setd", &Numbers::setd)
		.def("setf", &Numbers::setf);
}