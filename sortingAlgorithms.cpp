#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;


//base class for algorithms.  This has the generatedVector variable with the print and generate vector functions.
class Algo { 
	
	public:
		vector<int> generatedVector;

	protected:
		
		void printVector(vector<int> vec)
		{
			for (int i = 0; i < vec.size(); i++) {
				printf("%d ", vec[i]);
			}
		}
		

		vector<int> GenerateVector(int maxNum)
		{
			vector<int> randomVector;
			randomVector.resize(10);

			for (int i = 0; i < 10; i++) {
				randomVector.at(i)= rand() % maxNum + 1;
			};

			return randomVector;
		}


};

//This is the implementation of a selection sort algorithm. It will print and 
class SelectionSort: public Algo{

	public:


	void sort(int maxNum){

		generatedVector = GenerateVector(maxNum);

		cout << "\nUnsorted\n";
		printVector(generatedVector);
		for (int i=0; i<10; i++)
		{
			for (int j=i+1; j<10; j++)
			{
				if (generatedVector.at(i)>generatedVector.at(j))
				{
					std::swap(generatedVector[i], generatedVector[j]);


				}
			}
		}
		cout << "\nSorted\n";
		printVector(generatedVector);
	}
};

// This  is the usage of the standard library sort function to time it out.
class StdSort: public Algo{

	public:

	void sort(int maxNum){
		generatedVector = GenerateVector(maxNum);
		cout << "\nUnsorted\n";
		printVector(generatedVector);
		std::sort(generatedVector.begin(), generatedVector.end());
		cout << "\nSorted\n";
		printVector(generatedVector);

	}
};

//Main Driver Code
int main() {

	char userChoice = 'y';
	int maxNum = 0;
	SelectionSort sSort;
	StdSort stdSort;
	clock_t t;

	cout << "WANNA SORT SOME NUMBERS?!?!? y/n \n";
	cin >> userChoice;
	
	//Ths While loop will continuously prompt the user to sort numbers until the user enters n.
	while (userChoice == 'y') {
		cout << "Enter a number from 1-100 \n";
		cin >> maxNum;

		//If maxNum is not between 1-100, while loop starts over.
		if((maxNum > 100) || (maxNum < 1))
		{
			continue;
		}

		//Calls the functions and times execution
		t = clock();
		cout << "\nSelection Sort\n";
		sSort.sort(maxNum);
		t = clock() - t;
		printf("\nSelection sorted in %f seconds\n",((float)t)/CLOCKS_PER_SEC);


		t = clock();
		cout << "\n_____________\n";
		stdSort.sort(maxNum);
		t = clock() - t;
		printf("\nStandard library sorted in %f seconds\n",((float)t)/CLOCKS_PER_SEC);
	
		cout << "\nWANNA SORT SOME NUMBERS?!?!?\n";
		cin >> userChoice;
	}
	
	cout << "Bye\n";

	return 0;
}
