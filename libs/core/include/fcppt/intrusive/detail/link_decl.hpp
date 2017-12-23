//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_DETAIL_LINK_DECL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_DETAIL_LINK_DECL_HPP_INCLUDED

#include <fcppt/intrusive/base_fwd.hpp>
#include <fcppt/intrusive/detail/link_fwd.hpp>


namespace fcppt
{
namespace intrusive
{
namespace detail
{

template<
	typename Type
>
class link
{
public:
	typedef
	fcppt::intrusive::base<
		Type
	>
	base_type;

	link(
		base_type *prev,
		base_type *next
	);

	void
	unlink();

	void
	reset(
		base_type &
	);

	void
	move_to(
		base_type &
	);

	base_type *prev_;

	base_type *next_;
};

}
}
}

#endif
