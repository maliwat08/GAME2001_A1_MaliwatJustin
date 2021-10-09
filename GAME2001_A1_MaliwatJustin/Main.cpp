#include <iostream>	
#include "Array.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"
using namespace std;

int main()
{

	cout << "Unordered Int Array" << endl;
	UnorderedArray<int> array(5);
	OrderedArray<int> arraydup(5);

	array.push(69);
	array.push(31);
	array.push(94);
	array.push(55);
	array.push(64);

	for (int i = 0; i < array.getSize(); i++)
	{
		cout << array[i] << ", ";
	}
	cout << endl;
	cout << endl;
	cout << "Check if there's any duplicate data" << endl;
	cout << endl;
	arraydup.setDuplicateData(true);


	cout << "Ordered Int Array" << endl;
	arraydup.push(5);
	arraydup.push(94);
	arraydup.push(15);
	arraydup.push(31);
	arraydup.push(69);

	for (int i = 0; i < arraydup.getSize(); i++)
	{
		cout << arraydup[i] << ",";
	}
	arraydup.push(94);


	cout << endl;
	cout << "Expanding" << endl;
	array.push(2);
	cout << array.getGrowSize() << endl;
	array.push(4);
	cout << array.getGrowSize() << endl;
	





	


}