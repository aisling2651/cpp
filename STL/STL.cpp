// STLexercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int question1();
int question2();
int question3();
int question4();
int question6();
int question8();
int question9();
int question10();
int question12();
int question13();
int question14();

int main()
{
	question14();

}


int question1()
{
	ifstream in("nums.txt");
	if (in)
	{
		vector<int>nums;
		int num;
		while (!in.eof())
		{
			in >> num;
			nums.push_back(num);
		}

		cout << "Please enter a number to find: ";
		int search;
		cin >> search;
		bool found = false;

		/*for (int i = 0; i < nums.size(); i++)
		{

			if (nums[i] == search)
			{
				cout << search << " found at position " << i << endl;
				found = true;
			}
			
			if (i != 0)
			{
				cout  <<", ";

			}
			cout << nums[i];

		}*/

		/*if (!found)
		{
			cout << search << "has not been found ";
		}*/


		if (find(nums.begin(), nums.end(), search) != nums.end())
		{
			cout << search << " has been found";

		}
		else
		{
			cout << search << " has not been found";
		}
		in.close();
	}
	else
	{
		cout << "Error opening file";
	}
	return 0;
}


int question2()
{
	ifstream in("nums.txt");
	if (in)
	{
		list<int>nums;
		int num;
		while (!in.eof())
		{
			in >> num;
			nums.push_back(num);
		}

		cout << "Please enter a number to find: ";
		int search;
		cin >> search;
		bool found = false;
		int i = 0;
		for (list<int>::iterator iter = nums.begin(); iter != nums.end(); iter ++)
		{

			if (*iter == search)
			{
				cout << search << " found at position " << i << endl;
				found = true;
			}
			i++;


		}


	}
	else
	{
		cout << "Error opening file";
	}
	return 0;
}

void display(vector<int> nums)
{
	for (int i = 0; i < nums.size(); i++)
	{


		if (i != 0)
		{
			cout << ", ";

		}
		cout << nums[i];
	}

}

double getMedian(vector<int> nums)
{
	vector<double>::size_type size = nums.size();
	vector<double>::size_type mid = size / 2;
	if (size % 2 == 0)
	{
		//median is the average of the middle two elements
		return (nums[mid - 1] + nums[mid]) / 2.0f;
	}
	else
	{
		//Uneven so just return the mid element
		return nums[mid];
	}


}

int question4()
{
	ifstream in("nums.txt");
	if (in)
	{
		vector<int>nums;
		int num;
		while (!in.eof())
		{
			in >> num;
			nums.push_back(num);
		}

		cout << "Median is : " <<  getMedian(nums);
	}
	return 0;

}

int question3()
{
	ifstream in("nums.txt");
	if (in)
	{
		vector<int>nums;
		int num;
		while (!in.eof())
		{
			in >> num;
			nums.push_back(num);
		}


		display(nums);
		sort(nums.begin(), nums.end());
		cout<<"\nSorted ascending order: ";
		display(nums);
		cout << "\nShuffled:  ";
		random_shuffle(nums.begin(), nums.end());
		display(nums);
		//sort(nums.begin(), nums.end(), greater<int>());
		//anonymous function
		sort(nums.begin(), nums.end(), [](int x, int y) {return x > y; });
		cout << "\nSorted descending order: ";
		display(nums);



	}
	else
	{
		cout << "Error opening file";
	}
	return 0;
}


void splitOneMedian(vector<int>& nums, vector<int>& above, vector<int>& below, int &total)
{
	double median = getMedian(nums);
	total = nums.size();

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < median)
		{
			below.push_back(nums[i]);
		}
		else
		{
			above.push_back(nums[i]);
		}
	}


}

void print(const string& prompt, const vector<int>& items)
{
	cout << prompt <<"[";
	for (int i = 0; i < items.size(); i++)
	{
		if (i != 0)
		{
			cout << ",";
		}
		cout << items[i];
	}
	cout << "]" << endl;
}
//Question 7
void print(const string& prompt, const list<int>& items)
{
	cout << prompt << "[";
	for (list<int>::const_iterator iter = items.begin(); iter !=items.end(); iter++)
	{
		if (iter != items.begin())
		{
			cout << ",";
		}
		cout << *iter;
	}
	cout << "]" << endl;
}


int question6()
{
	vector<int> nums;
	vector<int> above;
	vector<int> below;
	list<int> numbers;

	ifstream in("nums.txt");
	if(in)
	{
		int i; 
		while (!in.eof())
		{
			in >> i;
			numbers.push_back(i);
			nums.push_back(i);
		}
		int total;
		splitOneMedian(nums, above, below, total);
		print("Above: ", above);
		print("Below: ", below);
		print("Numbers: ", numbers);

		cout << "\nThere are " << total << " items"<<endl;
	}
	else
	{
		cout << "Error opening file";
	}

	return 0;
	
}




