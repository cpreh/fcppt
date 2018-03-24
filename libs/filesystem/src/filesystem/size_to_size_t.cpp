//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_size_t.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/filesystem/size_to_size_t.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename Size
>
std::enable_if_t<
	sizeof(
		Size
	)
	>=
	sizeof(
		boost::uintmax_t
	),
	bool
>
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
std::enable_if_t<
	sizeof(
		Size
	)
	<
	sizeof(
		boost::uintmax_t
	),
	bool
>
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

fcppt::optional_size_t
fcppt::filesystem::size_to_size_t(
	boost::uintmax_t const _size
)
{
	return
		fcppt::optional::make_if(
			check_size<
				std::size_t
			>(
				_size
			),
			[
				_size
			]{
				return
					fcppt::cast::size<
						std::size_t
					>(
						_size
					);
			}
		);
}
