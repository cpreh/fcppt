//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assign/make_container.hpp>
#include <set>
#include <vector>
#include <map>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(assign_make_container)
{
	{
	typedef
	std::vector<int> 
	sequence;
	
	sequence c(
		fcppt::assign::make_container<sequence>
			(
				3)
			(
				4)
			(
				5));
	
	BOOST_REQUIRE(
		c.size() == static_cast<sequence::size_type>(3) &&
		c[0] == 3 && 
		c[1] == 4 &&
		c[2] == 5);
	}
	
	{
	typedef
	std::set<int>
	set;
	
	set c(
		fcppt::assign::make_container<set>
			(
				3)
			(
				4)
			(
				5));
	
	BOOST_REQUIRE(
		c.size() == static_cast<set::size_type>(3) &&
		c.find(3) != c.end() && 
		c.find(4) != c.end() && 
		c.find(5) != c.end());
	}
		
	{
	typedef
	std::map<int,int>
	map;
	
	map m(
		fcppt::assign::make_container<map>
			(std::make_pair(
				3,
				2))
			(std::make_pair(
				4,
				5)));
	
	BOOST_REQUIRE(
		m.size() == static_cast<map::size_type>(2) &&
		m.find(3) != m.end() &&
		m.find(3)->second == 2 && 
		m.find(4) != m.end() &&
		m.find(4)->second == 5);
	}
}
