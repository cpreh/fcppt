//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/container/array_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <cstddef>
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
		std::size_t const _value
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

	std::size_t
	value() const
	{
		return
			value_;
	}
private:
	std::size_t value_;
};

}

BOOST_AUTO_TEST_CASE(
	array_init
)
{
	typedef
	std::array<
		movable,
		2
	>
	array;

	array const inited(
		fcppt::container::array_init<
			array
		>(
			[](
				auto const _index
			){
				return
					movable{
						_index()
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
		0u
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			inited
		).value(),
		1u
	);
}
