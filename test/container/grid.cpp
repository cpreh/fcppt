//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/next_prior.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ostream>

// To test: resize in 2d, resize in 3d, resize_simple, non-pods as data types

namespace
{
typedef
std::vector<int>
array_type;

typedef
fcppt::container::grid::object<array_type,2>
grid2d;

typedef
fcppt::container::grid::object<array_type,3>
grid3d;

int const 
	max_value = 1000,
	digit_count = 6;

void
output(
	grid2d const &g)
{
	typedef 
	grid2d::size_type
	size_type;

	typedef 
	grid2d::vector
	vector;

	for (size_type y = 0; y < g.dimension().h(); ++y)
	{
		for (size_type x = 0; y < g.dimension().w(); ++x)
			std::cout << std::setw(digit_count) << g.pos(vector(x,y));
		std::cout << "\n";
	}
}

// "unreal" in the sense that they are not identical, but equal
template<typename A,fcppt::container::grid::size_type N>
void
check_unreal_equality(
	fcppt::container::grid::object<A,N> const &a,
	fcppt::container::grid::object<A,N> const &b)
{
	// This is more of an internal check (the test program would be wrong if this didn't check out)
	BOOST_CHECK(
		&a != &b);

	typedef
	fcppt::container::grid::object<A,N>
	grid_type;

	BOOST_CHECK(
		a.dimension() == b.dimension());

	// Dimension could have been copied but not the underlying containers
	BOOST_CHECK(
		a.size() == b.size());
	
	for (
		typename grid_type::const_iterator 
			i = a.cbegin(),
			j = b.cbegin(); 
			// NOTE: It's safe to test only one field here because (*) ensures that
			// distance(begin,end) == b.size() and both sizes agree
			i != a.end();
			++i,++j)
	{
		BOOST_CHECK(*i == *j);
	}
	
	// Test to see if they do not share the same data pointers
	BOOST_CHECK(&(*a.cbegin()) != &(*b.cbegin()));
}
}

BOOST_AUTO_TEST_CASE(container_grid_construction_and_basic)
{
	typedef
	grid3d
	grid_type;

	typedef
	grid3d::dim
	dim_type;

	typedef
	grid3d::size_type
	size_type;

	// Test if we can construct empty grids
	grid_type g;

	BOOST_CHECK(
		g.size() == 0 && 
		g.max_size() > 0 // <-- this check is just to instantiate the max_size function
		);
	
	BOOST_CHECK(
		g.empty());

	BOOST_CHECK(
		g.begin() == g.end());

	BOOST_CHECK(
		g.cbegin() == g.cend());

	BOOST_CHECK(
		g.rbegin() == g.rend());

	BOOST_CHECK(
		g.crbegin() == g.crend());

	BOOST_CHECK(
		g.get_allocator().max_size() > 0 // <-- see the comment above
		);

	BOOST_CHECK(
		g.dimension() == dim_type::null());

	// Test if we can construct nonempty grids
	grid_type nonempty(
		dim_type(
			3,
			2,
			3)); 

	BOOST_CHECK(
		nonempty.size() == static_cast<size_type>(3*2*3));
	
	BOOST_CHECK(
		!nonempty.empty());

	BOOST_CHECK(
		nonempty.begin() != nonempty.end());

	BOOST_CHECK(
		nonempty.cbegin() != nonempty.cend());

	BOOST_CHECK(
		nonempty.rbegin() != nonempty.rend());

	BOOST_CHECK(
		nonempty.crbegin() != nonempty.crend());
	
	// Make sure the begin iterators point to the same thing
	BOOST_CHECK(
		&(*nonempty.begin()) == &(*nonempty.cbegin()));

	// (*)
	BOOST_CHECK(
		nonempty.end() == 
		boost::next(
			nonempty.begin(),
			nonempty.size()));

	BOOST_CHECK(
		nonempty.dimension() == dim_type(3,2,3));
	
	// Test if we can copy-construct
	check_unreal_equality(
		nonempty,
		grid_type(
			nonempty));
	
	// Test if operator= works;
	grid_type nonempty_copy2;

	nonempty_copy2 = nonempty;

	check_unreal_equality(
		nonempty,
		nonempty_copy2);
	
	// Test the iterator constructor
	check_unreal_equality(
		nonempty,
		grid_type(
			nonempty.dimension(),
			nonempty.cbegin(),
			nonempty.cend()));
}

