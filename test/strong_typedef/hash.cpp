//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/strong_typedef_std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

}

BOOST_AUTO_TEST_CASE(
	strong_typedef_hash
)
{
	typedef
	std::unordered_set<
		strong_int
	>
	hash_set;

	hash_set elements;

	elements.insert(
		strong_int(1)
	);

	elements.insert(
		strong_int(2)
	);

	BOOST_CHECK_EQUAL(
		elements.count(
			strong_int(1)
		),
		1u
	);

	BOOST_CHECK_EQUAL(
		elements.count(
			strong_int(2)
		),
		1u
	);
}
