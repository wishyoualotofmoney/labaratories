#include <iostream>
#include <string>
#include <fstream>

using namespace std;



struct pipe {
	float diametrPipe;
	float lenghtPipe;
	bool inRepair;

	bool check() {
		if (diametrPipe > 0 && lenghtPipe > 0 ) {
			return true;
		}
		else {
			cout << "Повторите ввод" << endl;
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
	system("cls");
	cout << "1. Добавить трубу" << endl;
	cout << "2. Добавить КС" << endl;
	cout << "3. Редактировать трубу" << endl;
	cout << "4. Редактировать КС" << endl;
	cout << "5. Просмотр всех объектов" << endl;
	cout << "6. Загрузить" << endl;
	cout << "7. Сохранить" << endl;
	cout << "0. Выход " << endl;
}

void addPipe() {
	system("cls");
	cout << "Введите диаметр трубы: ";
	cin >> newPipe.diametrPipe;
	cout << "Введите длину трубы: ";
	cin >> newPipe.lenghtPipe;
	cout << "В ремонте: ";
	cin >> newPipe.inRepair;
	if (!newPipe.check()) {
		system("cls");
		cout << "повторите ввод" << endl;
		addPipe();
	}
	else {
		cout << "Труба добавлена" << endl;
	}

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
	cout << "Укажите коэффицент: ";
	cin >> newStation.efficiency;
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
		cout << "Редактирование КС" << endl;
		cout << "Название КС: " << newStation.name << endl;
		cout << "Количество цехов: " << newStation.workshop << endl;
		cout << "Количество активных цехов: " << newStation.activeWorkshop << endl;
		cout << "Коэффицент: " << newStation.efficiency << endl;
		cout << "Введите название: ";
		cin >> newStation.name;
		cout << "Укажите количество цехов: ";
		cin >> newStation.workshop;
		cout << "Укажите количество активных цехов: ";
		cin >> newStation.activeWorkshop;
		cout << "Укажите коэффицент: ";
		cin >> newStation.efficiency;
		if (newStation.check()) {
			system("cls");
			cout << "Успешно" << endl;
		}
		else {
			cout << "Ошибка" << endl;
		}
	}
	else {
		cout << "КС не сущкествует" << endl;
	}
	showMenu();
	
}

void showObjects()
{
	system("cls");
	cout << "Просмотр всех объектов\n\n";

	cout << "Длинна\t" << "Диаметр\t" << "Ремонт\t" << endl;
	cout << "================================================" << endl;
	cout << newPipe.lenghtPipe << '\t' << newPipe.diametrPipe << '\t' << newPipe.inRepair << endl;

	cout << "\n";

	cout << "Имя\t" << "countWS\t" << "actWS\t" << "Эффективность\t" << endl;
	cout << "===========================================================================" << endl;
	cout << newStation.name << '\t' << newStation.workshop << '\t' << newStation.activeWorkshop << '\t' << newStation.efficiency << endl;
}



  

void saveToFile()
{
	ofstream fout("Z:\\Documents\\GitHub\\labaratories\\halitovich_AC_21_04\\123.txt");
	fout << newPipe.lenghtPipe << "/" << newPipe.diametrPipe << "/" << newPipe.inRepair << endl;
	fout << newStation.name << "/" << newStation.workshop << "/" << newStation.activeWorkshop << "/" << newStation.efficiency << endl;
	fout.close();
}

void loadFromFile()
{
	ifstream fin("Z:\\Documents\\GitHub\\labaratories\\halitovich_AC_21_04\\123.txt");
	string buff; //буферная переменная для гетлайн
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		getline(fin, buff, '/');
		newPipe.lenghtPipe = stoi(buff);

		getline(fin, buff, '/');
		newPipe.diametrPipe = stoi(buff);

		getline(fin, buff);
		newPipe.inRepair = stoi(buff);

		getline(fin, newStation.name, '/');

		getline(fin, buff, '/');
		newStation.workshop = stoi(buff);

		getline(fin, buff, '/');
		newStation.activeWorkshop = stoi(buff);

		getline(fin, buff);
		newStation.efficiency = stof(buff);

		fin.close(); // закрываем файл  
		return;
	}
}




















int main() {
	setlocale(LC_CTYPE, "");
	int chooseMenu;
	
	while (true) {
		showMenu();
		cout << "Выберите пункт меню: ";
		cin >> chooseMenu;
		switch (chooseMenu)
		{
		case 1:
			addPipe();
			break;

		case 2:
			addKs();
			break;

		case 3:
			
			editPipe();
			break;

		case 4:
			editKs();
			break;

		case 5: 
			showObjects();
			break;

		case 6:
			loadFromFile();
			break;

		case 7:
			saveToFile();
			break;
			
		case 0:
			return 0;
			break;

		default: 
			cout << "Повторите ввод" << endl;
			break;
		}
		if (chooseMenu != 0) system("pause");
	}


}