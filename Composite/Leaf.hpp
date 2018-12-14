#pragma once

#include "Component.hpp"

#include <string>
#include <iostream>

struct Leaf : public Component
{
	explicit Leaf(const std::string& i_name) : Component(i_name) {}
	explicit Leaf(std::string&& i_name) : Component(i_name) {}

	virtual void traverse(std::size_t scope = 0) override final
	{
		for (std::size_t i = 0; i < scope; i++)
			std::cout << "\t";
		std::cout << "Picture: " << name << std::endl;
	}
};
