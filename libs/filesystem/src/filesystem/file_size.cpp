//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/filesystem/file_size.hpp>
#include <fcppt/filesystem/optional_size.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


fcppt::filesystem::optional_size
fcppt::filesystem::file_size(
	boost::filesystem::path const &_path
)
{
	boost::uintmax_t const size{
		boost::filesystem::file_size(
			_path
		)
	};

	return
		fcppt::optional::make_if(
			size
			!=
			static_cast<
				boost::uintmax_t
			>(
				-1
			),
			fcppt::const_(
				size
			)
		);
}
