//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

struct function
{
	template<
		typename T1,
		typename T2,
		typename T3
	>
	bool
	operator()(
		T1 const &,
		T2 const &,
		T3 const &
	) const
	{
		return
			false;
	}

	bool
	operator()(
		bool const _bool,
		int const _int,
		std::string const &_string
	) const
	{
		return
			_bool == false
			&&
			_int == 42
			&&
			_string == "foo";
	}
};

}

BOOST_AUTO_TEST_CASE(
	variant_apply_prvalue
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
		"foo"
	);

	BOOST_CHECK(
		fcppt::variant::apply_ternary(
			function(),
			variant(
				false
			),
			variant(
				42
			),
			variant(
				string
			)
		)
	);
}
