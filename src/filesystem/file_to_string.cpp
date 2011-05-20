//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/file_to_string.hpp>
#include <fcppt/filesystem/exception.hpp>
#include <fcppt/filesystem/file_size.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/io/ifstream.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/char_type.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/cstdint.hpp>
#include <iterator>

namespace
{

template<
	typename Size
>
typename boost::enable_if<
	boost::mpl::greater_equal<
		boost::mpl::sizeof_<
			Size
		>,
		boost::mpl::sizeof_<
			boost::uintmax_t
		>
	>,
	bool
>::type
check_size(
	boost::uintmax_t
)
{
	return true;
}

template<
	typename Size
>
typename boost::enable_if<
	boost::mpl::less<
		boost::mpl::sizeof_<
			Size
		>,
		boost::mpl::sizeof_<
			boost::uintmax_t
		>
	>,
	bool
>::type
check_size(
	boost::uintmax_t const _size
)
{
	return
		static_cast<
			Size
		>(
			static_cast<
				boost::uintmax_t
			>(
				_size
			)
		)
		== _size;
}

}

fcppt::string const
fcppt::filesystem::file_to_string(
	filesystem::path const &_path
)
{
	fcppt::io::ifstream stream(
		_path
	);

	if(
		!stream.is_open()
	)
		throw filesystem::exception(
			FCPPT_TEXT("Unable to open file ")
			+ fcppt::filesystem::path_to_string(
				_path
			)
		);

	boost::uintmax_t const size(
		fcppt::filesystem::file_size(
			_path
		)
	);

	if(
		!check_size<
			fcppt::string::size_type
		>(
			size
		)
	)
		throw filesystem::exception(
			fcppt::filesystem::path_to_string(
				_path
			)
			+ FCPPT_TEXT(" is too large for a string to store!")
		);

	fcppt::string ret;

	ret.reserve(
		static_cast<
			fcppt::string::size_type
		>(
			size
		)
	);

	ret.assign(
		std::istreambuf_iterator<
			fcppt::char_type
		>(
			stream
		),
		std::istreambuf_iterator<
			fcppt::char_type
		>()
	);

	FCPPT_ASSERT(
		stream.eof()
	);

	return ret;
}
