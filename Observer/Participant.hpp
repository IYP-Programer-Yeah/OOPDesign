#pragma once

#include "Observer.hpp"
#include "Auctioneer.hpp"

#include <iostream>
#include <string>

struct Participant : public Observer
{
	const Interest interest;
	const std::string name;
	Auctioneer &auctioner;

	bool stop_bidding;

	Bid highest_bid = { nullptr, 0 };

	Participant(const Interest i_interest, const std::string& i_name, Auctioneer &i_auctioneer) : interest(i_interest), name(i_name), auctioner(i_auctioneer), stop_bidding(false) {};
	Participant(const Interest i_interest, std::string&& i_name, Auctioneer &i_auctioneer) : interest(i_interest), name(std::move(i_name)), auctioner(i_auctioneer), stop_bidding(false) {};

	virtual void update_highest_bid(const Bid &bid) override final
	{
		highest_bid = bid;
	}

	virtual void update_item_sold(const Bid &bid) override final
	{
		if (stop_bidding)
			return;
		stop_bidding = true;
		if (bid.bidder == this)
			std::cout << "i, "<< name << ", won!" << std::endl;
		else
			std::cout << "i, " << name << ", lost!" << std::endl;
	}

	void bid(const unsigned int amount)
	{
		if (!stop_bidding)
			auctioner.bid({ this, amount }, interest);
	}
};
