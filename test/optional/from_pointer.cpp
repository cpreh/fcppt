//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/from_pointer.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

void
test_function(
	int
)
{
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	optional_from_pointer
)
{
FCPPT_PP_POP_WARNING

	typedef
	void (*fun_ptr)(int);

	BOOST_CHECK(
		fcppt::optional::from_pointer(
			&test_function
		).has_value()
	);

	fun_ptr const ptr(
		nullptr
	);

	BOOST_CHECK(
		!fcppt::optional::from_pointer(
			ptr
		).has_value()
	);
}
