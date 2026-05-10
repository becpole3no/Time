#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    int milliseconds;

    void normalize();

public:
    Time();
    Time(int h, int m, int s, int ms);
    Time(const Time& other);
    ~Time();

    Time& operator=(const Time& other);

    Time operator+(const Time& other) const;
    Time operator-(const Time& other) const;

    void print() const;
};

void Time::normalize() {
    if (milliseconds >= 1000) {
        seconds += milliseconds / 1000;
        milliseconds %= 1000;
    }

    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }

    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }

    hours %= 24;

    if (milliseconds < 0) {
        milliseconds += 1000;
        seconds--;
    }

    if (seconds < 0) {
        seconds += 60;
        minutes--;
    }

    if (minutes < 0) {
        minutes += 60;
        hours--;
    }

    if (hours < 0) {
        hours += 24;
    }
}

Time::Time() {
    cout << "Вызван конструктор без параметров" << endl;

    hours = 0;
    minutes = 0;
    seconds = 0;
    milliseconds = 0;
}

Time::Time(int h, int m, int s, int ms) {
    cout << "Вызван конструктор с параметрами" << endl;

    hours = h;
    minutes = m;
    seconds = s;
    milliseconds = ms;

    normalize();
}

Time::Time(const Time& other) {
    cout << "Вызван конструктор копирования" << endl;

    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    milliseconds = other.milliseconds;
}

Time::~Time() {
    cout << "Вызван деструктор" << endl;
}

Time& Time::operator=(const Time& other) {
    cout << "Вызван оператор присваивания" << endl;

    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        milliseconds = other.milliseconds;
    }

    return *this;
}

Time Time::operator+(const Time& other) const {
    cout << "Вызван оператор +" << endl;

    Time temp;

    temp.hours = hours + other.hours;
    temp.minutes = minutes + other.minutes;
    temp.seconds = seconds + other.seconds;
    temp.milliseconds = milliseconds + other.milliseconds;

    temp.normalize();

    return temp;
}

Time Time::operator-(const Time& other) const {
    cout << "Вызван оператор -" << endl;

    Time temp;

    temp.hours = hours - other.hours;
    temp.minutes = minutes - other.minutes;
    temp.seconds = seconds - other.seconds;
    temp.milliseconds = milliseconds - other.milliseconds;

    temp.normalize();

    return temp;
}

void Time::print() const {
    cout << setfill('0');

    cout << setw(2) << hours << ":"
         << setw(2) << minutes << ":"
         << setw(2) << seconds << "."
         << setw(3) << milliseconds << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Создание объекта time1" << endl;
    Time time1(10, 20, 30, 500);

    cout << "time1 = ";
    time1.print();

    cout << endl;

    cout << "Создание объекта time2" << endl;
    Time time2(5, 45, 50, 750);

    cout << "time2 = ";
    time2.print();

    cout << endl;

    cout << "Сложение времени" << endl;
    Time time3 = time1 + time2;

    cout << "time3 = ";
    time3.print();

    cout << endl;

    cout << "Вычитание времени" << endl;
    Time time4 = time1 - time2;

    cout << "time4 = ";
    time4.print();

    cout << endl;

    cout << "Проверка конструктора копирования" << endl;
    Time time5 = time1;

    cout << "time5 = ";
    time5.print();

    cout << endl;

    cout << "Проверка оператора присваивания" << endl;
    Time time6;
    time6 = time2;

    cout << "time6 = ";
    time6.print();

    cin.get();

    return 0;
}