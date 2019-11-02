//          Copyright Carl Philipp Reh 2009 - 2018.
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
#include <fcppt/either/failure_type.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/always.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/trait.hpp>
#include <metal/list/all_of.hpp>
#include <metal/list/list.hpp>
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
	fcppt::either::failure_type<
		fcppt::type_traits::remove_cv_ref_t<
			Either1
		>
	>,
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
	fcppt::type_traits::remove_cv_ref_t<
		Either1
	>
	either1;

	static_assert(
		fcppt::either::is_object<
			either1
		>::value,
		"Either1 must be an either"
	);

	typedef
	::metal::list<
		fcppt::type_traits::remove_cv_ref_t<
			Eithers
		>...
	>
	eithers;

	static_assert(
		::metal::all_of<
			eithers,
			::metal::trait<
				fcppt::either::is_object
			>
		>::value,
		"Eithers must all be eithers"
	);

	typedef
	fcppt::either::failure_type<
		either1
	>
	failure;

	static_assert(
		::metal::all_of<
			eithers,
			::metal::bind<
				::metal::trait<
					std::is_same
				>,
				::metal::always<
					failure
				>,
				::metal::lambda<
					fcppt::either::failure_type
				>
			>
		>::value,
		"All eithers must have the same failure type"
	);

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

	FCPPT_PP_PUSH_WARNING
	FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

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

	FCPPT_PP_POP_WARNING
}

}
}

#endif
