//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class Vector3D {
//private:
//	double x, y, z;
//
//public:
//	// default constructor
//	Vector3D() : x(0), y(0), z(0) {
//		cout << "default constructor called here " << endl;
//	}
//
//	// parameterized constructor
//	Vector3D(double x, double y, double z) : x(x), y(y), z(z) {
//		cout << "parametrized constructor called here " << endl;
//	}
//
//	// copy constructor
//	Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {
//		cout << "copy constructor called here " << endl;
//	}
//
//	// destructor
//	~Vector3D() {
//		cout << "destructor called here " << endl;
//	}
//
//	// getters
//	double getX() const {
//		return x;
//	}
//	double getY() const {
//		return y;
//	}
//	double getZ() const {
//		return z;
//	}
//
//	// for magnitude
//	double magnitude() const {
//		return std::sqrt(x * x + y * y + z * z);
//	}
//
//	// normalize it...
//	void normalize() {
//		double mag = magnitude();
//		if (mag != 0) {
//			x /= mag;
//			y /= mag;
//			z /= mag;
//		}
//	}
//
//	// for unary +
//	Vector3D operator+() const {
//		return *this;
//	}
//
//	// for unary -
//	Vector3D operator-() const {
//		return Vector3D(-x, -y, -z);
//	}
//
//	// for Binary +
//	Vector3D operator+(const Vector3D& other) const {
//		return Vector3D(x + other.x, y + other.y, z + other.z);
//	}
//
//	// for Binary -
//	Vector3D operator-(const Vector3D& other) const {
//		return Vector3D(x - other.x, y - other.y, z - other.z);
//	}
//
//	// for Dot product
//	double operator*(const Vector3D& other) const {
//		return x * other.x + y * other.y + z * other.z;
//	}
//
//	// for Scalar *
//	Vector3D operator*(double scalar) const {
//		return Vector3D(x * scalar, y * scalar, z * scalar);
//	}
//
//	// for Scalar /
//	Vector3D operator/(double scalar) const {
//		if (scalar != 0)
//			return Vector3D(x / scalar, y / scalar, z / scalar);
//		else
//			return Vector3D();
//	}
//
//	// for Equality
//	bool operator==(const Vector3D& other) const {
//		return (x == other.x && y == other.y && z == other.z);
//	}
//
//	// for Inequality
//	bool operator!=(const Vector3D& other) const {
//		return !(*this == other);
//	}
//
//	// Function to print the vector
//	void print() const {
//		std::cout << "Vector3D(" << x << ", " << y << ", " << z << ")\n";
//	}
//
//	// Pre-increment 
//	Vector3D& operator++() {
//		++x;
//		++y;
//		++z;
//		return *this;
//	}
//
//	// Post-increment 
//	Vector3D operator++(int) {
//		Vector3D temp = *this;
//		x++;
//		y++;
//		z++;
//		return temp;
//	}
//
//};
//
//// scalar * vector
//Vector3D operator*(double scalar, const Vector3D& vec) {
//	return vec * scalar;
//}
//
//void testUnaryOperators() {
//	cout << endl;
//	cout << "*** Testing Unary Operators ***"<<endl;
//	Vector3D v1(1, 2, 3);
//
//	cout << "Original obj1 is "<<endl;
//	v1.print();
//
//	++v1;
//	cout << "After pre-increment "<<endl;
//	v1.print();
//
//	v1++;
//	cout << "After post-increment "<<endl;
//	v1.print();
//
//	Vector3D negated = -v1;
//	cout << "Negated -v1 "<<endl;
//	negated.print();
//}
//
//void testBinaryOperators() {
//	cout << "*** Testing Binary Operators ***"<<endl;
//	Vector3D v1(1, 2, 3);
//	Vector3D v2(2, 2, 3);
//
//	cout << "v1 is " << endl;
//	v1.print();
//	cout << "v2 is " << endl;
//	v2.print();
//	Vector3D sum = v1 + v2;
//	cout << "v1 + v2 = " << endl;
//	sum.print();
//	Vector3D diff = v2 - v1;
//	cout << "v2 - v1 = " << endl;
//	diff.print();
//
//	double dot = v1 * v2;
//	cout << "v1 * v2  = " << dot << endl;
//	if (v1 == v2) {
//		cout << "v1 and v2 are equal" << endl;
//	}
//	else {
//		cout << "v1 and v2 are not equal" << endl;
//	}
//}
//
//
//int main() {
//	Vector3D obj1;
//	Vector3D obj2(1.0, 2.0, 3.0);
//	Vector3D obj3 = obj2;
//
//	obj1.print();
//	obj2.print();
//	obj3.print();
//
//	cout << endl;
//
//	cout << "Magnitude of obj2 is " << obj2.magnitude() << endl;
//
//	cout << "Normalizing obj2..." << endl;
//	obj2.normalize();
//	obj2.print();
//
//	Vector3D pos = +obj2;
//	cout << "Unary +obj2 is ";
//	pos.print();
//
//	Vector3D neg = -obj2;
//	cout << "Unary -obj2 is ";
//	neg.print();
//
//	Vector3D sum = obj2 + obj3;
//	cout << "obj2 + obj3 = ";
//	sum.print();
//
//	Vector3D diff = obj2 - obj3;
//	cout << "obj2 - obj3 = ";
//	diff.print();
//
//	double dot = obj2 * obj3;
//	cout << "Dot product (obj2 * obj3) = " << dot << endl;
//
//	Vector3D scaled = obj3 * 2.0;
//	cout << "obj3 * 2 = ";
//	scaled.print();
//
//	Vector3D divided = obj3 / 2.0;
//	cout << "obj3 / 2 = ";
//	divided.print();
//
//	Vector3D scalarLeft = 3.0 * obj3;
//	cout << "3 * obj3 = ";
//	scalarLeft.print();
//
//	if (obj2 == obj3) {
//		cout << "obj2 and obj3 are equal " << endl;
//	}
//	else {
//		cout << "obj2 and obj3 are not equal " << endl;
//	}
//
//	if (obj2 != obj3) {
//		cout << "obj2 and obj3 are different " << endl;
//	}
//	else {
//		cout << "obj2 and obj3 are the same " << endl;
//	}
//
//	testUnaryOperators();
//	testBinaryOperators();
//
//	return 0;
//}
