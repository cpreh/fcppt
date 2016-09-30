//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_LABEL_DECL_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_DECL_HPP_INCLUDED

#include <fcppt/record/label_fwd.hpp>
#include <fcppt/record/detail/element_init_fwd.hpp>
#include <fcppt/record/detail/is_tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

template<
	typename Tag
>
struct label
{
	typedef
	Tag
	tag;

	static_assert(
		fcppt::record::detail::is_tag<
			Tag
		>::value,
		"Tag must be a tag"
	);

	template<
		typename Arg
	>
	fcppt::record::detail::element_init<
		Tag,
		typename
		std::decay<
			Arg
		>::type
	>
	operator=(
		Arg &&
	);
};

}
}

#endif
