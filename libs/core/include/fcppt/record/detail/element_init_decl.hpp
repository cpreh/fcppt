//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_ELEMENT_INIT_DECL_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ELEMENT_INIT_DECL_HPP_INCLUDED

#include <fcppt/record/detail/element_init_fwd.hpp>
#include <fcppt/record/detail/is_tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Tag,
	typename Type
>
class element_init
{
public:
	typedef
	Tag
	tag;

	typedef
	Type
	value_type;

	static_assert(
		!std::is_lvalue_reference<
			value_type
		>::value,
		"Type must not be a reference"
	);

	static_assert(
		fcppt::record::detail::is_tag<
			Tag
		>::value,
		"Tag must be a tag"
	);

	explicit
	element_init(
		value_type &&
	);

	explicit
	element_init(
		value_type const &
	);

	value_type &
	value();
private:
	value_type value_;
};

}
}
}

#endif
