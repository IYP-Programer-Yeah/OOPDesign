#pragma once

#include "IList.hpp"
#include "List.hpp"

struct ReadOnlyList : public IList
{
	ReadOnlyList(const List& i_list) : list(i_list) {}

	virtual void push_back(const Element e) override final
	{
		throw std::exception("Cannot perform modifying operations on read-only list.");
	}
	virtual void pop_back() override final
	{
		throw std::exception("Cannot perform modifying operations on read-only list.");
	}
	virtual void push_front(const Element e) override final
	{
		throw std::exception("Cannot perform modifying operations on read-only list.");
	}
	virtual void pop_front() override final
	{
		throw std::exception("Cannot perform modifying operations on read-only list.");
	}

	virtual Iterator begin() override final
	{
		throw std::exception("Cannot perform modifying operations on read-only list.");
	}

	virtual ConstIterator cbegin() const  override final
	{
		return list.cbegin();
	}

	virtual Iterator end() override final
	{
		throw std::exception("Cannot perform modifying operations on read-only list.");
	}

	virtual ConstIterator cend() const override final
	{
		return list.cend();
	}
private:
	const List& list;
};
