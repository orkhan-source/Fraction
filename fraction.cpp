#include <iostream>

using namespace std;

class Fraction
{
private:
    int numerator, denominator;
public:
    Fraction(int nominator, int denominator);
    int getNumerator(){return numerator;}
    int getDenominator(){return denominator;}
    void setNumerator(int a){ numerator = a;}
    void setDenominator(int a){ denominator = a;}
    double toDouble();
    void simplify();
    Fraction operator+(Fraction &that);
    Fraction operator-(Fraction &that);
    Fraction operator*(Fraction &that);
    Fraction operator/(Fraction &that);
    bool operator==(Fraction &that);
    friend int GCD(int a, int b);
    friend int LCM(int a, int b);
    friend ostream& operator<<(ostream& out, Fraction& fraction)
    {
        out << fraction.numerator << " / " << fraction.denominator;
        return out;
    }
    bool operator==(int a);
    friend bool operator==(int a, Fraction& fraction);
    bool operator==(double a);
    friend bool operator==(double a, Fraction& fraction);
    bool operator!=(Fraction& that)
    {
        return !((*this) == that);
    }

};

int GCD(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }        
    }
    return a;
}

int LCM(int a, int b)
{
    int c, d, e;
    c = max(a, b);
    d = min(a, b);
    e = c;
    while((c % d) != 0)
    {
        c += e;   
    }
    return c;
}

bool operator==(int a, Fraction& fraction)
{
    return a * fraction.denominator == fraction.numerator;
}

bool operator==(double a, Fraction& fraction)
{
    return fraction.toDouble() == a;
}

Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator)
{
}

double Fraction::toDouble()
{
    return (double)numerator / denominator;
}

void Fraction::simplify()
{
    // -4 / -2
    int gcd = GCD(abs(numerator), abs(denominator));
    numerator /= gcd;
    denominator /= gcd;
    // -2 / -1
    if((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0))
    {
        numerator = -numerator;
        denominator = -denominator;
    }
    else if(numerator == 0 && denominator != 0)
    {
        denominator = 1;
    }
       
    // 2 / 1
}
 


// Fraction& Fraction::operator+(Fraction &that)
// {
//     int a = LCM(this->denominator, that.getDenominator());
//     Fraction *result = new Fraction((a / this->denominator) * this->numerator + (a / that.denominator) * that.numerator, a);
//     return *result;
// }

Fraction Fraction::operator+(Fraction &that)
{
    int a = LCM(this->denominator, that.getDenominator());
    Fraction result((a / this->denominator) * this->numerator + (a / that.denominator) * that.numerator, a);
    return result;
}


Fraction Fraction::operator-(Fraction &that)
{
    int a = LCM(this->denominator, that.getDenominator());
    Fraction result((a / this->denominator) * this->numerator - (a / that.denominator) * that.numerator, a);
    return result;
}

Fraction Fraction::operator*(Fraction &that)
{
    Fraction result(this->numerator * that.numerator, this->denominator * that.denominator);
    return result;
}

Fraction Fraction::operator/(Fraction &that)
{
    Fraction result(this->numerator * that.denominator, this->denominator * that.numerator);
    return result;
}

bool Fraction::operator==(Fraction &that)
{   
    // Fraction a(getNumerator(), getDenominator());
    // Fraction b(that.getNumerator(), that.getDenominator());
    // a.simplify();
    // b.simplify();
    // return a.numerator == b.numerator && a.denominator == b.denominator;

    //return (*this) / that == 1; // cagirliacak fonksiyon (bool Fraction::operator==(int a)) 
    return 1 == (*this) / that;
}

bool Fraction::operator==(int a)
{
    //return (double)numerator / denominator == a; 
    return a * denominator == numerator;
}


bool Fraction::operator==(double a)
{
    return this->toDouble() == a;
}


int main()
{
    Fraction a(2, 4);
    Fraction b(3, 9);
    Fraction c = a + b;
    
    //a.simplify();
    int m = LCM(3, 5);
    cout << c.getNumerator() << " " << c.getDenominator() << endl;
    cout << (Fraction(0, 1) - a) << endl;
    
    return 0;
}