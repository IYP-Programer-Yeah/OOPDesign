#pragma once
struct Observer;

struct Bid
{
	Observer* bidder;
	unsigned int amount;
};

struct Observer
{
	virtual void update_highest_bid(const Bid &bid) = 0;

	virtual void update_item_sold(const Bid &bid) = 0;
};
