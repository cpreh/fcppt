//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/create_directories_recursive.hpp>
#include <fcppt/system/make_optional_error_code.hpp>
#include <fcppt/system/optional_error_code.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


fcppt::system::optional_error_code
fcppt::filesystem::create_directories_recursive(
	boost::filesystem::path const &_path
)
{
	boost::system::error_code code{};

	boost::filesystem::create_directories(
		_path,
		code
	);

	return
		fcppt::system::make_optional_error_code(
			code
		);
}
