#include <iostream>

class Complex
{
private:
    double m_a;
    double m_b;
public:
    //базовый конструктор
    Complex(double a=0.0, double b=0.0):m_a(a), m_b(b){}
    //конструктор копирования
    Complex(const Complex& z)
    {
        m_a =z.m_a;
        m_b=z.m_b;
    }
    //оператор присваивания копированием
    Complex& operator = (Complex z)
    {
        std::swap(m_a, z.m_a);
        std::swap(m_b, z.m_b);
        return *this;
    }
    //деструктор
    ~Complex(){}
    //операторы +=
    Complex& operator+=(const Complex& z)//rvo
    {
        Complex temp = *this;
        (*this).m_a += z.m_a;
        (*this).m_b += z.m_b;
        return *this;
    }
    //оператор *=
    Complex& operator*=(const Complex& z)
    {
        double a = m_a;
        m_a =  m_a * z.m_a - m_b * z.m_b;
        m_b = a * z.m_b + m_b * z.m_a;
        return *this;
    }
    // оператор *
    Complex operator*(const Complex z2)
    {
        Complex temp;
        temp.m_a = m_a * z2.m_a - m_b * z2.m_b;
        temp.m_b = m_a * z2.m_b + m_b * z2.m_a;
        return temp;
    }
    //оператор ++ префиксный
    Complex& operator++()
    {
        this->m_a +=1;
        return *this;
    }

    //оператор ++ постфиксный
    Complex& operator++(int)
    {
        Complex temp =*this;
        this-> m_a+=1;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& z);
    friend std::istream& operator>>(std::istream& in, Complex& z);
};

Complex operator+(const Complex& z1, const Complex z2) //rvo
{
    Complex temp = z1;
    temp += z2;
    return temp;
}

//операторы вывода
std::ostream& operator<<(std::ostream& out, const Complex& z)
{
    out << z.m_a <<" "<<z.m_b<<"i";
    return out;
}

std::istream& operator>>(std::istream& in, Complex& z)
{
    in >> z.m_a >> z.m_b;
    return in;
}

int main()
{
    Complex z1;

    std::cin >> z1;
    Complex z2(1,2);

    std::cout << z1 + z2 << std::endl;
    return 0;
}
