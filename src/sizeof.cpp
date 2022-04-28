#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

int main(int argc, char * argv[])
{
	char * seq = new char[100];
	for(int i = 0; i < 50; i++)
	{
		seq[i] = 'c';
	}
	for(int i = 60; i< 100; i++)
		seq[i] = 'd';
	for(int i = 0; i < 80; i++)
		cout << seq[i];
	cout << endl;
	cout << "strlen(seq) is: " << strlen(seq) << endl;
	cout << "sizeof(seq) is: " << sizeof(seq) << endl;

	char str[100] = "hello world";
	cout << "strlen(str) is: " << strlen(str) << endl;
	cout << "sizeof(str) is: " << sizeof(str) << endl;

	string cplusplusstr = "hello world hhljhfkdsfjlsdjfs";
	cout << "sizeof(c++str) is: " << sizeof(cplusplusstr) << endl;
	cout << "sizeof(c++str.c_str()) is: " << sizeof(cplusplusstr.c_str()) << endl;
	cout << "strlen(c++str.c_str()) is: " << strlen(cplusplusstr.c_str()) << endl;

	int arr[100];
	int arr1[] = {1, 2, 3, 4, 5, 6, 7};
	cout << "sizeof int arr is: " << sizeof(arr) << endl;
	cout << "sizeof(arr) / sizeof(arr[0]) is: " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "sizeof int arr1 is: " << sizeof(arr1) << endl;
	cout << "sizeof(arr1) / sizeof(arr1[0]) is: " << sizeof(arr1) / sizeof(arr1[0]) << endl;

	vector<int> int_vec;
	vector<string> str_vec;
	vector<double> double_vec;
	cout << "sizeof(int_vec) is: " << sizeof(int_vec) << endl;
	cout << "sizeof(str_vec) is: " << sizeof(str_vec) << endl;
	cout << "sizeof(double_vec) is: " << sizeof(double_vec) << endl;
	int_vec.push_back(1);
	int_vec.push_back(2);
	int_vec.push_back(3);
	str_vec.push_back("hello");
	str_vec.push_back("hello");
	double_vec.push_back(1.0);
	double_vec.push_back(1.0);
	double_vec.push_back(1.0);
	double_vec.push_back(1.0);
	double_vec.push_back(1.0);
	double_vec.push_back(1.0);

	cout << "sizeof(int_vec) is: " << sizeof(int_vec) << endl;
	cout << "sizeof(str_vec) is: " << sizeof(str_vec) << endl;
	cout << "sizeof(double_vec) is: " << sizeof(double_vec) << endl;

	unordered_map<int, double> int_map;
	unordered_map<string, int> str_map;
	cout << "sizeof(int_map) is: " << sizeof(int_map) << endl;
	cout << "sizeof(str_map) is: " << sizeof(str_map) << endl;

	unordered_set<int> int_set;
	unordered_set<string> str_set;
	cout << "sizeof(int_set) is: " << sizeof(int_set) << endl;
	cout << "sizeof(str_set) is: " << sizeof(str_set) << endl;


}
