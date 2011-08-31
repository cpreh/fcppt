//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/generate_has_member_function.hpp>
#include <fcppt/type_traits/generate_has_type.hpp>
#include <fcppt/type_traits/is_iterable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
FCPPT_TYPE_TRAITS_GENERATE_HAS_MEMBER_FUNCTION(
	worm);

FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE(
	size_type);

struct apple
{
public:
	void worm();
};

struct orange
{
public:
	void skin();

	typedef
	int
	size_type;
};
}

BOOST_AUTO_TEST_CASE(generate_has_member_function)
{
	BOOST_CHECK(
		(has_worm<apple,void(apple::*)()>::value));

	BOOST_CHECK(
		(!has_worm<orange,void(orange::*)()>::value));
}

BOOST_AUTO_TEST_CASE(generate_has_type)
{
	BOOST_CHECK(
		!has_size_type<apple>::value);

	BOOST_CHECK(
		has_size_type<orange>::value);
}

BOOST_AUTO_TEST_CASE(is_iterable)
{
	BOOST_CHECK(
		!fcppt::type_traits::is_iterable<int>::value);

	BOOST_CHECK(
		fcppt::type_traits::is_iterable<std::vector<int> >::value);
}
