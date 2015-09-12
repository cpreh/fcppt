//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/forward_optional_get.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{
typedef
fcppt::unique_ptr<
	int
>
int_unique_ptr;

typedef
fcppt::optional<
	int_unique_ptr
>
optional_int_unique_ptr;

static_assert(
	std::is_same<
		decltype(
			fcppt::forward_optional_get<
				optional_int_unique_ptr
			>(
				std::declval<
					int_unique_ptr &
				>()
			)
		),
		int_unique_ptr &&
	>::value,
	""
);

template<
	typename Optional,
	typename Function
>
int_unique_ptr
test_move(
	Optional &&_arg,
	Function const _function
)
{
	return
		_function(
			fcppt::forward_optional_get<
				Optional
			>(
				_arg.get_unsafe()
			)
		);
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	forward_get
)
{
FCPPT_PP_POP_WARNING

	int_unique_ptr const result(
		test_move(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[](
				int_unique_ptr &&_ptr
			)
			{
				return
					std::move(
						_ptr
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		*result,
		42
	);
}
