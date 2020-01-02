//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_DETAIL_APPLY_HPP_INCLUDED
#define FCPPT_OPTIONS_DETAIL_APPLY_HPP_INCLUDED

#include <fcppt/options/product_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
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
fcppt::type_traits::remove_cv_ref_t<
	Parser1
>
apply(
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
apply(
	Parser1 &&_parser1,
	Parsers &&..._parsers
)
{
	return
		fcppt::options::product<
			fcppt::type_traits::remove_cv_ref_t<
				Parser1
			>,
			decltype(
				fcppt::options::detail::apply(
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
			fcppt::options::detail::apply(
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
