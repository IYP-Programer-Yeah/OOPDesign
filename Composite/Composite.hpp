#pragma once

#include "Component.hpp"

#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>
#include <utility>

struct Composite : public Component
{
	std::unordered_map<std::string, std::shared_ptr<Component>> components;

	explicit Composite(const std::string& i_name) : Component(i_name) {}
	explicit Composite(std::string&& i_name) : Component(i_name) {}

	virtual void traverse(std::size_t scope = 0) override final
	{
		for (std::size_t i = 0; i < scope; i++)
			std::cout << "\t";
		std::cout << name << std::endl;
		for (const auto & entry : components)
			entry.second->traverse(scope + 1);
	}

	void add_componet(const std::shared_ptr<Component> &component)
	{
		components.emplace(std::make_pair(component->name, std::move(component)));
	}

	void add_componet(std::shared_ptr<Component> &&component)
	{
		components.emplace(std::make_pair(component->name, component));
	}

	void remove_component(const std::string &name)
	{
		components.erase(name);
	}
};
