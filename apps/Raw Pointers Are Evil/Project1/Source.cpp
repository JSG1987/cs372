#include<iostream>

using namespace std;


void partuno();
void partdos();


int main()
{
	partuno();
	partdos();

	return 0;
}

void partuno()
{
	const int arraySize = 1000000;

	int* ptr1 = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		ptr1[i] = i;
	}
	int* ptr2 = ptr1;
	delete[] ptr1;

	for (int i = 0; i < 10; i++)
	{
		cout << ptr2[i] << " ";  //execption thrownException thrown: read access violation.
		                        //ptr2 was 0x1E64152.


	}
	cout << endl;
}

void partdos()
{
	const int arraySize = 1000000;
	int* ptr1 = new int[arraySize];

	for (int i = 0; i < arraySize; ++i)
	{
		ptr1[i] = i;
	}
	int* ptr2 = ptr1;
	delete ptr1;

	std::cout << "Address of ptr2: " << ptr2 << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << ptr2[i] << " ";
	}
		cout << endl;

}
