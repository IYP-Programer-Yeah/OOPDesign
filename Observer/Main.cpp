#include "Participant.hpp"
#include "Auctioneer.hpp"

#include <random>

int main()
{
	Auctioneer auctioneer;

	Participant a1(Interest::ANCIENT_JEWLERY, "a1", auctioneer);
	Participant a2(Interest::ANCIENT_JEWLERY, "a2", auctioneer);
	Participant a3(Interest::ANCIENT_JEWLERY, "a3", auctioneer);
	Participant a4(Interest::ANCIENT_JEWLERY, "a4", auctioneer);
	Participant a5(Interest::ANCIENT_JEWLERY, "a5", auctioneer);

	Participant b1(Interest::OLD_CARS, "b1", auctioneer);
	Participant b2(Interest::OLD_CARS, "b2", auctioneer);
	Participant b3(Interest::OLD_CARS, "b3", auctioneer);
	Participant b4(Interest::OLD_CARS, "b4", auctioneer);
	Participant b5(Interest::OLD_CARS, "b5", auctioneer);

	Participant c1(Interest::PAINTINGS, "c1", auctioneer);
	Participant c2(Interest::PAINTINGS, "c2", auctioneer);
	Participant c3(Interest::PAINTINGS, "c3", auctioneer);
	Participant c4(Interest::PAINTINGS, "c4", auctioneer);
	Participant c5(Interest::PAINTINGS, "c5", auctioneer);

	auctioneer.add_observer_to_auction(&a1, a1.interest);
	auctioneer.add_observer_to_auction(&a2, a2.interest);
	auctioneer.add_observer_to_auction(&a3, a3.interest);
	auctioneer.add_observer_to_auction(&a4, a4.interest);
	auctioneer.add_observer_to_auction(&a5, a5.interest);

	auctioneer.add_observer_to_auction(&b1, b1.interest);
	auctioneer.add_observer_to_auction(&b2, b2.interest);
	auctioneer.add_observer_to_auction(&b3, b3.interest);
	auctioneer.add_observer_to_auction(&b4, b4.interest);
	auctioneer.add_observer_to_auction(&b5, b5.interest);

	auctioneer.add_observer_to_auction(&c1, c1.interest);
	auctioneer.add_observer_to_auction(&c2, c2.interest);
	auctioneer.add_observer_to_auction(&c3, c3.interest);
	auctioneer.add_observer_to_auction(&c4, c4.interest);
	auctioneer.add_observer_to_auction(&c5, c5.interest);

	for (int i = 0; i < 180; i++)
	{
		a1.bid(std::abs(std::rand()));
		a2.bid(std::abs(std::rand()));
		a3.bid(std::abs(std::rand()));
		a4.bid(std::abs(std::rand()));
		a5.bid(std::abs(std::rand()));

		b1.bid(std::abs(std::rand()));
		b2.bid(std::abs(std::rand()));
		b3.bid(std::abs(std::rand()));
		b4.bid(std::abs(std::rand()));
		b5.bid(std::abs(std::rand()));

		c1.bid(std::abs(std::rand()));
		c2.bid(std::abs(std::rand()));
		c3.bid(std::abs(std::rand()));
		c4.bid(std::abs(std::rand()));
		c5.bid(std::abs(std::rand()));
		auctioneer.tick();
	}



	auctioneer.remove_observer(&a1, a1.interest);
	auctioneer.remove_observer(&a2, a2.interest);
	auctioneer.remove_observer(&a3, a3.interest);
	auctioneer.remove_observer(&a4, a4.interest);
	auctioneer.remove_observer(&a5, a5.interest);

	auctioneer.remove_observer(&b1, b1.interest);
	auctioneer.remove_observer(&b2, b2.interest);
	auctioneer.remove_observer(&b3, b3.interest);
	auctioneer.remove_observer(&b4, b4.interest);
	auctioneer.remove_observer(&b5, b5.interest);

	auctioneer.remove_observer(&c1, c1.interest);
	auctioneer.remove_observer(&c2, c2.interest);
	auctioneer.remove_observer(&c3, c3.interest);
	auctioneer.remove_observer(&c4, c4.interest);
	auctioneer.remove_observer(&c5, c5.interest);

	return 0;
}