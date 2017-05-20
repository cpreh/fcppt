//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/char_type.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/filesystem/file_size.hpp>
#include <fcppt/filesystem/file_to_string.hpp>
#include <fcppt/filesystem/ifstream.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <boost/filesystem/path.hpp>
#include <iterator>
#include <type_traits>
#include <utility>
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

fcppt::optional_string
fcppt::filesystem::file_to_string(
	boost::filesystem::path const &_path
)
{
	return
		fcppt::optional::bind(
			fcppt::filesystem::file_size(
				_path
			),
			[
				&_path
			](
				boost::uintmax_t const _size
			)
			{
				if(
					!check_size<
						fcppt::string::size_type
					>(
						_size
					)
				)
					throw
						fcppt::exception{
							fcppt::filesystem::path_to_string(
								_path
							)
							+
							FCPPT_TEXT(" of size ")
							+
							fcppt::insert_to_fcppt_string(
								_size
							)
							+
							FCPPT_TEXT(" is too large for a string to store!")
						};

				fcppt::filesystem::ifstream stream(
					_path
				);

				if(
					!stream.is_open()
				)
					return
						fcppt::optional_string{};

				fcppt::string ret;

				ret.reserve(
					fcppt::cast::size<
						fcppt::string::size_type
					>(
						_size
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

				return
					fcppt::optional::make_if(
						stream.eof(),
						[
							&ret
						]{
							return
								std::move(
									ret
								);
						}
					);
			}
		);
}
