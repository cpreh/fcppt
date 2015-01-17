//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/algorithm/array_init_move.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	array_init_move
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::array<
		movable,
		2
	>
	array;

	int counter{
		0
	};

	array const inited(
		fcppt::algorithm::array_init_move<
			array
		>(
			[
				&counter
			]{
				return
					movable(
						counter++
					);
			}
		)
	);

	BOOST_CHECK(
		inited[0].value() == 0
		&&
		inited[1].value() == 1
	);
}
