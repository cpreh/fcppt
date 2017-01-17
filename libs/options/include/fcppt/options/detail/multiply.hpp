//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_MULTIPLY_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_MULTIPLY_HPP_INCLUDED

#include <fcppt/options/product_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{
namespace detail
{

template<
	typename Parser1
>
inline
Parser1
multiply(
	Parser1 &&_parser1
)
{
	return
		std::forward<
			Parser1
		>(
			_parser1
		);
}

template<
	typename Parser1,
	typename... Parsers
>
inline
auto
multiply(
	Parser1 &&_parser1,
	Parsers &&..._parsers
)
{
	return
		fcppt::options::product<
			typename
			std::decay<
				Parser1
			>::type,
			decltype(
				fcppt::options::detail::multiply(
					std::forward<
						Parsers
					>(
						_parsers
					)...
				)
			)
		>(
			std::forward<
				Parser1
			>(
				_parser1
			),
			fcppt::options::detail::multiply(
				std::forward<
					Parsers
				>(
					_parsers
				)...
			)
		);
}

}
}
}

#endif
