//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_APPLY_HPP_INCLUDED
#define FCPPT_EITHER_APPLY_HPP_INCLUDED

#include <fcppt/identity.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/either/detail/first_failure.hpp>
#include <fcppt/mpl/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
#include <array>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Applies a function to several eithers

\ingroup fcppteither

For eithers <code>e_1 = _either1</code> and <code>e_2, ..., e_n =
_eithers</code>, let <code>i</code> be the smallest number such that
<code>e_i</code> is set to failure <code>f</code>. If such an <code>i</code>
exists, <code>f</code> is returned. Otherwise, <code>e_1, ...., e_n</code> are
set to successes <code>s_1,...,s_n</code> and the result is
<code>_function(s_1,...,s_n)</code>.
*/
template<
	typename Function,
	typename Either1,
	typename... Eithers
>
auto
apply(
	Function const &_function,
	Either1 &&_either1,
	Eithers && ..._eithers
)
->
fcppt::either::object<
	typename
	std::decay<
		Either1
	>::type::failure,
	decltype(
		_function(
			fcppt::move_if_rvalue<
				Either1
			>(
				_either1.get_success_unsafe()
			),
			fcppt::move_if_rvalue<
				Eithers
			>(
				_eithers.get_success_unsafe()
			)...
		)
	)
>
{
	typedef
	typename
	std::decay<
		Either1
	>::type
	either1;

	static_assert(
		fcppt::either::is_object<
			either1
		>::value,
		"Either1 must be an either"
	);

	static_assert(
		fcppt::mpl::all_of<
			boost::mpl::vector<
				typename
				std::decay<
					Eithers
				>::type...
			>,
			fcppt::either::is_object<
				boost::mpl::_1
			>
		>::value,
		"Eithers must all be eithers"
	);

	typedef
	typename
	either1::failure
	failure;

	typedef
	fcppt::either::object<
		failure,
		decltype(
			_function(
				fcppt::move_if_rvalue<
					Either1
				>(
					_either1.get_success_unsafe()
				),
				fcppt::move_if_rvalue<
					Eithers
				>(
					_eithers.get_success_unsafe()
				)...
			)
		)
	>
	result_type;

	return
		_either1.has_success()
		&&
		fcppt::algorithm::all_of(
			std::array<
				bool,
				sizeof...(Eithers)
			>{{
				_eithers.has_success()...
			}},
			fcppt::identity{}
		)
		?
			result_type(
				_function(
					fcppt::move_if_rvalue<
						Either1
					>(
						_either1.get_success_unsafe()
					),
					fcppt::move_if_rvalue<
						Eithers
					>(
						_eithers.get_success_unsafe()
					)...
				)
			)
		:
			result_type(
				fcppt::either::detail::first_failure<
					failure
				>(
					std::forward<
						Either1
					>(
						_either1
					),
					std::forward<
						Eithers
					>(
						_eithers
					)...
				)
			)
		;
}

}
}

#endif
