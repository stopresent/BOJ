#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Q) map vs hash_map (C++11 ǥ�� unordered_map)

// map : Red-Black Tree
// - �߰�/Ž��/���� O(logN)

// C# dictionary = C++ map (X)
// C# dictionary = C++ unordered_map

// hash_map (unordered_map)
// - �߰�/Ž��/���� O(1)

// �޸𸮸� ���ְ� �ӵ��� ���Ѵ�.

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

	// 123456789�� ���� ���� ����
	users[key] = User{ userId, "stopresent" };

	// 12345678�� ���� �̸���?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.userName;
		cout << name << endl;
	}

	// �浹 ����
	// �浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�Ƴ����� �ȴ�
	// - ���� ����� (linear probing)
	// hash(key)+1 -> hash(key)+2
	// - ���� ����� (qudratic probing)
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

	// 123456789�� ���� ���� ����
	users[key].push_back(User{ userId, "stopresent" });

	// 123456789�� ���� �̸���?
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