//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/filesystem/remove_extension.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	filesystem_remove_extension
)
{
FCPPT_PP_POP_WARNING

	boost::filesystem::path const path1(
		boost::filesystem::path(
			FCPPT_TEXT("foo")
		)
		/
		boost::filesystem::path(
			FCPPT_TEXT("bar")
		)
	);

	BOOST_CHECK(
		path1 ==
		fcppt::filesystem::remove_extension(
			path1
		)
	);

	boost::filesystem::path const path2(
		path1
		/ FCPPT_TEXT("baz.txt")
	);

	BOOST_CHECK(
		fcppt::filesystem::remove_extension(
			path2
		)
		==
		path1
		/ FCPPT_TEXT("baz")
	);
}
