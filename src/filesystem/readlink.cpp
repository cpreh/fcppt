//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/readlink.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config.h>
#ifdef FCPPT_POSIX_PLATFORM
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/error/strerrno.hpp>
#include <fcppt/iconv.hpp>
#include <unistd.h>
#include <cerrno>
#endif

fcppt::filesystem::path const
fcppt::filesystem::readlink(
#ifdef FCPPT_POSIX_PLATFORM
	fcppt::filesystem::path const &link
#else
	fcppt::filesystem::path const &
#endif
)
{
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
				link.string().c_str(),
				buf.data(),
				buf.capacity()
			)
		);

		if(ret == -1)
		{
			if(errno == ENAMETOOLONG)
			{
				buf.reserve(
					buf.capacity() * 2
				);
				continue;
			}

			throw exception(
				FCPPT_TEXT("readlink failed: ")
				+ error::strerrno()
			);
		}

		buf.resize_uninitialized(
			ret
		);

		buf.push_back(0);

		return path(
			iconv(
				buf.data()
			)
		);
	}
#else
	throw exception(
		FCPPT_TEXT("readlink not supported!")
	);
#endif
}