float  getAverage(const vector<int>& nums)
{
	float total =0;
	int count =0;

	for (const int& i : nums)
	{
		total += i;
		count++;
	}

	return total / nums.size();
}
float getStdDev(vector<int> nums)
{
	float stdDev = 0.0;

	float avg = getAverage(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		stdDev += pow(nums[i] - avg, 2);
	}
	return sqrt(stdDev / nums.size());
}

int question8()
{
	vector<int> nums = { 600,470,170,430,300 };
	cout << "Standard Deviation = " << getStdDev(nums) << endl;
	return 0;
}

int question9()
{
	vector<string> months = { "Jan", "Apr", "May", "Sept", "Nov", "Dec" };
	vector<string>::iterator iter = months.begin();
	iter++;
	iter = months.insert(iter,"Feb")+1;
	iter = months.insert(iter,"Mar")+3;
	iter = months.insert(iter, "Jun") +1;
	iter = months.insert(iter, "Jul") + 1;
	iter = months.insert(iter, "Aug") + 2;
	months.insert(iter, "Oct") + 2;

	for (string i : months)
	{
		cout << i<<endl;
	}

	return 0;
}

//bool areSame(vector<int> a, vector<int> b)
//{
//	if (a.size() != b.size())
//		return false;
//	vector<int> copy(b);
//	for (const int& x : a)
//	{
//		for (int i = 0; i < copy.size(); i++)
//		{
//			if (x == copy[i])
//			{
//				copy.erase(copy.begin() + i);
//				break;
//			}
//		}
//	}
//
//	return copy.size == 0;
//
//
//}
int question10()
{

	/*vector<int> list1 = { 1,2,3,4,5,1 };
	vector<int> list2 = { 1,2,3,4,5,2};
	print("List A: ", list1);
	print("List B: ", list2);
	cout << "\nDo the lists match? ";
	if (areSame(list1, list2) == 0)
	{
		cout << "No False" << endl;
	}
	else
	{
		cout << "Yes True" << endl;
	}*/
	return 0;

}

vector<int>::size_type areSameUntil(const vector<int>& a, const vector<int>& b)
{
	vector<int>::size_type max = a.size() > b.size() ? a.size() : b.size();

	for (vector<int>::size_type i = 0; i < max; i++)
	{
		if (i < a.size() && i < b.size() && a[i] == b[i])
		{
			i++;
		}
		else
		{
			return i - 1;
		}
	}
	return max-1;
	
}

int question12()
{

	vector<int> list1 = { 1,2,3 };
	vector<int> list2 = { 1 ,2,6,5};
	int same1 = areSameUntil(list1, list2);
	print("Test 1\nList A: ", list1);
	print("List B: ", list2);
	cout << "\nDo the lists match? ";
	cout << "vectors are the same until index " << same1 << "\n" << endl;

	vector<int> list3 = { 4,5,6 };
	vector<int> list4 = { 7,8};
	same1 = areSameUntil(list3, list4);
	print("Test 2\nList A: ", list3);
	print("List B: ", list4);
	cout << "Do the lists match? ";
	cout << "vectors are the same until index " << same1 << "\n" << endl;

	vector<int> list5 = { 12,34,56 };
	vector<int> list6 = { 12,34,56 };
	same1 = areSameUntil(list5, list6);
	print("Test 3\nList A: ", list5);
	print("List B: ", list5);
	cout << "Do the lists match? ";
	cout << "vectors are the same until index " << same1 <<"\n"<< endl;

	

	return 0;

}

bool areSameReverse(const list<int>& a, const list<int>& b)
{
	list<int>::const_iterator it = a.begin();
	list<int>::const_reverse_iterator it2 = b.rbegin();
	while (it != a.end() && it2 != b.rend())
	{
		if (*it != *it2)
		{
			return false;
		}
		it++; it2++;
	}
	return true;
}



int question13()
{
	list<int> list1 = { 1,2,3,4,5 };
	list<int> list2 = { 5,4,3,2,5};


	if (areSameReverse(list1, list2))
	{
		cout << "List 1 is the reverse of list 2" << endl;
	}
	else
	{
		cout << "List 1 is not the reverse of list 2" << endl;
	}

	
	
	return 0;
}

bool palindrome(const string a)
{
	string::const_iterator it = a.begin();
	string::const_reverse_iterator it2 = a.rbegin();
	while (it != a.end() && it2 != a.rend())
	{
		if (*it != *it2)
		{
			return false;
		}
		it++; it2++;
	}
	return true;
}

int question14()
{

	string name = "hannah";
	if (palindrome(name))
	{
		cout << name << " is a palindrome" << endl;
	}
	else
	{
		cout << name << " is not a palindrome" << endl;
	}
	return 0;
}
