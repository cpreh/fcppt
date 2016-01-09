//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_CAT_HPP_INCLUDED
#define FCPPT_EITHER_CAT_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Cats a container of eithers

\ingroup fcppteither

Let \a _source be a container <code>[e_1,...e_n]</code> of type
<code>%fcppt::either::object<F,S></code>. If there is an <code>i</code> such
that <code>e_i</code> has failure <code>f</code> and there is no <code>j <
i</code> such that <code>e_j</code> has a failure, then <code>f</code> is
returned. Otherwise, all eithers have success values,
<code>[s_1,...,s_n]</code>, and
<code>%fcppt::either::object<F,ResultContainer>{s_1,...,s_n}</code> is
returned.

\tparam ResultContainer Must be a container of type <code>S</code>

\tparam Source Must be an either type
*/
template<
	typename ResultContainer,
	typename Source
>
fcppt::either::object<
	typename
	std::decay<
		Source
	>::type::value_type::failure,
	ResultContainer
>
cat(
	Source &&_source
)
{
	typedef
	typename
	std::remove_reference<
		Source
	>::type
	source_type;

	typedef
	typename
	source_type::value_type
	source_either;

	static_assert(
		fcppt::either::is_object<
			source_either
		>::value,
		"The source must be a container of eithrs"
	);

	typedef
	fcppt::either::object<
		typename
		source_either::failure,
		ResultContainer
	>
	result_type;

	static_assert(
		std::is_same<
			typename
			ResultContainer::value_type,
			typename
			source_either::success
		>::value,
		"ResultContainer must be a container of the source's success type"
	);

	return
		fcppt::optional::maybe(
			fcppt::algorithm::find_if_opt(
				_source,
				[](
					auto const &_either
				)
				{
					return
						_either.has_failure();
				}
			),
			[
				&_source
			]{
				return
					result_type{
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
										_value.get_success_unsafe()
									);
							}
						)
					};
			},
			[](
				fcppt::container::to_iterator_type<
					source_type
				> const &_iterator
			)
			{
				return
					result_type{
						fcppt::move_if_rvalue<
							Source
						>(
							_iterator->get_failure_unsafe()
						)
					};
			}
		);
}

}
}

#endif
