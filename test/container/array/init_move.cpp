//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/container/array/init_move.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <array>
#include <ostream>
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

bool
operator==(
	movable const &_left,
	movable const &_right
)
{
	return
		_left.value()
		==
		_right.value();
}

std::ostream &
operator<<(
	std::ostream &_stream,
	movable const &_obj
)
{
	return
		_stream
		<<
		_obj.value();
}

}

TEST_CASE(
	"array::init_move",
	"[container],[array]"
)
{
	typedef
	std::array<
		movable,
		2
	>
	movable_2_array;

	CHECK(
		fcppt::container::array::init_move<
			movable_2_array
		>(
			[]{
				return
					movable{
						42
					};
			}
		)
		==
		movable_2_array{{
			movable{
				42
			},
			movable{
				42
			}
		}}

	);
}
