// MIKEL PANARITI
// CS-210
// PROJECT THREE
// 02/17/2023

// This program reads data from a file, and prints a list of the products and their frequencies. 
// The user can choose to check the frequency of a specific product, 
// print a list of all products and their frequencies or
// print a list of all products and their frequencies using a histogram. In this case '$' is used.
// Program will ask user for an option to print the lists until user decides to exit the program.



// Declaring libraries that will be used.
#include <iostream>
#include<string>
#include <map>
#include <fstream>

using namespace std;




// Defining productFrequency Class.
class productFrequency {

// Declaring public methods
public:

    // Function reads the input file and generates frequency data
    void processInput(string fileName) {
        ifstream input(fileName);
        if (input.fail()) {
            cout << "Couldn't open the file!" << endl;
            return;
        }

        // Declare variable used in loop 
        string product;
        
        // Go through each item in the file and update its frequency.
        while (input >> product) {
            freqData[product]++;

        }
        input.close();
    }

    // Function gets frequency of a given product.
    int getProductFrequency(string product) {
        return freqData[product];
    }

    // Function prints the list of all prducts with their frequencies.
    void printProductFrequency() {
        for (auto product = freqData.begin(); product != freqData.end(); ++product) {
            cout << product->first << ": " << product->second << endl;
        }
    }

    // Function prints the list of all products and a symbol of their frequencies.
    void printProductFrequencySpecial() {
        for (auto product = freqData.begin(); product != freqData.end(); ++product) {
            cout << product->first << " ";
            for (int i = 0; i < product->second; i++) {
                cout << "$";
            }
            cout << endl;
        }
    }

    // Function writes the item and its frequency to a backup file.
    void backupFile(string fileName) {
        ofstream output(fileName);
        if (output.fail()) {
            cout << "Couldn't open the file!" << endl;
            return;
        }
        for (auto product = freqData.begin(); product != freqData.end(); ++product) {
            output << product->first << ": " << product->second << endl;
        }
        output.close();
    }

// Declaring private members.
private:
    
    // Map used to track the frequency of the product.
    map<string, int> freqData;
};


// Function displays the menu to user. 
void displayMenu() {
    cout << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Look up an item's frequency" << endl;
    cout << "2. Print list of all items and their frequencies" << endl;
    cout << "3. Print list of all items and a histogram for their frequencies" << endl;
    cout << "4. Exit the program" << endl;
    return;


}

// Main function used to run the product.
int main()
{
    // Declaring varaibles used in the main function. 
    int userOption;
    string product;
    int frequency;
    bool run = true;

    //Create an instance of productFrequency classs to use during the main function. 
    productFrequency grocery;

    // Use function to read the file.
    grocery.processInput("CS210_Project_Three_Input_FIle.txt");

    // start a while loop to run until user chooses option 4 to exit the program.
    while(run){
        // Print menu using function.
        displayMenu();
        
        // Ask user for their choice. 
        cout << "Please enter your choice (1-4): ";
        cin >> userOption;

        // Start loop to display data based on user choice.
        switch (userOption) {
            case 1: {

                // Ask user for the product that they want to check the frequency.
                cout << "Please enter the product you want to look up: ";
                cin >> product;

                // Calculate frequency of that product and print it.
                frequency = grocery.getProductFrequency(product);
                cout << " Frequency of " << product << ": " << frequency << endl;
                break;
            }

            case 2: {
                // Print list of products and their frequencies.
                grocery.printProductFrequency();
                break;
            }

            case 3: {
                // Print list of products and their frequencies with histograms.
                grocery.printProductFrequencySpecial();
                break;
            }

            case 4: {
                // Write data into the backup file and exit the program.
                grocery.backupFile("frequency.dat");
                run = false;
                break;
            }
            
                  // Display Invalid choice! if input is not 1-4. 
            default: {
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
                break;
            }



        }
        
    }

    // Print a thank you sentence when user exits program.
    cout << "You have exited the program! Thank you!";

}



