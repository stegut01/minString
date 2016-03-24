#include <iostream>
#include <vector>


/**
* @author  Stefan Gutmann
* @version 0.1
*
* @section DESCRIPTION
* This string class provides function to manipulate strings.
*/
class minString 
{
private:
	char *b, *e;

public:
	class iterator
	{
	public:
		typedef iterator self_type;
		typedef char& reference;
		typedef char* pointer;
		iterator() {}
		iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator=(const self_type& other) { ptr_ = other.ptr_; return *this; }
		self_type operator++() { ptr_++; return *this; }
		self_type operator++(int junk) { self_type i = *this; ptr_++; return i; }
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
	};

	iterator begin() { return b; }
	iterator end() { return e; }

	/**
	* Default Constructor.
	*/
	minString() : b(NULL), e(NULL) {}

	/**
	* Constructor that sets the string to a given value.
	* @param s Any string.
	*/
	minString(char* _b): b(_b), e(b + std::strlen(b)) {}

	/**
	* Print String
	*/
	void print();

	/**
	* Create a substring from [ to ).
	* @param from Position of the begin of the substring.
	* @param to Position of the end of the substring.
	* @return A substring specified by the parameters.
	*/
	minString cut(int from, int to);

	/**
	* Create a substring from [ to the end of the string.
	* @param from Position of the begin of the substring.
	* @return A substring specified by the parameter.
	*/
	minString cut(int from);

	/**
	* Split a string into a vector.
	* @param seperator Character to split.
	* @return A vector containing the substrings.
	*/
	std::vector<minString> split(char seperator);

	/**
	* Split a string into a vector.
	* @param seperator Character to split.
	* @param v A vector containing the substrings.
	*/
	void split(char seperator, std::vector<minString> *v);

	/**
	* Join strings to a vector of String.
	* @param v_str vector of strings.
	* @return A vector containing the Strings.
	*/
	//std::vector<minString> join(std::vector<char*> v_str);

	/**
	* Count charcters in String.
	* @param c character to count.
	* @return Number of found characters.
	*/
	int count(char c);

	/**
	* Count substrings in String.
	* @param c substring to count.
	* @return Number of found substrings.
	*/
	int count(char* c);

	/**
	* Get pointer to begin of string
	* @return Pointer to begin of strings.
	*/
	char* get_b() { return b; }

	/**
	* Get pointer to end of string
	* @return Pointer to end of strings.
	*/
	char* get_e() { return e; }
};