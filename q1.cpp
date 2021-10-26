#include <iostream>
#include <iomanip>

using namespace std;

class GasPump {
	private:
		double amountDispensed,
		       amountCharged,
		       costPerGallon,
               totGas,
               totCost;

	public:
		int seconds;
        double cpg;
        double gasPumpRate;

        double getAmountDispensed() { return amountDispensed; }
		double getAmountCharged() { return amountCharged; }
		double getCostPerGallon() { return costPerGallon; }
		void setCostPerGallon(double cpg) { costPerGallon = cpg; }
        
		void dispense(int seconds) {

            amountDispensed = seconds * gasPumpRate; 
			amountCharged = amountDispensed * costPerGallon;
		}
	    void reset() {
			amountDispensed = 0.0;
			amountCharged = 0.0;
		}		
        double totalGas() {
            totGas += getAmountDispensed();
            return totGas;
        }
        double totalCost() {
            totCost += getAmountCharged();
            return totCost;
        }
};
	
int main() {

    GasPump pump;

    pump.gasPumpRate = 0.10;

    cout << "Enter the price of gas you would like: " << endl;
    cin >> pump.cpg;
    pump.setCostPerGallon(pump.cpg);

    cout << "Enter how long you want to pump gas in seconds: " << endl;
    cin >> pump.seconds;

    cout << "Dispensing..." << endl;
    pump.dispense(pump.seconds);

    pump.totalGas();
    pump.totalCost();

    cout << "You pumped " << pump.getAmountDispensed() << " gallons of gas" << endl; 
    cout << "at a rate of $" << pump.getCostPerGallon() << " per gallon" << endl;
    cout << "for a total price of $" << pump.getCostPerGallon() * pump.getAmountDispensed() << "." << endl;
    cout << "Thank you for your business!";

    pump.reset();
	
	return 0;
}