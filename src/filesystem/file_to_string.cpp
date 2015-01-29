//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/char_type.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/exception.hpp>
#include <fcppt/assert/post.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/filesystem/exception.hpp>
#include <fcppt/filesystem/file_to_string.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/io/ifstream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Size
>
typename
std::enable_if<
	sizeof(
		Size
	)
	>=
	sizeof(
		boost::uintmax_t
	),
	bool
>::type
check_size(
	boost::uintmax_t
)
{
	return
		true;
}

template<
	typename Size
>
typename
std::enable_if<
	sizeof(
		Size
	)
	<
	sizeof(
		boost::uintmax_t
	),
	bool
>::type
check_size(
	boost::uintmax_t const _size
)
{
	return
		fcppt::cast::size<
			Size
		>(
			fcppt::cast::size<
				boost::uintmax_t
			>(
				_size
			)
		)
		==
		_size;
}

}

fcppt::string
fcppt::filesystem::file_to_string(
	boost::filesystem::path const &_path
)
{
	fcppt::io::ifstream stream(
		_path
	);

	if(
		!stream.is_open()
	)
		throw fcppt::filesystem::exception(
			FCPPT_TEXT("Unable to open file ")
			+ fcppt::filesystem::path_to_string(
				_path
			)
		);

	boost::uintmax_t const size(
		boost::filesystem::file_size(
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
		throw fcppt::filesystem::exception(
			fcppt::filesystem::path_to_string(
				_path
			)
			+ FCPPT_TEXT(" is too large for a string to store!")
		);

	fcppt::string ret;

	ret.reserve(
		fcppt::cast::size<
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

	FCPPT_ASSERT_POST(
		stream.eof(),
		fcppt::assert_::exception
	);

	return
		ret;
}
