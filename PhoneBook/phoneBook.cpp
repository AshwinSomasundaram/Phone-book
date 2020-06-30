#include <vector>
#include "phoneBook.h"
#include "linkedList.h"
#include "orderedLinkedList.h"
#include <iterator>
#include <string>
#include <iomanip>

//Creates the default constructor for phoneBook class
phoneBook::phoneBook()
{
	
}

//Returns the beginning of the vector
phoneBook::iterator phoneBook::begin()
{
	return entries.begin();
}

//Returns the end of the vector
phoneBook::iterator phoneBook::end()
{
	return entries.end();
}

//Insert constructors when parameter is a phoneBook Entry.
void phoneBook::insert(const phoneBookEntry& entry)
{
	if (find(entry.name()))
	{
		entries.erase(entry);
		//std::cout << "here" << std::endl;
		entries.insert(entry);
	}
	else
	{

		entries.insert(entry);
	}
}

//Insert constructor when the 3 string parameters are passed
void phoneBook::insert(const std::string& name, const std::string& number, const std::string& email)
{
	phoneBookEntry entry(name, number, email);
	insert(entry);
	

}

//Insert constructor when the 2 string parameters are passed
void phoneBook::insert(const std::string& name, const std::string& number)
{
	phoneBookEntry entry(name, number);
	insert(entry);
	
}

//Erase constructor
bool phoneBook::erase(std::string name)
{
	phoneBookEntry temp(name, "");
	return entries.erase(temp);

}


//Find constructor
bool phoneBook::find(std::string name)
{
	phoneBookEntry entry(name, "");
	return entries.find(entry) != nullptr;
}




//Prints all the elements in the vector
void phoneBook::print() const
{
	print(std::cout);
}

//Prints all the elements in the vector using an ostream

void phoneBook::print(std::ostream& out) const
{
	out << std::setw(31) << std::left << "Name:" << std::setw(16) << std::left << "Phone Number:" << "E-Mail:" << std::endl;
	for (const auto & entry: entries)
	{
		out << std::setw(31) << std::left << entry.name() << std::setw(16) << std::left << entry.phoneNumber() << entry.email() << std::endl;
	}

}

//Prints all the variables in the phonebook
void phoneBook::debug(std::ostream& out) const
{
	print(out);
}


//Returns the size of the phoneBook
std::size_t phoneBook::size() const
{
	return entries.size();
}

