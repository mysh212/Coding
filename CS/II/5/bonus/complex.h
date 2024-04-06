
class Complex{
    private:
    double real,imag;

    public:
    Complex(double,double);
    ~Complex();
    Complex add(Complex);
    Complex multiply(Complex);
    Complex divide(Complex);
    Complex conjugate();
    inline Complex operator=(Complex);
    inline Complex operator+(Complex);
    inline Complex operator+(double);
    inline Complex operator-(Complex);
    inline Complex operator-(double);
    inline Complex operator*(Complex);
    inline Complex operator*(double);
    inline Complex operator/(Complex);
    inline Complex operator/(double);
    inline Complex operator|(bool);
    inline double operator()();

    inline void print(ostream &out);
};