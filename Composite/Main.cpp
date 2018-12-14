#include "Composite.hpp"
#include "Leaf.hpp"

#include <memory>

int main()
{
	Composite album("Album");

	album.add_componet(std::make_shared<Leaf>("School"));
	album.add_componet(std::make_shared<Leaf>("Home"));
	album.add_componet(std::make_shared<Leaf>("University"));
	
	auto birthday = std::make_shared<Composite>("Birthday");
	birthday->add_componet(std::make_shared<Leaf>("1393"));
	birthday->add_componet(std::make_shared<Leaf>("1394"));
	birthday->add_componet(std::make_shared<Leaf>("1356"));
	auto good = std::make_shared<Composite>("Good");
	good->add_componet(std::make_shared<Leaf>("1387"));
	good->add_componet(std::make_shared<Leaf>("1397"));
	birthday->add_componet(good);
	birthday->add_componet(std::make_shared<Leaf>("1312"));
	birthday->add_componet(std::make_shared<Leaf>("1345"));
	birthday->add_componet(std::make_shared<Leaf>("1369"));
	album.add_componet(birthday);

	album.traverse();
	return 0;
}