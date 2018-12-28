#pragma once

#include "IList.hpp"
#include <list>

struct List : public IList
{
	virtual void push_back(const Element e) override final
	{
		list.push_back(e);
	}
	virtual void pop_back() override final
	{
		list.pop_back();
	}
	virtual void push_front(const Element e) override final
	{
		list.push_front(e);
	}
	virtual void pop_front() override final
	{
		list.pop_front();
	}

	virtual Iterator begin() override final
	{
		return list.begin();
	}

	virtual ConstIterator cbegin() const  override final
	{
		return list.cbegin();
	}

	virtual Iterator end() override final
	{
		return list.end();
	}

	virtual ConstIterator cend() const override final
	{
		return list.cend();
	}
private:
	std::list<Element> list;
};
