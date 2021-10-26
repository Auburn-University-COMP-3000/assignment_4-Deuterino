#include <iostream>

using namespace std;

class Temperature {
    private:
            double kelvin,
                   celsius,
                   fahrenheit;
    public:
            void setTempKelvin(double kelvin) { this->kelvin = kelvin; }
            void setTempCelsius(double kelvin) { celsius = kelvin - 273.15; }
            void setTempFahrenheit(double kelvin) { fahrenheit = (9.0/5)*celsius + 32; }
            double getTempKelvin() { return kelvin; }
            double getTempCelsius() { return celsius; }
            double getTempFahrenheit() { return fahrenheit; }
};

int main() 
{
    
    Temperature temp;

    double inputTemp;

    cout << "Enter a temperature in Kelvin: " << endl;
    cin >> inputTemp;

    temp.setTempKelvin(inputTemp);
    
    temp.setTempCelsius(temp.getTempKelvin());
    temp.setTempFahrenheit(temp.getTempKelvin());

    cout << "The entered temperature in Kelvin was " << temp.getTempKelvin() << " degrees." << endl;
    cout << "The converted temperature in Celsius is " << temp.getTempCelsius() << " degrees." << endl;
    cout << "The converted temperature in Fahrenheit is " << temp.getTempFahrenheit() << " degrees.";

}