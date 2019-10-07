/*
* Class: CS2A
* Description: CandyCalculator calculates the number of candy bars needed for a person to maintain his/her weight. 
* This is done by calculating BMR, which is based on gender, weight, height, age, and activity.  
* Due date: Oct 14, 2019
* Name: Alina Li
* File name: CandyCalculator.cpp
*/

#include <iostream>
using namespace std;

#define AGE_MIN 1
#define AGE_MAX 100
#define HEIGHT_MIN 10
#define HEIGHT_MAX 100
#define WEIGHT_MIN 10
#define WEIGHT_MAX 500
#define CANDY_BAR_CAL 230
#define ACTIVITY_A 1.2
#define ACTIVITY_B 1.3
#define ACTIVITY_C 1.4
#define ACTIVITY_D 1.5

int main()
{
	cout << "This program will calculate the number of 230 calorie candy bars to eat to maintain your weight." << endl;
	
	cout << "What is your age in years?" << endl;
	int age;
	cin >> age;
	if ((age < AGE_MIN) || (age > AGE_MAX))
	{
		cout << "You must enter an age between 1 and 100.";
		return 0;
	}

	cout << "What is your total height in inches?" << endl;
	int height;
	cin >> height;
	if ((height < HEIGHT_MIN) || (height > HEIGHT_MAX))
	{
		cout << "You must enter a height between 10 and 100.";
		return 0;
	}

	cout << "What is your weight in pounds?" << endl;
	int weight;
	cin >> weight;
	if ((weight < WEIGHT_MIN) || (weight > WEIGHT_MAX))
	{
		cout << "You must enter a weight between 10 and 500.";
		return 0;
	}

	cout << "Enter M for male calculation and F for female calculation." << endl;
	char gender;
	cin >> gender;
	if ((gender != 'M') && (gender != 'F'))
	{
		cout << "You must enter either M or F.";
		return 0;
	}

	double BMR;
	if (gender == 'M')
	{
		BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
	}
	else // gender is F
	{
		BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
	}

	cout << "Are you:" << endl;
	cout << "	A. Sedentary" << endl;
	cout <<	"	B. Somewhat active (exercise ocasionally)" << endl;
	cout << "	C. Active (exercise 3-4 days per week)" << endl;
	cout << "	D. Highly active (exercise everday)" << endl;
	cout << "Enter A, B, C, or D." << endl;
	char activity;
	cin >> activity;

	if ((activity != 'A') && (activity != 'B') && (activity != 'C') && (activity != 'D'))
	{
		cout << "You must enter A, B, C, or D.";
		return 0;
	}

	double increaseBMR;
	if (activity == 'A')
	{
		increaseBMR = ACTIVITY_A;
	}
	else if (activity == 'B')
	{
		increaseBMR = ACTIVITY_B;
	}
	else if (activity == 'C')
	{
		increaseBMR = ACTIVITY_C;
	}
	else // activity is D
	{
		increaseBMR = ACTIVITY_D;
	}

	BMR *= increaseBMR;
	double candyBars = BMR / CANDY_BAR_CAL;

	cout << "A ";
	if (gender == 'M')
	{
		cout << "male";
	}
	else
	{
		cout << "female";
	}
	cout << " with those measurements should eat " << candyBars 
		<< " candy bars per day to maintain the same weight.";

	return 0;
}