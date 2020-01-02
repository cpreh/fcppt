//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_optional_error_code.hpp>
#include <fcppt/optional_error_code.hpp>
#include <fcppt/filesystem/create_directory.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>


fcppt::optional_error_code
fcppt::filesystem::create_directory(
	std::filesystem::path const &_path
)
{
	std::error_code code{};

	std::filesystem::create_directory(
		_path,
		code
	);

	return
		fcppt::make_optional_error_code(
			code
		);
}
