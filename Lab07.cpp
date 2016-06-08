//**************************************************************************************************************
// FILE:        Lab07.cpp
//
// DESCRIPTION: Calculates a person's lucky number using Zelda's Even Better Lucky Number formula
//
//              Illustrates the following C++ concepts:
//              1. Concepts covered in Labs 1-6.
//              2. Writing if statements to alter flow of control.
//              3. Writing programs involving multiple functions.
//              4. Calling functions and passing paramters by value.
//              5. Returning values from functions..
//
// AUTHORS:     Zoe Aiyanna M. Cayetano            (zcayetan@asu.edu)
//
// COURSE:      CSE100 Principles of Programming with C++, Sprig 2016
//
// -------------------------------------------------------------------------------------------------------------
// TEST CASE 1:
// -------------------------------------------------------------------------------------------------------------
// DESCRIPTION:
// Tests that the correct lucky number is calculated and displayed.
//
// TEST CASE INPUT DATA:
// Customer name          = Cletus
// Birthdate month        = 8
// Birthdate day          = 31
// Birthdate year         = 1961
// Height in inches       = 70
// Weight in pounds       = 190
// Eye color              = Brown (e will be 5)
// Index finger in inches = 3.1
// Ring finger in inches  = 3.8 (f will be -1)
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Cletus, your lucky number is 10. Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Cletus, your lucky number is 10. Thank you, that will be $25."
//
// TEST CASE RESULT: PASSED
//
// -------------------------------------------------------------------------------------------------------------
// TEST CASE 2:
// -------------------------------------------------------------------------------------------------------------
// DESCRIPTION:
// Tests that the correct lucky number is calculated and displayed.
//
// TEST CASE INPUT DATA:
// Customer name          = Derek
// Birthdate month        = 9
// Birthdate day          = 4
// Birthdate year         = 1990
// Height in inches       = 67
// Weight in pounds       = 180
// Eye color              = Blue (e will be 2)
// Index finger in inches = 2.5
// Ring finger in inches  = 2.8 (f will be -1)
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Derek, your lucky number is 9. Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Derek, your lucky number is 9. Thank you, that will be $25."
//
// TEST CASE RESULT: PASSED
//
// -------------------------------------------------------------------------------------------------------------
// TEST CASE 3:
// -------------------------------------------------------------------------------------------------------------
// DESCRIPTION:
// Tests that the correct lucky number is calculated and displayed.
//
// TEST CASE INPUT DATA:
// Customer name          = Zoe
// Birthdate month        = 10
// Birthdate day          = 22
// Birthdate year         = 1997
// Height in inches       = 63
// Weight in pounds       = 102
// Eye color              = Black (e will be 1)
// Index finger in inches = 3.0
// Ring finger in inches  = 2.7 (f will be +1)
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Zoe, your lucky number is 7. Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Zoe, your lucky number is 7. Thank you, that will be $25."
//
// TEST CASE RESULT: PASSED
//**************************************************************************************************************
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const double CM_PER_INCH =       2.54;
const double LB_PER_KG   = 2.20462262;

const int MENU_BLACK   = 1;
const int MENU_BLUE    = 2;
const int MENU_GREEN   = 3;
const int MENU_BROWN   = 4;
const int MENU_GRAY    = 5;
const int MENU_HAZEL   = 6;
const int MENU_RED     = 7;
const int MENU_PINK    = 8;
const int MENU_VIOLET  = 9;

void ValidateEyeColor(int pChoice);

int GetInt(string pPrompt);

int CalcLucky(int pDate, int pHeight, int pMonth, int pWeight, int pYear, int pEye, int pFinger)
{
    double term1;
    term1 = (2 * (pow(pMonth, 2.2))) + (3 * (pow(pDate, 3.3))) + (5 * sqrt(pYear));

    int term2;
    term2 = (pEye * pHeight) / 3;

    int term3;
    term3 = (11 * pWeight) / 5;

    double term4;
    term4 = term1 + (pFinger * (term2 + term3));

    return static_cast<int>(abs(term4)) %10 + 1;
}

double ConvertInchToCm(double pInches)
{
    return pInches * CM_PER_INCH;
}

double ConvertLbToKg(double pLbs)
{
    return pLbs / LB_PER_KG;
}

double GetDouble(string pPrompt)
{
    double n;
    cout << pPrompt;
    cin >> n;
    return n;
}

int GetEyeColor(int pEye)
{
    cout << "What color are your eyes?" << endl;
    cout << "1.   Black" << endl;
    cout << "2.   Blue" << endl;
    cout << "3.   Green" << endl;
    cout << "4.   Brown" << endl;
    cout << "5.   Gray" << endl;
    cout << "6.   Hazel" << endl;
    cout << "7.   Red" << endl;
    cout << "8.   Pint" << endl;
    cout << "9.   Violet" << endl;

    int pChoice;
    pChoice = GetInt("Select Eye Color: ");

    ValidateEyeColor(pChoice);

    int e;

    if (pChoice == MENU_BLACK) {
        e = 3;
    } else if (pChoice == MENU_BLUE) {
        e = -2;
    } else if (pChoice == MENU_GREEN) {
        e = 17;
    } else if (pChoice == MENU_BROWN) {
        e = 5;
    } else if (pChoice == MENU_GRAY) {
        e = 12;
    } else if (pChoice == MENU_HAZEL) {
        e = -8;
    } else if (pChoice == MENU_RED) {
        e = 4;
    } else if (pChoice == MENU_PINK) {
        e = 0;
    } else if (pChoice == MENU_VIOLET) {
        e = 11;
    }
    
    return e;
}

int GetInt(string pPrompt)
{
    int n;
    cout << pPrompt;
    cin >> n;
    return n;
}

string GetString(string pPrompt)
{
    string s;
    cout << pPrompt;
    cin >> s;
    return s;
}

int Round(double pDouble)
{
    if (pDouble >= 0) {
        return static_cast<int>(pDouble + 0.5);
    } else {
        return static_cast<int>(pDouble - 0.5);
    }
}

void ValidateEyeColor(int pChoice)
{
    if (pChoice < MENU_BLACK || pChoice > MENU_VIOLET) {
        cout << "An invalid eye color was selected. The program is terminating..." << endl;
        exit(-1);
    }
}

int main()
{
    cout << "Zelda's Lucky Number Calculator" << endl << endl;
    
    int date, e, heightCm, heightIn, lucky, month, weightKg, weightLb, year;
    
    double f, index, ring;
    string name;
    name = GetString("What is your name? ");
    month = GetInt("In what month were you born? ");
    date = GetInt("What was the date? ");
    year = GetInt("What was the year (yyyy)? ");
    heightIn = GetInt("What is your height (inches)? ");
    weightLb = GetInt("What is your weight (lbs)? ");
    heightCm = Round(ConvertInchToCm(heightIn));
    weightKg = Round(ConvertLbToKg(weightLb));
    e = GetEyeColor(e);
    index = GetDouble("How long is your index finger? ");
    ring = GetDouble("How long is your ring finger? ");
    f = 0;
    
    if (index < ring) {
        f = -1;
    } else if (index > ring) {
        f = 1;
    }
    
    lucky = CalcLucky (date, heightCm, month, weightKg, year, e, f);
    
    cout << name << ", your lucky number is " << lucky << ". Thank you, that will be $25." << endl;
    
    return 0;
}