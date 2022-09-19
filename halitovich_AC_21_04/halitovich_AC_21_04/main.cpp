#include <iostream>
using namespace std;

struct pipe {
	float diametrPipe;
	float lenghtPipe;
	bool inRepair;

	bool check() {
		if (diametrPipe > 0 && lenghtPipe > 0) {
			return true;
		}
		else {
			return false;
		}
	}





};

struct station {
	string name;
	int workshop;
	int activeWorkshop;
	double efficiency;

	bool check() {
		if (name != "" && activeWorkshop > 0 && workshop > 0) {
			return true;
		}
		else {
			return false;
		}
	}




};