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

class link
{
public:
	link(
		fcppt::intrusive::base *prev,
		fcppt::intrusive::base *next
	);

	void
	unlink();

	fcppt::intrusive::detail::link
	move_to(
		fcppt::intrusive::base &
	);

	fcppt::intrusive::base *prev_;

	fcppt::intrusive::base *next_;
};

}
}
}

#endif
