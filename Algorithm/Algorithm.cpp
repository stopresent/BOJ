#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Q) map vs hash_map (C++11 표준 unordered_map)

// map : Red-Black Tree
// - 추가/탐색/삭제 O(logN)

// C# dictionary = C++ map (X)
// C# dictionary = C++ unordered_map

// hash_map (unordered_map)
// - 추가/탐색/삭제 O(1)

// 메모리를 내주고 속도를 취한다.

void TestTable()
{
	struct User
	{
		int userId = 0;
		string userName;
	};

	vector<User> users;
	users.resize(1000);

	users[777] = User{ 777,"stopresent" };

	string name = users[777].userName;
	cout << name << endl;
	
}

void TestHash()
{
	struct User
	{
		int userId = 0;
		string userName;
	};

	vector<User> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000);

	// 123456789번 유저 정보 세팅
	users[key] = User{ userId, "stopresent" };

	// 12345678번 유저 이름은?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.userName;
		cout << name << endl;
	}

	// 충돌 문제
	// 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾아나서면 된다
	// - 선형 조사법 (linear probing)
	// hash(key)+1 -> hash(key)+2
	// - 이차 조사법 (qudratic probing)
	// hash(key)+1^2 -> hash(key)+2^2
	// - etc

}

void TestHashTableChaining()
{
	struct User
	{
		int userId = 0;
		string username;
	};

	vector<vector<User>> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000);

	// 123456789번 유저 정보 세팅
	users[key].push_back(User{ userId, "stopresent" });

	// 123456789번 유저 이름은?
	vector<User>& bucket = users[key];
	for (User& user : bucket)
	{
		if (user.userId == userId)
		{
			string name = user.username;
			cout << name << endl;
		}
	}

}

int main()
{

	TestHash();

}