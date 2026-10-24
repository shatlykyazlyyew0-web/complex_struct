#include<iostream>
#include<cmath>
using namespace std;


struct complex{
    double re, im;

    void complexInput();
    void complexOutput();


    bool isEqual(complex);
    double mod();

    complex sum(complex);
    complex sub(complex);
    complex mul(complex);
    complex div(complex);

};

complex complex::sum(complex x){
    complex res;

    res.re  = re + x.re;
    res.im = im + x.im;

    return res;
}

complex complex::sub(complex x){
    complex res;

    res.re = re - x.re;
    res.im = im - x.im; 

    return res;
}

complex complex::mul(complex x){
    complex res;

    res.re = (re * x.re) - (im * x.im);
    res.im = (re * x.im) + (im * x.re);

    return  res;
}

complex complex::div(complex x){
    complex res;
    
    double denom = (x.re * x.re) + (x.im * x.im);
    
    if (denom == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        res.re = 0; 
        res.im = 0;
        return res;
    }

    res.re = ((re * x.re) + (im * x.im)) / denom;
    
    res.im = ((im * x.re) - (re * x.im)) / denom;
    
    return res;
}

void complex::complexInput(){
    cout<<"re: ";
    cin>>re;
    cout<<"im: ";
    cin>>im;
}

bool complex::isEqual(complex x){
    return (re==x.re&&im==x.im);
}

double complex::mod(){
    double testmod = sqrt((re*re)+(im*im));
    return testmod;
}

void complex::complexOutput() {
    cout << re;
    if (im >= 0) 
        cout << " + " << im << "i";
    else 
        cout << " - " << -im << "i"; 
    cout << endl;
}



int main(){

    complex c1, c2, result, resultsub, resultmul, resultdiv;

    c1.complexInput();
    c2.complexInput();

    double testmod = c1.mod();
    cout<<"mod::"<<testmod<<endl;

    if (c1.isEqual(c2)) {
        cout << "equal" << endl;
    } else {
        cout << "not equal" << endl;
    }

    result = c1.sum(c2);    
    resultsub = c1.sub(c2);
    resultmul = c1.mul(c2);
    resultdiv = c1.div(c2);

    result.complexOutput(); 
    resultsub.complexOutput();
    resultmul.complexOutput();
    resultdiv.complexOutput();


    return 0;


}