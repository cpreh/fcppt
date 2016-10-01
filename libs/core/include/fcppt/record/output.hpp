//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_OUTPUT_HPP_INCLUDED
#define FCPPT_RECORD_OUTPUT_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Outputs a record to a stream

\ingroup fcpptrecord
*/
template<
	typename Ch,
	typename Traits,
	typename Types
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::record::object<
		Types
	> const &_record
)
{
	_stream
		<<
		_stream.widen(
			'{'
		);

	fcppt::algorithm::loop(
		Types{},
		[
			&_stream,
			&_record
		](
			auto const _element
		)
		{
			FCPPT_USE(
				_element
			);

			typedef
			fcppt::record::element_to_label<
				fcppt::tag_type<
					decltype(
						_element
					)
				>
			>
			label;

			_stream
				<<
				fcppt::to_std_string(
					fcppt::type_name_from_info(
						typeid(
							typename
							label::tag
						)
					)
				)
				// TODO: Simplify this!
				<<
				_stream.widen(
					' '
				)
				<<
				_stream.widen(
					'='
				)
				<<
				_stream.widen(
					' '
				)
				<<
				fcppt::record::get<
					label
				>(
					_record
				)
				<<
				_stream.widen(
					','
				)
				<<
				_stream.widen(
					' '
				);
		}
	);

	return
		_stream
		<<
		_stream.widen(
			'}'
		);
}

}
}

#endif
