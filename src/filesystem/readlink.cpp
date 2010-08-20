//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/readlink.hpp>
#include <fcppt/filesystem/config.hpp>
#ifdef FCPPT_USE_FILESYSTEM_V3
#include <boost/filesystem/operations.hpp>
#else
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config.hpp>
#ifdef FCPPT_POSIX_PLATFORM
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/error/strerrno.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/to_std_string.hpp>
#include <unistd.h>
#include <cerrno>
#endif
#endif

fcppt::filesystem::path const
fcppt::filesystem::readlink(
#if defined(FCPPT_POSIX_PLATFORM) || defined(FCPPT_USE_FILESYSTEM_V3)
	fcppt::filesystem::path const &link
#else
	fcppt::filesystem::path const &
#endif
)
{
#ifdef FCPPT_USE_FILESYSTEM_V3
	return
		boost::filesystem::read_symlink(
			link
		);
#else
#ifdef FCPPT_POSIX_PLATFORM
	container::raw_vector<
		char
	> buf;

	buf.reserve(
		512
	);

	for (;;)
	{
		ssize_t const ret(
			::readlink(
				to_std_string(
					link.string()
				).c_str(),
				buf.data(),
				buf.capacity()
			)
		);

		if(ret == -1)
		{
			switch(
				errno
			)
			{
			case EINVAL:
				return path();
			case ENAMETOOLONG:
				buf.reserve(
					buf.capacity() * 2
				);
				continue;
			default:
				throw exception(
					FCPPT_TEXT("readlink failed: ")
					+ error::strerrno()
				);
			}
		}

		buf.resize_uninitialized(
			ret
		);

		buf.push_back(0);

		return path(
			from_std_string(
				buf.data()
			)
		);
	}
#else
	throw exception(
		FCPPT_TEXT("readlink not supported!")
	);
#endif
#endif
}
