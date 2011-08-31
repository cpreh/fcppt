//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/array.hpp>
#include <fcppt/container/array_fusion.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>

namespace
{

class accumulate
{
public:
	accumulate()
	:
		value_(0)
	{
	}

	typedef void result_type;

	result_type
	operator()(
		int const _value
	) const
	{
		value_ += _value;
	}

	int
	value() const
	{
		return value_;
	}
private:
	mutable int value_;
};

}

BOOST_AUTO_TEST_CASE(
	container_array_fusion
)
{
	fcppt::container::array<
		int,
		5
	> const array =
	{{
		0, 1, 2, 3, 4
	}};

	accumulate functor;

	boost::fusion::for_each(
		array,
		functor
	);

	BOOST_REQUIRE(
		functor.value()
		== 10
	);
}
