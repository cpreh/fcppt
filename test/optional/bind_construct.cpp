//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::optional::object<
		std::string::size_type
	>
	optional_size;

	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	auto const conversion(
		[](
			std::string const &_val
		)
		{
			return
				_val.size();
		}
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::map(
			optional_string(),
			conversion
		),
		optional_size()
	);

	BOOST_CHECK_EQUAL(
		fcppt::optional::map(
			optional_string(
				"test"
			),
			conversion
		).get_unsafe(),
		4u
	);
}

namespace
{

class noncopyable
{
	FCPPT_NONCOPYABLE(
		noncopyable
	);
public:
	noncopyable()
	{
	}

	~noncopyable()
	{
	}
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_bind_ref
)
{
FCPPT_PP_POP_WARNING
	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	noncopyable test{};

	BOOST_CHECK_EQUAL(
		&fcppt::optional::map(
			optional_string(
				"42"
			),
			[
				&test
			](
				std::string
			)
			-> noncopyable &
			{
				return
					test;
			}
		).get_unsafe(),
		&test
	);
}
