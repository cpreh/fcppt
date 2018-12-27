//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_RECORD_HPP_INCLUDED
#define FCPPT_CATCH_RECORD_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/catch/detail/convert.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/label_name.hpp>
#include <fcppt/record/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace Catch
{

/**
\brief Output specialization for \link fcppt::record::object\endlink.

\ingroup fcpptcatch
*/
template<
	typename Types
>
struct StringMaker<
	fcppt::record::object<
		Types
	>
>
{
	static
	std::string
	convert(
		fcppt::record::object<
			Types
		> const &_record
	)
	{
		return
			'{'
			+
			fcppt::algorithm::fold(
				Types{},
				std::string{},
				[
					&_record
				](
					auto const _element,
					std::string &&_output
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

					return
						std::move(
							_output
						)
						+
						fcppt::record::label_name<
							label
						>()
						+
						" = "
						+
						fcppt::catch_::detail::convert(
							fcppt::record::get<
								label
							>(
								_record
							)
						)
						+
						", ";
				}
			)
			+
			'}';
	}
};

}

#endif
