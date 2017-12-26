//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_APPLY_HPP_INCLUDED
#define FCPPT_EITHER_APPLY_HPP_INCLUDED

#include <fcppt/absurd.hpp>
#include <fcppt/identity.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/either/failure_opt.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/all.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <array>
#include <cstddef>
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
		::brigand::all<
			::brigand::list<
				typename
				std::decay<
					Eithers
				>::type...
			>,
			fcppt::either::is_object<
				::brigand::_1
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

	typedef
	fcppt::optional::object<
		failure
	>
	optional_failure;

	constexpr std::size_t const num_eithers{
		sizeof...(Eithers) + 1u
	};

	typedef
	std::array<
		optional_failure,
		num_eithers
	>
	failure_array;

	return
		fcppt::algorithm::all_of(
			std::array<
				bool,
				num_eithers
			>{{
				_either1.has_success(),
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
			result_type{
				[](
					failure_array &&_failures
				)
				{
					fcppt::optional::object<
						typename
						failure_array::iterator
					> const failure_opt{
						fcppt::algorithm::find_if_opt(
							_failures,
							[](
								optional_failure const &_failure
							)
							{
								return
									_failure.has_value();
							}
						)
					};

					typedef
					typename
					failure_array::iterator
					iterator;

					// Silence -Wnull-dereference warning
					iterator const failure_it{
						failure_opt.has_value()
						?
							failure_opt.get_unsafe()
						:
							fcppt::absurd<
								iterator
							>()
					};

					return
						std::move(
							failure_it->get_unsafe()
						);
				}(
					failure_array{{
						fcppt::either::failure_opt(
							std::forward<
								Either1
							>(
								_either1
							)
						),
						fcppt::either::failure_opt(
							std::forward<
								Eithers
							>(
								_eithers
							)
						)...
					}}
				)
			}
		;
}

}
}

#endif
