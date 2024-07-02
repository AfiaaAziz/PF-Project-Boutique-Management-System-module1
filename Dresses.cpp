#include <iostream> // header file for input output stream
#include <fstream> // header file for file streams
using namespace std;

// Function declarations
void displayMenu(); // Function to display the menu
void addDress(); // Function to add a dress
void viewDress(); // Function to view all dresses
void searchDress(); // Function to search for a dress by dress code
void updateDress(); // Function to update dress information
void deleteDress(); // Function to delete a dress

int main() // main function from execution of programs starts.
{
    while (true) // loops through the block of code as long as the condition is true.
    {
        displayMenu(); // Call the function to display the menu
    }
    return 0; //return 0 will indicate the successful execution of program.
}

// Function to display the menu
void displayMenu()
{ //starting brackets of function.
    int choice; // Variable to store user's choice
    cout << " *BOUTIQUE MANAGEMENT SYSTEM* " << endl; // Display system title
    cout << "1. Add dress " << endl; // Display menu option
    cout << "2. View dress " << endl; // Display menu option
    cout << "3. Search dress " << endl; // Display menu option
    cout << "4. Update dress " << endl; // Display menu option
    cout << "5. Delete dress " << endl; // Display menu option
    cout << "6. Exit Menu " << endl; // Display menu option
    cout << " Enter your choice " << endl; // Prompt user for choice
    cin >> choice; // Get user input for choice

    switch (choice) // Evaluate user's choice
    { //starting brackets of switch statements.
        case 1:
            addDress(); // Call the function to add a dress
            break; // Exit the switch block after executing case 1
        case 2:
            viewDress(); // Call the function to view all dresses
            break; // Exit the switch block after executing case 2
        case 3:
            searchDress(); // Call the function to search for a dress
            break; // Exit the switch block after executing case 3
        case 4:
            updateDress(); // Call the function to update dress information
            break; // Exit the switch block after executing case 4
        case 5:
            deleteDress(); // Call the function to delete a dress
            break; // Exit the switch block after executing case 5
        case 6:
            exit(0); //terminates program with status code 0
            break; // Exit the switch block after executing case 6
        default:
            cout << "Invalid choice!\n Enter a valid choice" << endl; // Display message for invalid choice
            break; //exit the switch block for any other cases.
    } //closing brackets of switch statements.
} //closing brackets of function.

//Function to add a dress
void addDress()
{
    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price
    ofstream outputfile; // Output stream to create and write to the file
    outputfile.open("dresses.txt", ios::app); // Open the file in append mode to add dress information

    cout << " Enter code of dress: "; // Prompt user for dress code
    cin >> dress_code; // Get user input for dress code
    cout << " Enter Name of dress: "; // Prompt user for dress name
    cin >> dress_Name; // Get user input for dress name
    cout << " Enter the material/type of dress: "; // Prompt user for dress type
    cin >> dress_type; // Get user input for dress type
    cout << " Enter the price of dress: "; // Prompt user for dress price
    cin >> dress_Price; // Get user input for dress price

    // Write dress information to the file
    outputfile << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t\t" << dress_Price << endl;

    cout << "Dress added successfully.\n"; // Display success message
    outputfile.close(); // Close the file
}

// Function to view all dresses
void viewDress()
{
    ifstream fin; // Input stream to read from the file
    fin.open("dresses.txt"); // Open the file for reading

    //using exception handling.
    try
    {
        if (fin.fail()) // Check if reading from the file fails
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e) // Catch and handle runtime error if file operation fails
    {
        cout << "Error" << e.what() << endl; // display the error
    }

    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price

    // Display header for dress information
    cout << "Dress Code\tDress Name\t\tDress Type\t\tDress Price " << endl;

    // Loop through the file's rows and display dress information
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        cout << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t" << dress_Price << endl;
    }
    fin.close(); // Close the file
}

// Function to search for a dress by dress code
void searchDress()
{
    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price
    ifstream fin; // Input stream to read from the file
    fin.open("dresses.txt"); // Open the file for reading

    //using exception handling.
    try
    {
        if (fin.fail()) // check if reading from the file files.
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e) // catch and handle runtime error if file operation fails.
    {
        cout << "Error" << e.what() << endl; // display the error
    }

    string search_code; // Variable to store the dress code to be searched
    cout << " Enter the Code of dress you want to search: "; // Prompt user for the dress code to search
    cin >> search_code; // Get user input for the dress code
    bool found = false; // Variable to track whether the dress is found or not

    // Loop through the file's rows and search for the dress with the specified dress code
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        if (dress_code == search_code) // Check if the dress code matches the search code
        {
            found = true; // Set found to true if the dress is found
            cout << " Dress Found: Code: " << dress_code << endl; // display dress code.
            cout << " Name: " << dress_Name << endl; // display dress name.
            cout << " Type: " << dress_type << endl; // display dress type.
            cout << " Price: " << dress_Price << endl; // display dress price.
        }
    }

    // Display message if the dress is not found
    if (!found)
    {
        cout << " Dress with this " << search_code << " does not found " << endl;
    }
    fin.close(); // Close the file
}

// Function to update the dress information
void updateDress()
{
    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price

    string update_code; // Variable to store the dress code to be updated
    cout << " Enter the dress Code you want to update: "; // Prompt user for the dress code to update
    cin >> update_code; // Get user input for the dress code to update
    ifstream fin; // Input stream to read from the file
    fin.open("dresses.txt"); // Open the file for reading

    //using exception handling.
    try
    {
        if (fin.fail()) // check if reading from the file files.
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e) // catch and handle runtime error if file operation fails.
    {
        cout << "Error" << e.what() << endl; // display the error.
    }

    ofstream fout; // Output stream to create and write to a temporary file
    fout.open("temp.txt"); // Open the temporary file

    // Loop through the file's rows and update the dress information
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        if (dress_code == update_code) // Check if the dress code matches the update code
        {
            cout << " Enter the new price: "; // Prompt user for the new dress price
            cin >> dress_Price; // Get user input for the new dress price
        }
        fout << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t\t" << dress_Price << endl;
    }
    cout << " Price updated successfully "; // Display success message
    fout.close(); // Close the temporary file
    fin.close(); // Close the original file

    // Remove the original file and rename the temporary file to the original file name
    remove("dresses.txt");
    rename("temp.txt", "dresses.txt");
}

// Function to delete a dress
void deleteDress()
{
    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price

    string delete_code; // Variable to store the dress code to be deleted
    cout << " Enter the code of dress you want to delete: "; // Prompt user for the dress code to delete
    cin >> delete_code; // Get user input for the dress code to delete
    ifstream fin; // Input stream to read from the file
    fin.open("dresses.txt"); // Open the file for reading

    //using exception handling.
    try
    {
        if (fin.fail()) // check if reading from the file files.
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e) // catch and handle runtime error if file operation fails.
    {
        cout << "Error" << e.what() << endl; // display the error
    }

    ofstream fout; // Output stream to create and write to a temporary file
    fout.open("temp.txt"); // Open the temporary file

    // Loop through the file's rows and delete the dress information
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        if (dress_code != delete_code) // Check if the dress code does not match the delete code
        {
            fout << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t\t" << dress_Price << endl;
        }
    }
    cout << "Dress deleted successfully"; // Display success message
    fout.close(); // Close the temporary file
    fin.close(); // Close the original file

    // Remove the original file and rename the temporary file to the original file name
    remove("dresses.txt");
    rename("temp.txt", "dresses.txt");
}
