#pragma once

#include <cinttypes>
#include <list>

struct IList
{
	using Element = std::uint32_t;
	using ConstIterator = decltype(std::list<Element>().cbegin());
	using Iterator = decltype(std::list<Element>().begin());

	virtual void push_back(const Element e) = 0;
	virtual void pop_back() = 0;
	virtual void push_front(const Element e) = 0;
	virtual void pop_front() = 0;

	virtual Iterator begin() = 0;
	virtual ConstIterator cbegin() const = 0;
	virtual Iterator end() = 0;
	virtual ConstIterator cend() const = 0;
};
