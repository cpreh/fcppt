//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/text.hpp>
#include <fcppt/filesystem/replace_extension.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>


std::filesystem::path
fcppt::filesystem::replace_extension(
	std::filesystem::path const &_path,
	fcppt::string_view const &_ext
)
{
	return
		std::filesystem::path(
			_path
		).replace_extension(
			fcppt::string{
				FCPPT_TEXT(".")
			}
			+
			fcppt::string{
				_ext
			}
		);
}
