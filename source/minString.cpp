#include "minString.h"

void minString::print()
{
	//std::foreach(b.begin, b.end, putchar);
	if (!e)
		std::cout << b << std::endl;
	else {
		for (char *i = b; i < e; ++i)
			std::cout << *i;
		std::cout << std::endl;
	}
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
	temp.e = NULL;
	return temp;
}

void minString::split(char seperator, std::vector<minString> *v)
{
	char* end;
	minString temp;
	temp.b = b;
	temp.e = NULL;

	if (e != NULL)
		end = e;
	else
		end = b + std::strlen(b);

	for (char *i = b; i <= end; ++i) {
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

std::vector<minString> minString::join(std::vector<char*> v_str)
{
	std::vector<minString> v;
	for (std::vector<char*>::iterator it = v_str.begin(); it != v_str.end(); ++it)
		v.push_back(*it);
	return v;
}