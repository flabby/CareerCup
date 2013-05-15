/*
   An animal shelter holds only dogs and cats, and operates ona strictly “first in, first out” basis. People must adopt either the “oldest”(based on arrival time) of all animals at the shelter, or they can selectwhether they could prefer a dog or a cat (and will receive the oldest animal ofthat type). They cannot select which specific animal they would like. Createthe data structures to maintain this system and implement operations such asenqueue, dequeueAny, dequeueDog and dequeueCat. You may use the built-inLinkedList data structure.
   */
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string>
using namespace std;

//queue: back empty front pop push size
enum Animal {CAT, DOG};

class Shelter
{
	public:
		void enQueue(Animal kind);
		int deQueueDog();
		int deQueueCat();
		int deQueueAny();

	private:
		queue<int> dog;
		queue<int> cat;
};

void Shelter::enQueue(Animal a)
{
	static int cnt = 0;
	if (a == CAT)
		cat.push(cnt++);
	else
		dog.push(cnt++);
}

int Shelter::deQueueDog()
{
	int ret;
	if (!dog.empty())
	{
		ret = dog.front();
		dog.pop();
		printf ("deQueue dog %d\n", ret);
	}
	else
		printf ("error: dog empty!\n");

	return ret;
}

int Shelter::deQueueCat()
{
	int ret;
	if (!cat.empty())
	{
		ret = cat.front();
		printf ("deQueue cat %d\n", ret);
		cat.pop();
	}
	else
		printf ("error: cat empty!\n");
	return ret;
}

int Shelter::deQueueAny()
{
	if (dog.empty() || cat.empty())
	{
		if (dog.empty())
			deQueueDog();
		if (cat.empty())	
			deQueueCat();
	}
	else if (cat.front() < dog.front())
		deQueueCat();
	else
		deQueueDog();
}

int main()
{
	Shelter sh;
	sh.enQueue(CAT);
	sh.enQueue(CAT);
	sh.enQueue(DOG);
	sh.enQueue(CAT);
	sh.enQueue(DOG);
	sh.enQueue(DOG);

	cout << sh.deQueueAny() << endl;
	cout << sh.deQueueAny() << endl;
	cout << sh.deQueueAny() << endl;

	return 0;
}

