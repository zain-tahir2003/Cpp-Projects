#include <iostream> // Required for input and output operations
#include <string> // Required for using and manipulating string data
#include <limits> // Required for handling limits of data types and clearing input buffer
#include <stdexcept> // Required for standard exception handling (e.g., invalid_argument)
#include <sstream> // Required for string stream operations and conversions

using namespace std;

// Function to get valid input from the user
float getValidInput(const string& prompt) {
    float value;
    string input;
    
    while (true) {
        cout << prompt; // Output the prompt message to the user
        getline(cin, input); // Get the entire line of input from the user as a string
        stringstream ss(input); // Create a string stream from the input string
        
        // Check if the input is a valid float and if it's positive
        if (ss >> value && !(ss >> input) && value > 0) {
            return value; // Return the valid input value
        } else {
            cout << "Invalid input. Please enter a numeric value greater than zero." << endl;
            // If the input is invalid, prompt the user to try again
        }
    }
}

// Function to calculate BMI and determine weight category
void calculateBMI() {
    float height, weight;

    while (true) {
        try {
            // Get user input for height and weight using the getValidInput function
            height = getValidInput("Enter Your Height (In Meters): ");
            weight = getValidInput("Enter Your Weight (In KG): ");

            // Check for negative values
            if (height <= 0 || weight <= 0) {
                // Throw an invalid_argument exception if values are non-positive
                throw invalid_argument("Height and weight must be positive numbers.");
            }

            break; // Exit the loop if valid input is received
        } catch (const invalid_argument& e) {
            // Handle invalid argument exceptions
            cout << "Invalid input: " << e.what() << ". Please enter numeric values greater than zero." << endl;
        } catch (const exception& e) {
            // Handle any other exceptions
            cout << "An error occurred: " << e.what() << ". Please try again." << endl;
        }
    }

    // Calculate BMI
    float bmi = weight / (height * height);

    // Print BMI
    cout << "Your BMI is " << bmi << endl;

    // Determine weight category based on BMI
    if (bmi < 18.5) {
        cout << "You are underweight" << endl;
    } else if (bmi >= 18.5 && bmi < 25) {
        cout << "You are normal weight" << endl;
    } else if (bmi >= 25 && bmi < 30) {
        cout << "You are overweight" << endl;
    } else {
        cout << "You are obese" << endl;
    }
}

int main() {
    cout << "******************************************************** BMI CALCULATOR ********************************************************\n" << endl;
    calculateBMI(); // Run the BMI calculator
    cout << "********************************************************************************************************************************\n";
    return 0;
}
