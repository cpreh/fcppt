//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_COMPARISON_HPP_INCLUDED
#define FCPPT_RECORD_COMPARISON_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/object_impl.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Compares two records for equality

\ingroup fcpptrecord
*/
template<
	typename Types
>
bool
operator==(
	fcppt::record::object<
		Types
	> const &_record1,
	fcppt::record::object<
		Types
	> const &_record2
)
{
	return
		fcppt::algorithm::all_of(
			Types{},
			[
				&_record1,
				&_record2
			](
				auto const _tag
			)
			{
				FCPPT_USE(
					_tag
				);

				typedef
				fcppt::record::element_to_label<
					fcppt::tag_type<
						decltype(
							_tag
						)
					>
				>
				label;

				return
					fcppt::record::get<
						label
					>(
						_record1
					)
					==
					fcppt::record::get<
						label
					>(
						_record2
					);
			}
		);
}

/**
\brief Compares two records for inequality

\ingroup fcpptrecord
*/
template<
	typename Types
>
inline
bool
operator!=(
	fcppt::record::object<
		Types
	> const &_record1,
	fcppt::record::object<
		Types
	> const &_record2
)
{
	return
		!(
			_record1
			==
			_record2
		);
}

}
}

#endif
