//==============================================================================
//  Langage C++ - Apprentissage 4e annee Informatique Polytech Paris-Sud
//                      TP 1 - Approche procedurale de C++
//==============================================================================
#ifndef QUESTION_HPP_INCLUDED
#define QUESTION_HPP_INCLUDED

//==============================================================================
// En-tete standard pour la predefinition des classes de flux
//==============================================================================
#include <iosfwd>

//==============================================================================
// En-tetes standards
//==============================================================================
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <iostream>

//==============================================================================
/**!
* @brief Template complex
**/
//==============================================================================

template <typename T>
class Complex {
public:

	T real;
	T img;

	// Constructor
	Complex(T _real, T _img)
		:real(_real),
		img(_img)
	{}

	Complex() {
		real = T();
		img = T();
	}

	// Operators
	// =
	template <typename X> Complex<T>& operator=(const Complex<X>& other) {

		this->real = other.real;
		this->img = other.img;
		return *this;
	}

	// +=
	template <typename X> Complex<T>& operator+=(const Complex<X>& other) {

		this->real += other.real;
		this->img += other.img;
		return *this;
	}

	Complex<T>& operator+=(const T& other) {

		this->real += other;
		return *this;
	}

	// -=
	template <typename X> Complex<T>& operator-=(const Complex<X>& other) {

		this->real -= other.real;
		this->img -= other.img;
		return *this;
	}

	Complex<T>& operator-=(const T& other) {

		this->real -= other;
		return *this;
	}

	// *=
	template <typename X> Complex<T>& operator*=(const Complex<X>& other) {

		this->real = (this->real * other.real) - (this->img * other.img);
		this->img = (this->real * other.real) + (this->img * other.img);
		return *this;
	}

	Complex<T>& operator*=(const T& other) {

		this->real *= other;
		return *this;
	}

	// /=
	template <typename X> Complex<T>& operator/=(const Complex<X>& other) {

		T r = other.real / ((other.real * other.real) + (other.img * other.img));
		T i = -(other.img/((other.real * other.real)+(other.img * other.img)));
		this->real = (this->real * r) - (this->img * i);
		this->img = (this->real * r) + (this->img * i);
		return *this;
	}

	Complex<T>& operator/=(const T& other) {

		this->real /= other;
		return *this;
	}

	
};

// >>

template <typename T> void operator>>(std::istream& stream, const Complex<T>& c) {

	stream >> c.real;
	stream >> c.img;
}

// << 
template <typename T> std::ostream &operator<<(std::ostream& stream, const Complex<T>& c) {

	return stream << c.real << " + " << c.img << "i";
}

// +
template <typename T> Complex<T> operator+(const Complex<T>& left, const Complex<T>& right) {

	return Complex<T> (left.real + right.real, left.img + right.img);
}

template <typename T> Complex<T> operator+(const T& left, const Complex<T>& right) {

	return Complex<T> (left + right.real, right.img);
}

template <typename T> Complex<T> operator+(const Complex<T>& left, const T& right) {

	return Complex<T> (left.real + right, left.img);
}

// -
template <typename T> Complex<T> operator-(const Complex<T>& left, const Complex<T>& right) {

	return Complex<T> (left.real - right.real, left.img - right.img);
}

template <typename T> Complex<T> operator-(const T& left, const Complex<T>& right) {

	return Complex<T> (left - right.real, right.img);
}

template <typename T> Complex<T> operator-(const Complex<T>& left, const T& right) {

	return Complex<T> (left.real - right, left.img);
}

// *
template <typename T> Complex<T> operator*(const Complex<T>& left, const Complex<T>& right) {

	T r = (left.real * right.real) - (left.img * right.img);
	T i = (left.real * right.real) + (left.img * right.img);
	return Complex<T> (r, i);
}

template <typename T> Complex<T> operator*(const T& left, const Complex<T>& right) {

	return Complex<T> (left * right.real, right.img);
}

template <typename T> Complex<T> operator*(const Complex<T>& left, const T& right) {

	return Complex<T> (left.real * right, left.img);
}

// /
template <typename T> Complex<T> operator/(const Complex<T>& left, const Complex<T>& right) {

	T r = right.real / ((right.real * right.real) + (right.img * right.img));
	T i = -(right.img / ((right.real * right.real) + (right.img * right.img)));
	r = (left.real * r) - (left.img * i);
	i = (left.real * r) + (left.img * i);
	return Complex<T> (r, i);
}

template <typename T> Complex<T> operator/(const T& left, const Complex<T>& right) {

	return Complex<T> (left / right.real, right.img);
}

template <typename T> Complex<T> operator/(const Complex<T>& left, const T& right) {

	return Complex<T> (left.real / right, left.img);
}

// exp

template <typename T> Complex<T> exp(const Complex<T>& c) {

	return Complex<T>(exp(c.real) * cos(c.img), exp(c.real) * sin(c.img));
}

// cos
template <typename T> Complex<T> cos(const Complex<T>& c) {

	Complex<T> z1 (-c.img, c.real);
	Complex<T> z2 (c.img, -c.real);
	z1 = exp(z1);
	z2 = exp(z2);
	z1 = z1 + z2;
	z1 = z1 / Complex<T>(2, 0);
	return z1;
}

// sin
template <typename T> Complex<T> sin(const Complex<T>& c) {

	Complex<T> z1(-c.img, c.real);
	Complex<T> z2 = (c.img, -c.real);
	z1 = exp(z1);
	z2 = exp(z2);
	z1 = z1 - z2;
	z1 = z1 / Complex<T>(0, 2);
	return z1;
}

// Transformée de Fourier discrète
template <typename T> std::vector<Complex<T>> dft(const std::vector<Complex<T>>& signal) {

	std::vector<Complex<T>> retour(signal.size());
	T pi = 3.14;
	
	for (unsigned int i = 0; i < signal.size(); i++) {
		for (unsigned int j = 0; j < signal.size(); j++) {

			//T img = -2 * pi * static_cast<signed int>(i) * (static_cast<signed int>(j) / signal.size());
			retour[i] += signal[j]*exp(Complex<T>(0, -2 * pi * static_cast<signed int>(i) * static_cast<signed int>(j) / static_cast<signed int>(signal.size())));
		}
	}

	return retour;
}

// Transformée de Fourier discrète inverse
template <typename T> std::vector<Complex<T>> inverse_dft(const std::vector<Complex<T>>& signal) {

	std::vector<Complex<T>> retour(signal.size());
	T pi = 3.14;

	for (unsigned int i = 0; i < signal.size(); i++) {
		for (unsigned int j = 0; j < signal.size(); j++) {

			//T img = 2 * pi * static_cast<signed int>(i) * (static_cast<signed int>(j) / static_cast<signed int>(signal.size()));
			retour[i] += signal[j] * exp(Complex<T>(0, 2 * pi * static_cast<signed int>(i) * static_cast<signed int>(j) / static_cast<signed int>(signal.size())));
		}
		
		retour[i] = retour[i] / static_cast<T>(signal.size());
	}

	return retour;
}

// Imaginaire pure
const Complex<int> img_pure = Complex<int>(0, 1);
#endif
