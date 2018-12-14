#pragma once

#include <string>
#include <cstddef>

struct Component
{
	std::string name;

	explicit Component(const std::string& i_name) : name(i_name) {}
	explicit Component(std::string&& i_name) : name(i_name) {}

	virtual void traverse(std::size_t scope = 0) = 0;
};
