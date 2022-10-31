#include <unordered_map>
#include <vector>
#include "Pipe.h"
#include "Station.h"

using namespace std;






void clearBuffer() {
	cin.clear();
	cin.ignore(1024, '\n');
}

template <typename T>
T GetCorrectNumber(std::string text, T min, T max) {
	cout << text;
	T number;
	cin >> number;
	for (;;) {
		if (cin.fail() || number < min || number > max) {
			clearBuffer();
			cout << "Введите корректные данные(" << min << "-" << max << "): ";
			cin >> number;
		}
		else {
			return number;
		}
	}
}

template <typename T>
using FilterP = bool(*)(const Pipe& p, T parametr);
template <typename T>
vector<unsigned int> findPipeByFilter(unordered_map<unsigned int, Pipe>& pipes, FilterP<T> f, T parametr) {
	vector<unsigned int> result;
	for (auto& it : pipes)
	{
		if (f(it.second, parametr))
		{
			result.push_back(it.second.getId());
		}
	}
	return result;
}



bool checkPipeByInRepair(const Pipe& p, bool parametr) {
	return p.getInRepair() == parametr;
}

bool checkPipeByName(const Pipe& p, string parametr) {
	return p.getName() == parametr;
}


ostream& operator << (ostream& out, Pipe& p) {
	out << endl << "Труба" << endl << "Имя: " << p.getName() << endl
		<< "ID: " << p.getId() << endl
		<< "Длина: " << p.getLength() << endl
		<< "Диаметр: " << p.getDiametr() << endl
		<< ((p.getInRepair()) ? "В работе " : "Не в работе") << endl;

	return out;
}






ostream& operator << (ostream& out, Pipe& p) {
	out << endl << "Труба" << endl << "Имя: " << p.getName() << endl
		<< "ID: " << p.getId() << endl
		<< "Длина: " << p.getLength() << endl
		<< "Диаметр: " << p.getDiametr() << endl
		<< ((p.getInRepair()) ? "В работе " : "Не в работе") << endl;

	return out;
}


istream& operator >> (istream& in, Pipe& p) {
	string name;
	clearBuffer();
	cout << "Имя трубы: ";
	getline(cin, name);
	p.setName(name);
	p.setLength(GetCorrectNumber("Длина: ", 0.00001, 3.4E+38));
	p.setDiametr(GetCorrectNumber("Диаметр: ", 0.00001, 3.4E+38));
	p.setInRepair(GetCorrectNumber("В работе: ", 0, 1));
	p.idP++;
	p.setId();
	return in;
}


ostream& operator << (ostream& out, Station& s) {
	out << endl << "Компрессорная Станция" << endl << "Имя: " << s.getName() << endl
		<< "ID: " << s.getId() << endl
		<< "Количество цехоы: " << s.getWorkshop() << endl
		<< "Количество цехов в работе: " << s.getWorkshopInWork() << endl
		<< "Эффективность: " << s.getEfficiency() << endl;

	return out;
}







void editPipe(struct Pipe& pipe) {
	if (validPipe(pipe)) {
		cout << "Статус: " << pipe.inRepair << endl;
		cout << "1. Включить" << endl;
		cout << "0. Выключить" << endl;
		bool action;
		cin >> action;
		if (action == 0 || action == 1) pipe.inRepair = action;
		else cout << "Ошибка" << endl;
	}
	else cout << "Труба не найдена" << endl;
}

void editStation(struct Station& station) {
	int countOn;
	if (!validStation(station)) {
		cout << "Ошибка" << endl;
		return;
	}
	int action;
	cout << "Количество цехов: " << station.workshop << "\nРабочих цехов: " << station.activeWorkshop << "\n0. Отключить\n1. Включить" << endl;
	cout << "Выберите действие: ";
	cin >> action;
	if (action == 1) {
		cout << "Введите количество цехов для включения: ";
		cin >> countOn;
		if ((countOn <= station.workshop - station.activeWorkshop) && countOn > 0) {
			station.activeWorkshop += countOn;
		}
		else {
			cout << "Ошибка" << endl;
		}
	}
	else if (action == 0) {
		cout << "Введите количество цехов для выключения: ";
		cin >> countOn;
		if (countOn <= station.activeWorkshop && countOn > 0) {
			station.activeWorkshop -= countOn;
		}
		else {
			cout << "Ошибка" << endl;
		}
	}
	else {
		cout << "Попробуйте еще раз" << endl;
	}
}

