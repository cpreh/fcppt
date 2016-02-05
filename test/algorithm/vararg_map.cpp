//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/decltype_sink.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	vararg_map
)
{
FCPPT_PP_POP_WARNING

	std::tuple<
		unsigned,
		unsigned long
	> const result(
		fcppt::algorithm::vararg_map<
			boost::mpl::vector2<
				int,
				long
			>
		>(
			[](
				auto const &... _args
			){
				return
					std::make_tuple(
						_args...
					);
			},
			[](
				auto const _tag
			)
			{
				return
					fcppt::cast::to_unsigned(
						fcppt::literal<
							fcppt::tag_type<
								FCPPT_DECLTYPE_SINK(
									_tag
								)
							>
						>(
							42
						)
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0u
		>(
			result
		),
		42u
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0u
		>(
			result
		),
		42uL
	);
}

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
	vararg_map_move
)
{
FCPPT_PP_POP_WARNING

	movable const result{
		fcppt::algorithm::vararg_map<
			boost::mpl::vector1<
				movable
			>
		>(
			[](
				auto && _args
			){
				return
					movable(
						std::forward<
							decltype(
								_args
							)
						>(
							_args
						)
					);
			},
			[](
				auto const _tag
			)
			{
				return
					fcppt::tag_type<
						FCPPT_DECLTYPE_SINK(
							_tag
						)
					>(
						42
					);
			}
		)
	};

	BOOST_CHECK_EQUAL(
		result.value(),
		42
	);
}
