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
	void testJoin(void);

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

void TestBasicString::testJoin(void)
{
	std::vector<char*> v_str = { "hello", "world", "three" };
	std::vector<minString> v = s->join(v_str);
	assert(v[0] == "hello");
	assert(v[1] == "world");
	assert(v[2] == "three");
}


int main()
{
	TestBasicString test;
	test.setUp();
	test.testCut1();
	test.testCut2();
	test.testSplit();
	test.testJoin();
	test.tearDown();

	return 0;
}