void saveToFile(struct Pipe& pipe, struct Station& station)
{
	bool pipeCheck, stationCheck;

	if (pipe.lenghtPipe != 0)
		pipeCheck = 1;
	if (station.name != "")
		stationCheck = 1;

	ofstream fout("result.txt");
	fout << pipeCheck << endl;
	fout << stationCheck << endl;

	cout <<  pipeCheck << endl;

	if (validPipe(pipe)) {
		fout << pipe.lenghtPipe << endl;
		fout << pipe.diametrPipe << endl;
		fout << pipe.inRepair << endl;
		cout << "Труба сохранена" << endl;
	}

	else cout << "Труба не найдена" << endl;
	if (validStation(station)) {
		fout << station.name << endl;
		fout << station.workshop << endl;
		fout << station.activeWorkshop << endl;
		fout << station.efficiency << endl;
		cout << "Станция сохранена" << endl;
	}
	else cout << "Станция не найдена" << endl;
	fout.close();
}

void loadFromFile(struct Pipe& pipe, struct Station& station) {
	ifstream fin;
	bool pipeCheck = false, stationCheck = false; // признак того что они не нулевые 
	fin.open("result.txt");
	if (fin.is_open()) {
		fin >> pipeCheck;
		fin >> stationCheck;
		if (pipeCheck && stationCheck) {
			fin >> pipe.lenghtPipe;
			fin >> pipe.diametrPipe;
			fin >> pipe.inRepair;
			fin >> ws; // пропускает пустое место 
			getline(fin, station.name);
			fin >> station.workshop;
			fin >> station.activeWorkshop;
			fin >> station.efficiency;

			

		}
		if (stationCheck) {
			fin >> ws;
			getline(fin, station.name);
			fin >> station.workshop;
			fin >> station.activeWorkshop;
			fin >> station.efficiency;

		}
		if (pipeCheck) {
			fin >> pipe.lenghtPipe;
			fin >> pipe.diametrPipe;
			fin >> pipe.inRepair;
		}



		if (pipe.lenghtPipe != 0 && pipe.diametrPipe != 0) {
			cout << "Труба загружена" << endl;
		}
		if (station.name != "" && station.workshop != 0 && station.efficiency != 0) {
			cout << "Станция загружена" << endl;
		}
		else
		{
			cout << "объекты не загружены" << endl;
		}
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
	fin.close();

}

void addPipe(struct Pipe& pipe) {
	do {
		cin.clear();
		cin.ignore(1223, '\n');
		cout << "Введите длину трубы: ";
		cin >> pipe.lenghtPipe;
	} while (pipe.lenghtPipe <= 0 || cin.fail());
	do {
		cin.clear();
		cin.ignore(1223, '\n');
		cout << "Введие диаметр трубы: ";
		cin >> pipe.diametrPipe;
	} while (pipe.diametrPipe <= 0 || cin.fail());
	do {
		cin.clear();
		cin.ignore(1223, '\n');
		cout << "В ремонте: ";
		cin >> pipe.inRepair;
	} while (cin.fail());
}

void addStation(struct Station& station) {
	string name;
	do {
		cin.clear();
		cout << "Введите название станции: ";
		cin.ignore();
		getline(cin, name); // получает сin и записывает в name до пробела 
	} while (cin.fail());
	station.name = name;
	do {
		cin.clear();
		cin.ignore(1223, '\n');
		cout << "Введие количество цехов: ";
		cin >> station.workshop;
	} while (station.workshop <= 0 || cin.fail());
	do {
		cin.clear();
		cin.ignore(1223, '\n'); // игнорить все что больше числа
		cout << "Введите количество рабочих цехов: ";
		cin >> station.activeWorkshop;
	} while (station.activeWorkshop < 0 || station.activeWorkshop > station.workshop || cin.fail());
	do {
		cin.clear();
		cin.ignore(1223, '\n');
		cout << "Эффективность: ";
		cin >> station.efficiency;
	} while (station.efficiency <= 0 || station.efficiency > 100 || cin.fail());
}


int main() {
	setlocale(LC_CTYPE, "");
	int chooseMenu;

	Pipe pipe;
	Station station;

	while (true) {
		showMenu();
		cout << "Выберите пункт меню: ";
		cin >> chooseMenu;
		switch (chooseMenu)
		{
		case 1:
			addPipe(pipe);
			break;

		case 2:
			addStation(station);
			break;

		case 3:
			editPipe(pipe);
			break;

		case 4:
			editStation(station);
			break;

		case 5: 
			showObjects(pipe, station);
			break;

		case 6:
			loadFromFile(pipe, station);
			break;

		case 7:
			saveToFile(pipe, station);
			break;
			
		case 0:
			return 0;
			break;

		default: 
			cout << "Повторите ввод" << endl;
			break;
		}
	}


}