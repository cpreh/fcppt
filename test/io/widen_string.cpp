//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/io/widen_string.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	io_widen_string
)
{
FCPPT_PP_POP_WARNING

	fcppt::io::ostringstream stream;

	stream
		<<
		fcppt::io::widen_string(
			"test"
		);

	BOOST_CHECK(
		stream.str()
		==
		FCPPT_TEXT("test")
	);
}
