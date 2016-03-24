#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

#include "../minString/minString.h"

bool operator==(minString s1, char* s2) {
	std::string str = s1.get_b();
	if (s1.get_e())
		str = str.substr(0, s1.get_e() - s1.get_b());
	return str == s2;
}


//-----------------------------------------------------------------------------
class TestBasicString
{

public:
	void setUp(void);
	void tearDown(void);
	void testCut1(void);
	void testCut2(void);
	void testSplit(void);
	void testCount(void);
	void testIterator(void);

private:
	minString *s;
};

//-----------------------------------------------------------------------------
void TestBasicString::setUp(void)
{
	s = new minString("hello;world;two");
}

void TestBasicString::tearDown(void)
{
	delete s;
}

void TestBasicString::testCut1(void)
{
	minString s1 = s->cut(2, 7);
	assert(s1 == "llo;w");
}

void TestBasicString::testCut2(void)
{
	minString s1 = s->cut(4);
	assert (s1 == "o;world;two");
}

void TestBasicString::testSplit(void)
{
	std::vector<minString> v = s->split(';');
	assert(v[0] == "hello");
	assert(v[1] == "world");
	assert(v[2] == "two");
}

void TestBasicString::testCount(void)
{
	int mycount = s->count('o');
	assert(mycount == 3);

	mycount = s->count('x');
	assert(mycount == 0);

	mycount = s->count("wo");
	//assert(mycount == 2);
}

void TestBasicString::testIterator(void)
{
	minString::iterator i = s->begin();
	assert(*i == 'h');
	++i;
	assert(*i == 'e');
	i++;
	assert(*i == 'l');
	i = s->end();
	assert(*i == '\0');
}

int main()
{
	TestBasicString test;
	test.setUp();
	test.testCut1();
	test.testCut2();
	test.testSplit();
	test.testCount();
	test.testIterator();
	test.tearDown();

	/*
	std::ifstream in("testminString.txt");
	std::string s((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	std::cout << "STRING:" << std::endl;
	std::cout << s;
	*/

	std::ifstream is("testminString.txt");
	if (is) {
		is.seekg(0, std::ios::end);
		int len = is.tellg();
		is.seekg(0, std::ios::beg);
		char *buffer = new char[len];
		is.read(buffer, len);
		is.close();

		minString s1(buffer);
		s1.print();
		minString s2 = s1.cut(4, 14);
		s2.print();

		delete[] buffer;
	}
	return 0;
}