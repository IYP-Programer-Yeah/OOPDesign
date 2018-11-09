#pragma once
#include <list>

#include "Observer.hpp"

enum class Interest
{
	OLD_CARS,
	PAINTINGS,
	ANCIENT_JEWLERY,
};

struct Subject
{
	virtual void add_observer_to_auction(Observer* const o, const Interest interest) = 0;

	virtual void remove_observer(Observer* const o, const Interest interest) = 0;

	virtual void notify_highest_bid(const Bid& highest_bid, const Interest interest) = 0;

	virtual void notify_item_sold(const Bid& highest_bid, const Interest interest) = 0;
};
