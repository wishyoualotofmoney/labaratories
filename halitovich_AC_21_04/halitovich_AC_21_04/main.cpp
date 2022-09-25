#include <iostream>

using namespace std;

int inf = 0;

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

void showMenu() {
	cout << "1. Добавить трубу" << endl;
	cout << "2. Добавить КС" << endl;
	cout << "3. Редактировать трубу" << endl;
	cout << "4. Редактировать КС" << endl;
	cout << "5. Просмотр всех объектов" << endl;
	cout << "6. Загрузить" << endl;
	cout << "7. Сохранить" << endl;
	cout << "8. Выход " << endl;
}


