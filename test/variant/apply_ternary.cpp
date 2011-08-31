//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/object.hpp>
#include <fcppt/variant/apply_ternary.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace
{

struct functor
{
	typedef bool result_type;

	template<
		typename T1,
		typename T2,
		typename T3
	>
	result_type
	operator()(
		T1 const &,
		T2 const &,
		T3 const &
	) const
	{
		return false;
	}

	result_type
	operator()(
		bool const _bool,
		int const _int,
		std::string const &_string
	) const
	{
		return
			_bool == false
			&& _int == 42
			&& _string == "foo";
	}
};

}

BOOST_AUTO_TEST_CASE(
	variant_apply_ternary
)
{
	typedef fcppt::variant::object<
		boost::mpl::vector3<
			bool,
			int,
			std::string
		>
	> variant;

	std::string const string(
		"foo"
	);

	variant const
		v1(
			false
		),
		v2(
			42
		),
		v3(
			string
		);

	BOOST_REQUIRE(
		fcppt::variant::apply_ternary(
			functor(),
			v1,
			v2,
			v3
		)
	);
}
