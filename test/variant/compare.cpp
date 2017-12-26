//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/compare.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

struct compare
{
	template<
		typename T
	>
	bool
	operator()(
		T const &_a,
		T const &_b
	) const
	{
		return
			_a
			==
			_b;
	}
};

}

BOOST_AUTO_TEST_CASE(
	variant_equal
)
{
	typedef
	fcppt::variant::variadic<
		bool,
		int,
		std::string
	>
	variant;

	std::string const string(
		"hello world"
	);

	variant const v1(
		string
	);

	variant const v2(
		string
	);

	BOOST_CHECK(
		fcppt::variant::compare(
			v1,
			v2,
			compare()
		)
	);

	variant const v3(
		42
	);

	BOOST_CHECK(
		!fcppt::variant::compare(
			v1,
			v3,
			compare()
		)
	);
}
