//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/algorithm/array_init_move.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace
{

class movable
{
	FCPPT_NONCOPYABLE(
		movable
	);
public:
	explicit
	movable(
		int const _value
	)
	:
		value_{
			_value
		}
	{
	}

	~movable()
	{
	}

	movable(
		movable &&
	) = default;

	int
	value() const
	{
		return
			value_;
	}
private:
	int value_;
};

}

BOOST_AUTO_TEST_CASE(
	array_init_move
)
{
	typedef
	std::array<
		movable,
		2
	>
	array;

	array const inited(
		fcppt::algorithm::array_init_move<
			array
		>(
			[]{
				return
					movable{
						42
					};
			}
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			inited
		).value(),
		42
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			inited
		).value(),
		42
	);
}
