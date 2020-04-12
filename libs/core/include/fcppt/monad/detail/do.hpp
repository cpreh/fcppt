//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MONAD_DETAIL_DO_HPP_INCLUDED
#define FCPPT_MONAD_DETAIL_DO_HPP_INCLUDED

#include <fcppt/monad/bind.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace monad
{
namespace detail
{

template<
	typename Value
>
inline
fcppt::type_traits::remove_cv_ref_t<
	Value
>
do_(
	Value &&_value
)
{
	return
		std::forward<
			Value
		>(
			_value
		);
}

template<
	typename Value,
	typename Lambda,
	typename... Lambdas
>
auto
do_(
	Value &&_value,
	Lambda const &_lambda,
	Lambdas const &... _lambdas
)
{
	return
		fcppt::monad::detail::do_(
			fcppt::monad::bind(
				std::forward<
					Value
				>(
					_value
				),
				_lambda
			),
			_lambdas...
		);
}

}
}
}

#endif
