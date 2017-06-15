//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

struct throw_cctor
{
	throw_cctor()
	{
	}

	throw_cctor(
		throw_cctor const &
	)
	{
		throw
			fcppt::exception(
				FCPPT_TEXT("Throwing cctor")
			);
	}

	throw_cctor(
		throw_cctor &&
	)
	{
		throw
			fcppt::exception(
				FCPPT_TEXT("Throwing move cctor")
			);
	}

	throw_cctor &
	operator=(
		throw_cctor const &
	) = default;

	throw_cctor &
	operator=(
		throw_cctor &&
	) = default;
};

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	variant_exception
)
{
FCPPT_PP_POP_WARNING

	typedef fcppt::variant::object<
		boost::mpl::vector2<
			std::string,
			throw_cctor
		>
	> variant;

	variant test(
		std::string("test")
	);

	BOOST_CHECK(
		!test.is_invalid()
	);

	throw_cctor const test_cctor{};

	BOOST_CHECK_THROW(
		test =
			test_cctor,
		fcppt::exception
	);

	BOOST_CHECK(
		test.is_invalid()
	);

	BOOST_CHECK_THROW(
		test =
			throw_cctor(),
		fcppt::exception
	);

	BOOST_CHECK(
		test.is_invalid()
	);
}
