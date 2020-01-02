//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_SEQUENCE_HPP_INCLUDED
#define FCPPT_OPTIONAL_SEQUENCE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/optional/is_object.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Sequences a container of optionals

\ingroup fcpptoptional

Let \a _source be a container <code>[o_1,...o_n]</code> of type
<code>%fcppt::optional::object\<T\></code>. If there is an <code>i</code> such
that <code>o_i</code> is nothing, then nothing is
returned. Otherwise, all optionals have a value,
<code>[v_1,...,v_n]</code>, and
<code>%fcppt::optional::object\<ResultContainer\>{v_1,...,v_n}</code> is
returned.

\tparam ResultContainer Must be a container of type <code>T</code>

\tparam Source Must be an optional type
*/
template<
	typename ResultContainer,
	typename Source
>
fcppt::optional::object<
	ResultContainer
>
sequence(
	Source &&_source
)
{
	typedef
	fcppt::type_traits::value_type<
		fcppt::type_traits::remove_cv_ref_t<
			Source
		>
	>
	source_optional;

	static_assert(
		fcppt::optional::is_object<
			source_optional
		>::value,
		"The source must be a container of optionals"
	);

	static_assert(
		std::is_same<
			fcppt::type_traits::value_type<
				ResultContainer
			>,
			fcppt::type_traits::value_type<
				source_optional
			>
		>::value,
		"ResultContainer must be a container of the source's success type"
	);

	return
		fcppt::optional::make_if(
			!fcppt::algorithm::contains_if(
				_source,
				[](
					auto const &_optional
				)
				-> bool
				{
					return
						!_optional.has_value();
				}
			),
			[
				&_source
			]{
				return
					fcppt::algorithm::map<
						ResultContainer
					>(
						std::forward<
							Source
						>(
							_source
						),
						[](
							auto &&_value
						)
						{
							return
								fcppt::move_if_rvalue<
									Source
								>(
									_value.get_unsafe()
								);
						}
					);
			}
		);
}

}
}

#endif
