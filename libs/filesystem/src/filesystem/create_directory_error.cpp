//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/filesystem/create_directory_error.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/system/error_code_to_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/system/error_code.hpp>
#include <fcppt/config/external_end.hpp>


fcppt::string
fcppt::filesystem::create_directory_error(
	boost::filesystem::path const &_path,
	boost::system::error_code const _error
)
{
	return
		FCPPT_TEXT("Failed to create ")
		+
		fcppt::filesystem::path_to_string(
			_path
		)
		+
		FCPPT_TEXT(". Reason: ")
		+
		fcppt::system::error_code_to_string(
			_error
		);
}
