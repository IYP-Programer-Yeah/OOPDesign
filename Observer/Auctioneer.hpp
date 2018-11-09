#pragma once

#include "Subject.hpp"
#include <iostream>

struct Auctioneer : public Subject
{
	static const int MAX_BIDS;
	static const int BIDDING_TIME_OUT;

	Bid highest_old_car_bid = { nullptr, 0 };
	Bid highest_painting_bid = { nullptr, 0 };
	Bid highest_ancient_jewlery_bid = { nullptr, 0 };

	unsigned int number_of_current_old_car_bids = 0;
	unsigned int number_of_current_painting_bids = 0;
	unsigned int number_of_current_ancient_jewlery_bids = 0;

	unsigned int passed_time_in_seconds = 0;

	std::list<Observer*> old_car_auction_observers;
	std::list<Observer*> painting_auction_observers;
	std::list<Observer*> ancient_jewlery_auction_observers;


	virtual void add_observer_to_auction(Observer* const o, const Interest interest) override final
	{
		switch (interest)
		{
		case Interest::OLD_CARS:
			old_car_auction_observers.emplace_back(o);
			break;
		case Interest::PAINTINGS:
			painting_auction_observers.emplace_back(o);
			break;
		case Interest::ANCIENT_JEWLERY:
			ancient_jewlery_auction_observers.emplace_back(o);
			break;
		default:
			break;
		}
	}

	virtual void remove_observer(Observer* const o, const Interest interest) override final
	{
		switch (interest)
		{
		case Interest::OLD_CARS:
			old_car_auction_observers.remove(o);
			break;
		case Interest::PAINTINGS:
			painting_auction_observers.remove(o);
			break;
		case Interest::ANCIENT_JEWLERY:
			ancient_jewlery_auction_observers.remove(o);
			break;
		default:
			break;
		}
	}

	virtual void notify_highest_bid(const Bid& highest_bid, const Interest interest) override final
	{
		switch (interest)
		{
		case Interest::OLD_CARS:
			for (Observer * const o : old_car_auction_observers)
				o->update_highest_bid(highest_bid);
			break;
		case Interest::PAINTINGS:
			for (Observer * const o : painting_auction_observers)
				o->update_highest_bid(highest_bid);
			break;
		case Interest::ANCIENT_JEWLERY:
			for (Observer * const o : ancient_jewlery_auction_observers)
				o->update_highest_bid(highest_bid);
			break;
		default:
			break;
		}
	}

	virtual void notify_item_sold(const Bid& highest_bid, const Interest interest) override final
	{
		switch (interest)
		{
		case Interest::OLD_CARS:
			for (Observer * const o : old_car_auction_observers)
				o->update_item_sold(highest_bid);
			break;
		case Interest::PAINTINGS:
			for (Observer * const o : painting_auction_observers)
				o->update_item_sold(highest_bid);
			break;
		case Interest::ANCIENT_JEWLERY:
			for (Observer * const o : ancient_jewlery_auction_observers)
				o->update_item_sold(highest_bid);
			break;
		default:
			break;
		}
	}

	void bid(Bid current_bid, const Interest interest)
	{
		switch (interest)
		{
		case Interest::OLD_CARS:
			if (current_bid.amount > highest_old_car_bid.amount)
			{
				highest_old_car_bid = current_bid;
				number_of_current_old_car_bids++;
				notify_highest_bid(current_bid, interest);
				if (number_of_current_old_car_bids == MAX_BIDS)
					notify_item_sold(current_bid, interest);
			}
			break;
		case Interest::PAINTINGS:
			if (current_bid.amount > highest_painting_bid.amount)
			{
				highest_painting_bid = current_bid;
				number_of_current_painting_bids++;
				notify_highest_bid(current_bid, interest);
				if (number_of_current_painting_bids == MAX_BIDS)
					notify_item_sold(current_bid, interest);
			}
			break;
		case Interest::ANCIENT_JEWLERY:
			if (current_bid.amount > highest_ancient_jewlery_bid.amount)
			{
				highest_ancient_jewlery_bid = current_bid;
				number_of_current_ancient_jewlery_bids++;
				notify_highest_bid(current_bid, interest);
				if (number_of_current_ancient_jewlery_bids == MAX_BIDS)
					notify_item_sold(current_bid, interest);
			}
			break;
		default:
			break;
		}
	}

	void tick()
	{
		passed_time_in_seconds++;
		if (passed_time_in_seconds == BIDDING_TIME_OUT)
		{
			std::cout << "Timed out!" << std::endl;
			if (highest_old_car_bid.bidder != nullptr)
			{
				notify_item_sold(highest_old_car_bid, Interest::OLD_CARS);
				highest_old_car_bid = { nullptr, 0 };
			}
			if (highest_painting_bid.bidder != nullptr)
				notify_item_sold(highest_painting_bid, Interest::PAINTINGS);
			if (highest_ancient_jewlery_bid.bidder != nullptr)
				notify_item_sold(highest_ancient_jewlery_bid, Interest::ANCIENT_JEWLERY);
		}

	}
};

const int Auctioneer::MAX_BIDS = 10;
const int Auctioneer::BIDDING_TIME_OUT = 180;
