#include <iostream>
#include <string>

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

pipe newPipe;
station newStation;

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


void addPipe() {
	system("cls");
	cout << "Введите диаметр трубы: ";
	cin >> newPipe.diametrPipe;
	cout << "Введите длину трубы: ";
	cin >> newPipe.lenghtPipe;
	cout << "В ремонте: ";
	cin >> newPipe.inRepair;
	system("cls");
	cout << "Труба добавлена" << endl;
	showMenu();


}
	


void addKs() {
	system ("cls");
	cout << "Введите название станции: ";
	cin >> newStation.name;
	cout << "Укажите количество цехов: ";
	cin >> newStation.workshop;
	cout << "Укажите количество активных цехов: ";
	cin >> newStation.activeWorkshop;
	if (!newStation.check()) {
		cout << "Ошибка, повторите ввод данных" << endl;
		addKs();
	}
	system("cls");
	cout << " КС добавлена" << endl;
	showMenu();

}


void editPipe() {
	if (newPipe.check()) {
		cout << "Редактирование трубы" << endl;
		cout << "Длина трубы: " << newPipe.lenghtPipe << endl;
		cout << "Даметр трубы: " << newPipe.diametrPipe << endl;
		cout << "В ремонте: " << newPipe.inRepair << endl;
		cout << "Введите длину трубы: ";
		cin >> newPipe.lenghtPipe;
		cout << "Введите диаметр трубы: ";
		cin >> newPipe.diametrPipe;
		cout << "В ремонте: ";
		cin >> newPipe.inRepair;
		if (newPipe.check()) {
			system("cls");
			cout << "Успешно" << endl;
		}
		else {
			cout << "Ошибка" << endl;
		}
	}
	else {
		cout << "Трубы не существует" << endl;
	}
	showMenu();


}

void editKs() {
	system("cls");
	if (newStation.check()) {

	}
	
}






}