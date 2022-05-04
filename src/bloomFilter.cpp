/* Author: Xiaoming Xu
 * Data: 2022/5/4
 * The bloom_filter_ontime.cpp is used for testing generating bloom filter compared with map retrieving. 
 * The bloom filter is finished when lookup the table.
 *
 *
 */
#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <string>//stoi
#include <cstdio>
#include <unordered_set>
#include <string.h>//memset

#include <sys/time.h>


double get_sec(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (double)tv.tv_sec + (double)tv.tv_usec/1000000;
}


using namespace std;

int main(int argc, char * argv[]){
	
	if(argc < 4){
		cerr << "run as: " << argv[0] << " 30 1 finded.out" << endl;
		cerr << "the second parameter(30) is the totalNumber(1<<30) for random generator;" << endl;
		cerr << "the third parameter(20) means the seedNumber(1<<20) for generation unordered_set or bloom filter; " << endl;
		cerr << "the fourth parameter(finded.out means the output findedArr " << endl;
		return 1;
	}
	int numBit = stoi(argv[1]);
	int seedBit = stoi(argv[2]);
	string outputFile = argv[3];

	uint64_t totalNumber = 1 << numBit;//1MB
	uint64_t seedNumber = 1 << seedBit;

	srand(23);//seed 23 for generating dictionary
	int * seedArr = new int[seedNumber];
	for(int i = 0; i < seedNumber; i++)
	{
		seedArr[i] = random();
	}

	double ta = get_sec();

	unordered_set<int> findedSet0;
	for(int i = 0; i < seedNumber; i++)
	{
		int key = seedArr[i];
		findedSet0.insert(key);
	}

	double tb  = get_sec();
	cerr << "size of findedSet0 is: " << findedSet0.size() << endl;
	cerr << "================the time of generating unordered_set dictionary is: " << tb - ta << endl;

	unordered_set<int> findedSet1;
	uint64_t bloomArrSize = 1 << 29;
	char * bloomArr = new char[bloomArrSize];
	memset(bloomArr, 0, bloomArrSize * sizeof(char));

	for(int i = 0; i < seedNumber; i++)
	{
		int key = seedArr[i];
		bloomArr[(1713137323*key)&(bloomArrSize-1)] = 1;
		bloomArr[(371371377*key)&(bloomArrSize-1)] = 1;
		bloomArr[key&(bloomArrSize-1)] = 1;
		findedSet1.insert(key);
	}

	double tc = get_sec();
	cerr << "size of findedSet1 is: " << findedSet1.size() << endl;
	cerr << "================the time of generating bloom filter and unordered_set dictionary is: " << tc - tb << endl;


	int * randomArr = new int[totalNumber];
	struct timeval tv;
	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	
	double t0 = get_sec();
	for(int i = 0; i < totalNumber; i++)
	{
		randomArr[i] = random();
	}
	double t1 = get_sec();
	cerr << "================the time of generating random array is: " << t1 - t0 << endl;

	//RAND_MAX = 1 << 31 -1;
	//printf("%lx\n", RAND_MAX);
	
	vector<int> findedArr0;
	vector<int> findedArr1;
	for(int i = 0; i < totalNumber; i++)
	{
		int key = randomArr[i];
		if(findedSet0.find(key) != findedSet0.end())
		{
			findedArr0.push_back(key);
		}
	}

	double t2 = get_sec();
	cerr << "=================the time of unordered_set is: " << t2 - t1 << endl;

	cerr << "the totalNumber is: " << totalNumber << endl;
	cerr << "the size of findedArr0 is: " << findedArr0.size() << endl;

	string outputFile0 = outputFile + ".set.out";
	FILE * fp0 = fopen(outputFile0.c_str(), "w");
	for(int i = 0; i < findedArr0.size(); i++)
	{
		fprintf(fp0, "%d\t%d\n", i, findedArr0[i]);
	}
	double t3 = get_sec();
	cerr << "=================the time of output unordered_set is: " << t3 - t2 << endl;


	for(int i = 0; i < totalNumber; i++)
	{
		int key = randomArr[i];
		if(bloomArr[(1713137323*key)&(bloomArrSize-1)] == 0)
		{
			continue;
		}
		if(bloomArr[(371371377*key)&(bloomArrSize-1)] == 0)
		{
			continue;
		}
		if(bloomArr[key &(bloomArrSize-1)] == 0)
		{
			continue;
		}
		if(findedSet1.find(key) != findedSet1.end())
		{
			findedArr1.push_back(key);
		}
	}
	double t4 = get_sec();
	cerr << "=================the time of bloomFilter is: " << t4 - t3 << endl;

	cerr << "the totalNumber is: " << totalNumber << endl;
	cerr << "the size of findedArr1 is: " << findedArr1.size() << endl;

	string outputFile1 = outputFile + ".filter.out";
	FILE * fp1 = fopen(outputFile1.c_str(), "w");
	for(int i = 0; i < findedArr1.size(); i++)
	{
		fprintf(fp1, "%d\t%d\n", i, findedArr1[i]);
	}

	double t5 = get_sec();
	cerr << "=================the time of output unordered_set is: " << t5 - t4 << endl;
	
	delete randomArr;
	delete bloomArr;

	return 0;
}

