//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/char_type.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/insert_to_fcppt_string.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/filesystem/file_size.hpp>
#include <fcppt/filesystem/file_to_string.hpp>
#include <fcppt/filesystem/ifstream.hpp>
#include <fcppt/filesystem/open.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/filesystem/size_to_size_t.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <boost/filesystem/path.hpp>
#include <cstddef>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


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
				std::size_t const size{
					fcppt::optional::to_exception(
						fcppt::filesystem::size_to_size_t(
							_size
						),
						[
							&_path,
							_size
						]{
							return
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
						}
					)
				};

				return
					fcppt::optional::bind(
						fcppt::filesystem::open<
							fcppt::filesystem::ifstream
						>(
							_path,
							std::ios_base::openmode{}
						),
						[
							size
						](
							fcppt::filesystem::ifstream &&_stream
						)
						{
							fcppt::string ret;

							ret.reserve(
								size
							);

							ret.assign(
								std::istreambuf_iterator<
									fcppt::char_type
								>(
									_stream
								),
								std::istreambuf_iterator<
									fcppt::char_type
								>()
							);

							return
								fcppt::optional::make_if(
									_stream.eof(),
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
		);
}
