//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//
//////****Task1****
////class Rectangle {
////private:
////	double length;
////	double width;
////	static int comparisonCount;
////public:
////	Rectangle(double l = 0, double w = 0) {
////		length = l;
////		width = w;
////	}
////	bool operator==(const Rectangle&  other) const {
////		comparisonCount++;
////		return (length * width) == (other.length * other.width);
////	}
////	bool operator<(const Rectangle&  other) const {
////		comparisonCount++;
////		return (length * width) < (other.length * other.width);
////	}
////	static int getComparisonCount() {
////		return comparisonCount;
////	}
////	void display(){
////		cout << "Rectangle Length " << length << " : width " << width << endl;
////	}
////};
////
////int Rectangle::comparisonCount = 0;
////
////int main() {
////	Rectangle r1(2, 4);
////	Rectangle r2(2, 4);
////	Rectangle r3(10, 12);
////	cout << "comparison operator :" << (r1 == r2) << endl;
////	cout << "< operator :" << (r3 < r1) << endl;
////	cout << "Result = " << Rectangle::getComparisonCount() << endl;
////	return 0;
////}
//
//
//////****task2****
////class Temperature {
////private:
////	double celsius;
////public:
////	Temperature(double c = 0.0) {
////		celsius = c;
////	}
////	Temperature& operator+=(double delta) {
////		celsius += delta;
////		return *this;
////	}
////	static double toFahrenheit(double celsiusValue) {
////		return (celsiusValue * 9.0 / 5.0) + 32.0;
////	}
////	void display() {
////		cout << "Temperature : Celsius -> " << celsius << " and Fahrenhiet -> " << toFahrenheit(celsius) << endl;
////	}
////};
////int main() {
////	Temperature t1(23.0);
////	t1.display();
////	t1 += 13;
////	t1.display();
////	cout << "100 C in Fahrenheit :"<< Temperature::toFahrenheit(100.0) << " F" << endl;
////	return 0;
////}
//
//
//////****task3****
////template <typename T>
////class Stack {
////private:
////    T* elements;          
////    int capacity;   
////    int topIndex;      
////    static int pushCount; 
////
////public:
////    Stack(int size = 10) {
////        capacity = size;
////        elements = new T[capacity];
////        topIndex = -1; 
////    }
////
////    Stack(const Stack<T>& other) {
////        capacity = other.capacity;
////        topIndex = other.topIndex;
////        elements = new T[capacity];
////        for (int i = 0; i <= topIndex; i++) {
////            elements[i] = other.elements[i];
////        }
////    }
////
////    Stack<T>& operator=(const Stack<T>& other) {
////        if (this != &other) { 
////            delete[] elements; 
////
////            capacity = other.capacity;
////            topIndex = other.topIndex;
////            elements = new T[capacity];
////
////            for (int i = 0; i <= topIndex; i++) {
////                elements[i] = other.elements[i];
////            }
////        }
////        return *this;
////    }
////
////    void push(const T& item) {
////        if (topIndex + 1 < capacity) {
////            elements[++topIndex] = item;
////            pushCount++;
////        }
////        else {
////            cout << "Stack overflow! ";
////        }
////    }
////
////    static int getPushCount() {
////        return pushCount;
////    }
////
////    ~Stack() {
////        delete[] elements;
////    }
////};
////
////template <typename T>
////int Stack<T>::pushCount = 0;
////int main() {
////    Stack<int> s1(5);
////    s1.push(10);
////    s1.push(20);
////
////    Stack<int> s2 = s1; 
////
////    Stack<int> s3;
////    s3 = s1; 
////
////    s2.push(30);
////    s3.push(40);
////
////    cout << "Total push operations = " << Stack<int>::getPushCount() << endl;
////
////    return 0;
////}
//
//
//
//////****Task4****
////class Currency {
////private:
////    int dollars;
////    int cents;
////
////public:
////    Currency(int d = 0, int c = 0) {
////        normalize(d, c);  
////        dollars = d;
////        cents = c;
////    }
////
////    Currency operator-(const Currency& other) const {
////        int total1 = dollars * 100 + cents;
////        int total2 = other.dollars * 100 + other.cents;
////        int resultTotal = total1 - total2;
////
////        int resultD = resultTotal / 100;
////        int resultC = resultTotal % 100;
////
////        if (resultC < 0) {
////            resultC += 100;
////            resultD -= 1;
////        }
////
////        return Currency(resultD, resultC);
////    }
////
////    static void normalize(int& d, int& c) {
////        if (c >= 100) {
////            d += c / 100;
////            c = c % 100;
////        }
////        else if (c < 0) {
////            int borrow = (abs(c) + 99) / 100;
////            d -= borrow;
////            c += borrow * 100;
////        }
////    }
////
////    void display() const {
////        cout << "Currency: " << dollars << ".";
////        if (cents < 10) 
////            cout << "0";
////        cout << cents << endl;
////    }
////};
////int main() {
////    Currency c1(10, 50);   
////    Currency c2(3, 75);    
////
////    Currency result = c1 - c2;  
////    result.display();
////
////    Currency c3(5, 10);
////    Currency c4(6, 80);
////
////    Currency result2 = c3 - c4; 
////    result2.display();
////
////    return 0;
////}
//
//
//////****task5****
////class Fraction {
////private:
////	int numerator;
////	int denominator;
////
////public:
////	Fraction(int num = 0, int den = 1) {
////		if (den == 0) {
////			cout << "Denominator can't be zero. Setting to 1.\n";
////			den = 1;
////		}
////		numerator = num;
////		denominator = den;
////	}
////	Fraction operator/(const Fraction& other) const {
////		int newNum = numerator * other.denominator;
////		int newDen = denominator * other.numerator;
////		return reduce(Fraction(newNum, newDen));
////	}
////
////	static Fraction reduce(const Fraction& f) {
////		int g = gcd(f.numerator, f.denominator);
////		return Fraction(f.numerator / g, f.denominator / g);
////	}
////
////	static int gcd(int a, int b) {
////		if (a < 0)
////			a = -a;
////		if (b < 0)
////			b = -b;
////		while (b != 0) {
////			int temp = b;
////			b = a % b;
////			a = temp;
////		}
////		return a;
////	}
////
////	void display() const {
////		cout << numerator << "/" << denominator << endl;
////	}
////};
////int main() {
////	Fraction f1(4,8);
////	Fraction f2(4, 5);
////	Fraction result = f1 / f2;
////	result.display();
////	return 0;
////}
//
//
//////****task6****
////class Logger {
////private:
////	ofstream logFile;
////	static int logCount;
////public:
////	Logger(const string& filename) {
////		logFile.open(filename);
////		if (!logFile.is_open()) {
////			cout << "Fail to open file ";
////		}
////	}
////	friend Logger& operator<<(Logger& logger, const string& message) {
////		if (logger.logFile.is_open()) {
////			logger.logFile << message << endl;
////			logCount++;
////		}
////		return logger;
////	}
////	static int getLogCount() {
////		return logCount;
////	}
////	~Logger() {
////		if (logFile.is_open()) {
////			logFile.close();
////		}
////	}
////};
////int Logger::logCount = 0;
////
////int main() {
////	Logger logger("log.txt");
////
////	logger << "This is lab 7";
////	logger << "Mid exams are going on";
////	logger << "Program ended";
////
////	cout << "Total logs written is " << Logger::getLogCount() << endl;
////
////	return 0;
////}
//
//
//////****task7****
////class Engine {
////private:
////    int horsepower;
////
////public:
////    Engine(int hp = 100) {
////
////    }
////    void start() const {
////
////    }
////};
////
////class Car {
////private:
////    Engine engine;
////    string model;
////
////public:
////    Car(string m, int hp) {
////
////    }
////    void drive() const {
////
////    }
////};
////int main() {
////
////    return 0;
////}
//
//
//////****task8****
////class Shape {
////public:
////    virtual double area() const = 0;  
////    virtual ~Shape() {
////    }               
////};
////
////class Circle : public Shape {
////private:
////    double radius;
////public:
////    Circle(double r) {
////        radius = r;
////    }
////
////    double area() const override {
////        return 3.14 * radius * radius;
////    }
////};
////
////class Rectangle : public Shape {
////private:
////    double width, height;
////
////public:
////    Rectangle(double w, double h) {
////        width = w;
////        height = h;
////    }
////
////    double area() const override {
////        return width * height;
////    }
////};
////int main() {
////    Shape* s1 = new Circle(5.0);
////    Shape* s2 = new Rectangle(4.0, 6.0);
////
////    cout << "Circle area = " << s1->area() << endl;
////    cout << "Rectangle area = " << s2->area() << endl;
////    delete s1;
////    delete s2;
////
////    return 0;
////}
//
//
//////****task9****
////class Box {
////private:
////    double length, width, height;
////public:
////    Box(double l = 1, double w = 1, double h = 1) {
////        length = l;
////        width = w;
////        height = h;
////    }
////
////    friend double totalVolume(const Box& b1, const Box& b2);
////};
////
////double totalVolume(const Box& b1, const Box& b2) {
////    double volume1 = b1.length * b1.width * b1.height;
////    double volume2 = b2.length * b2.width * b2.height;
////    return volume1 + volume2;
////}
////
////int main() {
////    Box box1(2, 3, 4);  
////    Box box2(1, 2, 3);   
////
////    double sum = totalVolume(box1, box2); 
////    cout << "Total volume = " << sum << endl;
////
////    return 0;
////}
//
//
//////****task10****
////class Student {
////private:
////    string name;
////    int rollNo;
////public:
////    Student() {
////        name = "";
////        rollNo = 0;
////    }
////
////    friend istream& operator>>(istream& in, Student& s);
////
////    void display() const {
////        cout << "Name = " << name << ", Roll No = " << rollNo << endl;
////    }
////};
////
////istream& operator>>(istream& in, Student& s) {
////    cout << "Enter nameb = ";
////    getline(in, s.name);
////    cout << "Enter roll number = ";
////    in >> s.rollNo;
////    in.ignore(); 
////    return in;
////}
////int main() {
////    Student s1;
////    cin >> s1;       
////    s1.display();   
////
////    return 0;
////}
