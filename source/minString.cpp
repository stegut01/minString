#include "../minString/minString.h"
#include <algorithm>

void minString::print()
{
	//std::foreach(b.begin, b.end, putchar);
	for (char *i = b; i < e; ++i)
		std::cout << *i;
	std::cout << std::endl;
}

minString minString::cut(int from, int to)
{
	minString temp; 
	temp.b = b + from;
	temp.e = b + to;
	return temp;
}

minString minString::cut(int from)
{
	minString temp;
	temp.b = b + from;
	temp.e = b + std::strlen(b);
	return temp;
}

void minString::split(char seperator, std::vector<minString> *v)
{
	minString temp;
	temp.b = b;
	temp.e = b + std::strlen(b);

	for (char *i = b; i <= e; ++i) {
		temp.e = i;
		if (*i == seperator) {
			(*v).push_back(temp);
			temp.b = i + 1;
		}
	}
	(*v).push_back(temp);
}

std::vector<minString> minString::split(char seperator)
{
	std::vector<minString> v;
	split(seperator, &v);
	return v;
}

/*
std::vector<minString> minString::join(std::vector<char*> v_str)
{
	std::vector<minString> v;
	for (std::vector<char*>::iterator it = v_str.begin(); it != v_str.end(); ++it)
		v.push_back(*it);
	return v;
}*/

int minString::count(char c)
{
	return std::count(b, e, c);
}

struct counter { 
	int found;
	char *search, *original;

	counter(char* c) : found(0), search(c), original(c) {}
	void operator() (char c) {
		if(c == *search) {
			if(std::strlen(++search) == 0)
				++found;
		} else search = original;
	}
};

int minString::count(char* c)
{
	counter cnt(c);
	std::for_each(b, e, cnt);
	return cnt.found;
}