BOOST_AUTO_TEST_CASE(container_grid_iteration)
{
	typedef
	grid2d::vector
	vector2_type;

	typedef
	grid3d::vector
	vector3_type;

	// 2 4
	// 5 6
	// 7 9
	grid2d g(
		grid2d::dim(2,3));
	
	// Test if pos works correctly
	g.pos(vector2_type(0,0)) = 2;
	g.pos(vector2_type(1,0)) = 4;
	g.pos(vector2_type(0,1)) = 5;
	g.pos(vector2_type(1,1)) = 6;
	g.pos(vector2_type(0,2)) = 7;
	g.pos(vector2_type(1,2)) = 9;

	BOOST_CHECK(
		g == grid2d(g) &&
		!(g != grid2d(g)));

	// Test if elements are stored in row major order
	grid2d::const_iterator i = g.begin();
	BOOST_CHECK(
		*i++ == 2 &&
		*i++ == 4 &&
		*i++ == 5 &&
		*i++ == 6 &&
		*i++ == 7 &&
		*i++ == 9);
	
	BOOST_CHECK(
		g.front() == 2);

	BOOST_CHECK(
		g.back() == 9);
	
	// Test if iterating using foreach is the same as with iterators
	i = g.begin();
	BOOST_FOREACH(grid2d::reference r,g)
	{
		BOOST_CHECK(*i++ == r);
	}
	
	BOOST_CHECK(
		i == g.cend());
	
	grid3d g2(
		grid3d::dim(
			2,3,2));
	
	int j = 0;
	BOOST_FOREACH(grid3d::reference r,g2)
		r = j++;
	
	// Just take control samples
	BOOST_CHECK(
		g2.pos(vector3_type(0,0,0)) == 0);
	BOOST_CHECK(
		g2.pos(vector3_type(1,2,1)) == 2*3*2-1);
	BOOST_CHECK(
		g2.pos(vector3_type(0,0,1)) == 2*3);
}

BOOST_AUTO_TEST_CASE(container_grid_resize)
{
	grid2d g;
	g.resize_plain(grid2d::dim(2,2));
	// Check if resize really changes the dimension data field
	BOOST_CHECK(
		g.dimension() == grid2d::dim(2,2));
	// Check if the underlying array was resized
	BOOST_CHECK(
		g.size() == 2*2);
	
	std::fill(
		g.begin(),
		g.end(),
		2);
	
	// 2 2 1 1
	// 2 2 1 1
	// 1 1 1 1
	// 1 1 1 1
	
	g.resize(
		grid2d::dim(4,4),
		1);
	
	// Check if resize really changes the dimension data field
	BOOST_CHECK(
		g.dimension() == grid2d::dim(4,4));
	// Check if the underlying array was resized
	BOOST_CHECK(
		g.size() == 4*4);
	
	BOOST_CHECK(
		g.pos(grid2d::vector(0,0)) == 2 && 
		g.pos(grid2d::vector(0,1)) == 2 && 
		g.pos(grid2d::vector(1,1)) == 2 && 
		g.pos(grid2d::vector(1,0)) == 2);

	BOOST_CHECK(
		g.pos(grid2d::vector(2,0)) == 1 && 
		g.pos(grid2d::vector(2,1)) == 1 && 
		g.pos(grid2d::vector(2,2)) == 1 && 
		g.pos(grid2d::vector(2,3)) == 1 &&
		g.pos(grid2d::vector(3,0)) == 1 && 
		g.pos(grid2d::vector(3,1)) == 1 && 
		g.pos(grid2d::vector(3,2)) == 1 && 
		g.pos(grid2d::vector(3,3)) == 1 &&
		g.pos(grid2d::vector(0,2)) == 1 && 
		g.pos(grid2d::vector(1,2)) == 1 && 
		g.pos(grid2d::vector(0,3)) == 1 && 
		g.pos(grid2d::vector(1,3)) == 1);
	
	g.resize(
		grid2d::dim(2,2));
	
	BOOST_CHECK(
		g.pos(grid2d::vector(0,0)) == 2 &&
		g.pos(grid2d::vector(0,1)) == 2 &&
		g.pos(grid2d::vector(1,1)) == 2 &&
		g.pos(grid2d::vector(1,0)) == 2);
}
