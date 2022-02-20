enum Vehicle_ID { Moto_ID = 0, Scooter_ID, Car_ID, Bus_ID };

#include <iostream>
#include <string>
#include <vector>
#include <clocale>

class Vehicle
{
protected:
	std::string name;
	int wheels;
	int maxSpeed;
public:
	Vehicle(std::string s, int w, int m) {
		this->name = s;
		this->wheels = w;
		this->maxSpeed = m;
	}
	void info() {
		std::cout << "Наименование транспорта:" << this->name << "\n";
		std::cout << "Кол-во колес:" << this->wheels << "\n";
		std::cout << "Максимальная скорость:" << this->maxSpeed << "\n\n";
	};
	virtual ~Vehicle() {}
};

class Car : public Vehicle
{
public:
	Car() :Vehicle("Автомобиль", 4, 160) {}
	Car(std::string s, int w, int m) :Vehicle(s, w, m) {};
};

class Scooter : public Vehicle
{
public:
	Scooter() :Vehicle("Скутер", 2, 60) {}
	Scooter(std::string s, int w, int m) :Vehicle(s, w, m) {};
};

class Moto : public Vehicle
{
public:
	Moto() :Vehicle("Мотоцикл", 2, 120) {}
	Moto(std::string s, int w, int m) :Vehicle(s, w, m) {};
};

class Bus : public Vehicle
{
public:
	Bus() :Vehicle("Автобус", 6, 100) {}
	Bus(std::string s, int w, int m) :Vehicle(s, w, m) {};
};

// Фабрики объектов
class Factory
{
public:
	virtual Vehicle* createVehicle() = 0;
	virtual ~Factory() {}
};

class CarFactory : public Factory
{
public:
	Vehicle* createVehicle() {
		return new Car;
	}
};

class ScooterFactory : public Factory
{
public:
	Vehicle* createVehicle() {
		return new Scooter;
	}
};

class MotoFactory : public Factory
{
public:
	Vehicle* createVehicle() {
		return new Moto;
	}
};

class BusFactory : public Factory
{
public:
	Vehicle* createVehicle() {
		return new Bus;
	}
};


int main(int argc, char** argv) {
	setlocale(0, "");
	if (argc < 1) {
		return -1;
	}
	CarFactory* carFactory = new CarFactory;
	ScooterFactory* scooterFactory = new ScooterFactory;
	MotoFactory* motoFactory = new MotoFactory;
	BusFactory* busFactory = new BusFactory;
	Vehicle* tmp;
	for (int i = 1; i < argc; i++) {
		switch (atoi(argv[i]))
		{
		case Car_ID:
			tmp = carFactory->createVehicle();
			break;
		case Scooter_ID:
			tmp = scooterFactory->createVehicle();
			break;
		case Moto_ID:
			tmp = motoFactory->createVehicle();
			break;
		case Bus_ID:
			tmp = busFactory->createVehicle();
			break;
		default:
			std::cout << atoi(argv[i]) << " - НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА\n";
			break;
		}
		if (tmp) {
			tmp->info();
		}
	}
}